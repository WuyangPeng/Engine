// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/16 09:53)

#ifndef MATHEMATICS_INTERPOLATION_INTP_BSPLINE_UNIFORMN_H
#define MATHEMATICS_INTERPOLATION_INTP_BSPLINE_UNIFORMN_H

#include "Mathematics/MathematicsDll.h"

#include "IntpBSplineUniform.h"

namespace Mathematics
{
	template <typename Real>
	class  IntpBSplineUniformN	: public IntpBSplineUniform<Real>
	{
	public:
		// Construction and destruction.  IntpBSplineUniformN accepts
		// responsibility for deleting the input array data.  The input array
		// dim is copied.
		IntpBSplineUniformN(int dims, int degree, const int* dim, Real* data);
		virtual ~IntpBSplineUniformN();

		int Index(int* I) const;

		// Spline evaluation for function interpolation (no derivatives).
		virtual Real operator() (Real* X);

		// Spline evaluation, derivative counts given in dx[].
		virtual Real operator() (int* dx, Real* X);

	private:
		using IntpBSplineUniform<Real>::mDims;
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

		int* mEvI;
		int* mCiLoop;
		int* mCiDelta;
		int* mOpI;
		int* mOpJ;
		int* mOpDelta;

		void EvaluateUnknownData();
		void ComputeIntermediate();
	};

	using IntpBSplineUniformNf = IntpBSplineUniformN<float>;
	using IntpBSplineUniformNd = IntpBSplineUniformN<double>;
}

#endif // MATHEMATICS_INTERPOLATION_INTP_BSPLINE_UNIFORMN_H
