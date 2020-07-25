#include <iostream>
class A
{
public:
    friend class C;
private:
    int data;
};



class C
{
public:
    void set(int x, A& a){a.data = x;std::cout << a.data << std::endl;}
};

int main(int argc, char *argv[])
{


    A a;
    C c;
    c.set(1, a);

    return 0;
}
