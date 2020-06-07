#ifndef EulerDdtScheme_H
#define EulerDdtScheme_H
#include "ddtScheme.H"
#include <string>
class EulerDdtScheme
:
    public ddtScheme
{
public:
    static const std::string typeName;//static const std::string typeName;
    EulerDdtScheme() { std::cout << "Construct Euler scheme." << std::endl; }
};
#endif
