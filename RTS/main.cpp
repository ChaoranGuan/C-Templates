#include <iostream>
#include <string>
#include <memory>
#include <unordered_map>
#include "TypeInfo.H"
#include <typeinfo>

class ddtScheme
{
public:
    Typename("ddtScheme")
    ddtScheme() {}

    static std::shared_ptr<ddtScheme> New(const std::string& type)
    {
        ddtScheme::constructorMap::iterator it = ddtScheme::constructorMapPtr_->find(type);
        if (it != ddtScheme::constructorMapPtr_->end())
        {
            return it->second();
        }
        else
        {
            std::cout << "Unknown type: " << type << std::endl;
            return nullptr;
        }
    }

    // 为构造函数定义类型别名
    typedef std::shared_ptr<ddtScheme> (*constructorPtr)();

    // 为 map 定义类型别名
    typedef std::unordered_map<std::string, constructorPtr> constructorMap;

    // 声明 map 对象指针
    static constructorMap *constructorMapPtr_;

    // 创建 map 对象
    static void constructConstructorMaps()
    {
        static bool constructed = false;
        if (!constructed)
        {
            constructed = true;
            constructorMapPtr_ = new constructorMap;
        }
    }

    // 用于实现初始化 map 对象的类模板，定义该类的静态变量以实现自动添加条目至 map 对象
    template<typename ddtSchemeType>
    class addConstructorToMap
    {
    public:
        static std::shared_ptr<ddtScheme> ddtSchemeNew()
        {
            return std::shared_ptr<ddtScheme>(new ddtSchemeType);
        }

        addConstructorToMap(const std::string& lookup = ddtSchemeType::typeName)
        {
            ddtScheme::constructConstructorMaps();
            ddtScheme::constructorMapPtr_->insert(ddtScheme::constructorMap::value_type(lookup, ddtSchemeNew));
        }
    };
};

ddtScheme::constructorMap *ddtScheme::constructorMapPtr_ = NULL;

class EulerDdtScheme
:
    public ddtScheme
{
public:
    Typename("Euler");//static const std::string typeName;
    int type(){ return 8;}
    EulerDdtScheme() { std::cout << "Construct Euler scheme." << std::endl; }
};


class backwardDdtScheme
:
    public ddtScheme
{
public:
    Typename("backward");
    backwardDdtScheme() { std::cout << "Construct backward scheme." << std::endl; }
};


class steadyStateDdtScheme
:
    public ddtScheme
{
public:
    Typename("steadyState");
    steadyStateDdtScheme() { std::cout << "Construct steadyState scheme." << std::endl; }
};

class bananaDdtScheme
:
    public EulerDdtScheme
{
public:
    Typename("banana");
    bananaDdtScheme() { std::cout << "Construct banana scheme." << std::endl; }
};


// 定义 typeName
defineTypeName(EulerDdtScheme);//Tname("Euler");//const std::string EulerDdtScheme::typeName = "Euler";
defineTypeName(backwardDdtScheme);
defineTypeName(steadyStateDdtScheme);
defineTypeName(bananaDdtScheme);
defineTypeName(ddtScheme);
// 用模板特化后的类定义静态变量
ddtScheme::addConstructorToMap<ddtScheme> addDdtConstructorToTable_;
ddtScheme::addConstructorToMap<EulerDdtScheme> addEulerConstructorToTable_;
ddtScheme::addConstructorToMap<backwardDdtScheme> addbackwardConstructorToTable_;
ddtScheme::addConstructorToMap<steadyStateDdtScheme> addsteadyStateConstructorToTable_;
ddtScheme::addConstructorToMap<bananaDdtScheme> addbananaStateConstructorToTable_;


int main(int argc, char *argv[])
{
    std::shared_ptr<ddtScheme> euler = ddtScheme::New("Euler");
    std::cout << euler->type() << std::endl;  
    std::shared_ptr<ddtScheme> p {new EulerDdtScheme};
    std::shared_ptr<ddtScheme> steadystate = ddtScheme::New("steadyState");
    std::shared_ptr<ddtScheme> banana = ddtScheme::New("banana");
    std::cout << bananaDdtScheme::typeName << std::endl;

    return 0;
}

