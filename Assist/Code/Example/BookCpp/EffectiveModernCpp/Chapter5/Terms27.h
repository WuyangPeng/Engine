///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.6 (2021/11/16 20:44)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER5_TERM27_H
#define EFFECTIVE_MODERN_CPP_CHAPTER5_TERM27_H

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
            namespace Terms27
            {
                namespace Example0
                {
                    std::string NameFromIdx(MAYBE_UNUSED int idx);

                    class Person
                    {
                    public:
                        explicit Person(std::string n) noexcept;  // 替换掉T&&型别的构造函数

                        explicit Person(int idx);

                    private:
                        std::string name;
                    };
                }

                extern std::multiset<std::string> names;  // 全局数据结构

                template <typename T>
                void Log(MAYBE_UNUSED const T& time, MAYBE_UNUSED const std::string& message) noexcept
                {
                }

                namespace Example0
                {
                    template <typename T>
                    void LogAndAdd(T&& name)  // 制备日志条目，将名字添加到数据结构中
                    {
                        const auto now = std::chrono::system_clock::now();

                        Log(now, "logAndAdd");

                        names.emplace(std::forward<T>(name));
                    }
                }

                namespace Example1
                {
                    std::string NameFromIdx(MAYBE_UNUSED int idx);

                    void LogAndAddImpl(int idx, std::true_type);

                    template <typename T>
                    void LogAndAddImpl(T&& name, std::false_type)
                    {
                        const auto now = std::chrono::system_clock::now();

                        Log(now, "logAndAdd");

                        names.emplace(std::forward<T>(name));
                    }

                    template <typename T>
                    void LogAndAdd(T&& name)
                    {
                        LogAndAddImpl(std::forward<T>(name),
                                      std::is_integral<T>());  // 不够正确
                    }
                }

                namespace Example2
                {
                    std::string NameFromIdx(MAYBE_UNUSED int idx);

                    // 整数实参：查找名字并用它调用LogAndAdd
                    void LogAndAddImpl(int idx, std::true_type);

                    // 非整数实参：将名字添加到全局数据结构中
                    template <typename T>
                    void LogAndAddImpl(T&& name, std::false_type)
                    {
                        const auto now = std::chrono::system_clock::now();

                        Log(now, "logAndAdd");

                        names.emplace(std::forward<T>(name));
                    }

                    template <typename T>
                    void LogAndAdd(T&& name)
                    {
                        LogAndAddImpl(std::forward<T>(name),
                                      std::is_integral<typename std::remove_reference<T>::type>());
                    }
                }

                namespace Example1
                {
                    /*
                    class Person
                    {
                    public:
                        template <typename T,
                                  typename = typename std::enable_if<condition>::type>
                        explicit Person(T&& n);

                        // ...
                    };
                    */

                    class Person
                    {
                    public:
                        template <typename T,
                                  typename = typename std::enable_if<
                                      !std::is_same<Person,
                                                    typename std::decay<T>::type  // ...
                                                    >::value>  // ...
                                  ::type>  // ...
                        explicit Person(T&& n);

                        // ...
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

                namespace Example2
                {
                    class Person
                    {
                    public:
                        template <typename T,
                                  typename = typename std::enable_if<
                                      !std::is_base_of<Person,
                                                       typename std::decay<T>::type  // ...
                                                       >::value>  // ...
                                  ::type>  // ...
                        explicit Person(T&& n);

                        // ...
                    };
                }

                namespace Example3
                {
                    class Person  // C++14
                    {
                    public:
                        template <typename T,
                                  typename = std::enable_if_t<  // 这里代码量更少
                                      !std::is_base_of<Person,
                                                       typename std::decay_t<T>  // 还有这里
                                                       >::value  // ...
                                      >  // 还有这里
                                  >  // ...
                        explicit Person(T&& n);

                        // ...
                    };
                }

                namespace Example4
                {
                    std::string NameFromIdx(MAYBE_UNUSED int idx);

                    class Person
                    {
                    public:
                        template <typename T,
                                  typename = std::enable_if_t<
                                      !std::is_base_of<Person, typename std::decay_t<T>>::value  //...
                                      &&  // ...
                                      !std::is_integral<std::remove_reference_t<T>>::value  //...
                                      >  // ...
                                  >  // ...
                        explicit Person(T&& n)
                            : name(std::forward<T>(n))
                        {
                            // 接受std::string型别以及可以强制转型到std::string的实参型别的构造函数
                        }

                        // 接受整型实参的构造函数
                        explicit Person(int idx);

                        // 复制构造函数和移动构造函数
                        // ...

                    private:
                        std::string name;
                    };
                }

                namespace Example5
                {
                    std::string NameFromIdx(MAYBE_UNUSED int idx);

                    class Person
                    {
                    public:
                        template <typename T,  // 同前
                                  typename = std::enable_if_t<
                                      !std::is_base_of<Person, typename std::decay_t<T>>::value  //...
                                      &&  // ...
                                      !std::is_integral<std::remove_reference_t<T>>::value  //...
                                      >  // ...
                                  >  // ...
                        explicit Person(T&& n)
                            : name(std::forward<T>(n))
                        {
                            // 断言可以从T型别的对象构造一个std::string型别的对象
                            static_assert(std::is_constructible<std::string, T>::value,
                                          "Parameter n can't be used to construct a std::string");

                            // 构造函数通常要完成的工作放在这里
                        }

                        explicit Person(int idx);

                        // ...
                        // Person 类的其他部分（同前）

                    private:
                        std::string name;
                    };
                }
            }
        }
    }
}
#endif  // EFFECTIVE_MODERN_CPP_CHAPTER5_TERM27_H
