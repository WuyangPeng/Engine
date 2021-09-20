///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/17 10:47)

#ifndef MATHEMATICS_OBJECTS3D_ELLIPSOID3_COEFFICIENTS_IMPL_DETAIL_H
#define MATHEMATICS_OBJECTS3D_ELLIPSOID3_COEFFICIENTS_IMPL_DETAIL_H

#include "Ellipsoid3CoefficientsImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Mathematics/Algebra/Vector3DTools.h"
#include "Mathematics/Base/MathDetail.h"

#include <gsl/util>

template <typename Real>
Mathematics::Ellipsoid3CoefficientsImpl<Real>::Ellipsoid3CoefficientsImpl(const Matrix3& matrix, const Vector3D& vector, Real constants)
    : m_Coefficients{ constants, vector.GetX(), vector.GetY(), vector.GetZ(),
                      matrix.GetValue<0, 0>(), matrix.GetValue<0, 1>() * Math::GetValue(2), matrix.GetValue<0, 2>() * Math::GetValue(2),
                      matrix.GetValue<1, 1>(), matrix.GetValue<1, 2>() * Math::GetValue(2), matrix.GetValue<2, 2>() }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::Ellipsoid3CoefficientsImpl<Real>::Ellipsoid3CoefficientsImpl(const CoefficientsType& coefficient)
    : m_Coefficients{ coefficient }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Ellipsoid3CoefficientsImpl<Real>::IsValid() const noexcept
{
    if (m_Coefficients.size() == gsl::narrow_cast<size_t>(GetCoefficientsSize()))
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Matrix3<Real> Mathematics::Ellipsoid3CoefficientsImpl<Real>::GetMatrix() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    return Matrix3{ m_Coefficients[4],
                    Math::GetRational(1, 2) * m_Coefficients[5],
                    Math::GetRational(1, 2) * m_Coefficients[6],
                    Math::GetRational(1, 2) * m_Coefficients[5],
                    m_Coefficients[7],
                    Math::GetRational(1, 2) * m_Coefficients[8],
                    Math::GetRational(1, 2) * m_Coefficients[6],
                    Math::GetRational(1, 2) * m_Coefficients[8],
                    m_Coefficients[9] };

#include STSTEM_WARNING_POP
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Ellipsoid3CoefficientsImpl<Real>::GetVector() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    return Vector3D{ m_Coefficients[1], m_Coefficients[2], m_Coefficients[3] };

#include STSTEM_WARNING_POP
}

template <typename Real>
Real Mathematics::Ellipsoid3CoefficientsImpl<Real>::GetConstants() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
    return m_Coefficients[0];
#include STSTEM_WARNING_POP
}

template <typename Real>
const typename Mathematics::Ellipsoid3CoefficientsImpl<Real>::CoefficientsType Mathematics::Ellipsoid3CoefficientsImpl<Real>::GetCoefficients() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    CoefficientsType coefficients{ m_Coefficients };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    // 安排x0^2或x1^2或x2^2系数之一是1。
    auto maxValue = Math::FAbs(coefficients[4]);
    int maxIndex{ 4 };
    auto absValue = Math::FAbs(coefficients[7]);
    if (maxValue < absValue)
    {
        maxValue = absValue;
        maxIndex = 7;
    }
    absValue = Math::FAbs(coefficients[9]);
    if (maxValue < absValue)
    {
        maxValue = absValue;
        maxIndex = 9;
    }

    auto invMaxValue = Math::GetValue(1) / maxValue;
    for (auto i = 0; i < GetCoefficientsSize(); ++i)
    {
        if (i != maxIndex)
        {
            coefficients[i] *= invMaxValue;
        }
        else
        {
            coefficients[i] = Math::GetValue(1);
        }
    }

#include STSTEM_WARNING_POP

    return coefficients;
}

#endif  // MATHEMATICS_OBJECTS3D_ELLIPSOID3_COEFFICIENTS_IMPL_DETAIL_H
