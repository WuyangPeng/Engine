///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 10:25)

#ifndef MATHEMATICS_CYLINDRICAL_COORDINATES_ACHIEVE_H
#define MATHEMATICS_CYLINDRICAL_COORDINATES_ACHIEVE_H

#include "CylindricalCoordinatesDetail.h"
#include "Vector3Detail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
requires std::is_floating_point_v<Real>
Mathematics::CylindricalCoordinates<Real>::CylindricalCoordinates(Real r, Real phi, Real y)
    : r{ r },
      phi{ phi },
      y{ y }
{
    if (!IsValid())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("r值范围在[0,∞)之间，φ值范围在[0,2π)之间"))
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
requires std::is_floating_point_v<Real> bool Mathematics::CylindricalCoordinates<Real>::IsValid() const noexcept
{
    return Math::GetValue(0) <= r && Math::GetValue(0) <= phi && phi < Math::GetTwoPI();
}

template <typename Real>
requires std::is_floating_point_v<Real>
void Mathematics::CylindricalCoordinates<Real>::SetR(Real radius)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    if (Math::GetValue(0) <= radius)
    {
        r = radius;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("radius值范围在[0,∞)之间。"))
    }
}

template <typename Real>
requires std::is_floating_point_v<Real>
void Mathematics::CylindricalCoordinates<Real>::SetPhi(Real phi)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    if (Math::GetValue(0) <= phi && phi < Math::GetTwoPI())
    {
        phi = phi;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("phi值必需在[0,2π)之间。"))
    }
}

template <typename Real>
requires std::is_floating_point_v<Real>
void Mathematics::CylindricalCoordinates<Real>::SetCartesian(Real xCoordinate, Real yCoordinate, Real zCoordinate) noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    r = Math::Sqrt(Math::Square(xCoordinate) + Math::Square(zCoordinate));
    phi = Math::GetZeroTolerance() < r ? Math::ASin(xCoordinate / r) : Real{};
    y = yCoordinate;
}

template <typename Real>
requires std::is_floating_point_v<Real>
Mathematics::Vector3<Real> Mathematics::CylindricalCoordinates<Real>::GetCartesian() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return Vector3{ r * Math::Sin(phi), y, r * Math::Cos(phi) };
}

#endif  // MATHEMATICS_CYLINDRICAL_COORDINATES_ACHIEVE_H