#include "reverse.h"

int reverse(){
    int answer = 0;
    int var1 = prt();
    while(current() != '='){
        move();
        int var2 = prt();
        move();
        switch (current()){
            case '+':
                move();
                answer = var1 + var2;
                var1 = answer;
                break;
            case '-':
                move();
                answer = var1 - var2;
                var1 = answer;
                break;
            case '*':
                move();
                answer = var1 * var2;
                var1 = answer;
                break;
            case '/':
                move();
                if (var2 == 0){
                    return -1;
                }
                else{
                    answer = var1 / var2;
                    var1 = answer;
                    break;
                }
        }
    }
    return answer;
}
