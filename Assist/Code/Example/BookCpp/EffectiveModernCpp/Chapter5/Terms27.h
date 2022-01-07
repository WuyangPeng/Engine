///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.6 (2021/11/16 20:44)

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
                        explicit Person(std::string n) noexcept;  // �滻��T&&�ͱ�Ĺ��캯��

                        explicit Person(int idx);

                    private:
                        std::string name;
                    };
                }

                extern std::multiset<std::string> names;  // ȫ�����ݽṹ

                template <typename T>
                void Log(MAYBE_UNUSED const T& time, MAYBE_UNUSED const std::string& message) noexcept
                {
                }

                namespace Example0
                {
                    template <typename T>
                    void LogAndAdd(T&& name)  // �Ʊ���־��Ŀ����������ӵ����ݽṹ��
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
                                      std::is_integral<T>());  // ������ȷ
                    }
                }

                namespace Example2
                {
                    std::string NameFromIdx(MAYBE_UNUSED int idx);

                    // ����ʵ�Σ��������ֲ���������LogAndAdd
                    void LogAndAddImpl(int idx, std::true_type);

                    // ������ʵ�Σ���������ӵ�ȫ�����ݽṹ��
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
                        // ���ƹ��캯�������õ��ǻ��������ת�����캯��
                        SpecialPerson(const SpecialPerson& rhs)
                            : Person(rhs)
                        {
                            // ...
                        }

                        // �ƶ����캯�������õ��ǻ��������ת�����캯��
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
                                  typename = std::enable_if_t<  // �������������
                                      !std::is_base_of<Person,
                                                       typename std::decay_t<T>  // ��������
                                                       >::value  // ...
                                      >  // ��������
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
                            // ����std::string�ͱ��Լ�����ǿ��ת�͵�std::string��ʵ���ͱ�Ĺ��캯��
                        }

                        // ��������ʵ�εĹ��캯��
                        explicit Person(int idx);

                        // ���ƹ��캯�����ƶ����캯��
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
                        template <typename T,  // ͬǰ
                                  typename = std::enable_if_t<
                                      !std::is_base_of<Person, typename std::decay_t<T>>::value  //...
                                      &&  // ...
                                      !std::is_integral<std::remove_reference_t<T>>::value  //...
                                      >  // ...
                                  >  // ...
                        explicit Person(T&& n)
                            : name(std::forward<T>(n))
                        {
                            // ���Կ��Դ�T�ͱ�Ķ�����һ��std::string�ͱ�Ķ���
                            static_assert(std::is_constructible<std::string, T>::value,
                                          "Parameter n can't be used to construct a std::string");

                            // ���캯��ͨ��Ҫ��ɵĹ�����������
                        }

                        explicit Person(int idx);

                        // ...
                        // Person ����������֣�ͬǰ��

                    private:
                        std::string name;
                    };
                }
            }
        }
    }
}
#endif  // EFFECTIVE_MODERN_CPP_CHAPTER5_TERM27_H
