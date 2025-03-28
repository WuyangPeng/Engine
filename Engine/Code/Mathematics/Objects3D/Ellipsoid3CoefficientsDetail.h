/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 10:38)

#ifndef MATHEMATICS_OBJECTS_3D_ELLIPSOID3_COEFFICIENTS_DETAIL_H
#define MATHEMATICS_OBJECTS_3D_ELLIPSOID3_COEFFICIENTS_DETAIL_H

#include "Ellipsoid3Coefficients.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include <gsl/util>

template <typename Real>
Mathematics::Ellipsoid3Coefficients<Real>::Ellipsoid3Coefficients(const Matrix3Type& matrix, const Vector3Type& vector, Real constants)
    : coefficients{ constants,
                    vector.GetX(),
                    vector.GetY(),
                    vector.GetZ(),
                    matrix.template GetValue<0, 0>(),
                    matrix.template GetValue<0, 1>() * MathType::GetValue(2),
                    matrix.template GetValue<0, 2>() * MathType::GetValue(2),
                    matrix.template GetValue<1, 1>(),
                    matrix.template GetValue<1, 2>() * MathType::GetValue(2),
                    matrix.template GetValue<2, 2>() }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::Ellipsoid3Coefficients<Real>::Ellipsoid3Coefficients(const CoefficientsType& coefficient)
    : coefficients{ coefficient }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::Ellipsoid3Coefficients<Real>::IsValid() const noexcept
{
    if (coefficients.size() == gsl::narrow_cast<size_t>(GetCoefficientsSize()))
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Matrix3<Real> Mathematics::Ellipsoid3Coefficients<Real>::GetMatrix() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    return Matrix3Type{ coefficients[4],
                    MathType::GetRational(1, 2) * coefficients[5],
                    MathType::GetRational(1, 2) * coefficients[6],
                    MathType::GetRational(1, 2) * coefficients[5],
                    coefficients[7],
                    MathType::GetRational(1, 2) * coefficients[8],
                    MathType::GetRational(1, 2) * coefficients[6],
                    MathType::GetRational(1, 2) * coefficients[8],
                    coefficients[9] };

#include SYSTEM_WARNING_POP
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::Ellipsoid3Coefficients<Real>::GetVector() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    return Vector3Type{ coefficients[1], coefficients[2], coefficients[3] };

#include SYSTEM_WARNING_POP
}

template <typename Real>
Real Mathematics::Ellipsoid3Coefficients<Real>::GetConstants() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    return coefficients[0];

#include SYSTEM_WARNING_POP
}

template <typename Real>
typename Mathematics::Ellipsoid3Coefficients<Real>::CoefficientsType Mathematics::Ellipsoid3Coefficients<Real>::GetCoefficients() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    CoefficientsType result{ coefficients };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    // 安排x0^2或x1^2或x2^2系数之一是1。
    auto maxValue = MathType::FAbs(result[4]);
    int maxIndex{ 4 };
    auto absValue = MathType::FAbs(result[7]);
    if (maxValue < absValue)
    {
        maxValue = absValue;
        maxIndex = 7;
    }
    absValue = MathType::FAbs(result[9]);
    if (maxValue < absValue)
    {
        maxValue = absValue;
        maxIndex = 9;
    }

    auto invMaxValue = MathType::GetValue(1) / maxValue;
    for (auto i = 0; i < GetCoefficientsSize(); ++i)
    {
        if (i != maxIndex)
        {
            result[i] *= invMaxValue;
        }
        else
        {
            result[i] = MathType::GetValue(1);
        }
    }

#include SYSTEM_WARNING_POP

    return result;
}

template <typename Real>
bool Mathematics::Approximate(const Ellipsoid3Coefficients<Real>& lhs, const Ellipsoid3Coefficients<Real>& rhs, const Real epsilon)
{
    auto lhsCoefficients = lhs.GetCoefficients();
    auto rhsCoefficients = rhs.GetCoefficients();

    constexpr auto coefficientsSize = Ellipsoid3Coefficients<Real>::GetCoefficientsSize();

    if (lhsCoefficients.size() != coefficientsSize || rhsCoefficients.size() != coefficientsSize)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("GetCoefficients返回的数组大小错误！"s));
    }

    for (auto i = 0; i < coefficientsSize; ++i)
    {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

        if (!Math<Real>::Approximate(lhsCoefficients[i], rhsCoefficients[i], epsilon))

#include SYSTEM_WARNING_POP
        {
            return false;
        }
    }

    return true;
}

#endif  // MATHEMATICS_OBJECTS_3D_ELLIPSOID3_COEFFICIENTS_DETAIL_H
