#ifndef ddtScheme_H
#define ddtScheme_H
#include <memory>
#include <unordered_map>
#include <iostream>
class ddtScheme
{
public:
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
#endif

