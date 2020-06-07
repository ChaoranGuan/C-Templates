#include <iostream>

template<typename T>
auto max(T a, T b) -> decltype(true?b:a)
{
	return a < b ? b : a;
}

int main()
{
	double i = 0;
        double j = 1.1;
	double& i1 = i;
        double& j1 = j;
	//::max(i1, j1);
	std::cout << ::max(i1, j1) << std::endl;
}
