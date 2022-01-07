///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.2.5 (2021/11/03 22:38)

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
                    // 位于名字空间std内
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
                    // C++14实现，仍位于名字空间std内
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
                        // 待复制的形参，
                        explicit Annotation(MAYBE_UNUSED std::string text) noexcept;

                        // ...
                    };
                }

                namespace Example1
                {
                    class Annotation
                    {
                    public:
                        // 待复制的形参，
                        explicit Annotation(const std::string text);

                        // ...

                    private:
                        std::string value;
                    };
                }

                // std::string实际上是个typedef，代表std::basic_string<char>
                class String
                {
                public:
                    // ...
                    String(const String& rhs);  // 复制构造函数
                    String(String&& rhs);  // 移动构造函数
                };

                namespace Example0
                {
                    class Widget
                    {
                    };

                    void Process(MAYBE_UNUSED const Widget& lvalArg) noexcept;  // 处理左值
                    void Process(MAYBE_UNUSED Widget&& rvalArg) noexcept;  // 处理右值

                    template <typename T>
                    void MakeLogEntry(MAYBE_UNUSED const std::string& message, MAYBE_UNUSED const T& time) noexcept
                    {
                    }

                    // 把param传递给process的函数模板
                    template <typename T>
                    void LogAndProcess(T&& param)
                    {
                        // 取得当前时间
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
                            : s(std::forward<std::string>(rhs.s))  // 离经叛道结果错误的实现
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
