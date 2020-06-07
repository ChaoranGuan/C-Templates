#include <iostream>
#include <typeinfo>
using namespace std;
 
class Base
{
public:
	Base(int a = 1)
	{
		ma = a;
	}
	virtual void show()
	{
		cout<<"base show 1"<<endl;
	}
	void show(int b)
	{
		cout<<"base show 2"<<endl;
	}
        int m{90};

        Base& operator()() {return *this;}
private:
	int ma;
};
class Derive : public Base
{
public:
	Derive(int b = 2):Base(b)
	{
		mb = b;
	}
	void show()  //函数覆盖 虚函数表中地址的覆盖 override
	{
		//cout<<"derive show 1"<<endl;
		cout << m << endl;
		cout << Base::m << endl;  // 隐藏 overhide
		print();
	}
	void print()
	{
		cout<<"derive print 1"<<endl;
	}

	
private:
	int mb;
 	int m{100};
};
int main()
{
	int& a =5;	
	Base b;
	Derive d;
	Base* p = &d;
        Base& f = (*p)();
	f.show();
	/*cout<<"base size:"<<" "<<sizeof(b)<<endl;
	cout<<"derive size:"<<" "<<sizeof(d)<<endl;
	cout<<"p type:"<<" "<<typeid(p).name()<<endl;
	cout<<"*p type:"<<" "<<typeid(*p).name()<<endl;*/
	return 0;
}

