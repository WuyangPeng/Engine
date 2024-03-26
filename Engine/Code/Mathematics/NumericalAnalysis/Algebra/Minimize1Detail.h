/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/18 13:12)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ALGEBRA_MINIMIZE1_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ALGEBRA_MINIMIZE1_DETAIL_H

#include "Minimize1.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename T>
Mathematics::Algebra::Minimize1<T>::Minimize1(const std::function<T(T)>& f, int maxSubdivisions, int maxBisections, T epsilon, T tolerance)
    : function{ f },
      maxSubdivisions{ maxSubdivisions },
      maxBisections{ maxBisections },
      tMin{},
      fMin{},
      epsilon{ std::max(epsilon, T{}) },
      tolerance{ std::max(tolerance, T{}) }
{
    ASSERT_FAIL_THROW_EXCEPTION(maxSubdivisions > 0 && maxBisections > 0, SYSTEM_TEXT("无效参数"))

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename T>
bool Mathematics::Algebra::Minimize1<T>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename T>
void Mathematics::Algebra::Minimize1<T>::SetEpsilon(T aEpsilon) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    epsilon = std::max(aEpsilon, T{});
}

template <typename T>
void Mathematics::Algebra::Minimize1<T>::SetTolerance(T aTolerance) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    tolerance = std::max(aTolerance, T{});
}

template <typename T>
T Mathematics::Algebra::Minimize1<T>::GetEpsilon() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return epsilon;
}

template <typename T>
T Mathematics::Algebra::Minimize1<T>::GetTolerance() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return tolerance;
}

template <typename T>
void Mathematics::Algebra::Minimize1<T>::GetMinimum(T t0, T t1, T& aTMin, T& aFMin)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    GetMinimum(t0, t1, Math::GetRational(1, 2) * (t0 + t1), aTMin, aFMin);
}

template <typename T>
void Mathematics::Algebra::Minimize1<T>::GetMinimum(T t0, T t1, T tInitial, T& aTMin, T& aFMin)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    ASSERT_FAIL_THROW_EXCEPTION(t0 <= tInitial && tInitial <= t1, SYSTEM_TEXT("初始t值无效"))

    /// 计算3个初始点的最小值。
    tMin = std::numeric_limits<T>::max();
    fMin = std::numeric_limits<T>::max();

    const auto f0 = function(t0);
    if (f0 < fMin)
    {
        tMin = t0;
        fMin = f0;
    }

    const auto fInitial = function(tInitial);
    if (fInitial < fMin)
    {
        tMin = tInitial;
        fMin = fInitial;
    }

    const auto f1 = function(t1);
    if (f1 < fMin)
    {
        tMin = t1;
        fMin = f1;
    }

    /// 在[t0,t1]上搜索全局最小值，并选择tInitial，希望从最小括号开始。
    if (((fInitial < f0) && (f1 >= fInitial)) ||
        ((f1 > fInitial) && (f0 >= fInitial)))
    {
        /// 折线{(f0,f0), (tInitial,fInitial), (t1,f1)}是V形的。
        GetBracketedMinimum(t0, f0, tInitial, fInitial, t1, f1);
    }
    else
    {
        /// 折线{(f0,f0), (tInitial,fInitial), (t1,f1)}不是V形的，
        /// 因此继续在子区间[t0,tInitial]和[tInitial,t1]中搜索。
        Subdivide(t0, f0, tInitial, fInitial, maxSubdivisions);
        Subdivide(tInitial, fInitial, t1, f1, maxSubdivisions);
    }

    aTMin = tMin;
    aFMin = fMin;
}

template <typename T>
void Mathematics::Algebra::Minimize1<T>::Subdivide(T t0, T f0, T t1, T f1, int subdivisionsRemaining)
{
    if (subdivisionsRemaining-- == 0)
    {
        /// 已达到细分的最大数量。
        return;
    }

    /// 计算[t0,t1]中点处的函数。
    const auto tm = Math::GetRational(1, 2) * (t0 + t1);
    const auto fm = function(tm);
    if (fm < fMin)
    {
        tMin = tm;
        fMin = fm;
    }

    if (((fm < f0) && (f1 >= fm)) || ((f1 > fm) && (f0 >= fm)))
    {
        /// 折线{(f0,f0), (tm,fm), (t1,f1)}是V形的。
        GetBracketedMinimum(t0, f0, tm, fm, t1, f1);
    }
    else
    {
        /// 折线 {(f0,f0), (tm,fm), (t1,f1)}不是V形的，
        /// 所以继续在子区间[t0,tm]和[tm,t1]中搜索。
        Subdivide(t0, f0, tm, fm, subdivisionsRemaining);
        Subdivide(tm, fm, t1, f1, subdivisionsRemaining);
    }
}

