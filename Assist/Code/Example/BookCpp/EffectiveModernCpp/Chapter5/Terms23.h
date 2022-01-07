///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.2.5 (2021/11/03 22:38)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER5_TERM23_H
#define EFFECTIVE_MODERN_CPP_CHAPTER5_TERM23_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <chrono>
#include <string>

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter5
        {
            namespace Terms23
            {
                namespace Example0
                {
                    // λ�����ֿռ�std��
                    template <typename T>
                    typename std::remove_reference<T>::type&&
                        Move(T&& param)
                    {
                        using ReturnType = typename std::remove_reference<T>::type&&;

                        return static_cast<ReturnType>(param);
                    }
                }

                namespace Example1
                {
                    // C++14ʵ�֣���λ�����ֿռ�std��
                    template <typename T>
                    decltype(auto) Move(T&& param)
                    {
                        using ReturnType = typename std::remove_reference_t<T>&&;

                        return static_cast<ReturnType>(param);
                    }
                }

                namespace Example0
                {
                    class Annotation
                    {
                    public:
                        // �����Ƶ��βΣ�
                        explicit Annotation(MAYBE_UNUSED std::string text) noexcept;

                        // ...
                    };
                }

                namespace Example1
                {
                    class Annotation
                    {
                    public:
                        // �����Ƶ��βΣ�
                        explicit Annotation(const std::string text);

                        // ...

                    private:
                        std::string value;
                    };
                }

                // std::stringʵ�����Ǹ�typedef������std::basic_string<char>
                class String
                {
                public:
                    // ...
                    String(const String& rhs);  // ���ƹ��캯��
                    String(String&& rhs);  // �ƶ����캯��
                };

                namespace Example0
                {
                    class Widget
                    {
                    };

                    void Process(MAYBE_UNUSED const Widget& lvalArg) noexcept;  // ������ֵ
                    void Process(MAYBE_UNUSED Widget&& rvalArg) noexcept;  // ������ֵ

                    template <typename T>
                    void MakeLogEntry(MAYBE_UNUSED const std::string& message, MAYBE_UNUSED const T& time) noexcept
                    {
                    }

                    // ��param���ݸ�process�ĺ���ģ��
                    template <typename T>
                    void LogAndProcess(T&& param)
                    {
                        // ȡ�õ�ǰʱ��
                        const auto now = std::chrono::system_clock::now();

                        MakeLogEntry("Calling 'process'", now);

                        Process(std::forward<T>(param));
                    }
                }

                namespace Example1
                {
                    class Widget
                    {
                    public:
                        Widget(Widget&& rhs) noexcept
                            : s(std::move(rhs.s))
                        {
                            ++moveCtorCalls;
                        }

                        // ...

                        ~Widget() noexcept = default;
                        Widget(const Widget& rhs) = default;
                        Widget& operator=(const Widget& rhs) = default;
                        Widget& operator=(Widget&& rhs) noexcept = default;

                    private:
                        static std::size_t moveCtorCalls;
                        std::string s;
                    };
                }

                namespace Example2
                {
                    class Widget
                    {
                    public:
                        Widget(Widget&& rhs) noexcept
                            : s(std::forward<std::string>(rhs.s))  // �뾭�ѵ���������ʵ��
                        {
                            ++moveCtorCalls;
                        }

                        // ...

                        ~Widget() noexcept = default;
                        Widget(const Widget& rhs) = default;
                        Widget& operator=(const Widget& rhs) = default;
                        Widget& operator=(Widget&& rhs) noexcept = default;

                    private:
                        static std::size_t moveCtorCalls;
                        std::string s;
                    };
                }
            }
        }
    }
}
#endif  // EFFECTIVE_MODERN_CPP_CHAPTER5_TERM23_H
