bool isdigit(char b){
    if ('0'<=b && b<='9'){
        return true;
    }
    else{
        return false;
    }
}
int perform(int a, int b, char op){
    switch(op){
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default:
            break;
    }
    return 0;
}
int precedence(char op){
    if(op == '+'||op == '-')
        return 1;
    if(op == '*'||op == '/')
        return 2;
    return 0;
}