template <typename T>
void Mathematics::Algebra::Minimize1<T>::GetBracketedMinimum(T t0, T f0, T tm, T fm, T t1, T f1)
{
    for (auto i = 0; i < maxBisections; ++i)
    {
        /// 更新最小位置和值。
        if (fm < fMin)
        {
            tMin = tm;
            fMin = fm;
        }

        /// 收敛性测试
        const auto dt10 = t1 - t0;
        const auto dtBound = Math::GetValue(2) * tolerance * std::fabs(tm) + epsilon;
        if (dt10 <= dtBound)
        {
            break;
        }

        /// 计算插值抛物线的顶点。
        const auto dt0M = t0 - tm;
        const auto dt1M = t1 - tm;
        const auto df0M = f0 - fm;
        const auto df1M = f1 - fm;
        const auto tmp0 = dt0M * df1M;
        const auto tmp1 = dt1M * df0M;
        const auto denominator = tmp1 - tmp0;
        if (std::fabs(denominator) <= epsilon)
        {
            return;
        }

        /// 计算tv并箝位到 [t0,t1]以偏移浮点舍入误差。
        auto tv = tm + Math::GetRational(1, 2) * (dt1M * tmp1 - dt0M * tmp0) / denominator;
        tv = std::max(t0, std::min(tv, t1));
        const auto fv = function(tv);
        if (fv < fMin)
        {
            tMin = tv;
            fMin = fv;
        }

        if (tv < tm)
        {
            if (fv < fm)
            {
                t1 = tm;
                f1 = fm;
                tm = tv;
                fm = fv;
            }
            else
            {
                t0 = tv;
                f0 = fv;
            }
        }
        else if (tv > tm)
        {
            if (fv < fm)
            {
                t0 = tm;
                f0 = fm;
                tm = tv;
                fm = fv;
            }
            else
            {
                t1 = tv;
                f1 = fv;
            }
        }
        else
        {
            /// 抛物线的顶点位于中间采样点。最小值可以出现在任一子区间上，但也可能出现在顶点上。
            /// 在任何一种情况下，都会通过检查顶点的邻域来继续搜索。
            /// 当一个括号有两个选项时，将使用中点处函数值最小的选项。
            const auto tm0 = Math::GetRational(1, 2) * (t0 + tm);
            const auto fm0 = function(tm0);
            const auto tm1 = Math::GetRational(1, 2) * (tm + t1);
            const auto fm1 = function(tm1);

            if (fm0 < fm)
            {
                if (fm1 < fm)
                {
                    if (fm0 < fm1)
                    {
                        // {(t0,f0),(tm0,fm0),(tm,fm)}
                        t1 = tm;
                        f1 = fm;
                        tm = tm0;
                        fm = fm0;
                    }
                    else
                    {
                        // {(tm,fm),(tm1,fm1),(t1,f1)}
                        t0 = tm;
                        f0 = fm;
                        tm = tm1;
                        fm = fm1;
                    }
                }
                else  // fm1 >= fm
                {
                    // {(t0,f0),(tm0,fm0),(tm,fm)}
                    t1 = tm;
                    f1 = fm;
                    tm = tm0;
                    fm = fm0;
                }
            }
            else if (fm0 > fm)
            {
                if (fm1 < fm)
                {
                    // {(tm,fm),(tm1,fm1),(t1,f1)}
                    t0 = tm;
                    f0 = fm;
                    tm = tm1;
                    fm = fm1;
                }
                else  // fm1 >= fm
                {
                    // {(tm0,fm0),(tm,fm),(tm1,fm1)}
                    t0 = tm0;
                    f0 = fm0;
                    t1 = tm1;
                    f1 = fm1;
                }
            }
            else  // fm0 = fm
            {
                if (fm1 < fm)
                {
                    // {(tm,fm),(tm1,fm1),(t1,f1)}
                    t0 = tm;
                    f0 = fm;
                    tm = tm1;
                    fm = fm1;
                }
                else  // fm1 >= fm
                {
                    // {(tm0,fm0),(tm,fm),(tm1,fm1)}
                    t0 = tm0;
                    f0 = fm0;
                    t1 = tm1;
                    f1 = fm1;
                }
            }
        }
    }
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_ALGEBRA_MINIMIZE1_DETAIL_H
