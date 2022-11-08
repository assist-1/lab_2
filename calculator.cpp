/**
 * @file calculator.cpp
 * */
#include <fstream>
#include <iostream>
#include <stack>
#include <cstring>
#include "calculator.h"
using namespace std;


int level(char s)
{
    if (s == '+' || s == '-') return 1;
    return 0;
}

/*!
 * \brief Проверка наличия символа в строке
 * \param s Строка
 * \param symbol Символ
 * \return Усли найден, False в обратном случае.
 * */
bool in(string s, char symbol)//проверяет наличие символа в строке
{ 
    bool fl = false;
    for(int i = 0; i < s.size(); i++)
    {
        if (s[i] == symbol) return true;
    }
    return false;
}

float func(string n1, string n2, char func)//два числа фигачит
{
    // cout << n2 + " " + func + " " + n1 + "\n";
    if (func == '+') return stof(n1) + stof(n2);
    if (func == '-') return stof(n2) - stof(n1);
    if (func == '*') return stof(n1) * stof(n2);
    return stof(n2) / stof(n1);
}   


int mistake(int num)//сообщение об ошибке
{
    cout << "\nOoops, you made a mistake.\n\nError " + to_string(num) + "\n";
    return EXIT_FAILURE;
}



int calculate_forward(bool file)//основная функция, считающая нормальное выражение
{
    string s;//строка, с которой работаем
    if(file)
    {
        try
        {
            ifstream input("input.txt");
            if(input.is_open()) getline(input, s);
            input.close();
        }
        catch(...)
        {
            return mistake(4);
        }
    }
    else
    {
        getline(cin, s);      
    }

    stack <string> nums;
    stack <char> funcs;  

    string n;//число, которое будет собираться
    bool flag_empty = true;
    for (int i = 0; i < s.size(); i++)
    {
        if(in("+-*/", s[i]))
        {
            if(n=="") return(mistake(1));//ошибка, если две функции идут следом, то есть ++

            if(flag_empty)//для первой функции
            {   
                funcs.push(s[i]);
                flag_empty = false;
                nums.push(n);
                n = "";
            }
            else
            {  
                nums.push(n);//кладем число в стек
                n = "";//сбрасмываем его
                if (level(funcs.top()) <= level(s[i]))//если одинаковая приоритетность, то два крайних числа нужно считать
                {
                    string n1 = nums.top();//берем последнее число
                    nums.pop();
                    string n2 = nums.top();//и предпоследнее
                    nums.pop();
                    nums.push(to_string(func(n1, n2, funcs.top())));//и вместо них кладем результат функции
                    funcs.pop();
                }
                funcs.push(s[i]);
            }
        }

        else if(in("0123456789.", s[i]))
        {   
            if(s[i] == '.' && n =="") return(mistake(2));//ошибка число, начинается с точки
            n += s[i];
        }
        else if(s[i] != ' ')//неопознанный символ
        {
            for(int j = 0; j<i; j++) cout << ' ';
            cout << "^\n";
            for(int j = 0; j<i-8; j++) cout << ' ';
            cerr << "Unexpected symbol\n\nError 3";//ошибка непредвиденного символа
            return EXIT_FAILURE;
        }

    }
    nums.push(n);

    for(int i = nums.size(); i>1; i--)
    {
        string n1 = nums.top();//берем последнее число
        nums.pop();
        string n2 = nums.top();//и предпоследнее
        nums.pop();
        nums.push(to_string(func(n1, n2, funcs.top())));//и вместо них кладем результат функции
        funcs.pop();
    }

    string ans = nums.top();
    for(int i = ans.size()-1; i>0;i--)
    {
        if(ans[i] == '0')
        {
            ans.erase(i, 1);
            if(ans[i-1] == '.') ans.erase(i-1, 1);
        }
        else
        {
            cout << ans << "\n";
            return EXIT_SUCCESS;
        }
    }
    cout << ans << "\n";
    return EXIT_SUCCESS;
}





int calculate_reverse(bool file)
{
    string s;//строка, с которой работаем
    if(file)
    {
        try
        {
            ifstream input("input.txt");
            if(input.is_open()) getline(input, s);
            input.close();
        }
        catch(...)
        {
            return mistake(4);//ошибка отсутствие файла input.txt
        }
    }
    else
    {
        getline(cin, s);      
    }

    stack <string> nums;//стек с числами
    string n;
    for(int i = 0; i < s.size(); i++)
    {
        if(in("0123456789.", s[i]))
        {
            if(s[i] == '.' && n =="") return mistake(2);
            if (i == s.size()-1) return mistake(6);//ошибка типа 1 2+ 4
            n += s[i];
        }

        else if(s[i] == ' ')
        {
            if(n!="")
            {
                nums.push(n);
                n = "";
            }
        }

        else if(in("+-/*", s[i]))
        {
            if(n!="")//если две функции подряд
            {
                nums.push(n);
                n="";
            }

            if(nums.size() < 2) return mistake(5);//ошибка типа 3+ одно число 

            string n1 = nums.top();
            nums.pop();
            string n2 = nums.top();
            nums.pop();
            nums.push(to_string(func(n1, n2, s[i])));
        }
    }
    if(nums.size() != 1) return mistake(7);//ошибка типа 3 3 3 3+
    cout << nums.top() << "\n";
    return EXIT_SUCCESS;
}