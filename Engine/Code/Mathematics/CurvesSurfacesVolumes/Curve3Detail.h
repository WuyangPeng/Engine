///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/13 15:21)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_CURVE3_DETAIL_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_CURVE3_DETAIL_H

#include "Curve3.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_CURVE3_DETAIL)

    #include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
    #include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
    #include "Mathematics/Algebra/Vector3Tools.h"

template <typename Real>
Mathematics::Curve3<Real>::Curve3(Real tmin, Real tmax) noexcept
    : tMin{ tmin }, tMax{ tmax }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

    #ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::Curve3<Real>::IsValid() const noexcept
{
    return true;
}

    #endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::Curve3<Real>::GetMinTime() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return tMin;
}

template <typename Real>
Real Mathematics::Curve3<Real>::GetMaxTime() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return tMax;
}

template <typename Real>
void Mathematics::Curve3<Real>::SetTimeInterval(Real tmin, Real tmax)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    MATHEMATICS_ASSERTION_0(tmin < tmax, "时间间隔无效。\n");
    tMin = tmin;
    tMax = tmax;
}

template <typename Real>
Real Mathematics::Curve3<Real>::GetSpeed(Real t) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto velocity = GetFirstDerivative(t);
    const auto speed = Vector3Tools<Real>::GetLength(velocity);

    return speed;
}

template <typename Real>
Real Mathematics::Curve3<Real>::GetTotalLength() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return GetLength(tMin, tMax);
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::Curve3<Real>::GetTangent(Real t) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto velocity = GetFirstDerivative(t);
    velocity.Normalize();

    return velocity;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::Curve3<Real>::GetNormal(Real t) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto velocity = GetFirstDerivative(t);
    const auto acceleration = GetSecondDerivative(t);
    auto vDotV = Vector3Tools<Real>::DotProduct(velocity, velocity);
    auto vDotA = Vector3Tools<Real>::DotProduct(velocity, acceleration);
    auto normal = vDotV * acceleration - vDotA * velocity;
    normal.Normalize();

    return normal;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::Curve3<Real>::GetBinormal(Real t) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto velocity = GetFirstDerivative(t);
    const auto acceleration = GetSecondDerivative(t);
    auto vDotV = Vector3Tools<Real>::DotProduct(velocity, velocity);
    auto vDotA = Vector3Tools<Real>::DotProduct(velocity, acceleration);
    auto normal = vDotV * acceleration - vDotA * velocity;
    normal.Normalize();
    velocity.Normalize();
    auto binormal = Vector3Tools<Real>::CrossProduct(velocity, normal);

    return binormal;
}

template <typename Real>
void Mathematics::Curve3<Real>::GetFrame(Real t, Vector3<Real>& position, Vector3<Real>& tangent, Vector3<Real>& normal, Vector3<Real>& binormal) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    position = GetPosition(t);
    auto velocity = GetFirstDerivative(t);
    const auto acceleration = GetSecondDerivative(t);
    auto vDotV = Vector3Tools<Real>::DotProduct(velocity, velocity);
    auto vDotA = Vector3Tools<Real>::DotProduct(velocity, acceleration);
    normal = vDotV * acceleration - vDotA * velocity;
    normal.Normalize();
    tangent = velocity;
    tangent.Normalize();
    binormal = Vector3Tools<Real>::CrossProduct(tangent, normal);
}

template <typename Real>
Real Mathematics::Curve3<Real>::GetCurvature(Real t) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto velocity = GetFirstDerivative(t);
    auto speedSqr = Vector3Tools<Real>::GetLengthSquared(velocity);

    if (speedSqr >= Math<Real>::GetZeroTolerance())
    {
        const auto acceleration = GetSecondDerivative(t);
        const auto cross = Vector3Tools<Real>::CrossProduct(velocity, acceleration);
        auto numer = Vector3Tools<Real>::GetLength(cross);
        auto denom = Math<Real>::Pow(speedSqr, static_cast<Real>(1.5));
        return numer / denom;
    }
    else
    {
        return Math<Real>::GetValue(0);
    }
}

template <typename Real>
Real Mathematics::Curve3<Real>::GetTorsion(Real t) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto velocity = GetFirstDerivative(t);
    const auto acceleration = GetSecondDerivative(t);
    const auto cross = Vector3Tools<Real>::CrossProduct(velocity, acceleration);
    auto denom = Vector3Tools<Real>::GetLengthSquared(cross);

    if (denom >= Math<Real>::GetZeroTolerance())
    {
        const auto jerk = GetThirdDerivative(t);
        auto numer = Vector3Tools<Real>::DotProduct(cross, jerk);
        return numer / denom;
    }
    else
    {
        return Math<Real>::GetValue(0);
    }
}

template <typename Real>
std::vector<Mathematics::Vector3<Real>> Mathematics::Curve3<Real>::SubdivideByTime(int numPoints) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    MATHEMATICS_ASSERTION_0(numPoints >= 2, "Subdivision 至少需要两点。\n");
    std::vector<Vector3<Real>> points{};

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
std::vector<Mathematics::Vector3<Real>> Mathematics::Curve3<Real>::SubdivideByLength(int numPoints) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    MATHEMATICS_ASSERTION_0(numPoints >= 2, "Subdivision 至少需要两点。\n");
    std::vector<Mathematics::Vector3<Real>> points{};

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

#endif  // !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_CURVE3_DETAIL)

#endif  // MATHEMATICS_CURVES_SURFACES_VOLUMES_CURVE3_DETAIL_H