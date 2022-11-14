#include <iostream>
#include <stack>
#include <cctype>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
#include <fstream>
#include <vector>
using namespace std;


//Считаем в польской 
void Reverse(std::string expression)
{
    //Заведем стек переменных
    vector<int> stack;
    int number = 0;
    bool flag = true;

    for (const auto& i : expression)
    {
        // Сформируем число 
        if (isdigit(i))//Цифра?
        {
            number *= 10;
            number += (i - '0');
            flag = true;
        }
        else //Уже сформировано число
        {
            if (i != ' ')  //Встретили знак, то выполним операцию
            {

                //Возьмём два последних операнда
                int num2 = stack.back();
                stack.pop_back();
                int num1 = stack.back();
                stack.pop_back();

                //Определим и произведем операцию
                if (i == '+')
                    stack.push_back(num1 + num2);
                else if (i == '-')
                    stack.push_back(num1 - num2);
                else if (i == '*')
                    stack.push_back(num1 * num2);
                else if (i == '/')
                    stack.push_back(num1 / num2);
                flag = false;  // Нужно ли возращать что-то? false = да)
            }

            //Вернем результат
            else if (i == ' ' && flag) //flag нужен, так как добавляем обратно, если взяли от туда 2 операнда 
            {
                stack.push_back(number);
                number = 0;
            }
        }
    }

    cout << stack.back();
}

// Создадим из обычной польскую
std::string RPN(std::string str)
{
    std::string srpn;

    std::string::size_type ind; //целочисленный без знаковый
    while ((ind = str.find(' ')) != std::string::npos) // удаление пробелов из входной строки (npos конец строки)
    {
        str.erase(ind, 1); //уберем пробел
    }

    //Обработаем отрицательные числа
    for (int i = 0; i < str.size(); ++i)
    {
        if ((str[i] == '+' || str[i] == '-') && (0 == i || (!isalnum(str[i - 1]) && str[i - 1] != '.' && str[i - 1] != ')')))//  isalnum - цифра или буква
        {
            //Компилятор определяет тип 
            auto it = std::find_if(str.begin() + i + 1, str.end(), [](char const c) { return !isalnum(c); }); // найти (начало)(конец)(символ)
            // если было -1 стало (0-1)
            str.insert(it, ')');
            str.insert(i, "(0");
        }
    }

    //Укажем вес знаков
    std::map<char, size_t> map;
    map.insert(std::make_pair('*', 3));
    map.insert(std::make_pair('/', 3));
    map.insert(std::make_pair('+', 2));
    map.insert(std::make_pair('-', 2));
    map.insert(std::make_pair('(', 1));
    std::stack<char> stack;

    //Сформируем строку в польской 
    for (auto c : str)
    {
        if (!isalnum(c) && ('.' != c)) // если это знак
        {
            srpn += ' ';

            // Если нашли конец скобки 
            if (')' == c)
            {

                //Найдём начало скобки, добавим в результирющую польсукую 
                while (stack.top() != '(')
                {
                    srpn += stack.top();
                    stack.pop();
                    srpn += ' ';
                }
                stack.pop();
            }

            //Если только открыли скобку, то запомним место 
            else if ('(' == c)
            {
                stack.push(c);
            }

            //Добавим в стек если он пуст
            else if (stack.empty() || (map[stack.top()] < map[c]))
            {
                stack.push(c);
            }
            else
            {
                do
                {
                    srpn += stack.top();
                    srpn += ' ';
                    stack.pop();
                } while (!(stack.empty() || (map[stack.top()] < map[c])));
                stack.push(c);
            }
        }
        else
        {
            srpn += c;
        }
    }
    srpn += ' ';
    //  Добавим остаток из стека добавляется в результ. строку
    while (!stack.empty())
    {
        srpn += stack.top();
        srpn += ' ';
        stack.pop();
    }
    return srpn;
}

//считаем в обычной
void Forward(std::string str) {
    Reverse(RPN(str));
}

//Считаем из файла данные
string ReadFromFile(string filename)
{
    ifstream ifs(filename);
    string str;
    while (ifs)
        ifs >> str;
    return str;
}

// Калькулятор через файл
void ForwardFile(string str) {
    Forward(ReadFromFile(str));
}
