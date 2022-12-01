#include <iostream>
#include <fstream>
int prioritet(int s){
    if (s==-3 || s==-4)
        return 1;
    else if (s==-5 || s==-6)
        return 2;
    else if (s==-2 || s==-1)
        return 0;
    else return -10000000;
}
class stackdlyachisel {
private:
    int i = 0;
    int mas[1000];
public:
    stackdlyachisel() {
    }
    void pop() {mas[i - 1] = 0;i--;}
    void push(int a) {mas[i] = a;i++;}
    int top() {return mas[i - 1];}
    int size() {return i;}
};
bool is_digit(char s){
    if (s>='0' && s<='9')
        return true;
    else
        return false;
}
int digit(char s){
    if (s=='0') return 0;
    else if (s=='1') return 1;
    else if (s=='2') return 2;
    else if (s=='3') return 3;
    else if (s=='4') return 4;
    else if (s=='5') return 5;
    else if (s=='6') return 6;
    else if (s=='7') return 7;
    else if (s=='8') return 8;
    else if (s=='9') return 9;
    else return -10000000;
}
bool is_operation(char s){
    if (s=='+' || s=='-' || s=='*' || s=='/')
        return true;
    else
        return false;
}
bool is_skobka1(char s){
    if (s=='(')
        return true;
    else
        return false;
}
bool is_skobka2(char s){
    if (s==')')
        return true;
    else
        return false;
}
bool is_ravno(char s){
    if (s=='=')
        return true;
    else
        return false;
}
int operation(char s){
    if (s=='+') return -3;
    else if (s=='-') return -4;
    else if (s=='*') return -5;
    else if (s=='/') return -6;
    else return 1000000;
}
int skobki(char s){
    if (is_skobka1(s)==true)
        return -2;
    else if(is_skobka2(s)==true)
        return -1;
    else return 1000000;
}
int vozmozhnsimv(char s){
    if (is_digit(s)==true || is_operation(s)==true || is_skobka1(s)==true || is_skobka2(s)==true || is_ravno(s)==true || s==' ')
        return 1;
    else return 10000000;
}
int zad1(int flag) {
    std::ifstream file2;
    stackdlyachisel stck1,stck2;
    int f = 0;
    int arr[100];
    std::string str;
    int i = 0;
    int z=0;
    char c=0;
    arr[i] = -2;
    file2.open("calcul.txt");
    while (f == 0) {
        if (flag==0) {
            c = getchar();
            if (vozmozhnsimv(c)!=1)
                return -100000000;
        }
        else{
            c = file2.get();
            if (vozmozhnsimv(c)!=1)
                return -100000000;
        }
        if (digit(c) >= 0 && digit(c) <= 9 && z==0)
            str += c;
        else if (digit(c) >= 0 && digit(c) <= 9 && z==1) {
            str += c;
            z=0;
        }
        else if (is_operation(c) == true && z ==0) {
            i++;
            arr[i] = atoi(str.c_str());
            str = "";
            i++;
            arr[i] = operation(c);
        }
        else if (is_operation(c) == true && z ==1) {
            str = "";
            i++;
            arr[i] = operation(c);
        }
        else if (is_skobka1(c) == true) {
            i++;
            arr[i] = skobki(c);
        } else if (is_skobka2(c) == true && z==0) {
            i++;
            arr[i] = atoi(str.c_str());
            str = "";
            i++;
            arr[i] = skobki(c);
            z = 1;
        }
        else if (is_skobka2(c) == true && z==1) {
            i++;
            arr[i] = skobki(c);
            z=1;
        } else if (is_ravno(c) == true && z==0) {
            i++;
            arr[i] = atoi(str.c_str());
            str="";
            i++;
            arr[i] = -1;
            i++;
            arr[i] = -7;
            f=1;
        }
        else if (is_ravno(c) == true && z==1) {
            str="";
            i++;
            arr[i] = -1;
            i++;
            arr[i] = -7;
            f=1;
        }
    }
    int j=0;
    int u,v;
    i=1;
    stck2.push(arr[j]);
    while (i!=0) {
        j++;
        if (arr[j] >= 0)
            stck1.push(arr[j]);
        else if (arr[j] < -2 && arr[j] > -7)
            if (prioritet(stck2.top())<prioritet(arr[j])) {
                stck2.push(arr[j]);
            }
            else{
                u=stck1.top();
                stck1.pop();
                v=stck1.top();
                stck1.pop();
                if (stck2.top()==-3){
                    stck1.push(u+v);
                    stck2.pop();
                    if (prioritet(stck2.top())<prioritet(arr[j]))
                        stck2.push(arr[j]);
                    else j--;
                }
                else if (stck2.top()==-4){
                    stck1.push(v-u);
                    stck2.pop();
                    if (prioritet(stck2.top())<prioritet(arr[j]))
                        stck2.push(arr[j]);
                    else j--;
                }
                else if (stck2.top()==-5){
                    stck1.push(v*u);
                    stck2.pop();
                    if (prioritet(stck2.top())<prioritet(arr[j]))
                        stck2.push(arr[j]);
                    else j--;
                }
                else if (stck2.top()==-6){
                    if (u!=0){
                        stck1.push(v/u);
                        stck2.pop();
                    }
                    else
                        return -10000000;
                    if (prioritet(stck2.top())<prioritet(arr[j]))
                        stck2.push(arr[j]);
                    else j--;
                }
            }
        else if (arr[j]==-2){
            stck2.push(arr[j]);
            i+=1;
        }
        else if (arr[j]==-1) {
            while (stck2.top() != -2) {
                u=stck1.top();
                stck1.pop();
                v=stck1.top();
                stck1.pop();
                if (stck2.top()==-3){
                    stck1.push(u+v);
                    stck2.pop();
                }
                else if (stck2.top()==-4){
                    stck1.push(v-u);
                    stck2.pop();
                }
                else if (stck2.top()==-5){
                    stck1.push(v*u);
                    stck2.pop();
                }
                else if (stck2.top()==-6){
                    if (u!=0){
                        stck1.push(v/u);
                        stck2.pop();
                    }
                    else
                        return -10000000;
                }
            }
            i--;
            stck2.pop();
        }
    }
    file2.close();
    return stck1.top();
}

