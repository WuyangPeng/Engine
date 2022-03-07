///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/10 16:48)

#ifndef MATHEMATICS_OBJECTS3D_TORUS3_ACHIEVE_H
#define MATHEMATICS_OBJECTS3D_TORUS3_ACHIEVE_H

#include "Torus3.h"
#include "Torus3ParametersDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

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
    if (Math::GetValue(0) < innerRadius && innerRadius < outerRadius)
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
Mathematics::Vector3<Real> Mathematics::Torus3<Real>::GetPosition(Real s, Real t) const noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    MATHEMATICS_ASSERTION_1(Math::GetValue(0) <= s && s <= Math::GetValue(1) && Math::GetValue(0) <= t && t <= Math::GetValue(1), "s和t必须在0和1之间");

    const auto twoPiS = Math::GetTwoPI() * s;
    const auto twoPiT = Math::GetTwoPI() * t;
    const auto cosTwoPiS = Math::Cos(twoPiS);
    const auto sinTwoPiS = Math::Sin(twoPiS);
    const auto cosTwoPiT = Math::Cos(twoPiT);
    const auto sinTwoPiT = Math::Sin(twoPiT);
    const auto maxRadius = outerRadius + innerRadius * cosTwoPiT;

    return Vector3{ maxRadius * cosTwoPiS, maxRadius * sinTwoPiS, innerRadius * sinTwoPiT };
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::Torus3<Real>::GetNormal(Real s, Real t) const noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    MATHEMATICS_ASSERTION_1(Math::GetValue(0) <= s && s <= Math::GetValue(1) && Math::GetValue(0) <= t && t <= Math::GetValue(1), "s和t必须在0和1之间");

    const auto twoPiS = Math::GetTwoPI() * s;
    const auto cosTwoPiS = Math::Cos(twoPiS);
    const auto sinTwoPiS = Math::Sin(twoPiS);
    const auto position = GetPosition(s, t);

    Vector3 normal{ position.GetX() - outerRadius * cosTwoPiS,
                    position.GetY() - outerRadius * sinTwoPiS,
                    position.GetZ() };
    normal.Normalize();

    return normal;
}

template <typename Real>
Mathematics::Torus3Parameters<Real> Mathematics::Torus3<Real>::GetParameters(const Vector3& position) const noexcept(g_Assert < 3 || g_MathematicsAssert < 3)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto radius = Math::Sqrt(position.GetX() * position.GetX() + position.GetY() * position.GetY());

    auto s = Math::GetValue(0);

    if (Math::GetZeroTolerance() < radius)
    {
        auto angle = Math::ATan2(position.GetY(), position.GetX());
        if (Math::GetValue(0) <= angle)
        {
            s = angle * Math::GetInverseTwoPI();
        }
        else
        {
            s = Math::GetValue(1) + angle * Math::GetInverseTwoPI();
        }
    }

    auto diff = radius - outerRadius;

    auto t = Math::GetValue(0);

    if (Math::FAbs(diff) < Math::GetZeroTolerance() && Math::FAbs(position.GetZ()) < Math::GetZeroTolerance())
    {
        t = Math::GetValue(0);
    }
    else
    {
        auto angle = Math::ATan2(position.GetZ(), diff);
        if (Math::GetValue(0) <= angle)
        {
            t = angle * Math::GetInverseTwoPI();
        }
        else
        {
            t = Math::GetValue(1) + angle * Math::GetInverseTwoPI();
        }
    }

    return Torus3Parameters{ s, t };
}

#endif  // MATHEMATICS_OBJECTS3D_TORUS3_ACHIEVE_H
