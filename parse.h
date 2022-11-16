int convert_to_int(char digit);
int GetSymbol(bool from_file);
int precedence(char op);
int eval(int a, int b, char op);
void op();
void parenthesis();
void digit();
int parse(bool from_file);