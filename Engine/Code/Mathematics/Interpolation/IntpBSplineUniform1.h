// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/16 09:51)

#ifndef MATHEMATICS_INTERPOLATION_INTP_BSPLINE_UNIFORM1_H
#define MATHEMATICS_INTERPOLATION_INTP_BSPLINE_UNIFORM1_H

#include "Mathematics/MathematicsDll.h"

#include "IntpBSplineUniform.h"

namespace Mathematics
{

	template <typename Real>
	class  IntpBSplineUniform1 : public IntpBSplineUniform<Real>
	{
	public:
		// Construction.  IntpBSplineUniform1 accepts responsibility for
		// deleting the input array data.
		IntpBSplineUniform1(int degree, int dim, Real* data);

		// Spline evaluation for function interpolation (no derivatives).
		Real operator() (Real x);
		virtual Real operator() (Real* X);

		// Spline evaluation, derivative count given in dx and dx[].
		Real operator() (int dx, Real x);
		virtual Real operator() (int* dx, Real* X);

	private:
		using IntpBSplineUniform<Real>::mDegree;
		using IntpBSplineUniform<Real>::mData;
		using IntpBSplineUniform<Real>::mGridMin;
		using IntpBSplineUniform<Real>::mGridMax;
		using IntpBSplineUniform<Real>::mBase;
		using IntpBSplineUniform<Real>::mOldBase;
		using IntpBSplineUniform<Real>::mMatrix;
		using IntpBSplineUniform<Real>::mInter;
		using IntpBSplineUniform<Real>::mPoly;
		using IntpBSplineUniform<Real>::mEvaluateCallback;
		using IntpBSplineUniform<Real>::SetPolynomial;

		void EvaluateUnknownData();
		void ComputeIntermediate();
	};

	using IntpBSplineUniform1f = IntpBSplineUniform1<float>;
	using IntpBSplineUniform1d = IntpBSplineUniform1<double>;

}

#endif // MATHEMATICS_INTERPOLATION_INTP_BSPLINE_UNIFORM1_H
