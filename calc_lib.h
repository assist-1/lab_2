#ifndef CALC_CALC_LIB_H
#define CALC_CALC_LIB_H

double make_double(char*, int);

int priority(char);

double make_operation(double, double, char);

bool check_forward(char*, int);

bool check_reverse(char*, int);

double calculate_reverse(char*, int);

char* forward_to_reverse(char*, int);

int len_of_reversed(char*);

#endif //CALC_CALC_LIB_H
