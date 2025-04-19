/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 10:43)

#ifndef MATHEMATICS_OBJECTS_3D_CONE3_ACHIEVE_H
#define MATHEMATICS_OBJECTS_3D_CONE3_ACHIEVE_H

#include "Cone3.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3Tools.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::Cone3<Real>::Cone3(const Vector3Type& vertex, const Vector3Type& axis, const Real angle, const Real height, const Real epsilon) noexcept(gAssert < 1 || gMathematicsAssert < 1)
    : vertex{ vertex },
      axis{ axis },
      cosAngle{ MathType::Cos(angle) },
      sinAngle{ MathType::Sin(angle) },
      height{ height },
      epsilon{ epsilon }
{
    MATHEMATICS_ASSERTION_1(MathType::GetValue(0) <= angle && angle <= MathType::GetHalfPI(), "角度必须在第一象限！");

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::Cone3<Real>::Cone3(const Real cosAngle, const Real sinAngle, const Real height, const Vector3Type& vertex, const Vector3Type& axis, const Real epsilon) noexcept
    : vertex{ vertex }, axis{ axis }, cosAngle{ cosAngle }, sinAngle{ sinAngle }, height{ height }, epsilon{ epsilon }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::Cone3<Real>::IsValid() const noexcept
{
    try
    {
        if (MathType::Approximate(cosAngle * cosAngle + sinAngle * sinAngle, MathType::GetValue(1), epsilon) &&
            epsilon < height &&
            axis.IsNormalize(epsilon))
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
Mathematics::Vector3<Real> Mathematics::Cone3<Real>::GetVertex() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return vertex;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::Cone3<Real>::GetAxis() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return axis;
}

template <typename Real>
Real Mathematics::Cone3<Real>::GetCosAngle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return cosAngle;
}

template <typename Real>
Real Mathematics::Cone3<Real>::GetSinAngle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return sinAngle;
}

template <typename Real>
Real Mathematics::Cone3<Real>::GetHeight() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return height;
}

#endif  // MATHEMATICS_OBJECTS_3D_CONE3_ACHIEVE_H
