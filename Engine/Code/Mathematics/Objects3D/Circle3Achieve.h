/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 10:44)

#ifndef MATHEMATICS_OBJECTS_3D_CIRCLE3_ACHIEVE_H
#define MATHEMATICS_OBJECTS_3D_CIRCLE3_ACHIEVE_H

#include "Circle3.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3Tools.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::Circle3<Real>::Circle3(const Vector3Type& center, const Vector3Type& direction0, const Vector3Type& direction1, const Vector3Type& normal, const Real radius, const Real epsilon) noexcept
    : center{ center }, direction0{ direction0 }, direction1{ direction1 }, normal{ normal }, radius{ radius }, epsilon{ epsilon }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::Circle3<Real>::IsValid() const noexcept
{
    try
    {
        if (Vector3ToolsType::Approximate(Vector3ToolsType::CrossProduct(direction0, direction1), normal, epsilon) &&
            Vector3ToolsType::Approximate(Vector3ToolsType::CrossProduct(direction1, normal), direction0, epsilon) &&
            Vector3ToolsType::Approximate(Vector3ToolsType::CrossProduct(normal, direction0), direction1, epsilon))
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
Mathematics::Vector3<Real> Mathematics::Circle3<Real>::GetCenter() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return center;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::Circle3<Real>::GetDirection0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return direction0;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::Circle3<Real>::GetDirection1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return direction1;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::Circle3<Real>::GetNormal() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return normal;
}

template <typename Real>
Real Mathematics::Circle3<Real>::GetRadius() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return radius;
}

template <typename Real>
Mathematics::Circle3<Real> Mathematics::Circle3<Real>::GetMove(Real t, const Vector3Type& velocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return Circle3{ center * t + velocity, direction0, direction1, normal, radius, epsilon };
}

#endif  // MATHEMATICS_OBJECTS_3D_CIRCLE3_ACHIEVE_H
