// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/16 09:51)

#ifndef MATHEMATICS_INTERPOLATION_INTP_BSPLINE_UNIFORM2_H
#define MATHEMATICS_INTERPOLATION_INTP_BSPLINE_UNIFORM2_H

#include "Mathematics/MathematicsDll.h"

#include "IntpBSplineUniform.h"

namespace Mathematics
{
	template <typename Real>
	class  IntpBSplineUniform2 : public IntpBSplineUniform<Real>
	{
	public:
		// Construction.  IntpBSplineUniform2 accepts responsibility for
		// deleting the input array data.
		IntpBSplineUniform2(int degree, const int* dim, Real* data);

		int Index(int ix, int iy) const;

		// Spline evaluation for function interpolation (no derivatives).
		Real operator() (Real x, Real y);
		virtual Real operator() (Real* X);

		// Spline evaluation, derivative counts given in dx, dy, dx[].
		Real operator() (int dx, int dy, Real x, Real y);
		virtual Real operator() (int* dx, Real* X);

	private:
		using IntpBSplineUniform<Real>::mDegree;
		using IntpBSplineUniform<Real>::mDp1;
		using IntpBSplineUniform<Real>::mDp1ToN;
		using IntpBSplineUniform<Real>::mDim;
		using IntpBSplineUniform<Real>::mData;
		using IntpBSplineUniform<Real>::mGridMin;
		using IntpBSplineUniform<Real>::mGridMax;
		using IntpBSplineUniform<Real>::mBase;
		using IntpBSplineUniform<Real>::mOldBase;
		using IntpBSplineUniform<Real>::mMatrix;
		using IntpBSplineUniform<Real>::mCache;
		using IntpBSplineUniform<Real>::mInter;
		using IntpBSplineUniform<Real>::mPoly;
		using IntpBSplineUniform<Real>::mProduct;
		using IntpBSplineUniform<Real>::mSkip;
		using IntpBSplineUniform<Real>::mEvaluateCallback;
		using IntpBSplineUniform<Real>::SetPolynomial;

		void EvaluateUnknownData();
		void ComputeIntermediate();
	};

	using IntpBSplineUniform2f = IntpBSplineUniform2<float>;
	using IntpBSplineUniform2d = IntpBSplineUniform2<double>;

}

#endif // MATHEMATICS_INTERPOLATION_INTP_BSPLINE_UNIFORM2_H
