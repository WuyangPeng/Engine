// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/16 09:50)

#ifndef MATHEMATICS_INTERPOLATION_INTP_BSPLINE_UNIFORM_H
#define MATHEMATICS_INTERPOLATION_INTP_BSPLINE_UNIFORM_H

#include "Mathematics/MathematicsDll.h"

namespace Mathematics
{
	template <typename Real>
	class  IntpBSplineUniform
	{
	public:
		// Construction and destruction.  IntpBSplineUniform accepts
		// responsibility for deleting the input array data.  The input array
		// dim is copied.
		IntpBSplineUniform(int dims, int degree, const int* dim, Real* data);
		virtual ~IntpBSplineUniform();

		int GetDimension() const;
		int GetDegree() const;
		Real GetDomainMin(int i) const;
		Real GetDomainMax(int i) const;
		int GetGridMin(int i) const;
		int GetGridMax(int i) const;

		// spline evaluation for function interpolation (no derivatives)
		virtual Real operator() (Real* X) = 0;

		// spline evaluation, derivative counts given in dx[]
		virtual Real operator() (int* dx, Real* X) = 0;

	protected:
		int mDims;       // N, number of dimensions
		int mDegree;     // D, degree of polynomial spline
		int mDp1;        // D+1
		int mDp1ToN;     // power(D+1,N)
		int mDp1To2N;    // power(D+1,2N)
		int* mDim;       // dimension sizes dim[0] through dim[N-1]
		Real* mData;     // N-dimensional array of data
		Real* mDomMin;   // minimum allowed value of spline input vector
		Real* mDomMax;   // maximum allowed value of spline input vector
		int* mGridMin;   // minimum allowed value for current local grid
		int* mGridMax;   // maximum allowed value for current local grid
		int* mBase;      // base indices for grid of local control points
		int* mOldBase;   // old base indices for grid of local control points
		Real** mMatrix;  // (D+1)x(D+1) blending matrix
		Real* mCache;    // cache for subblock of data
		Real* mInter;    // intermediate product of data with blending matrix
		Real** mPoly;    // poly[N][D+1], store polynomials and derivatives
		Real** mCoeff;   // coefficients for polynomial construction
		Real* mProduct;  // outer tensor product of m with itself N times
		int* mSkip;      // for skipping zero values of mtensor

		Real(*mEvaluateCallback)(int);

		virtual void EvaluateUnknownData() = 0;
		virtual void ComputeIntermediate() = 0;
		void SetPolynomial(int order, Real diff, Real* poly);

		static int Choose(int n, int k);  // n choose k
		static Real** BlendMatrix(int degree);
	};

	using IntpBSplineUniformf = IntpBSplineUniform<float>;
	using IntpBSplineUniformd = IntpBSplineUniform<double>;
}

#endif // MATHEMATICS_INTERPOLATION_INTP_BSPLINE_UNIFORM_H
