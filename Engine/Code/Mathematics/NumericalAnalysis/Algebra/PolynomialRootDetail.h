/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/20 13:19)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_ALGEBRA_POLYNOMIAL_ROOTS_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_ALGEBRA_POLYNOMIAL_ROOTS_DETAIL_H

#include "PolynomialRoot.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Algebra::PolynomialRoot<Real> Mathematics::Algebra::PolynomialRoot<Real>::CreateZero() noexcept(noexcept(Real::CreateZero())) requires(!std::is_floating_point_v<Real>)
{
    return PolynomialRoot{ Real::CreateZero(), 0 };
}

template <typename Real>
Mathematics::Algebra::PolynomialRoot<Real> Mathematics::Algebra::PolynomialRoot<Real>::CreateZero() noexcept requires(std::is_floating_point_v<Real>)
{
    return PolynomialRoot{};
}

template <typename Real>
Mathematics::Algebra::PolynomialRoot<Real>::PolynomialRoot() noexcept requires(std::is_floating_point_v<Real>)
    : x{}, m{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::Algebra::PolynomialRoot<Real>::PolynomialRoot(Real x, int m) noexcept
    : x{ x }, m{ m }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::Algebra::PolynomialRoot<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::Algebra::PolynomialRoot<Real>::GetX() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return x;
}

template <typename Real>
int Mathematics::Algebra::PolynomialRoot<Real>::GetM() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m;
}

template <typename Real>
void Mathematics::Algebra::PolynomialRoot<Real>::SetX(Real aX) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    x = aX;
}

template <typename Real>
void Mathematics::Algebra::PolynomialRoot<Real>::SetM(int aM) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m = aM;
}

template <typename Real>
bool Mathematics::Algebra::operator==(const PolynomialRoot<Real>& lhs, const PolynomialRoot<Real>& rhs) noexcept
{
    return lhs.GetX() == rhs.GetX();
}

template <typename Real>
bool Mathematics::Algebra::operator<(const PolynomialRoot<Real>& lhs, const PolynomialRoot<Real>& rhs) noexcept
{
    return lhs.GetX() < rhs.GetX();
}

template <typename Real>
void Mathematics::Algebra::PolynomialRoot<Real>::PolynomialRootBisect(const std::function<Real(Real)>& function, int signFMin, int signFMax, Real& xMin, Real& xMax)
{
    const auto fMin = function(xMin);
    const auto trueSignFMin = (fMin > Real{} ? +1 : (fMin < Real{} ? -1 : 0));
    if (trueSignFMin == signFMin)
    {
        const auto fMax = function(xMax);
        const auto trueSignFMax = (fMax > Real{} ? +1 : (fMax < Real{} ? -1 : 0));
        if (trueSignFMax == signFMax)
        {
            /// 这些标志是正确的平分线。
            /// 当中点处的函数值为0时，迭代算法终止。
            /// 或者，当当前间隔的中点等于其中一个间隔端点时，它终止，此时间隔端点是连续的浮点数。
            /// 上限maxBisections足够大以确保循环终止，但典型的迭代次数要小得多。
            constexpr auto maxBisections = 4096;
            for (auto iteration = 1; iteration < maxBisections; ++iteration)
            {
                auto x = Math::GetRational(1, 2) * (xMin + xMax);
                auto f = function(x);

                if (Math::Approximate(x, xMin) || Math::Approximate(x, xMax))
                {
                    /// 浮点数xMin和xMax是连续的，
                    /// 在这种情况下，细分无法在它们之间产生浮点数。
                    /// 将边界间隔返回给调用者以进行进一步处理。
                    return;
                }

                const auto signF = (f > Real{} ? 1 : (f < Real{} ? -1 : 0));
                if (signF == 0)
                {
                    /// 该函数恰好为零，并且找到了根。
                    xMin = x;
                    xMax = x;
                    return;
                }

                /// 将正确的端点更新为中点。
                if (signF == signFMin)
                {
                    xMin = x;
                }
                else  // signF == signFMax
                {
                    xMax = x;
                }
            }
        }
        else
        {
            /// 浮点舍入误差会妨碍对根的多重性进行正确分类。
            xMin = xMax;
        }
    }
    else
    {
        /// 浮点舍入误差会妨碍对根的多重性进行正确分类。
        xMax = xMin;
    }
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_ALGEBRA_POLYNOMIAL_ROOTS_DETAIL_H
