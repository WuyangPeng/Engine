///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/16 17:46)

#ifndef MATHEMATICS_OBJECTS3D_SPHERE3_ACHIEVE_H
#define MATHEMATICS_OBJECTS3D_SPHERE3_ACHIEVE_H

#include "Sphere3.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <typename Real>
Mathematics::Sphere3<Real>::Sphere3(const Vector3D& center, Real radius) noexcept
    : m_Center{ center }, m_Radius{ radius }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::Sphere3<Real>::Sphere3() noexcept
    : m_Center{}, m_Radius{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Sphere3<Real>::IsValid() const noexcept
{
    if (Math::GetValue(0) <= m_Radius)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
typename const Mathematics::Sphere3<Real>::Vector3D Mathematics::Sphere3<Real>::GetCenter() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Center;
}

template <typename Real>
Real Mathematics::Sphere3<Real>::GetRadius() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Radius;
}

template <typename Real>
void Mathematics::Sphere3<Real>::SetSphere(const Vector3D& center, Real radius) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    m_Center = center;
    m_Radius = radius;
}

#endif  // MATHEMATICS_OBJECTS3D_SPHERE3_ACHIEVE_H