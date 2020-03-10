// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 18:04)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_NATURAL_SPLINE1_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_NATURAL_SPLINE1_H

#include "Mathematics/MathematicsDll.h"

namespace Mathematics
{
	template <typename Real>
	class   NaturalSpline1
	{
	public:
		// Construction and destruction.  NaturalSpline1 accepts responsibility
		// for deleting the input arrays.  Each input array must have numSamples
		// elements, where numSamples >= 2 is required.  If f(t) is the function
		// to be fit, then values[i] = f(times[i]) is the sample.  The time
		// samples must be increasing:  times[i+1] > times[i] for all i.  The
		// spline curve is referred to as S(t).  In the comments, tmin refers to
		// times[0] and tmax refers to times[numSamples-1].

		// Set free to 'true' for free splines or to 'false' for periodic
		// splines.  In the periodic case, the implementation uses f(tmin) for
		// computing coefficients.  It does not use f(tmax), which is assumed to
		// be equal to f(tmin).
		//
		// Free:  S"(tmin) = 0,  S"(tmax) = 0
		// Periodic:  S(tmin) = S(tmax), S'(tmin) = S'(tmax), S"(tmin) = S"(tmax)
		NaturalSpline1(bool free, int numSamples, Real* times, Real* values);

		// Clamped:  S'(tmin) = slopeFirst, S'(tmax) = slopeLast
		NaturalSpline1(int numSamples, Real* times, Real* values, Real slopeFirst, Real slopeLast);

		~NaturalSpline1();

		// Evaluators for S(t), S'(t), S''(t), and S'''(t).
		Real GetFunction(Real t) const;
		Real GetFirstDerivative(Real t) const;
		Real GetSecondDerivative(Real t) const;
		Real GetThirdDerivative(Real t) const;

		// Access the coefficients of the polynomials.
		int GetNumSegments() const;
		const Real* GetA() const;
		const Real* GetB() const;
		const Real* GetC() const;
		const Real* GetD() const;

	private:
		void CreateFreeSpline();
		void CreateClampedSpline(Real slopeFirst, Real slopeLast);
		void CreatePeriodicSpline();

		void GetKeyInfo(Real t, int& key, Real& dt) const;

		int mNumSamples, mNumSegments;
		Real* mTimes;

		// The cubic polynomial coefficients.  All arrays have
		// mNumSegments elements.  The i-th polynomial is
		// S_i(t) =
		//   mA[i] +
		//   mB[i]*(t - mTimes[i]) +
		//   mC[i]*(t - mTimes[i])^2 +
		//   mD[i]*(t - mTimes[i])^3
		Real* mA;
		Real* mB;
		Real* mC;
		Real* mD;
	};

	using NaturalSpline1f = NaturalSpline1<float>;
	using NaturalSpline1d = NaturalSpline1<double>;
}

#endif // MATHEMATICS_CURVES_SURFACES_VOLUMES_NATURAL_SPLINE1_H
