///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/16 15:51)

#ifndef MATHEMATICS_OBJECTS3D_CIRCLE3_ACHIEVE_H
#define MATHEMATICS_OBJECTS3D_CIRCLE3_ACHIEVE_H

#include "Circle3.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Mathematics/Algebra/Vector3DTools.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::Circle3<Real>::Circle3(const Vector3D& center, const Vector3D& direction0, const Vector3D& direction1, const Vector3D& normal, const Real radius, const Real epsilon) noexcept
    : m_Center{ center }, m_Direction0{ direction0 }, m_Direction1{ direction1 }, m_Normal{ normal }, m_Radius{ radius }, m_Epsilon{ epsilon }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Circle3<Real>::IsValid() const noexcept
{
    try
    {
        if (Vector3DTools::Approximate(Vector3DTools::CrossProduct(m_Direction0, m_Direction1), m_Normal, m_Epsilon) &&
            Vector3DTools::Approximate(Vector3DTools::CrossProduct(m_Direction1, m_Normal), m_Direction0, m_Epsilon) &&
            Vector3DTools::Approximate(Vector3DTools::CrossProduct(m_Normal, m_Direction0), m_Direction1, m_Epsilon))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    catch (...)
    {
        return false;
    }
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Circle3<Real>::GetCenter() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Center;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Circle3<Real>::GetDirection0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Direction0;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Circle3<Real>::GetDirection1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Direction1;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Circle3<Real>::GetNormal() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Normal;
}

template <typename Real>
Real Mathematics::Circle3<Real>::GetRadius() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Radius;
}

template <typename Real>
const Mathematics::Circle3<Real> Mathematics::Circle3<Real>::GetMove(Real t, const Vector3D& velocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return Circle3{ m_Center * t + velocity, m_Direction0, m_Direction1, m_Normal, m_Radius, m_Epsilon };
}

#endif  // MATHEMATICS_OBJECTS3D_CIRCLE3_ACHIEVE_H
