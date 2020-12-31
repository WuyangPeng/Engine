///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/16 16:11)

#ifndef MATHEMATICS_OBJECTS3D_LINE3_ACHIEVE_H
#define MATHEMATICS_OBJECTS3D_LINE3_ACHIEVE_H

#include "Line3.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Mathematics/Algebra/Vector3DTools.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::Line3<Real>::Line3(const Vector3D& origin, const Vector3D& direction, const Real epsilon) noexcept
    : m_Origin{ origin }, m_Direction{ direction }, m_Epsilon{ epsilon }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Line3<Real>::IsValid() const noexcept
{
    try
    {
        if (m_Direction.IsNormalize(m_Epsilon))
            return true;
        else
            return false;
    }
    catch (...)
    {
        return false;
    }
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Line3<Real>::GetOrigin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Origin;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Line3<Real>::GetDirection() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Direction;
}

template <typename Real>
const Mathematics::Line3<Real> Mathematics::Line3<Real>::GetMove(Real t, const Vector3D& velocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return Line3{ m_Origin + t * velocity, m_Direction, m_Epsilon };
}

#endif  // MATHEMATICS_OBJECTS3D_LINE3_ACHIEVE_H
