#include <iostream>
// int main(int argc, char *argv[]) {
//    for(int i = 0; i < argc; i++)
//        std::cout << argv[i] << std::endl;
//    return 1;
//
//}
int PrSymbol(char a){
    if(a >= '0' && a <= '9')
        return 1;
    else if(a == '*' || a == '/' || a == '+' || a == '-')
        return 2;
    else if(a == '(' || a == ')')
        return 3;
    else if(a == ' ')
        return 4;
    else
        return 0;
}
int main(){
    int k = 0;
    char str[200];
    for(int i = 0; i < 200; i++){
        str[i] = 0;
    }
    std::string text = str;
    std::string textNew = "";
    std::cin.getline(str, 200, '\n');

    if(str[0] == '-' && PrSymbol(str[1]) == 1) {
        textNew += str[k];
        k++;
    }
    for(; k < 199; k++){
        if(str[k] != 0) {
            if (PrSymbol(str[k]) == 0){
                std::cerr << "Wrong";
                return 0;
            }
            if (PrSymbol(str[k]) == 1){
                textNew += str[k];
                if(PrSymbol(str[k+1]) == 2 || PrSymbol(str[k+1]) == 3 || PrSymbol(str[k+1]) == 4){
                    textNew += " ";
                }
            } else if (PrSymbol(str[k]) == 2){
                textNew += str[k];
                if(PrSymbol(str[k+1]) == 2){
                    std::cerr << "Wrong1";
                    return 0;
                }
                if(PrSymbol(str[k+1]) == 1 || PrSymbol(str[k+1]) == 3 || PrSymbol(str[k+1]) == 4){
                    if(PrSymbol(str[k+1]) == 1 && str[k] == '-' && (str[k-1] == '(' || (str[k-1] == ' ' && str[k-2] == '('))){

                    } else {
                        textNew += " ";
                    }
                }
            } else if (PrSymbol(str[k]) == 3){
                textNew += str[k];
                if (PrSymbol(str[k + 1]) == 3 || PrSymbol(str[k + 1]) == 2){
                    if(((str[k]) == ')' && (str[k+1] == ')' || PrSymbol(str[k+1]) == 2 || (PrSymbol(str[k+2]) == 2)  && str[k+1] == ' ') )
                    || (str[k] == '(' && (PrSymbol(str[k+2]) == 1 && str[k+1] == '-')
                    || (PrSymbol(str[k+3]) == 1 && str[k+2] == '-' && str[k+1] == ' '))){
                        textNew += " ";
                    } else {
                        std::cerr << "Wrong2";
                        return 0;
                    }
                } else if(PrSymbol(str[k + 1]) == 1 || PrSymbol(str[k+1]) == 4){
                    textNew += " ";
                }
            }

        }
    }
    std::cout << textNew<< std::endl;
//    char arr[15];
//    for(int i = 0; i < 15; i++){
//        arr[i] = textNew[i];
//        std::cout << textNew[i] << " " << i << " "<< arr[i] << std::endl ;
////        if(arr[i] == textNew[i] && arr[i] == 0)
////            std::cout << 12;
//    }
    return 0;
}
