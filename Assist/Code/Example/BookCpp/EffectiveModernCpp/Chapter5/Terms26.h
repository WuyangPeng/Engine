///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.6 (2021/11/15 20:28)

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
                extern std::multiset<std::string> names;  // ȫ�����ݽṹ

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

                    std::string NameFromIdx(MAYBE_UNUSED int idx);  // ����������Ӧ������

                    void LogAndAdd(int idx);  // �µ����غ���
                }

                namespace Example0
                {
                    std::string NameFromIdx(MAYBE_UNUSED int idx);  // ����������Ӧ������

                    class Person
                    {
                    public:
                        template <typename T>
                        explicit Person(T&& n)
                            : name(std::forward<T>(n))  // ����ת�����캯������ʼ�������ݳ�Ա
                        {
                        }

                        /* explicit Person(Person& n)
                            : name(std::forward<Person&>(n))  // ������ת��ģ�����ʵ����
                        {
                        }*/

                        explicit Person(int idx);  // �β�Ϊint�Ĺ��캯��

                        // Person(const Person& n);  // ���ƹ��캯�����ɱ��������ɣ�
                        // Person(Person&& n);  // �ƶ����캯�����ɱ��������ɣ�

                    private:
                        std::string name;
                    };
                }

                namespace Example1
                {
                    std::string NameFromIdx(MAYBE_UNUSED int idx);  // ����������Ӧ������

                    class Person
                    {
                    public:
                        template <typename T>
                        explicit Person(T&& n)
                            : name(std::forward<T>(n))
                        {
                        }

                        /* explicit Person(const Person& n)
                            : name(std::forward<Person>(n))  // ��ģ�����ʵ�������õ��Ĺ��캯��
                        {
                        }*/

                        // Person(const Person& n);  // ���ƹ��캯�����ɱ��������ɣ�

                    private:
                        std::string name;
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
            }
        }
    }
}
#endif  // EFFECTIVE_MODERN_CPP_CHAPTER5_TERM26_H
