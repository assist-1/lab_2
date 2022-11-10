#include <fstream>
#include <iostream>
#include <stack>
#include <cstring>
#include "calculator.h"
using namespace std;
// #define DEBUG


int level(char s)//приоритетность математических операций
{
    if (s == '+' || s == '-') return 1;
    return 0;
}


bool in(string s, char symbol)//проверка на наличие символа в строке
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
    #ifdef DEBUG
    cout << n2 + " " + func + " " + n1 + "\n";
    #endif//DEBUG
    
    if (func == '+') return stof(n1) + stof(n2);
    if (func == '-') return stof(n2) - stof(n1);
    if (func == '*') return stof(n1) * stof(n2);
    return stof(n2) / stof(n1);
}   


int mistake(int num)//сообщение об ошибке
{
    cout << "Ooops, something is wrong.\nError " + to_string(num) + "\n";
    return EXIT_FAILURE;
}







int calculate_forward(bool file)//основная функция, считающая нормальное выражение
{
    string s;//строка, с которой работаем
    if(file)
    {
       ifstream file;
       file.open("input.txt");
       if(!file) return mistake(4);
    }
    else
    {
        getline(cin, s);      
    }

    stack <string> nums;//стек с числами
    stack <char> funcs;//стек с математическими операциями

    string n;//число, которое будет собираться
    bool flag_empty = true;//флаг для первой функции
    for (int i = 0; i < s.size(); i++)
    {
        if(in("+-*/", s[i]))
        {
            if(n=="") return(mistake(1));//ошибка, если две функции идут следом, то есть ++

            if(flag_empty)//без этого флага в стеке чисел будет только одно число, а обычно считаются два крайних числа из стека
            {   
                funcs.push(s[i]);//поэтому просто кидаем знак в стек с операциями
                flag_empty = false;
                nums.push(n);
                n = "";
            }
            else
            {  
                nums.push(n);//кладем число в стек
                n = "";//сбрасмываем его
                if (level(funcs.top()) <= level(s[i]))//если приоритетность не больше, то два крайних числа нужно считать
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
            if(s[i] == '.' && n =="") return mistake(2);//ошибка, число начинается с точки
            if(s[i-1] == ' ' && n!= "") return mistake(9);//ошибка, между числами нет знака
            n += s[i];
        }
        else if(s[i] != ' ' )//неопознанный символ
        {
            return mistake(3);//ошибка, неопознанный символ
        }
    }

    if(n=="") return mistake(8);//ошибка, математическое выражение заканчивается знаком
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
       ifstream file;
       file.open("input.txt");
       if(!file) return mistake(4);
    }
    else
    {
        getline(cin, s);      
    }

    stack <string> nums;//стек с числами
    string n;//число, которое будет собираться
    for(int i = 0; i < s.size(); i++)
    {
        if(in("0123456789.", s[i]))
        {
            if(s[i] == '.' && n =="") return mistake(2);//ошибка, число начинается с точки
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
            if(n!="")//если не две операции подряд
            {
                nums.push(n);
                n="";
            }

            if(nums.size() < 2) return mistake(5);//ошибка, чисел меньше; 3+

            string n1 = nums.top();
            nums.pop();
            string n2 = nums.top();
            nums.pop();
            nums.push(to_string(func(n1, n2, s[i])));
        }
        else if(s[i] != ' ' )//неопознанный символ
        {
            return mistake(3);//ошибка, неопознанный символ
        }
    }
    if(n!="") return mistake(6);//ошибка, выражение заканчивается числом
    if(nums.size() != 1) return mistake(7);//ошибка, при опн в стеке всегда будет максимум два числа, а после ласт операции одно 
    if(nums.size()==0) return mistake(8);
    cout << nums.top() << "\n";
    return EXIT_SUCCESS;
}