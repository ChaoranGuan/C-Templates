#include <iostream>
#include <string>

using namespace std;

int main()
{
	string* p = new string;
	delete p;
	p = 0;
//	cout << *p << endl;

}
