#include <iostream>
#include <cstdio>

using namespace std;



int Calc() {
    int i;
    char j;
    int k;
    cin >> i >> j >> k;
    switch (j)
    {
    case('+'):
        cout << i + k << "/n";
        break;
    case('-'):
        cout << i - k << "/n";
        break;
    case('*'):
        cout << i * k << "/n";
        break;

    case('/'):
        cout << i / k << "/n";
        break;

    default:
        break;
    }
    return 0;
}




int Calc2()
{
    int stack[100];
    int sp = 0;
    while (!feof(stdin))//пока есть что считывать оно работает
    {
        int c = getchar();//первый символ слева + - * /
        int x;
        switch (c)
        {
        case  ' ':
        case '\n':
            break;

        case '=':
            cout << stack[sp - 1] << "\n";  //после выполнения всех операций выводит последний элемент из "стека"
            return -1;
            break;



        case '+':
            stack[sp - 2] = stack[sp - 2] + stack[sp - 1]; sp--;
            break;


        case '-':
            stack[sp - 2] = stack[sp - 2] - stack[sp - 1]; sp--;
            break;


        case '*':
            stack[sp - 2] = stack[sp - 1] * stack[sp - 2]; sp--;
            break;

        case '/':
            stack[sp - 2] = stack[sp - 1] / stack[sp - 2]; sp--;
            break;


        default:
            ungetc(c, stdin);//если введена буква то выдает ошибку
            if (scanf_s("%d", &x) != 1)
            {
                cout << scanf_s("%d", &x) << "\n";
                return -1;
            }
            else {
                stack[sp] = x;  sp++;
            }
        }

    }

    return 0;
}





int main(int argc, char** argv)
{
    if (argc > 1)
    {
        string flag = argv[1];
        if (flag == "--forward") {
            Calc();
        }


        if (flag == "--reverse") {
            Calc2();
        }

    }


    else
    {
        cout << "Нет ключа/неизвестный ключ" << "\n";
    }
    system("pause");
    return 0;

}
