//#include "EulerDdtScheme.H"
#include "ddtScheme.H"

int main(int argc, char *argv[])
{
   std::shared_ptr<ddtScheme> euler = ddtScheme::New("Euler");
    //std::cout << euler->type() << std::endl;  
    
    return 0;
}
