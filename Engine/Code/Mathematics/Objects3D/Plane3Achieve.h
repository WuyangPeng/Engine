///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 17:24)

#ifndef MATHEMATICS_OBJECTS_3D_PLANE3_ACHIEVE_H
#define MATHEMATICS_OBJECTS_3D_PLANE3_ACHIEVE_H

#include "Plane3.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::Plane3<Real>::Plane3(const Vector3& normal, Real constant, Real epsilon) noexcept
    : normal{ normal }, constant{ constant }, epsilon{ epsilon }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::Plane3<Real>::Plane3() noexcept
    : normal{ Vector3::GetUnitX() }, constant{}, epsilon{ Math::GetZeroTolerance() }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::Plane3<Real>::Plane3(const Vector3& normal, const Vector3& point, Real epsilon) noexcept
    : normal{ normal }, constant{ Vector3Tools::DotProduct(normal, point) }, epsilon{ epsilon }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::Plane3<Real>::Plane3(const Triangle3& triangle, Real epsilon)
    : normal{}, constant{}, epsilon{ epsilon }
{
    const auto edge1 = triangle.GetVertex(1) - triangle.GetVertex(0);
    const auto edge2 = triangle.GetVertex(2) - triangle.GetVertex(0);
    normal = Vector3Tools::UnitCrossProduct(edge1, edge2);
    constant = Vector3Tools::DotProduct(normal, triangle.GetVertex(0));

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::Plane3<Real>::Plane3(const Vector3& point0, const Vector3& point1, const Vector3& point2, Real epsilon)
    : normal{}, constant{}, epsilon{ epsilon }
{
    const auto edge1 = point1 - point0;
    const auto edge2 = point2 - point0;
    normal = Vector3Tools::UnitCrossProduct(edge1, edge2);
    constant = Vector3Tools::DotProduct(normal, point0);

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::Plane3<Real>::IsValid() const noexcept
{
    try
    {
        if (normal.IsNormalize(epsilon))
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
Mathematics::Vector3<Real> Mathematics::Plane3<Real>::GetNormal() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return normal;
}

template <typename Real>
Real Mathematics::Plane3<Real>::GetConstant() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return constant;
}

template <typename Real>
Real Mathematics::Plane3<Real>::DistanceTo(const Vector3& point) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return Vector3Tools::DotProduct(normal, point) - constant;
}

template <typename Real>
Mathematics::NumericalValueSymbol Mathematics::Plane3<Real>::WhichSide(const Vector3& point) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto distance = DistanceTo(point);

    if (distance < -epsilon)
    {
        return NumericalValueSymbol::Negative;
    }
    else if (epsilon < distance)
    {
        return NumericalValueSymbol::Positive;
    }
    else
    {
        return NumericalValueSymbol::Zero;
    }
}

template <typename Real>
void Mathematics::Plane3<Real>::SetPlane(const Vector3& newNormal, const Vector3& point) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    normal = newNormal;

    constant = Vector3Tools::DotProduct(normal, point);
}

template <typename Real>
Mathematics::Plane3<Real> Mathematics::Plane3<Real>::GetMove(Real t, const Vector3& velocity) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto movedConstant = GetConstant() + t * Vector3Tools::DotProduct(GetNormal(), velocity);
    const Plane3 movedPlane{ GetNormal(), movedConstant, epsilon };

    return movedPlane;
}

#endif  // MATHEMATICS_OBJECTS_3D_PLANE3_ACHIEVE_H
