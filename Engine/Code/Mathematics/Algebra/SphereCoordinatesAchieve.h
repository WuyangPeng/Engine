///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 11:03)

#ifndef MATHEMATICS_SPHERE_COORDINATES_ACHIEVE_H
#define MATHEMATICS_SPHERE_COORDINATES_ACHIEVE_H

#include "SphereCoordinatesDetail.h"
#include "Vector3Detail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
requires std::is_floating_point_v<Real>
Mathematics::SphereCoordinates<Real>::SphereCoordinates(Real r, Real theta, Real phi)
    : r{ r },
      theta{ theta },
      phi{ phi }
{
    if (!IsValid())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("r值范围在[0,∞)之间，θ值范围在[0,π]之间，φ值范围在[0,2π)之间"))
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
requires std::is_floating_point_v<Real> bool Mathematics::SphereCoordinates<Real>::IsValid() const noexcept
{
    return Math::GetValue(0) <= r && Math::GetValue(0) <= theta && theta <= Math::GetPI() && Math::GetValue(0) <= phi && phi < Math::GetTwoPI();
}

template <typename Real>
requires std::is_floating_point_v<Real>
void Mathematics::SphereCoordinates<Real>::SetR(Real radius)
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
void Mathematics::SphereCoordinates<Real>::SetTheta(Real aTheta)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    if (Math::GetValue(0) <= aTheta && aTheta <= Math::GetPI())
    {
        theta = aTheta;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("theta值必需在[0,π]之间。"))
    }
}

template <typename Real>
requires std::is_floating_point_v<Real>
void Mathematics::SphereCoordinates<Real>::SetPhi(Real aPhi)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    if (Math::GetValue(0) <= aPhi && aPhi < Math::GetTwoPI())
    {
        phi = aPhi;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("phi值必需在[0,2π)之间。"))
    }
}

template <typename Real>
requires std::is_floating_point_v<Real>
void Mathematics::SphereCoordinates<Real>::SetCartesian(Real xCoordinate, Real yCoordinate, Real zCoordinate) noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    r = Math::Sqrt(Math::Square(xCoordinate) + Math::Square(yCoordinate) * 2 + Math::Square(zCoordinate));
    theta = Math::GetZeroTolerance() < r ? Math::ASin(Math::Sqrt((Math::Square(xCoordinate) + Math::Square(zCoordinate)) / Math::Square(r))) : Real{};
    phi = Math::GetZeroTolerance() < r ? Math::ASin(Math::Sqrt((Math::Square(xCoordinate) + Math::Square(yCoordinate)) / Math::Square(r))) : Real{};
}

template <typename Real>
requires std::is_floating_point_v<Real>
Mathematics::Vector3<Real> Mathematics::SphereCoordinates<Real>::GetCartesian() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return Vector3{ r * Math::Sin(theta) * Math::Sin(phi), r * Math::Cos(theta), r * Math::Sin(theta) * Math::Cos(phi) };
}

#endif  // MATHEMATICS_SPHERE_COORDINATES_ACHIEVE_H