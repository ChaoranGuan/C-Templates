#include <iostream>

class A
{
		int i {};
	public:
		A(int a){i = a;}
		int getI(){return i;}

};
void printA(A a)
{
	std::cout << a.getI() << std::endl;
}

int main()
{
A a = A (2);
printA(a);
printA(A (3));
}

