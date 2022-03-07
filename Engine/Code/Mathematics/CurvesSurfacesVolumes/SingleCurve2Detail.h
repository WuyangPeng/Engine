// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 19:09)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_SINGLE_CURVE2_DETAIL_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_SINGLE_CURVE2_DETAIL_H

#include "SingleCurve2.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE1) || defined(MATHEMATICS_INCLUDED_SINGLE_CURVE2_DETAIL)

#include "Mathematics/NumericalAnalysis/RombergIntegralDetail.h"
#include "System/Helper/PragmaWarning.h" 
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26474)
template <typename Real>
Mathematics::SingleCurve2<Real>::SingleCurve2(Real tmin, Real tmax) noexcept
    : Curve2<Real>(tmin, tmax)
{
}

template <typename Real>
Real Mathematics::SingleCurve2<Real>
	::GetSpeedWithData(Real t, const SingleCurve2<Real>* data)
{
    return dynamic_cast<const Curve2<Real>*>(data)->GetSpeed(t);
}

template <typename Real>
Real Mathematics::SingleCurve2<Real>
	::GetLength(Real t0, Real t1) const
{
    MATHEMATICS_ASSERTION_0(this->mTMin <= t0 && t0 <= this->mTMax, "Invalid input\n");
    MATHEMATICS_ASSERTION_0(this->mTMin <= t1 && t1 <= this->mTMax, "Invalid input\n");
    MATHEMATICS_ASSERTION_0(t0 <= t1, "Invalid input\n");

	return RombergIntegral<Real, SingleCurve2>(8, t0, t1, GetSpeedWithData, this).GetValue();
}

template <typename Real>
Real Mathematics::SingleCurve2<Real>
	::GetTime(Real length, int iterations, Real tolerance) const
{
    if (length <= Math::GetValue(0))
    {
        return this->mTMin;
    }

    if (length >= GetTotalLength())
    {
        return this->mTMax;
    }

    // If L(t) is the length function for t in [tmin,tmax], the derivative is
    // L'(t) = |x'(t)| >= 0 (the magnitude of speed).  Therefore, L(t) is a
    // nondecreasing function (and it is assumed that x'(t) is zero only at
    // isolated points; that is, no degenerate curves allowed).  The second
    // derivative is L"(t).  If L"(t) >= 0 for all t, L(t) is a convex
    // function and Newton's method for root finding is guaranteed to
    // converge.  However, L"(t) can be negative, which can lead to Newton
    // iterates outside the domain [tmin,tmax].  The algorithm here avoids
    // this problem by using a hybrid of Newton's method and bisection.

    // Initial guess for Newton's method.
    Real ratio = length/GetTotalLength();
    Real oneMinusRatio = Math::GetValue(1) - ratio;
    Real t = oneMinusRatio* this->mTMin + ratio* this->mTMax;

    // Initial root-bounding interval for bisection.
    Real lower = this->mTMin, upper = this->mTMax;

    for (int i = 0; i < iterations; ++i)
    {
        Real difference = GetLength(this->mTMin, t) - length;
        if (Math::FAbs(difference) < tolerance)
        {
            // |L(t)-length| is close enough to zero, report t as the time
            // at which 'length' is attained.
            return t;
        }

        // Generate a candidate for Newton's method.
        Real tCandidate = t - difference/GetSpeed(t);

        // Update the root-bounding interval and test for containment of the
        // candidate.
        if (difference > Math::GetValue(0))
        {
            upper = t;
            if (tCandidate <= lower)
            {
                // Candidate is outside the root-bounding interval.  Use
                // bisection instead.
                t = (Real{0.5})*(upper + lower);
            }
            else
            {
                // There is no need to compare to 'upper' because the tangent
                // line has positive slope, guaranteeing that the t-axis
                // intercept is smaller than 'upper'.
                t = tCandidate;
            }
        }
        else
        {
            lower = t;
            if (tCandidate >= upper)
            {
                // Candidate is outside the root-bounding interval.  Use
                // bisection instead.
                t = (Real{0.5})*(upper + lower);
            }
            else
            {
                // There is no need to compare to 'lower' because the tangent
                // line has positive slope, guaranteeing that the t-axis
                // intercept is larger than 'lower'.
                t = tCandidate;
            }
        }
    }

    // A root was not found according to the specified number of iterations
    // and tolerance.  You might want to increase iterations or tolerance or
    // integration accuracy.  However, in this application it is likely that
    // the time values are oscillating, due to the limited numerical
    // precision of 32-bit floats.  It is safe to use the last computed time.
    return t;
}
#include STSTEM_WARNING_POP
#endif // !defined(MATHEMATICS_EXPORT_TEMPLATE1) || defined(MATHEMATICS_INCLUDED_SINGLE_CURVE2_DETAIL)

#endif // MATHEMATICS_CURVES_SURFACES_VOLUMES_SINGLE_CURVE2_DETAIL_H