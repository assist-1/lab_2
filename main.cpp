#include <iostream>
#include <cstring>
#include "mylib.h"
int main(int argc,char* argv[]){
    int ans;
    if (argc ==2){
        if (strcmp(argv[1],"--reverse")==0)
            ans=opn(0);
        else if (strcmp(argv[1],"--forward")==0) ans=zad1(0);
    }
    if (argc ==3){
        if (strcmp(argv[1],"--reverse")==0 && strcmp(argv[2],"--file")==0)
            ans=opn(1);
        else if (strcmp(argv[1],"--forward")==0 && strcmp(argv[2],"--file")==0) ans=zad1(1);
    }
    std::cout<<ans<<'\n';
}
