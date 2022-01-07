///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.6 (2021/11/15 20:28)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER5_TERM26_H
#define EFFECTIVE_MODERN_CPP_CHAPTER5_TERM26_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <chrono>
#include <memory>
#include <set>
#include <string>

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter5
        {
            namespace Terms26
            {
                extern std::multiset<std::string> names;  // 全局数据结构

                template <typename T>
                void Log(MAYBE_UNUSED const T& time, MAYBE_UNUSED const std::string& message) noexcept
                {
                }

                namespace Example0
                {
                    void LogAndAdd(const std::string& name);
                }

                namespace Example1
                {
                    template <typename T>
                    void LogAndAdd(T&& name)
                    {
                        const auto now = std::chrono::system_clock::now();

                        Log(now, "logAndAdd");

                        names.emplace(std::forward<T>(name));
                    }
                }

                namespace Example2
                {
                    template <typename T>
                    void LogAndAdd(T&& name)
                    {
                        const auto now = std::chrono::system_clock::now();

                        Log(now, "logAndAdd");

                        names.emplace(name);
                    }

                    std::string NameFromIdx(MAYBE_UNUSED int idx);  // 返回索引对应有名字

                    void LogAndAdd(int idx);  // 新的重载函数
                }

                namespace Example0
                {
                    std::string NameFromIdx(MAYBE_UNUSED int idx);  // 返回索引对应有名字

                    class Person
                    {
                    public:
                        template <typename T>
                        explicit Person(T&& n)
                            : name(std::forward<T>(n))  // 完美转发构造函数，初始化了数据成员
                        {
                        }

                        /* explicit Person(Person& n)
                            : name(std::forward<Person&>(n))  // 由完美转发模板出发实例化
                        {
                        }*/

                        explicit Person(int idx);  // 形参为int的构造函数

                        // Person(const Person& n);  // 复制构造函数（由编译器生成）
                        // Person(Person&& n);  // 移动构造函数（由编译器生成）

                    private:
                        std::string name;
                    };
                }

                namespace Example1
                {
                    std::string NameFromIdx(MAYBE_UNUSED int idx);  // 返回索引对应有名字

                    class Person
                    {
                    public:
                        template <typename T>
                        explicit Person(T&& n)
                            : name(std::forward<T>(n))
                        {
                        }

                        /* explicit Person(const Person& n)
                            : name(std::forward<Person>(n))  // 由模板出发实例化而得到的构造函数
                        {
                        }*/

                        // Person(const Person& n);  // 复制构造函数（由编译器生成）

                    private:
                        std::string name;
                    };

                    /*
                    class SpecialPerson : public Person
                    {
                    public:
                        // 复制构造函数；调用的是基类的完美转发构造函数
                        SpecialPerson(const SpecialPerson& rhs)
                            : Person(rhs)
                        {
                            // ...
                        }

                        // 移动构造函数；调用的是基类的完美转发构造函数
                        SpecialPerson(SpecialPerson&& rhs)
                            : Person(std::move(rhs))
                        {
                            // ...
                        }
                    };
                    */
                }
            }
        }
    }
}
#endif  // EFFECTIVE_MODERN_CPP_CHAPTER5_TERM26_H
