///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/17 10:04)

#ifndef MATHEMATICS_OBJECTS3D_TORUS3_ACHIEVE_H
#define MATHEMATICS_OBJECTS3D_TORUS3_ACHIEVE_H

#include "Torus3.h"
#include "Torus3ParametersDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <typename Real>
Mathematics::Torus3<Real>::Torus3(Real outerRadius, Real innerRadius) noexcept
    : m_OuterRadius{ outerRadius }, m_InnerRadius{ innerRadius }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Torus3<Real>::IsValid() const noexcept
{
    if (Math::GetValue(0) < m_InnerRadius && m_InnerRadius < m_OuterRadius)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::Torus3<Real>::GetOuterRadius() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_OuterRadius;
}

template <typename Real>
Real Mathematics::Torus3<Real>::GetInnerRadius() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_InnerRadius;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Torus3<Real>::GetPosition(Real s, Real t) const noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    MATHEMATICS_ASSERTION_1(Math::GetValue(0) <= s && s <= Math::GetValue(1) && Math::GetValue(0) <= t && t <= Math::GetValue(1), "s和t必须在0和1之间");

    auto twoPiS = Math::GetTwoPI() * s;
    auto twoPiT = Math::GetTwoPI() * t;
    auto cosTwoPiS = Math::Cos(twoPiS);
    auto sinTwoPiS = Math::Sin(twoPiS);
    auto cosTwoPiT = Math::Cos(twoPiT);
    auto sinTwoPiT = Math::Sin(twoPiT);
    auto maxRadius = m_OuterRadius + m_InnerRadius * cosTwoPiT;

    return Vector3D{ maxRadius * cosTwoPiS, maxRadius * sinTwoPiS, m_InnerRadius * sinTwoPiT };
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Torus3<Real>::GetNormal(Real s, Real t) const noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    MATHEMATICS_ASSERTION_1(Math::GetValue(0) <= s && s <= Math::GetValue(1) && Math::GetValue(0) <= t && t <= Math::GetValue(1), "s和t必须在0和1之间");

    auto twoPiS = Math::GetTwoPI() * s;
    auto cosTwoPiS = Math::Cos(twoPiS);
    auto sinTwoPiS = Math::Sin(twoPiS);
    const auto position = GetPosition(s, t);

    Vector3D normal{ position.GetX() - m_OuterRadius * cosTwoPiS,
                     position.GetY() - m_OuterRadius * sinTwoPiS,
                     position.GetZ() };
    normal.Normalize();

    return normal;
}

template <typename Real>
const Mathematics::Torus3Parameters<Real> Mathematics::Torus3<Real>::GetParameters(const Vector3D& position) const noexcept(g_Assert < 3 || g_MathematicsAssert < 3)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    auto radius = Math::Sqrt(position.GetX() * position.GetX() + position.GetY() * position.GetY());

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

    auto diff = radius - m_OuterRadius;

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
