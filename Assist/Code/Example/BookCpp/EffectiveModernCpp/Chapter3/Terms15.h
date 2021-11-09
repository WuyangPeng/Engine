///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.4 (2021/10/05 14:25)

#ifndef EFFECTIVE_MODERN_CPP_CHAPTER3_TERM15_H
#define EFFECTIVE_MODERN_CPP_CHAPTER3_TERM15_H

#include "Example/BookCpp/EffectiveModernCpp/EffectiveModernCppDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <string>

namespace BookExperience
{
    namespace EffectiveModernCpp
    {
        namespace Chapter3
        {
            namespace Terms15
            {
                namespace Example0
                {
                    // pow是个constexpr函数，且不会抛出异常
                    constexpr int Pow(int base, int exp) noexcept
                    {
                        // ...
                        return (exp == 0 ? 1 : base * Pow(base, exp - 1));
                    }

                    int ReadFromDB(MAYBE_UNUSED const std::string& name) noexcept;
                }

                namespace Example1
                {
                    constexpr int Pow(int base, int exp) noexcept  // C++14
                    {
                        auto result = 1;
                        for (int i = 0; i < exp; ++i)
                        {
                            result *= base;
                        }

                        return result;
                    }
                }

                namespace Example0
                {
                    class Point
                    {
                    public:
                        constexpr Point(double xVal = 0, double yVal = 0) noexcept
                            : x(xVal), y(yVal)
                        {
                        }

                        constexpr double XValue() const noexcept
                        {
                            return x;
                        }

                        constexpr double YValue() const noexcept
                        {
                            return y;
                        }

                        void SetX(double newX) noexcept;
                        void SetY(double newY) noexcept;

                    private:
                        double x, y;
                    };

                    constexpr Point Midpoint(const Point& p1, const Point& p2) noexcept
                    {
                        // 调用constexpr成员函数
                        return { (p1.XValue() + p2.XValue()) / 2,
                                 (p1.YValue() + p2.YValue()) / 2 };
                    }
                }

                namespace Example1
                {
                    class Point
                    {
                    public:
                        constexpr Point(double xVal = 0, double yVal = 0) noexcept
                            : x(xVal), y(yVal)
                        {
                        }

                        constexpr double XValue() const noexcept
                        {
                            return x;
                        }

                        constexpr double YValue() const noexcept
                        {
                            return y;
                        }

                        // C++14
                        constexpr void SetX(double newX) noexcept
                        {
                            x = newX;
                        }

                        // C++14
                        constexpr void SetY(double newY) noexcept
                        {
                            y = newY;
                        }

                    private:
                        double x, y;
                    };

                    constexpr Point Midpoint(const Point& p1, const Point& p2) noexcept
                    {
                        // 调用constexpr成员函数
                        return { (p1.XValue() + p2.XValue()) / 2,
                                 (p1.YValue() + p2.YValue()) / 2 };
                    }

                    // 返回p相对于原点的中心对称点（C++14）
                    constexpr Point Reflection(const Point& p) noexcept
                    {
                        Point result;  // 创建一个非const的Point对象

                        result.SetX(-p.XValue());  // 设置其x和y成员的值
                        result.SetY(-p.YValue());

                        return result;  // 返回result的副本
                    }
                }
            }
        }
    }
}

#endif  // EFFECTIVE_MODERN_CPP_CHAPTER3_TERM15_H
