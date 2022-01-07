///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.6 (2021/11/14 20:42)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER5_TERM25_H
#define EFFECTIVE_MODERN_CPP_CHAPTER5_TERM25_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <chrono>
#include <memory>
#include <string>

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter5
        {
            namespace Terms25
            {
                namespace Example0
                {
                    class Widget
                    {
                        // rhs确定无疑地会绑定到可以合于移动目的的对象
                        Widget(Widget&& rhs);
                    };
                }

                class SomeDataStructure
                {
                };

                namespace Example1
                {
                    class Widget
                    {
                    public:
                        // rhs是个右值引用
                        Widget(Widget&& rhs) noexcept;

                        ~Widget() noexcept = default;
                        Widget(const Widget& rhs) = default;
                        Widget& operator=(const Widget& rhs) = default;
                        Widget& operator=(Widget&& rhs) noexcept = default;

                    private:
                        std::string name;
                        std::shared_ptr<SomeDataStructure> p;
                    };
                }

                namespace Example2
                {
                    class Widget
                    {
                    public:
                        template <typename T>
                        void SetName(T&& newName)
                        {
                            name = std::forward<T>(newName);  // newName是个万能引用
                        }

                    private:
                        std::string name;
                    };
                }

                namespace Example3
                {
                    class Widget
                    {
                    public:
                        template <typename T>
                        void SetName(T&& newName) noexcept
                        {
                            name = std::move(newName);  // 万能引用，可以编译，但是糟糕透顶！
                        }

                    private:
                        std::string name;
                        std::shared_ptr<SomeDataStructure> p;
                    };

                    std::string GetWidgetName();  // 工厂函数
                }

                namespace Example4
                {
                    class Widget
                    {
                    public:
                        void SetName(const std::string& newName);
                        void SetName(std::string&& newName) noexcept;

                    private:
                        std::string name;
                    };
                }

                template <class T, class... Args>
                std::shared_ptr<T> MakeShared(Args&&... args);  // 选自C++11标准

                template <class T, class... Args>
                std::unique_ptr<T> MakeUnique(Args&&... args);  // 选自C++14标准

                namespace Example5
                {
                    class Sign
                    {
                    public:
                        void SetText(MAYBE_UNUSED const std::string& text) noexcept;

                        void Add(MAYBE_UNUSED const std::chrono::time_point<std::chrono::system_clock>& now, MAYBE_UNUSED const std::string& text) noexcept;
                    };

                    class Widget
                    {
                    public:
                        template <typename T>
                        void SetSignText(T& text)  // text是个万能引用
                        {
                            sign.SetText(text);  // 使用text，但不改动其值

                            auto now = std::chrono::system_clock::now();  // 取得当前时间

                            signHistory.Add(now, std::forward<T>(text));  // 有条件地将text强制转换成右值型别
                        }

                    private:
                        Sign sign;
                        Sign signHistory;
                    };
                }

                namespace Example0
                {
                    class Matrix
                    {
                    public:
                        Matrix& operator+=(MAYBE_UNUSED const Matrix& rhs) noexcept;
                    };

                    Matrix operator+(Matrix&& lhs, const Matrix& rhs) noexcept;  // 按值返回
                }

                namespace Example1
                {
                    class Matrix
                    {
                    public:
                        Matrix& operator+=(MAYBE_UNUSED const Matrix& rhs) noexcept;
                    };

                    Matrix operator+(Matrix&& lhs, const Matrix& rhs) noexcept;  // 同上
                }

                class Fraction
                {
                };

                template <typename T>
                Fraction ReduceAndCopy(T&& frac)  // 按值返回，万能引用形参
                {
                    frac.Reduce();

                    // 对于右值，是移入返回值
                    // 对于左值，是复制入返回值
                    return std::forward<T>(frac);
                }

                namespace Example6
                {
                    class Widget
                    {
                    };

                    Widget MakeWidget() noexcept;  // MakeWidget的“复制”版本
                }

                namespace Example7
                {
                    class Widget
                    {
                    };

                    Widget MakeWidget() noexcept;  // MakeWidget的移动版本
                }

                namespace Example8
                {
                    class Widget
                    {
                    };

                    Widget MakeWidget(Widget w) noexcept;  // 按值传递的形参，与函数返回值型别相同
                }
            }
        }
    }
}
#endif  // EFFECTIVE_MODERN_CPP_CHAPTER5_TERM24_H
