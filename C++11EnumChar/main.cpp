#include <iostream>
#include <string>

int main()
{
enum type6 : char
{
	a = '{',
	b = '}',
	c = '\n'
};

std::string dictionary = "dictionary";
std::cout << char(type6::a) << dictionary << char(type6::b);
//std::cout << char(type6::c);
std::cout << type6::a << type6::b << type6::c << std::endl;

}
