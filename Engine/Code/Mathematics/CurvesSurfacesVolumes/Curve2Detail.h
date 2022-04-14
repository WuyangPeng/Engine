///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/13 15:02)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_CURVE2_DETAIL_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_CURVE2_DETAIL_H

#include "Curve2.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_CURVE2_DETAIL)

    #include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
    #include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
    #include "Mathematics/Algebra/Vector2Tools.h"

template <typename Real>
Mathematics::Curve2<Real>::Curve2(Real tmin, Real tmax) noexcept
    : tMin{ tmin }, tMax{ tmax }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

    #ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::Curve2<Real>::IsValid() const noexcept
{
    return true;
}

    #endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::Curve2<Real>::GetMinTime() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return tMin;
}

template <typename Real>
Real Mathematics::Curve2<Real>::GetMaxTime() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return tMax;
}

template <typename Real>
void Mathematics::Curve2<Real>::SetTimeInterval(Real tmin, Real tmax)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    MATHEMATICS_ASSERTION_0(tmin < tmax, "时间间隔无效。\n");

    tMin = tmin;
    tMax = tmax;
}

template <typename Real>
Real Mathematics::Curve2<Real>::GetSpeed(Real t) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto velocity = GetFirstDerivative(t);
    const auto speed = Vector2Tools<Real>::GetLength(velocity);

    return speed;
}

template <typename Real>
Real Mathematics::Curve2<Real>::GetTotalLength() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return GetLength(tMin, tMax);
}

template <typename Real>
Mathematics::Vector2<Real> Mathematics::Curve2<Real>::GetTangent(Real t) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto velocity = GetFirstDerivative(t);
    velocity.Normalize();

    return velocity;
}

template <typename Real>
Mathematics::Vector2<Real> Mathematics::Curve2<Real>::GetNormal(Real t) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto tangent = GetFirstDerivative(t);
    tangent.Normalize();
    const auto normal = Vector2Tools<Real>::GetPerp(tangent);

    return normal;
}

template <typename Real>
void Mathematics::Curve2<Real>::GetFrame(Real t, Vector2<Real>& position, Vector2<Real>& tangent, Vector2<Real>& normal) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    position = GetPosition(t);
    tangent = GetFirstDerivative(t);
    tangent.Normalize();
    normal = Vector2Tools<Real>::GetPerp(tangent);
}

template <typename Real>
Real Mathematics::Curve2<Real>::GetCurvature(Real t) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto der1 = GetFirstDerivative(t);
    const auto der2 = GetSecondDerivative(t);
    auto speedSqr = Vector2Tools<Real>::GetLengthSquared(der1);

    if (speedSqr >= Math<Real>::GetZeroTolerance())
    {
        auto numer = Vector2Tools<Real>::DotPerp(der1, der2);
        auto denom = Math<Real>::Pow(speedSqr, Math<Real>::GetRational(3, 2));

        return numer / denom;
    }
    else
    {
        return Math<Real>::GetValue(0);
    }
}

template <typename Real>
std::vector<Mathematics::Vector2<Real>> Mathematics::Curve2<Real>::SubdivideByTime(int numPoints) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    MATHEMATICS_ASSERTION_0(numPoints >= 2, "Subdivision 至少需要两点。\n");
    std::vector<Mathematics::Vector2<Real>> points{};

    const auto temp1 = tMax - tMin;
    const auto temp2 = numPoints - 1;
    const auto delta = (temp1) / (temp2);

    for (auto i = 0; i < numPoints; ++i)
    {
        auto t = tMin + delta * i;
        points.emplace_back(GetPosition(t));
    }

    return points;
}

template <typename Real>
std::vector<Mathematics::Vector2<Real>> Mathematics::Curve2<Real>::SubdivideByLength(int numPoints) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    MATHEMATICS_ASSERTION_0(numPoints >= 2, "Subdivision 至少需要两点。\n");
    std::vector<Mathematics::Vector2<Real>> points{};

    const auto temp = numPoints - 1;
    auto delta = GetTotalLength() / (temp);

    for (auto i = 0; i < numPoints; ++i)
    {
        auto length = delta * i;
        auto t = GetTime(length);
        points.emplace_back(GetPosition(t));
    }

    return points;
}

#endif  // !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_CURVE2_DETAIL)

#endif  // MATHEMATICS_CURVES_SURFACES_VOLUMES_CURVE2_DETAIL_H