#include <iostream>
#include <string>
double schet();
double skobki();
double proverkachisla()
{
	double result = 0;
	double k = 10;
	short int sign = 1;
	char c;
	c = std::cin.get();
	while (c == ' ')
		c = std::cin.get();
	if (c == '-')
		sign = -1;
	else
		std::cin.putback(c);
	while (true)
	{
		c = std::cin.get();
		while (c == ' ')
			c = std::cin.get();
		if (c>='0' && c<='9')
			result = result * 10 + (c - '0');
		else 
		{
			std::cin.putback(c);
			break;
		}
	}
	c = std::cin.get();
	if (c == '.')
	{
		while (true)
		{
			c = std::cin.get();
			if (c >= '0' && c <= '9')
			{
				result+=(c - '0')/k;
				k*=10;
			} 
			else
			{
				std::cin.putback(c);
				break;
			}
		}
	}
	else
	std::cin.putback(c);
	return sign*result;
}
double schetprioritet()
{
	double result=skobki();
	double temp;
	char c;
	while (true)
	{
		c = std::cin.get();
		while (c == ' ')
			c = std::cin.get();
		switch (c)
		{
		case '*':
			result *=skobki();
			break;
		case '/':
			temp = skobki();
			if (temp == 0)
			{
				std::cout << "nepravilno zadano virazhenie" << std::endl;
				exit(-1);
			}              
			result /= temp;
			break;
		default:
			std::cin.putback(c);
			return result;
		}
	}
}
double schet()
{
	double result = schetprioritet();;
	char c;
	while (true)
	{
		c = std::cin.get();
		while (c == ' ')
			c = std::cin.get();
		switch (c)          
		{
		case '+':
			result+=schetprioritet();;
			break;    
		case '-':
			result-=schetprioritet();;
			break;    
		default:
			std::cin.putback(c);
			return result;
		}
	}
}
double skobki()
{
	double result;
	short int znak = 1;
	char c;
	c = std::cin.get();
	while (c == ' ')
		c = std::cin.get();
	if (c == '-')
	{
		znak = -1;
		c = std::cin.get();
	}
	while (c == ' ')
		c = std::cin.get();
	if (c == '(')
	{
		result = znak*schet();
		c = std::cin.get();
		if (c != ')')
		{
			std::cout << "nepravilno zadano virazhenie" << std::endl;
			exit(-1);    
		}
		return result;
	}
	else
	{
		std::cin.putback(c);
		return znak*proverkachisla();
	}
}
int main()
{
double n;
char t;
std::string a;
std::cin >> a;
if (a=="--forward")
{
while(std::cin.get() != '\n')
	std::cin.clear();
n = schet();
std::cout << "Resultat: " << n << std::endl;
}
else if (a=="--reverse")
{
	while(std::cin.get() != '\n')
		std::cin.clear();
	while(std::cin.get() != ' ')
		t = std::cin.get();
	std::cout << "Resultat: " << t << std::endl;
}
}