///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 11:02)

#ifndef MATHEMATICS_ALGEBRA_QUATERNION_FACTOR_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_QUATERNION_FACTOR_ACHIEVE_H

#include "Quaternion.h"
#include "QuaternionFactor.h"
#include "Flags/QuaternionFlags.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::QuaternionFactor<Real>::QuaternionFactor(const QuaternionType& quaternion, QuaternionFactorFlags flag) noexcept(gAssert < 1 || gMathematicsAssert < 1)
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
requires std::is_arithmetic_v<Real> bool Mathematics::QuaternionFactor<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::QuaternionFactor<Real>::GetSinX() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return sinX;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::QuaternionFactor<Real>::GetSinY() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return sinY;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::QuaternionFactor<Real>::GetSinZ() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return sinZ;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::QuaternionFactor<Real>::GetCosX() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return cosX;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::QuaternionFactor<Real>::GetCosY() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return cosY;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::QuaternionFactor<Real>::GetCosZ() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return cosZ;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::QuaternionFactor<Real>::FactorXYZ() noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    const auto a = quaternion.GetW() * quaternion.GetX() - quaternion.GetY() * quaternion.GetZ();
    const auto b = MathType::GetRational(1, 2) * (quaternion.GetW() * quaternion.GetW() - quaternion.GetX() * quaternion.GetX() - quaternion.GetY() * quaternion.GetY() + quaternion.GetZ() * quaternion.GetZ());

    const auto length = MathType::Sqrt(a * a + b * b);

    if (MathType::GetZeroTolerance() < length)
    {
        auto sigma0 = a / length;
        auto gamma0 = b / length;

        if (MathType::GetValue(0) <= gamma0)
        {
            cosX = MathType::Sqrt(MathType::GetRational(1, 2) * (MathType::GetValue(1) + gamma0));
            sinX = MathType::GetRational(1, 2) * sigma0 / cosX;
        }
        else
        {
            sinX = MathType::Sqrt(MathType::GetRational(1, 2) * (MathType::GetValue(1) - gamma0));
            cosX = MathType::GetRational(1, 2) * sigma0 / sinX;
        }

        auto tmp0 = cosX * quaternion.GetW() + sinX * quaternion.GetX();
        auto tmp1 = cosX * quaternion.GetZ() - sinX * quaternion.GetY();
        auto invLength = MathType::InvSqrt(tmp0 * tmp0 + tmp1 * tmp1);
        cosZ = tmp0 * invLength;
        sinZ = tmp1 * invLength;

        if (MathType::FAbs(sinZ) <= MathType::FAbs(cosZ))
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
        if (MathType::GetValue(0) < quaternion.GetW() * quaternion.GetY() + quaternion.GetX() * quaternion.GetZ())
        {
            // p = (p0,p1,p0,p1)
            cosX = MathType::GetValue(1);
            sinX = MathType::GetValue(0);
            cosY = MathType::GetInverseSqrt2();
            sinY = MathType::GetInverseSqrt2();
            cosZ = MathType::GetSqrt2() * quaternion.GetW();
            sinZ = MathType::GetSqrt2() * quaternion.GetX();
        }
        else
        {
            // p = (p0,p1,-p0,-p1)
            cosX = MathType::GetValue(1);
            sinX = MathType::GetValue(0);
            cosY = MathType::GetInverseSqrt2();
            sinY = -MathType::GetInverseSqrt2();
            cosZ = MathType::GetSqrt2() * quaternion.GetW();
            sinZ = -MathType::GetSqrt2() * quaternion.GetX();
        }
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::QuaternionFactor<Real>::FactorXZY() noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    quaternion = QuaternionType{ quaternion.GetW(), quaternion.GetX(), quaternion.GetZ(), -quaternion.GetY() };

    FactorXYZ();

    auto temp = sinY;
    sinY = -sinZ;
    sinZ = temp;

    std::swap(cosY, cosZ);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::QuaternionFactor<Real>::FactorYZX() noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    quaternion = QuaternionType{ quaternion.GetW(), -quaternion.GetY(), quaternion.GetZ(), -quaternion.GetX() };

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
requires std::is_arithmetic_v<Real>
void Mathematics::QuaternionFactor<Real>::FactorYXZ() noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    quaternion = QuaternionType{ quaternion.GetW(), -quaternion.GetY(), quaternion.GetX(), quaternion.GetZ() };

    FactorXYZ();

    auto temp = sinY;
    sinY = -sinX;
    sinX = temp;

    std::swap(cosY, cosX);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::QuaternionFactor<Real>::FactorZXY() noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    quaternion = QuaternionType{ quaternion.GetW(), -quaternion.GetZ(), quaternion.GetX(), -quaternion.GetY() };

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
requires std::is_arithmetic_v<Real>
void Mathematics::QuaternionFactor<Real>::FactorZYX() noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    quaternion = QuaternionType{ quaternion.GetW(), quaternion.GetZ(), -quaternion.GetY(), quaternion.GetX() };

    FactorXYZ();

    auto temp = sinZ;
    sinZ = sinX;
    sinX = temp;
    sinY = -sinY;

    std::swap(cosZ, cosX);
}

#endif  // MATHEMATICS_ALGEBRA_QUATERNION_FACTOR_ACHIEVE_H
