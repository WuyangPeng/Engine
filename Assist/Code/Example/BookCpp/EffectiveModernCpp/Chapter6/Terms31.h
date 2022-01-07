///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.7 (2021/11/29 21:29)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER6_TERM31_H
#define EFFECTIVE_MODERN_CPP_CHAPTER6_TERM31_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <algorithm>
#include <functional>
#include <vector>

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter6
        {
            namespace Terms31
            {
                void AddDivisorFilter();

                int ComputeSomeValue1() noexcept;
                int ComputeSomeValue2() noexcept;

                constexpr int ComputeDivisor(int calc1, int calc2) noexcept
                {
                    return calc1 + calc2;
                }

                namespace Example0
                {
                    template <typename C>
                    void WorkWithContainer(const C& container)
                    {
                        const auto calc1 = ComputeSomeValue1();  // 同上
                        const auto calc2 = ComputeSomeValue2();  // 同上

                        auto divisor = ComputeDivisor(calc1, calc2);  // 同上

                        using ContElemT = typename C::value_type;  // 为实现泛型算法，取得容器中的元素型别。

                        using std::begin;
                        using std::end;

                        // 如果所有容器中的元素值都是divisor的倍数
                        if (std::all_of(begin(container), end(container),
                                        [&](const ContElemT& value) {
                                            return value % divisor;
                                        }))
                        {
                            // 若全是，执行这里
                            // ...
                        }
                        else
                        {
                            // 若至少有一个不是，执行这里
                            // ...
                        }
                    }
                }

                namespace Example1
                {
                    template <typename C>
                    void WorkWithContainer(const C& container)
                    {
                        const auto calc1 = ComputeSomeValue1();  // 同上
                        const auto calc2 = ComputeSomeValue2();  // 同上

                        auto divisor = ComputeDivisor(calc1, calc2);  // 同上

                        using std::begin;
                        using std::end;

                        // 如果所有容器中的元素值都是divisor的倍数
                        if (std::all_of(begin(container), end(container),
                                        [&](const auto& value) {  // C++14
                                            return value % divisor;
                                        }))
                        {
                            // 若全是，执行这里
                            // ...
                        }
                        else
                        {
                            // 若至少有一个不是，执行这里
                            // ...
                        }
                    }
                }

                namespace Example0
                {
                    using FilterContainer = std::vector<std::function<bool(int)>>;

                    extern FilterContainer filters;

                    class Widget
                    {
                    public:
                        // ...
                        // 构造函数等
                        void AddFilter() const;  // 向filters添加一个条目

                    private:
                        int divisor;  // 用于Widget的filter元素
                    };
                }

                namespace Example1
                {
                    using FilterContainer = std::vector<std::function<bool(int)>>;

                    extern FilterContainer filters;

                    class Widget
                    {
                    public:
                        // ...
                        // 构造函数等
                        void AddFilter() const;  // 向filters添加一个条目

                    private:
                        int divisor;  // 用于Widget的filter元素
                    };

                    void DoSomeWork();
                }

                namespace Example2
                {
                    using FilterContainer = std::vector<std::function<bool(int)>>;

                    extern FilterContainer filters;

                    class Widget
                    {
                    public:
                        // ...
                        // 构造函数等
                        void AddFilter() const;  // 向filters添加一个条目

                    private:
                        int divisor;  // 用于Widget的filter元素
                    };
                }

                namespace Example3
                {
                    using FilterContainer = std::vector<std::function<bool(int)>>;

                    extern FilterContainer filters;

                    class Widget
                    {
                    public:
                        // ...
                        // 构造函数等
                        void AddFilter() const;  // 向filters添加一个条目

                    private:
                        int divisor;  // 用于Widget的filter元素
                    };
                }

                namespace Example4
                {
                    using FilterContainer = std::vector<std::function<bool(int)>>;

                    extern FilterContainer filters;

                    class Widget
                    {
                    public:
                        // ...
                        // 构造函数等
                        void AddFilter() const;  // 向filters添加一个条目

                    private:
                        int divisor;  // 用于Widget的filter元素
                    };
                }

                namespace Example1
                {
                    void AddDivisorFilter();
                }
            }
        }
    }
}
#endif  // EFFECTIVE_MODERN_CPP_CHAPTER6_TERM31_H
