///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/10 13:19)

#ifndef MATHEMATICS_OBJECTS2D_ELLIPSE2_COEFFICIENTS_DETAIL_H
#define MATHEMATICS_OBJECTS2D_ELLIPSE2_COEFFICIENTS_DETAIL_H

#include "Ellipse2Coefficients.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename Real>
Mathematics::Ellipse2Coefficients<Real>::Ellipse2Coefficients(const Matrix2& matrix, const Vector2& vector, Real constants)
    : coefficients{ constants, vector.GetX(), vector.GetY(), matrix.GetValue<0, 0>(), matrix.GetValue<0, 1>() * Math::GetValue(2), matrix.GetValue<1, 1>() }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::Ellipse2Coefficients<Real>::Ellipse2Coefficients(const CoefficientsType& coefficient)
    : coefficients{ coefficient }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Ellipse2Coefficients<Real>::IsValid() const noexcept
{
    if (coefficients.size() == coefficientsSize)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Matrix2<Real> Mathematics::Ellipse2Coefficients<Real>::GetMatrix() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return Matrix2{ coefficients.at(3), Math::GetRational(1, 2) * coefficients.at(4), Math::GetRational(1, 2) * coefficients.at(4), coefficients.at(5) };
}

template <typename Real>
Mathematics::Vector2<Real> Mathematics::Ellipse2Coefficients<Real>::GetVector() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return Vector2{ coefficients.at(1), coefficients.at(2) };
}

template <typename Real>
Real Mathematics::Ellipse2Coefficients<Real>::GetConstants() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return coefficients.at(0);
}

template <typename Real>
typename Mathematics::Ellipse2Coefficients<Real>::CoefficientsType Mathematics::Ellipse2Coefficients<Real>::GetCoefficients() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    CoefficientsType result{ coefficients };

    // 安排x0^2或x1^2系数之一是1。
    auto maxValue = Math::FAbs(result.at(3));
    auto maxIndex = 3;
    auto absValue = Math::FAbs(result.at(5));
    if (maxValue < absValue)
    {
        maxValue = absValue;
        maxIndex = 5;
    }

    auto invMaxValue = Math::GetValue(1) / maxValue;
    for (auto i = 0; i < coefficientsSize; ++i)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
        if (i != maxIndex)
        {
            result[i] *= invMaxValue;
        }
        else
        {
            result[i] = Math::GetValue(1);
        }
#include STSTEM_WARNING_POP
    }

    return result;
}

template <typename Real>
bool Mathematics::Approximate(const Ellipse2Coefficients<Real>& lhs, const Ellipse2Coefficients<Real>& rhs, const Real epsilon)
{
    const auto lhsCoefficients = lhs.GetCoefficients();
    const auto rhsCoefficients = rhs.GetCoefficients();

    constexpr auto coefficientsSize = Ellipse2Coefficients<Real>::coefficientsSize;

    if (lhsCoefficients.size() != coefficientsSize || rhsCoefficients.size() != coefficientsSize)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("GetCoefficients返回的数组大小错误！"s));
    }

    for (auto i = 0; i < coefficientsSize; ++i)
    {
        if (!Math<Real>::Approximate(lhsCoefficients.at(i), rhsCoefficients.at(i), epsilon))
        {
            return false;
        }
    }

    return true;
}

#endif  // MATHEMATICS_OBJECTS2D_ELLIPSE2_COEFFICIENTS_DETAIL_H
