#include <iostream>

class A
{
  int a;
public:
    A(){a = 0;}

    ~A(){};

friend class B;
};

class B:public A{

public:
    void show()
    {std::cout << this->a << std::endl;}
};


int main()
{
    B b;
    b.show();
    return 0;
}
