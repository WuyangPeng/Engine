///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/08 13:59)

#ifndef MATHEMATICS_ALGEBRA_QUATERNION_FACTOR_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_QUATERNION_FACTOR_ACHIEVE_H

#include "Quaternion.h"
#include "QuaternionFactor.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::QuaternionFactor<Real>::QuaternionFactor(const Quaternion& quaternion, QuaternionFactorFlags flag) noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
    : quaternion{ quaternion }, sinX{}, cosX{}, sinY{}, cosY{}, sinZ{}, cosZ{}
{
    switch (flag)
    {
        case QuaternionFactorFlags::XYZ:
            FactorXYZ();
            break;
        case QuaternionFactorFlags::XZY:
            FactorXZY();
            break;
        case QuaternionFactorFlags::YZX:
            FactorYZX();
            break;
        case QuaternionFactorFlags::YXZ:
            FactorYXZ();
            break;
        case QuaternionFactorFlags::ZXY:
            FactorZXY();
            break;
        case QuaternionFactorFlags::ZYX:
            FactorZYX();
            break;
        default:
            MATHEMATICS_ASSERTION_1(false, "错误的枚举值！");
            break;
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::QuaternionFactor<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::QuaternionFactor<Real>::GetSinX() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return sinX;
}

template <typename Real>
Real Mathematics::QuaternionFactor<Real>::GetSinY() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return sinY;
}

template <typename Real>
Real Mathematics::QuaternionFactor<Real>::GetSinZ() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return sinZ;
}

template <typename Real>
Real Mathematics::QuaternionFactor<Real>::GetCosX() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return cosX;
}

template <typename Real>
Real Mathematics::QuaternionFactor<Real>::GetCosY() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return cosY;
}

template <typename Real>
Real Mathematics::QuaternionFactor<Real>::GetCosZ() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return cosZ;
}

template <typename Real>
void Mathematics::QuaternionFactor<Real>::FactorXYZ() noexcept(g_Assert < 3 || g_MathematicsAssert < 3)
{
    const auto a = quaternion.GetW() * quaternion.GetX() - quaternion.GetY() * quaternion.GetZ();
    const auto b = Math::GetRational(1, 2) * (quaternion.GetW() * quaternion.GetW() - quaternion.GetX() * quaternion.GetX() - quaternion.GetY() * quaternion.GetY() + quaternion.GetZ() * quaternion.GetZ());

    auto length = Math::Sqrt(a * a + b * b);

    if (Math::GetZeroTolerance() < length)
    {
        auto sigma0 = a / length;
        auto gamma0 = b / length;

        if (Math::GetValue(0) <= gamma0)
        {
            cosX = Math::Sqrt(Math::GetRational(1, 2) * (Math::GetValue(1) + gamma0));
            sinX = Math::GetRational(1, 2) * sigma0 / cosX;
        }
        else
        {
            sinX = Math::Sqrt(Math::GetRational(1, 2) * (Math::GetValue(1) - gamma0));
            cosX = Math::GetRational(1, 2) * sigma0 / sinX;
        }

        auto tmp0 = cosX * quaternion.GetW() + sinX * quaternion.GetX();
        auto tmp1 = cosX * quaternion.GetZ() - sinX * quaternion.GetY();
        auto invLength = Math::InvSqrt(tmp0 * tmp0 + tmp1 * tmp1);
        cosZ = tmp0 * invLength;
        sinZ = tmp1 * invLength;

        if (Math::FAbs(sinZ) <= Math::FAbs(cosZ))
        {
            cosY = tmp0 / cosZ;
            sinY = (cosX * quaternion.GetY() + sinX * quaternion.GetZ()) / cosZ;
        }
        else
        {
            cosY = tmp1 / cosZ;
            sinY = (cosX * quaternion.GetX() - sinX * quaternion.GetW()) / cosZ;
        }
    }
    else
    {
        // 无穷多解。选择其中之一。
        if (Math::GetValue(0) < quaternion.GetW() * quaternion.GetY() + quaternion.GetX() * quaternion.GetZ())
        {
            // p = (p0,p1,p0,p1)
            cosX = Math::GetValue(1);
            sinX = Math::GetValue(0);
            cosY = Math::GetInverseSqrt2();
            sinY = Math::GetInverseSqrt2();
            cosZ = Math::GetSqrt2() * quaternion.GetW();
            sinZ = Math::GetSqrt2() * quaternion.GetX();
        }
        else
        {
            // p = (p0,p1,-p0,-p1)
            cosX = Math::GetValue(1);
            sinX = Math::GetValue(0);
            cosY = Math::GetInverseSqrt2();
            sinY = -Math::GetInverseSqrt2();
            cosZ = Math::GetSqrt2() * quaternion.GetW();
            sinZ = -Math::GetSqrt2() * quaternion.GetX();
        }
    }
}

template <typename Real>
void Mathematics::QuaternionFactor<Real>::FactorXZY() noexcept(g_Assert < 3 || g_MathematicsAssert < 3)
{
    quaternion = Quaternion{ quaternion.GetW(), quaternion.GetX(), quaternion.GetZ(), -quaternion.GetY() };

    FactorXYZ();

    auto temp = sinY;
    sinY = -sinZ;
    sinZ = temp;

    std::swap(cosY, cosZ);
}

template <typename Real>
void Mathematics::QuaternionFactor<Real>::FactorYZX() noexcept(g_Assert < 3 || g_MathematicsAssert < 3)
{
    quaternion = Quaternion{ quaternion.GetW(), -quaternion.GetY(), quaternion.GetZ(), -quaternion.GetX() };

    FactorXYZ();

    auto temp = sinZ;
    sinZ = sinY;
    sinY = -sinX;
    sinX = -temp;

    temp = cosZ;
    cosZ = cosY;
    cosY = cosX;
    cosX = temp;
}

template <typename Real>
void Mathematics::QuaternionFactor<Real>::FactorYXZ() noexcept(g_Assert < 3 || g_MathematicsAssert < 3)
{
    quaternion = Quaternion{ quaternion.GetW(), -quaternion.GetY(), quaternion.GetX(), quaternion.GetZ() };

    FactorXYZ();

    auto temp = sinY;
    sinY = -sinX;
    sinX = temp;

    std::swap(cosY, cosX);
}

template <typename Real>
void Mathematics::QuaternionFactor<Real>::FactorZXY() noexcept(g_Assert < 3 || g_MathematicsAssert < 3)
{
    quaternion = Quaternion{ quaternion.GetW(), -quaternion.GetZ(), quaternion.GetX(), -quaternion.GetY() };

    FactorXYZ();

    auto temp = sinZ;
    sinZ = -sinX;
    sinX = sinY;
    sinY = -temp;

    temp = cosZ;
    cosZ = cosX;
    cosX = cosY;
    cosY = temp;
}

template <typename Real>
void Mathematics::QuaternionFactor<Real>::FactorZYX() noexcept(g_Assert < 3 || g_MathematicsAssert < 3)
{
    quaternion = Quaternion{ quaternion.GetW(), quaternion.GetZ(), -quaternion.GetY(), quaternion.GetX() };

    FactorXYZ();

    auto temp = sinZ;
    sinZ = sinX;
    sinX = temp;
    sinY = -sinY;

    std::swap(cosZ, cosX);
}

#endif  // MATHEMATICS_ALGEBRA_QUATERNION_FACTOR_ACHIEVE_H
