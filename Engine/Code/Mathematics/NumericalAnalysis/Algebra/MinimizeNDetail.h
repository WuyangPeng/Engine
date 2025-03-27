/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/18 16:06)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ALGEBRA_MINIMIZE_N_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ALGEBRA_MINIMIZE_N_DETAIL_H

#include "MinimizeN.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename T>
Mathematics::Algebra::MinimizeN<T>::MinimizeN(int dimensions, FunctionType f, int maxLevel, int maxBracket, int maxIterations, T epsilon)
    : dimensions{ dimensions },
      function{ std::move(f) },
      maxIterations{ maxIterations },
      epsilon{ 0 },
      directions{ boost::numeric_cast<size_t>(dimensions) + 1 },
      dConjIndex{ dimensions },
      dCurrIndex{ 0 },
      tCurr{ dimensions },
      tSave{ dimensions },
      minimizer{ [this](T t) {
                    return function((tCurr + t * directions.at(dCurrIndex)).GetContainer());
                },
                 maxLevel, maxBracket }
{
    SetEpsilon(epsilon);
    for (auto& direction : directions)
    {
        direction.SetSize(dimensions);
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename T>
bool Mathematics::Algebra::MinimizeN<T>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename T>
void Mathematics::Algebra::MinimizeN<T>::SetEpsilon(T aEpsilon) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    epsilon = (aEpsilon > T{} ? aEpsilon : T{});
}

template <typename T>
T Mathematics::Algebra::MinimizeN<T>::GetEpsilon() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return epsilon;
}

template <typename T>
void Mathematics::Algebra::MinimizeN<T>::GetMinimum(const Container& t0, const Container& t1, const Container& tInitial, Container& aTMin, T& aFMin)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    /// 最初的猜测。
    fCurr = function(tInitial);
    tSave.SetContainer(tInitial);
    tCurr.SetContainer(tInitial);

    /// 将方向集初始化为标准欧几里得基。
    for (auto i = 0; i < dimensions; ++i)
    {
        directions.at(i).MakeUnit(i);
    }

    T ell0{};
    T ell1{};
    T ellMin{};
    for (auto iter = 0; iter < maxIterations; ++iter)
    {
        /// 找到每个方向的最小值并更新当前位置。
        for (auto i = 0; i < dimensions; ++i)
        {
            dCurrIndex = i;
            ComputeDomain(t0, t1, ell0, ell1);
            minimizer.GetMinimum(ell0, ell1, T{}, ellMin, fCurr);
            tCurr += ellMin * directions.at(i);
        }

        /// 估计单位长度的共轭方向。
        directions.at(dConjIndex) = tCurr - tSave;
        auto length = directions.at(dConjIndex).Length();
        if (length <= epsilon)
        {
            /// 新位置与旧位置相比并没有显著变化。
            /// 这里应该有一个更好的收敛标准吗？
            break;
        }

        directions.at(dConjIndex) /= length;

        /// 沿共轭方向最小化。
        dCurrIndex = dConjIndex;
        ComputeDomain(t0, t1, ell0, ell1);
        minimizer.GetMinimum(ell0, ell1, T{}, ellMin, fCurr);
        tCurr += ellMin * directions.at(dCurrIndex);

        /// 循环方向并添加要设置的共轭方向。
        dConjIndex = 0;
        for (auto i = 0, ip1 = 1; i < dimensions; ++i, ++ip1)
        {
            directions.at(i) = directions.at(ip1);
        }

        /// 设置下一个过程的参数。
        tSave = tCurr;
    }
    aTMin = tCurr.GetContainer();

    aFMin = fCurr;
}

template <typename T>
void Mathematics::Algebra::MinimizeN<T>::ComputeDomain(const Container& t0, const Container& t1, T& ell0, T& ell1)
{
    ell0 = -std::numeric_limits<T>::max();
    ell1 = +std::numeric_limits<T>::max();

    for (auto i = 0; i < dimensions; ++i)
    {
        auto value = directions.at(dCurrIndex)[i];
        if (!MathType::Approximate(value, T{}))
        {
            auto b0 = t0.at(i) - tCurr[i];
            auto b1 = t1.at(i) - tCurr[i];
            auto inv = MathType::GetValue(1) / value;
            if (value > T{})
            {
                /// 有效的t-区间是[b0,b1]。
                b0 *= inv;
                if (b0 > ell0)
                {
                    ell0 = b0;
                }
                b1 *= inv;
                if (b1 < ell1)
                {
                    ell1 = b1;
                }
            }
            else
            {
                /// 有效的t-区间是[b1,b0]。
                b0 *= inv;
                if (b0 < ell1)
                {
                    ell1 = b0;
                }
                b1 *= inv;
                if (b1 > ell0)
                {
                    ell0 = b1;
                }
            }
        }
    }

    /// 如果数值误差导致数值几乎为零，则进行校正。
    if (ell0 > T{})
    {
        ell0 = T{};
    }
    if (ell1 < T{})
    {
        ell1 = T{};
    }
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_ALGEBRA_MINIMIZE_N_DETAIL_H
