#ifndef TypeInfo_H
#define TypeInfo_H
#define Typename(s) \
static const std::string typeName_()\
{return s;}\
static const std::string typeName;\
virtual const std::string& type() const {\
return typeName;}
#define defineTypeName(ss)\
const std::string ss::typeName = ss::typeName_();
#endif
