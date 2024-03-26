/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/18 13:12)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ALGEBRA_MINIMIZE1_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ALGEBRA_MINIMIZE1_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Base/Math.h"

#include <functional>

/// 使用连续抛物线插值在[t0,t1]上搜索F(t)的最小值。
/// 搜索是基于在区间的端点和中点处与(t,F(t))相关联的多段线递归的。
/// 设f0 = F(t0), f1 = F(t1)，tm在(t0,t1)中，fm = F(tm)）。
/// 多段线是{(t0,f0),(tm,fm),(t1,f1)}。
///
/// 如果多段线是V形的，则区间[t0,t1]包含一个最小点。
/// 多段线与顶点tv在(t0,t1)中的抛物线拟合。
/// 设fv = tv。如果{(t0,f0),(tv,fv),(tm,fm)}}是最小括号，则在[t0,tm]中继续进行抛物线插值。
/// 如果{(tm,fm),(tv,fv),(t1,f1)}}是最小括号，则在[tm,t1]中继续进行抛物线插值。
///
/// 如果多段线不是V形的，则搜索子区间[t0,tm]和[tm,t1]以寻找最小值。
namespace Mathematics::Algebra
{
    template <typename T>
    class Minimize1
    {
    public:
        using ClassType = Minimize1<T>;

        using Math = Math<T>;

    public:
        Minimize1(const std::function<T(T)>& f,
                  int maxSubdivisions,
                  int maxBisections,
                  T epsilon = Math::GetValue(1e-08),
                  T tolerance = Math::GetValue(1e-04));

        CLASS_INVARIANT_DECLARE;

        /// 成员访问
        void SetEpsilon(T aEpsilon) noexcept;
        void SetTolerance(T aTolerance) noexcept;

        NODISCARD T GetEpsilon() const noexcept;
        NODISCARD T GetTolerance() const noexcept;

        /// 使用(t0+t1)/2的初始猜测在区间[t0,t1]上搜索F(t)的最小值。
        /// 最小值的位置是tMin，最小值的值是fMin = F(tMin)。
        void GetMinimum(T t0, T t1, T& aTMin, T& aFMin);

        /// 使用tInitial的初始猜测在区间[t0,t1]上搜索F(t)的最小值。
        /// 最小值的位置是tMin，最小值的值是fMin = F(tMin)。
        void GetMinimum(T t0, T t1, T tInitial, T& aTMin, T& aFMin);

    private:
        /// 递归地搜索[t0,t1]以获得全局最小值。
        void Subdivide(T t0, T f0, T t1, T f1, int subdivisionsRemaining);

        /// 当{f0,f1,f2}括号中包含一个最小值时，调用此函数。
        void GetBracketedMinimum(T t0, T f0, T tm, T fm, T t1, T f1);

    private:
        std::function<T(T)> function;
        int maxSubdivisions;
        int maxBisections;
        T tMin;
        T fMin;
        T epsilon;
        T tolerance;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_ALGEBRA_MINIMIZE1_H
