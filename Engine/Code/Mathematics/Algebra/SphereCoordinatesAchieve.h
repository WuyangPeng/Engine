///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/26 11:03)

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
        THROW_EXCEPTION(SYSTEM_TEXT("rֵ��Χ��[0,��)֮�䣬��ֵ��Χ��[0,��]֮�䣬��ֵ��Χ��[0,2��)֮��"))
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
requires std::is_floating_point_v<Real> bool Mathematics::SphereCoordinates<Real>::IsValid() const noexcept
{
    return MathType::GetValue(0) <= r && MathType::GetValue(0) <= theta && theta <= MathType::GetPI() && MathType::GetValue(0) <= phi && phi < MathType::GetTwoPI();
}

template <typename Real>
requires std::is_floating_point_v<Real>
void Mathematics::SphereCoordinates<Real>::SetR(Real radius)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    if (MathType::GetValue(0) <= radius)
    {
        r = radius;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("radiusֵ��Χ��[0,��)֮�䡣"))
    }
}

template <typename Real>
requires std::is_floating_point_v<Real>
void Mathematics::SphereCoordinates<Real>::SetTheta(Real aTheta)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    if (MathType::GetValue(0) <= aTheta && aTheta <= MathType::GetPI())
    {
        theta = aTheta;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("thetaֵ������[0,��]֮�䡣"))
    }
}

template <typename Real>
requires std::is_floating_point_v<Real>
void Mathematics::SphereCoordinates<Real>::SetPhi(Real aPhi)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    if (MathType::GetValue(0) <= aPhi && aPhi < MathType::GetTwoPI())
    {
        phi = aPhi;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("phiֵ������[0,2��)֮�䡣"))
    }
}

template <typename Real>
requires std::is_floating_point_v<Real>
void Mathematics::SphereCoordinates<Real>::SetCartesian(Real xCoordinate, Real yCoordinate, Real zCoordinate) noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    r = MathType::Sqrt(MathType::Square(xCoordinate) + MathType::Square(yCoordinate) * 2 + MathType::Square(zCoordinate));
    theta = MathType::GetZeroTolerance() < r ? MathType::ASin(MathType::Sqrt((MathType::Square(xCoordinate) + MathType::Square(zCoordinate)) / MathType::Square(r))) : Real{};
    phi = MathType::GetZeroTolerance() < r ? MathType::ASin(MathType::Sqrt((MathType::Square(xCoordinate) + MathType::Square(yCoordinate)) / MathType::Square(r))) : Real{};
}

template <typename Real>
requires std::is_floating_point_v<Real>
Mathematics::Vector3<Real> Mathematics::SphereCoordinates<Real>::GetCartesian() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return Vector3Type{ r * MathType::Sin(theta) * MathType::Sin(phi), r * MathType::Cos(theta), r * MathType::Sin(theta) * MathType::Cos(phi) };
}

#endif  // MATHEMATICS_SPHERE_COORDINATES_ACHIEVE_H