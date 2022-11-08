
#ifndef CALCULATOR_FUNCTION_H
#define CALCULATOR_FUNCTION_H

extern int flag;
extern int countVal;
extern int countSign;
extern int countHooks1;
extern int countHooks2;
extern double val[200];
extern char Sign[200];
extern int hooks[200];
int PrSigns(char b);
bool Pr(char ar[200], int value);
bool Digit(char a);
void CompareSign (char sign1, char sign2);
void FinishStep();
void StepReverse(int End);
void endHooks(int end);
#endif //CALCULATOR_FUNCTION_H
