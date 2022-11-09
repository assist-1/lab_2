#include <iostream>
#include <fstream>
#include <cmath>

float n[100000], num=0; char buf[20], op[100000]; int ni=0, oi=0, flag=0, eflag=0, bflag=0;

#define ERR {std::cerr << "\nWrong math expression.\n"; return EXIT_FAILURE;}

bool in (char *a, char b)
{
  for (int i=0; a[i]!='\0'; ++i)
  {
    if (a[i]==b) return true;
  }
  return false; 
}

int ToDig (char a)
{
  return (int)(a-'0');
}

void ToNum(char a)
{
  static int dflag=0;
  if (!flag) dflag=0;
  if (a=='.') dflag++;
  else if (dflag) {num+=(ToDig(a)/pow(10,(dflag++)));}
  else {num=10*num+ToDig(a);}
}

void Operation (char a)
{
  switch(a)
  {
    case '+': n[ni-2]+=n[ni-1]; n[--ni]=0; break; 
    case '-': n[ni-2]-=n[ni-1]; n[--ni]=0; break;
    case '*': n[ni-2]*=n[ni-1]; n[--ni]=0; break;
    case '/': n[ni-2]/=n[ni-1]; n[--ni]=0; break;
    case '=': eflag=1; break;
    default: ;
  }
}

void FOper()
{
  switch (op[--oi])
  {
    case '+': op[oi]='0'; n[ni-2]+=n[ni-1]; n[--ni]=0; 
        break;
    case '-': op[oi]='0'; n[ni-2]-=n[ni-1]; n[--ni]=0; 
        break;
    case '*': op[oi]='0'; n[ni-2]*=n[ni-1]; n[--ni]=0; 
        break;
    case '/': op[oi]='0'; n[ni-2]/=n[ni-1]; n[--ni]=0; 
        break;
    default: break;    
  }
}

void FOpers(char a)
{
  switch (a)
  {
    case '=': eflag=1; break;
    case '(': if(flag) {op[oi++]='*'; op[oi++]='(';}
              else op[oi++]='(';
              break;
    case ')': bflag=1;
              while (op[oi-1]!='(')
              {
                FOper();
              }
              op[--oi] = '0';
              break;
    case '+': 
    case '-': while (op[oi-1]!='('&&oi!=0)
              {
                FOper();
              }
              op[oi++] = a;
              break;
    case '*': 
    case '/': while (op[oi-1]=='*'||op[oi-1]=='/')
              {
                FOper();
              }
              op[oi++] = a;
              break;
    default: break;
  }
}


bool comp (char *a, const char *b)
{
  for (int i=0; a[i]!='\0'; ++i)
  {
    if (a[i]!=b[i])
    {
      return false;
    }
  }
  return true;
}

int RevPolNot (bool nf)
{  
  if (nf) 
  {
    std::ifstream f (".\\SolveFile");
    for (;!(f.eof()||eflag);)
    {
      if (flag==1) {flag=0; n[ni++]=num; num=0;}
      f >> buf;
      for (int i=0; !(buf[i]=='\0'||eflag);++i)
      {
        if (buf[i]==26||buf[i]==10) eflag=1;
        else if (in("1234567890.",buf[i]))
        {
          ToNum(buf[i]);
          if (flag==0) flag=1;
        }
        else if (in("+-*/=",buf[i]))
        {
          if (flag==1) {flag=0; n[ni++]=num; num=0;}
          Operation (buf[i]);
        }
        else ERR
      }
    }
    f.close();
  }
  else
  {
    for (;!(std::cin.eof()||eflag);)
    {
      if (flag==1) {flag=0; n[ni++]=num; num=0;}
      std::cin >> buf;
      for (int i=0; !(buf[i]=='\0'||eflag);++i)
      {
        if (buf[i]==26||buf[i]==10) eflag=1;
        else if (in("1234567890.",buf[i]))
        {
          ToNum(buf[i]);
          if (flag==0) flag=1;
        }
        else if (in("+-*/=",buf[i]))
        {
          if (flag==1) {flag=0; n[ni++]=num; num=0;}
          Operation (buf[i]);
        }
        else ERR
      }
    }
  }
  if (ni!=1) ERR
  std::cout << "\n" << n[0] << "\n";  
  return EXIT_SUCCESS;
}

int ForNot (bool nf)
{
  if (nf) 
  {
    std::ifstream f (".\\SolveFile");
    for (;!f.eof();)
    {
      if (flag==1) {flag=0; n[ni++]=num; num=0;}
      f >> buf;
      for (int i=0; !(buf[i]=='\0'||eflag);++i)
      {
        if (buf[i]==26||buf[i]==10) eflag=1;
        else if (in("1234567890.",buf[i]))
        {
          ToNum(buf[i]);
          if (!flag&&bflag) op[oi++]='*';
          flag=1;
        }
        else if (in("+-*/=()",buf[i]))
        {
          bflag=0;
          if (flag) {n[ni++]=num; num=0;}
          FOpers(buf[i]);
          flag=0;
        }
        else ERR
      }
    }
    f.close();
  }
  else
  {
    for (;!(std::cin.eof()||eflag);)
    {
      if (flag==1) {flag=0; n[ni++]=num; num=0;}
      std::cin >> buf;
      for (int i=0; !(buf[i]=='\0'||eflag);++i)
      {
        if (buf[i]==26||buf[i]==10) eflag=1;
        else if (in("1234567890.",buf[i]))
        {
          ToNum(buf[i]);
          if (!flag&&bflag) op[oi++]='*';
          flag=1;
        }
        else if (in("+-*/=()",buf[i]))
        {
          bflag=0;
          if (flag) {n[ni++]=num; num=0;}
          FOpers(buf[i]);
          flag=0;
        }
        else ERR
      }
    }
  }
  while (!(oi==0||ni==1))
  {
    FOper();
  }
  if (oi!=0||ni!=1) ERR
  std::cout << "\n" << n[0] << "\n";
  return EXIT_SUCCESS;
}
#undef ERR