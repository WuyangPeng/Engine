/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 11:19)

#ifndef MATHEMATICS_OBJECTS_2D_ELLIPSE2_COEFFICIENTS_DETAIL_H
#define MATHEMATICS_OBJECTS_2D_ELLIPSE2_COEFFICIENTS_DETAIL_H

#include "Ellipse2Coefficients.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename Real>
Mathematics::Ellipse2Coefficients<Real>::Ellipse2Coefficients(const Matrix2Type& matrix, const Vector2Type& vector, Real constants)
    : coefficients{ constants, vector.GetX(), vector.GetY(), matrix.template GetValue<0, 0>(), matrix.template GetValue<0, 1>() * MathType::GetValue(2), matrix.template GetValue<1, 1>() }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::Ellipse2Coefficients<Real>::Ellipse2Coefficients(CoefficientsType coefficient) noexcept
    : coefficients{ std::move(coefficient) }
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

    return Matrix2Type{ coefficients.at(3), MathType::GetRational(1, 2) * coefficients.at(4), MathType::GetRational(1, 2) * coefficients.at(4), coefficients.at(5) };
}

template <typename Real>
Mathematics::Vector2<Real> Mathematics::Ellipse2Coefficients<Real>::GetVector() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return Vector2Type{ coefficients.at(1), coefficients.at(2) };
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
    auto maxValue = MathType::FAbs(result.at(3));
    auto maxIndex = 3;
    auto absValue = MathType::FAbs(result.at(5));
    if (maxValue < absValue)
    {
        maxValue = absValue;
        maxIndex = 5;
    }

    auto invMaxValue = MathType::GetValue(1) / maxValue;
    for (auto i = 0; i < coefficientsSize; ++i)
    {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

        if (i != maxIndex)
        {
            result[i] *= invMaxValue;
        }
        else
        {
            result[i] = MathType::GetValue(1);
        }

#include SYSTEM_WARNING_POP
    }

    return result;
}

template <typename Real>
bool Mathematics::Approximate(const Ellipse2Coefficients<Real>& lhs, const Ellipse2Coefficients<Real>& rhs, Real epsilon)
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

#endif  // MATHEMATICS_OBJECTS_2D_ELLIPSE2_COEFFICIENTS_DETAIL_H
