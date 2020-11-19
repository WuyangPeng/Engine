///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/16 18:56)

#ifndef MATHEMATICS_OBJECTS3D_PLANE3_ACHIEVE_H
#define MATHEMATICS_OBJECTS3D_PLANE3_ACHIEVE_H

#include "Plane3.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::Plane3<Real>::Plane3(const Vector3D& normal, Real constant, const Real epsilon) noexcept
    : m_Normal{ normal }, m_Constant{ constant }, m_Epsilon{ epsilon }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::Plane3<Real>::Plane3() noexcept
    : m_Normal{ Vector3D::GetUnitX() }, m_Constant{}, m_Epsilon{ Math::GetZeroTolerance() }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::Plane3<Real>::Plane3(const Vector3D& normal, const Vector3D& point, const Real epsilon) noexcept
    : m_Normal{ normal }, m_Constant{ Vector3DTools::DotProduct(normal, point) }, m_Epsilon{ epsilon }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::Plane3<Real>::Plane3(const Triangle3& triangle, const Real epsilon)
    : m_Normal{}, m_Constant{}, m_Epsilon{ epsilon }
{
    auto edge1 = triangle.GetVertex(1) - triangle.GetVertex(0);
    auto edge2 = triangle.GetVertex(2) - triangle.GetVertex(0);
    m_Normal = Vector3DTools::UnitCrossProduct(edge1, edge2);
    m_Constant = Vector3DTools::DotProduct(m_Normal, triangle.GetVertex(0));

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::Plane3<Real>::Plane3(const Vector3D& point0, const Vector3D& point1, const Vector3D& point2, const Real epsilon)
    : m_Normal{}, m_Constant{}, m_Epsilon{ epsilon }
{
    auto edge1 = point1 - point0;
    auto edge2 = point2 - point0;
    m_Normal = Vector3DTools::UnitCrossProduct(edge1, edge2);
    m_Constant = Vector3DTools::DotProduct(m_Normal, point0);

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Plane3<Real>::IsValid() const noexcept
{
    try
    {
        if (m_Normal.IsNormalize(m_Epsilon))
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
const Mathematics::Vector3D<Real> Mathematics::Plane3<Real>::GetNormal() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Normal;
}

template <typename Real>
Real Mathematics::Plane3<Real>::GetConstant() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Constant;
}

template <typename Real>
Real Mathematics::Plane3<Real>::DistanceTo(const Vector3D& point) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return Vector3DTools::DotProduct(m_Normal, point) - m_Constant;
}

template <typename Real>
Mathematics::NumericalValueSymbol Mathematics::Plane3<Real>::WhichSide(const Vector3D& point) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    auto distance = DistanceTo(point);

    if (distance < -m_Epsilon)
    {
        return NumericalValueSymbol::Negative;
    }
    else if (m_Epsilon < distance)
    {
        return NumericalValueSymbol::Positive;
    }
    else
    {
        return NumericalValueSymbol::Zero;
    }
}

template <typename Real>
void Mathematics::Plane3<Real>::SetPlane(const Vector3D& normal, const Vector3D& point) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    m_Normal = normal;

    m_Constant = Vector3DTools::DotProduct(m_Normal, point);
}

#endif  // MATHEMATICS_OBJECTS3D_PLANE3_ACHIEVE_H
