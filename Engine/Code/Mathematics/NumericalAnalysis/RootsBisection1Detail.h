/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/20 16:33)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ROOTS_BISECTION1_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ROOTS_BISECTION1_DETAIL_H

#include "RootsBisection1.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include <cfenv>

template <typename Real>
Mathematics::RootsBisection1<Real>::RootsBisection1(int maxIterations) requires(!CoreTools::IsArbitraryPrecision<Real>::value)
    : precision{ 0 }, maxIterations{ maxIterations }
{
    ASSERT_FAIL_THROW_EXCEPTION(maxIterations > 0, SYSTEM_TEXT("无效的最大迭代次数。"))

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::RootsBisection1<Real>::RootsBisection1(int precision, int maxIterations) requires(CoreTools::IsArbitraryPrecision<Real>::value)
    : precision{ precision }, maxIterations{ maxIterations }
{
    ASSERT_FAIL_THROW_EXCEPTION(maxIterations > 0, SYSTEM_TEXT("无效的最大迭代次数。"))
    ASSERT_FAIL_THROW_EXCEPTION(precision > 0, SYSTEM_TEXT("无效的精确。"));

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::RootsBisection1<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
int Mathematics::RootsBisection1<Real>::operator()(const std::function<Real(const Real&)>& f, const Real& tMin, const Real& tMax, Real& tRoot, Real& fAtTRoot)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    ASSERT_FAIL_THROW_EXCEPTION(tMin < tMax, SYSTEM_TEXT("t区间终结点的排序无效"))

    /// 按原样使用浮点输入。
    /// 将任意精度的输入四舍五入到指定的精度。
    Real t0{};
    Real t1{};
    RoundInitial(tMin, tMax, t0, t1);
    const auto f0 = f(t0);
    const auto f1 = f(t1);

    return operator()(f, t0, t1, f0, f1, tRoot, fAtTRoot);
}

template <typename Real>
int Mathematics::RootsBisection1<Real>::operator()(const std::function<Real(const Real&)>& f, const Real& tMin, const Real& tMax, const Real& fMin, const Real& fMax, Real& tRoot, Real& fAtTRoot)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    ASSERT_FAIL_THROW_EXCEPTION(tMin < tMax, SYSTEM_TEXT("t区间终结点的排序无效。"))

    const auto sign0 = (fMin > Real{} ? +1 : (fMin < Real{} ? -1 : 0));
    if (sign0 == 0)
    {
        tRoot = tMin;
        fAtTRoot = Real{};
        return 1;
    }

    const auto sign1 = (fMax > Real{} ? +1 : (fMax < Real{} ? -1 : 0));
    if (sign1 == 0)
    {
        tRoot = tMax;
        fAtTRoot = Real{};
        return 1;
    }

    if (sign0 == sign1)
    {
        /// 不知道间隔是否包含根。
        tRoot = Real{};
        fAtTRoot = Real{};
        return 0;
    }

    /// 平分步骤。
    auto t0 = tMin;
    auto t1 = tMax;
    auto iteration = 2;
    for (; iteration <= maxIterations; ++iteration)
    {
        /// 按原样使用浮点平均值。将任意精度的平均值四舍五入到指定的精度。
        tRoot = RoundAverage(t0, t1);
        fAtTRoot = f(tRoot);

        /// 如果函数恰好为零，则会找到根。
        /// 对于固定精度，两个连续数字的平均值可能是当前间隔端点之一。
        const auto signRoot = (fAtTRoot > Real{} ? +1 : (fAtTRoot < Real{} ? -1 : 0));
        if (signRoot == 0 || MathType::Approximate(tRoot, t0) || MathType::Approximate(tRoot, t1))
        {
            break;
        }

        /// 将正确的端点更新为中点。
        if (signRoot == sign0)
        {
            t0 = tRoot;
        }
        else  // signRoot == sign1
        {
            t1 = tRoot;
        }
    }
    return iteration;
}

template <typename Real>
void Mathematics::RootsBisection1<Real>::RoundInitial(Real const& inT0, Real const& inT1, Real& t0, Real& t1) noexcept requires(!CoreTools::IsArbitraryPrecision<Real>::value)
{
    t0 = inT0;
    t1 = inT1;
}

template <typename Real>
Real Mathematics::RootsBisection1<Real>::RoundAverage(Real const& t0, Real const& t1) noexcept requires(!CoreTools::IsArbitraryPrecision<Real>::value)
{
    const auto average = MathType::GetRational(1, 2) * (t0 + t1);
    return average;
}

template <typename Real>
void Mathematics::RootsBisection1<Real>::RoundInitial(Real const& inT0, Real const& inT1, Real& t0, Real& t1) requires(CoreTools::IsArbitraryPrecision<Real>::value)
{
    if (precision < std::numeric_limits<uint32_t>::max())
    {
        Convert(inT0, precision, FE_TONEAREST, t0);
        Convert(inT1, precision, FE_TONEAREST, t1);
    }
    else
    {
        t0 = inT0;
        t1 = inT1;
    }
}

template <typename Real>
Real Mathematics::RootsBisection1<Real>::RoundAverage(Real const& t0, Real const& t1) requires(CoreTools::IsArbitraryPrecision<Real>::value)
{
    auto average = std::ldexp(t0 + t1, -1);  // = (t0 + t1) / 2
    if (precision < std::numeric_limits<uint32_t>::max())
    {
        Real roundedAverage{};
        Convert(average, precision, FE_TONEAREST, roundedAverage);
        return roundedAverage;
    }
    else
    {
        return average;
    }
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_ROOTS_BISECTION1_DETAIL_H
