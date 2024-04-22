/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/30 14:38)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SYMMETRIC_EIGENSOLVER2_X_2_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SYMMETRIC_EIGENSOLVER2_X_2_DETAIL_H

#include "SymmetricEigensolver2x2.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Mathematics::SymmetricEigensolver2x2<Real>::SymmetricEigensolver2x2() noexcept
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::SymmetricEigensolver2x2<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::SymmetricEigensolver2x2<Real>::operator()(Real a00, Real a01, Real a11, int sortType, std::array<Real, 2>& eval, std::array<std::array<Real, 2>, 2>& evec) const
{
    /// 稳健地规范化(c2,s2)，避免sqrt调用中的浮点溢出。

    auto c2 = Math::GetRational(1, 2) * (a00 - a11);
    auto s2 = a01;
    auto maxAbsComp = std::max(std::fabs(c2), std::fabs(s2));
    if (maxAbsComp > Real{})
    {
        c2 /= maxAbsComp;  // in [-1,1]
        s2 /= maxAbsComp;  // in [-1,1]
        const auto length = std::sqrt(c2 * c2 + s2 * s2);
        c2 /= length;
        s2 /= length;
        if (c2 > Real{})
        {
            c2 = -c2;
            s2 = -s2;
        }
    }
    else
    {
        c2 = -Math::GetValue(1);
        s2 = Real{};
    }

    auto s = std::sqrt(Math::GetRational(1, 2) * (Math::GetValue(1) - c2));  // >= 1/sqrt(2)
    auto c = Math::GetRational(1, 2) * s2 / s;

    auto cSqr = c * c;
    auto sSqr = s * s;
    auto mid = s2 * a01;
    std::array<Real, 2> diagonal{ cSqr * a00 + mid + sSqr * a11, cSqr * a11 - mid + sSqr * a00 };

    if (sortType == 0 ||
        static_cast<Real>(sortType) * diagonal.at(0) <= static_cast<Real>(sortType) * diagonal.at(1))
    {
        eval.at(0) = diagonal.at(0);
        eval.at(1) = diagonal.at(1);
        evec.at(0).at(0) = c;
        evec.at(0).at(1) = s;
        evec.at(1).at(0) = -s;
        evec.at(1).at(1) = c;
    }
    else
    {
        eval.at(0) = diagonal.at(1);
        eval.at(1) = diagonal.at(0);
        evec.at(0).at(0) = s;
        evec.at(0).at(1) = -c;
        evec.at(1).at(0) = c;
        evec.at(1).at(1) = s;
    }
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_SYMMETRIC_EIGENSOLVER2_X_2_DETAIL_H
