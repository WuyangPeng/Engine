///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/16 10:37)

#ifndef MATHEMATICS_OBJECTS2D_ELLIPSE2_COEFFICIENTS_IMPL_DETAIL_H
#define MATHEMATICS_OBJECTS2D_ELLIPSE2_COEFFICIENTS_IMPL_DETAIL_H

#include "Ellipse2CoefficientsImpl.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Mathematics/Algebra/Vector2DTools.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::Ellipse2CoefficientsImpl<Real>::Ellipse2CoefficientsImpl(const Matrix2& matrix, const Vector2D& vector, Real constants)
    : m_Coefficients{ constants, vector.GetX(), vector.GetY(), matrix.GetValue<0, 0>(), matrix.GetValue<0, 1>() * Math::GetValue(2), matrix.GetValue<1, 1>() }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::Ellipse2CoefficientsImpl<Real>::Ellipse2CoefficientsImpl(const CoefficientsType& coefficient)
    : m_Coefficients{ coefficient }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Ellipse2CoefficientsImpl<Real>::IsValid() const noexcept
{
    if (m_Coefficients.size() == sm_CoefficientsSize)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Matrix2<Real> Mathematics::Ellipse2CoefficientsImpl<Real>::GetMatrix() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return Matrix2{ m_Coefficients.at(3), Math::GetRational(1, 2) * m_Coefficients.at(4), Math::GetRational(1, 2) * m_Coefficients.at(4), m_Coefficients.at(5) };
}

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::Ellipse2CoefficientsImpl<Real>::GetVector() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return Vector2D{ m_Coefficients.at(1), m_Coefficients.at(2) };
}

template <typename Real>
Real Mathematics::Ellipse2CoefficientsImpl<Real>::GetConstants() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Coefficients.at(0);
}

template <typename Real>
typename const Mathematics::Ellipse2CoefficientsImpl<Real>::CoefficientsType Mathematics::Ellipse2CoefficientsImpl<Real>::GetCoefficients() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    CoefficientsType coefficients{ m_Coefficients };

    // 安排x0^2或x1^2系数之一是1。
    auto maxValue = Math::FAbs(coefficients.at(3));
    int maxIndex{ 3 };
    auto absValue = Math::FAbs(coefficients.at(5));
    if (maxValue < absValue)
    {
        maxValue = absValue;
        maxIndex = 5;
    }

    auto invMaxValue = Math::GetValue(1) / maxValue;
    for (auto i = 0; i < sm_CoefficientsSize; ++i)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
        if (i != maxIndex)
        {
            coefficients[i] *= invMaxValue;
        }
        else
        {
            coefficients[i] = Math::GetValue(1);
        }
#include STSTEM_WARNING_POP
    }

    return coefficients;
}

#endif  // MATHEMATICS_OBJECTS2D_ELLIPSE2_COEFFICIENTS_IMPL_DETAIL_H
