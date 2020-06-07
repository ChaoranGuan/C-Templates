#include "EulerDdtScheme.H"
const std::string EulerDdtScheme::typeName = "Euler";
ddtScheme::addConstructorToMap<EulerDdtScheme> addEulerConstructorToTable_;
