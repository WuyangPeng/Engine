// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/16 09:52)

#ifndef MATHEMATICS_INTERPOLATION_INTP_BSPLINE_UNIFORM3_H
#define MATHEMATICS_INTERPOLATION_INTP_BSPLINE_UNIFORM3_H

#include "Mathematics/MathematicsDll.h"

#include "IntpBSplineUniform.h"

namespace Mathematics
{
	template <typename Real>
	class  IntpBSplineUniform3 : public IntpBSplineUniform<Real>
	{
	public:
		// Construction.  IntpBSplineUniform3 accepts responsibility for
		// deleting the input array data.
		IntpBSplineUniform3(int degree, const int* dim, Real* data);

		int Index(int ix, int iy, int iz) const;

		// Spline evaluation for function interpolation (no derivatives).
		Real operator() (Real x, Real y, Real z);
		virtual Real operator() (Real* X);

		// Spline evaluation, derivative counts given in dx, dy, dz, dx[].
		Real operator() (int dx, int dy, int dz, Real x, Real y, Real z);
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

	using IntpBSplineUniform3f = IntpBSplineUniform3<float>;
	using IntpBSplineUniform3d = IntpBSplineUniform3<double>;

}

#endif // MATHEMATICS_INTERPOLATION_INTP_BSPLINE_UNIFORM3_H
