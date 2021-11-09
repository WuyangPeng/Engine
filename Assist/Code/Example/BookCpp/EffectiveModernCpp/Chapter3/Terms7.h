///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.4 (2021/09/30 20:37)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER3_TERM7_H
#define EFFECTIVE_MODERN_CPP_CHAPTER3_TERM7_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <iostream>
#include <string>

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter3
        {
            namespace Terms7
            {
                class Widget
                {
                    //...

                private:
                    int x{ 0 };  // 可行，x的默认值为0
                    int y = 0;  // 也可行
                    // int z(0);  // 不可行！
                };

                namespace Example0
                {
                    class Widget
                    {
                    public:
                        Widget() noexcept = default;
                        Widget(MAYBE_UNUSED int x) noexcept;
                    };
                }

                namespace Example1
                {
                    class Widget
                    {
                    public:
                        Widget(MAYBE_UNUSED int i, MAYBE_UNUSED bool b) noexcept;  // 构造函数的形参中没有任何一个具备std::initialize_list型别
                        Widget(MAYBE_UNUSED int i, MAYBE_UNUSED double d) noexcept;
                    };
                }

                namespace Example2
                {
                    class Widget
                    {
                    public:
                        Widget(MAYBE_UNUSED int i, MAYBE_UNUSED bool b);  // 同前
                        Widget(MAYBE_UNUSED int i, MAYBE_UNUSED double d);  // 同前
                        Widget(MAYBE_UNUSED std::initializer_list<long double> i1);  // 增加的版本
                    };
                }

                namespace Example3
                {
                    class Widget
                    {
                    public:
                        Widget(MAYBE_UNUSED int i, MAYBE_UNUSED bool b);  // 同前
                        Widget(MAYBE_UNUSED int i, MAYBE_UNUSED double d);  // 同前
                        Widget(MAYBE_UNUSED std::initializer_list<long double> i1);  // 同前

                        operator float() const noexcept;  // 强制转换成float型别
                    };
                }

                namespace Example4
                {
                    class Widget
                    {
                    public:
                        Widget(MAYBE_UNUSED int i, MAYBE_UNUSED bool b) noexcept;  // 同前
                        Widget(MAYBE_UNUSED int i, MAYBE_UNUSED double d) noexcept;  // 同前
                        Widget(MAYBE_UNUSED std::initializer_list<bool> i1) noexcept;  // 容器元素型别现在是bool了

                        // ...
                        // 并没有隐式强制型别转换函数
                    };
                }

                namespace Example5
                {
                    class Widget
                    {
                    public:
                        Widget(MAYBE_UNUSED int i, MAYBE_UNUSED bool b) noexcept;  // 同前
                        Widget(MAYBE_UNUSED int i, MAYBE_UNUSED double d) noexcept;  // 同前
                        // std::initializer_list模板的元素型别现在是std::string了
                        Widget(MAYBE_UNUSED std::initializer_list<std::string> i1) noexcept;

                        // ...
                        // 并没有隐式强制型别转换函数
                    };
                }

                namespace Example6
                {
                    class Widget
                    {
                    public:
                        Widget() noexcept = default;  // 默认构造函数
                        Widget(std::initializer_list<int> i1);  // 带有std::initializer_list型别形参的构造函数

                        // ...
                        // 并没有隐式强制型别转换函数
                    };
                }

                template <typename T,  // 创建对象的型别
                          typename... Ts>  // 一系列对象的型别
                void DoSomeWork(Ts&&... params)
                {
                    // 复用params创建局部对象T
                    // ...

                    T localObject0(std::forward<Ts>(params)...);  // 利用小括号
                    T localObject1{ std::forward<Ts>(params)... };  // 利用大括号

                    std::cout << "localObject0大小为：" << localObject0.size() << '\n';
                    std::cout << "localObject1大小为：" << localObject1.size() << '\n';
                }
            }
        }
    }
}

#endif  // EFFECTIVE_MODERN_CPP_CHAPTER3_TERM7_H
