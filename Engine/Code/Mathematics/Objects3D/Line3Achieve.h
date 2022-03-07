///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/10 14:05)

#ifndef MATHEMATICS_OBJECTS3D_LINE3_ACHIEVE_H
#define MATHEMATICS_OBJECTS3D_LINE3_ACHIEVE_H

#include "Line3.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Mathematics/Algebra/Vector3Tools.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::Line3<Real>::Line3(const Vector3& origin, const Vector3& direction, const Real epsilon) noexcept
    : origin{ origin }, direction{ direction }, epsilon{ epsilon }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::Line3<Real>::IsValid() const noexcept
{
    try
    {
        if (direction.IsNormalize(epsilon))
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
Mathematics::Vector3<Real> Mathematics::Line3<Real>::GetOrigin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return origin;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::Line3<Real>::GetDirection() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return direction;
}

template <typename Real>
Mathematics::Line3<Real> Mathematics::Line3<Real>::GetMove(Real t, const Vector3& velocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return Line3{ origin + t * velocity, direction, epsilon };
}

#endif  // MATHEMATICS_OBJECTS3D_LINE3_ACHIEVE_H