int opn(int flag) {
    std::ifstream file1;
    int f = 0;
    int arr[100];
    std::string str;
    int i = -1;
    int z = 0;
    char c = 0;
    arr[i] = -2;
    file1.open("calculopn.txt");
    while (f == 0) {
        if (flag == 0) {
            c =getchar();
            if (vozmozhnsimv(c) != 1)
                return -100000000;
        } else {
            c = file1.get();
            if (vozmozhnsimv(c) != 1)
                return -100000000;
        }
        if (digit(c) >= 0 && digit(c) <= 9){
            str += c;
            z=1;
        }
        else if (c==' ') {
            if (z==1){
                i++;
                arr[i] = atoi(str.c_str());
                str="";
                z=0;
            }
        }
        else if (is_operation(c)==true) {
            if (z==1){
                i++;
                arr[i] = atoi(str.c_str());
                str="";
                z=0;
            }
            if (operation(c) == -3) {
                arr[i - 1] = arr[i] + arr[i - 1];
                i--;
            }
            if (operation(c) == -4) {
                arr[i - 1] = arr[i-1] - arr[i];
                i--;
            }
            if (operation(c) == -5) {
                arr[i - 1] = arr[i] * arr[i - 1];
                i--;
            }
            if (operation(c) == -6) {
                if (arr[i]!=0) {
                    arr[i - 1] = arr[i - 1] / arr[i];
                    i--;
                }
                else
                    return -10000000;
            }
        }
        else if (is_ravno(c)==true) {
            f = 1;
            file1.close();
            return arr[i];
        }
    }
    return -1000000;
}
