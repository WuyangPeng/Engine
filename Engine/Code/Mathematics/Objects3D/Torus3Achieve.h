/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 10:36)

#ifndef MATHEMATICS_OBJECTS_3D_TORUS3_ACHIEVE_H
#define MATHEMATICS_OBJECTS_3D_TORUS3_ACHIEVE_H

#include "Torus3.h"
#include "Torus3ParametersDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Torus3<Real>::Torus3(Real outerRadius, Real innerRadius) noexcept
    : outerRadius{ outerRadius }, innerRadius{ innerRadius }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::Torus3<Real>::IsValid() const noexcept
{
    if (MathType::GetValue(0) < innerRadius && innerRadius < outerRadius)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::Torus3<Real>::GetOuterRadius() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return outerRadius;
}

template <typename Real>
Real Mathematics::Torus3<Real>::GetInnerRadius() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return innerRadius;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::Torus3<Real>::GetPosition(Real s, Real t) const noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    MATHEMATICS_ASSERTION_1(MathType::GetValue(0) <= s && s <= MathType::GetValue(1) && MathType::GetValue(0) <= t && t <= MathType::GetValue(1), "s和t必须在0和1之间");

    const auto twoPiS = MathType::GetTwoPI() * s;
    const auto twoPiT = MathType::GetTwoPI() * t;
    const auto cosTwoPiS = MathType::Cos(twoPiS);
    const auto sinTwoPiS = MathType::Sin(twoPiS);
    const auto cosTwoPiT = MathType::Cos(twoPiT);
    const auto sinTwoPiT = MathType::Sin(twoPiT);
    const auto maxRadius = outerRadius + innerRadius * cosTwoPiT;

    return Vector3Type{ maxRadius * cosTwoPiS, maxRadius * sinTwoPiS, innerRadius * sinTwoPiT };
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::Torus3<Real>::GetNormal(Real s, Real t) const noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    MATHEMATICS_ASSERTION_1(MathType::GetValue(0) <= s && s <= MathType::GetValue(1) && MathType::GetValue(0) <= t && t <= MathType::GetValue(1), "s和t必须在0和1之间");

    const auto twoPiS = MathType::GetTwoPI() * s;
    const auto cosTwoPiS = MathType::Cos(twoPiS);
    const auto sinTwoPiS = MathType::Sin(twoPiS);
    const auto position = GetPosition(s, t);

    Vector3Type normal{ position.GetX() - outerRadius * cosTwoPiS,
                    position.GetY() - outerRadius * sinTwoPiS,
                    position.GetZ() };
    normal.Normalize();

    return normal;
}

template <typename Real>
Mathematics::Torus3Parameters<Real> Mathematics::Torus3<Real>::GetParameters(const Vector3Type& position) const noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto radius = MathType::Sqrt(position.GetX() * position.GetX() + position.GetY() * position.GetY());

    auto s = MathType::GetValue(0);

    if (MathType::GetZeroTolerance() < radius)
    {
        auto angle = MathType::ATan2(position.GetY(), position.GetX());
        if (MathType::GetValue(0) <= angle)
        {
            s = angle * MathType::GetInverseTwoPI();
        }
        else
        {
            s = MathType::GetValue(1) + angle * MathType::GetInverseTwoPI();
        }
    }

    auto diff = radius - outerRadius;

    auto t = MathType::GetValue(0);

    if (MathType::FAbs(diff) < MathType::GetZeroTolerance() && MathType::FAbs(position.GetZ()) < MathType::GetZeroTolerance())
    {
        t = MathType::GetValue(0);
    }
    else
    {
        auto angle = MathType::ATan2(position.GetZ(), diff);
        if (MathType::GetValue(0) <= angle)
        {
            t = angle * MathType::GetInverseTwoPI();
        }
        else
        {
            t = MathType::GetValue(1) + angle * MathType::GetInverseTwoPI();
        }
    }

    return Torus3ParametersType{ s, t };
}

#endif  // MATHEMATICS_OBJECTS_3D_TORUS3_ACHIEVE_H
