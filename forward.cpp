#include "forward.h"

const char* ch;

char current();
char move();
int number();
int prt();
int mltp();
int forward();

char current(){
    return *ch;
}

char move(){
    return *ch++;
}

int number(){
    int answer = move() - '0';
    while (current() >= '0' && current() <= '9'){
        answer = 10*answer + move() - '0';
    }
    return answer;
}

int prt(){
    if (current() >= '0' && current() <= '9'){
        return number();
    }
    else if (current() == '('){
        move();
        int answer = forward();
        move();
        return answer;
    }
    else if (current() == '-'){
        move();
        return -prt();
    }
    return 0;
}

int mltp(){
    int answer = prt();
    while (current() == '*' || current() == '/'){
        if (move() == '*'){
            answer *= prt();
        }
        else{
            answer /= prt();
        }
    }
    return answer;
}

int forward(){
    int answer = mltp();
    while (current() == '+' || current() == '-'){
        if (move() == '+'){
            answer += mltp();
        }
        else{
            answer -= mltp();
        }
    }
    return answer;
}
