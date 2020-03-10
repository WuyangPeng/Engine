// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 17:56)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_CURVE_FIT_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_CURVE_FIT_H

#include "Mathematics/MathematicsDll.h"

#include "BSplineFitBasis.h"

namespace Mathematics
{
	template <typename Real>
	class BSplineCurveFit
	{
	public:
		// Construction and destruction.  The preconditions for calling the
		// constructor are
		//   1 <= degree && degree < numControls <= numSamples
		// The samples point are contiguous blocks of dimension real value
		// stored in sampleData.

		BSplineCurveFit(int dimension, int numSamples, const Real* sampleData, int degree, int numControls);
		~BSplineCurveFit();

		// Access to input sample information.
		int GetDimension() const;
		int GetSampleQuantity() const;
		const Real* GetSampleData() const;

		// Access to output control point and curve information.
		int GetDegree() const;
		int GetControlQuantity() const;
		const Real* GetControlData() const;
		const BSplineFitBasis<Real>& GetBasis() const;

		// Evaluation of the B-spline curve.  It is defined for 0 <= t <= 1.  If
		// a t-value is outside [0,1], an open spline clamps it to [0,1].  The
		// caller must ensure that position[] has (at least) 'dimension'
		// elements.
		void GetPosition(Real t, Real* position) const;

	private:
		// Input sample information.
		int mDimension;
		int mNumSamples;
		const Real* mSampleData;

		// The fitted B-spline curve, open and with uniform knots.
		int mDegree;
		int mNumControls;
		Real* mControlData;
		BSplineFitBasis<Real> mBasis;
	};

	using BSplineCurveFitf = BSplineCurveFit<float>;
	using BSplineCurveFitd = BSplineCurveFit<double>;
}


#endif // MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_CURVE_FIT_H
