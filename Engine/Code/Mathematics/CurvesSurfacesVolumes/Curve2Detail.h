// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 18:51)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_CURVE2_DETAIL_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_CURVE2_DETAIL_H

#include "Curve2.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE1) || defined(MATHEMATICS_INCLUDED_CURVE2_DETAIL)
    #include "System/Helper/PragmaWarning.h"
    #include STSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26429)
    #include SYSTEM_WARNING_DISABLE(26481)

    #include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
    #include "Mathematics/Algebra/Vector2Tools.h"

template <typename Real>
Mathematics::Curve2<Real>::Curve2(Real tmin, Real tmax) noexcept
    : mTMin{ tmin }, mTMax{ tmax }
{
}

template <typename Real>
Mathematics::Curve2<Real>::~Curve2() noexcept
{
}

template <typename Real>
Real Mathematics::Curve2<Real>::GetMinTime() const noexcept
{
    return mTMin;
}

template <typename Real>
Real Mathematics::Curve2<Real>::GetMaxTime() const noexcept
{
    return mTMax;
}

template <typename Real>
void Mathematics::Curve2<Real>::SetTimeInterval(Real tmin, Real tmax)
{
    MATHEMATICS_ASSERTION_0(tmin < tmax, "Invalid time interval\n");
    mTMin = tmin;
    mTMax = tmax;
}

template <typename Real>
Real Mathematics::Curve2<Real>::GetSpeed(Real t) const
{
    const Vector2<Real> velocity = GetFirstDerivative(t);
    const Real speed = Vector2Tools<Real>::GetLength(velocity);
    return speed;
}

template <typename Real>
Real Mathematics::Curve2<Real>::GetTotalLength() const
{
    return GetLength(mTMin, mTMax);
}

template <typename Real>
Mathematics::Vector2<Real> Mathematics::Curve2<Real>::GetTangent(Real t) const
{
    auto velocity = GetFirstDerivative(t);
    velocity.Normalize();
    return velocity;
}

template <typename Real>
Mathematics::Vector2<Real> Mathematics::Curve2<Real>::GetNormal(Real t) const
{
    auto tangent = GetFirstDerivative(t);
    tangent.Normalize();
    auto normal = Vector2Tools<Real>::GetPerp(tangent);
    return normal;
}

template <typename Real>
void Mathematics::Curve2<Real>::GetFrame(Real t, Vector2<Real>& position, Vector2<Real>& tangent, Vector2<Real>& normal) const
{
    position = GetPosition(t);
    tangent = GetFirstDerivative(t);
    tangent.Normalize();
    normal = Vector2Tools<Real>::GetPerp(tangent);
}

template <typename Real>
Real Mathematics::Curve2<Real>::GetCurvature(Real t) const
{
    const auto der1 = GetFirstDerivative(t);
    const auto der2 = GetSecondDerivative(t);
    auto speedSqr = Vector2Tools<Real>::GetLengthSquared(der1);

    if (speedSqr >= Math<Real>::GetZeroTolerance())
    {
        auto numer = Vector2Tools<Real>::DotPerp(der1, der2);
        auto denom = Math<Real>::Pow(speedSqr, static_cast<Real>(1.5));
        return numer / denom;
    }
    else
    {
        // Curvature is indeterminate, just return 0.
        return Math<Real>::GetValue(0);
    }
}

template <typename Real>
void Mathematics::Curve2<Real>::SubdivideByTime(int numPoints, Vector2<Real>*& points) const
{
    MATHEMATICS_ASSERTION_0(numPoints >= 2, "Subdivision requires at least two points\n");
    points = nullptr;  //NEW1<Vector2<Real>>(numPoints);

    const auto temp1 = mTMax - mTMin;
    const auto temp2 = numPoints - 1;
    const auto delta = (temp1) / (temp2);

    for (auto i = 0; i < numPoints; ++i)
    {
        auto t = mTMin + delta * i;
        points[i] = GetPosition(t);
    }
}

template <typename Real>
void Mathematics::Curve2<Real>::SubdivideByLength(int numPoints, Vector2<Real>*& points) const
{
    MATHEMATICS_ASSERTION_0(numPoints >= 2, "Subdivision requires at least two points\n");
    points = nullptr;  // NEW1<Vector2<Real>>(numPoints);

    const auto temp = numPoints - 1;
    auto delta = GetTotalLength() / (temp);

    for (auto i = 0; i < numPoints; ++i)
    {
        auto length = delta * i;
        auto t = GetTime(length);
        points[i] = GetPosition(t);
    }
}
    #include STSTEM_WARNING_POP
#endif  // !defined(MATHEMATICS_EXPORT_TEMPLATE1) || defined(MATHEMATICS_INCLUDED_CURVE2_DETAIL)

#endif  // MATHEMATICS_CURVES_SURFACES_VOLUMES_CURVE2_DETAIL_H