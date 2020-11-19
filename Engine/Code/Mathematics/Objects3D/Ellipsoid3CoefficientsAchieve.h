///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/17 13:07)

#ifndef MATHEMATICS_OBJECTS3D_ELLIPSOID3_COEFFICIENTS_ACHIEVE_H
#define MATHEMATICS_OBJECTS3D_ELLIPSOID3_COEFFICIENTS_ACHIEVE_H

#include "Ellipsoid3Coefficients.h"
#include "Detail/Ellipsoid3CoefficientsImplDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Ellipsoid3Coefficients<Real>::Ellipsoid3Coefficients(const Matrix3& matrix, const Vector3D& vector, Real constants)
    : m_Impl{ std::make_shared<ImplType>(matrix, vector, constants) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::Ellipsoid3Coefficients<Real>::Ellipsoid3Coefficients(const CoefficientsType& coefficient)
    : m_Impl{ std::make_shared<ImplType>(coefficient) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Ellipsoid3Coefficients<Real>::IsValid() const noexcept
{
    if (m_Impl != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Matrix3<Real> Mathematics::Ellipsoid3Coefficients<Real>::GetMatrix() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetMatrix();
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Ellipsoid3Coefficients<Real>::GetVector() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetVector();
}

template <typename Real>
Real Mathematics::Ellipsoid3Coefficients<Real>::GetConstants() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetConstants();
}

template <typename Real>
const typename Mathematics::Ellipsoid3Coefficients<Real>::CoefficientsType Mathematics::Ellipsoid3Coefficients<Real>::GetCoefficients() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetCoefficients();
}

#endif  // MATHEMATICS_OBJECTS3D_ELLIPSOID3_COEFFICIENTS_ACHIEVE_H
