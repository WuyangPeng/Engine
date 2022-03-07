// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/16 09:55)

#ifndef MATHEMATICS_INTERPOLATION_INTP_THIN_PLATE_SPLINE3_H
#define MATHEMATICS_INTERPOLATION_INTP_THIN_PLATE_SPLINE3_H

// WARNING.  The implementation allows you to transform the inputs (x,y,z) to
// the unit cube and perform the interpolation in that space.  The idea is
// to keep the floating-point numbers to order 1 for numerical stability of
// the algorithm.  The classical thin-plate spline algorithm does not include
// this transformation.  The interpolation is invariant to translations and
// rotations of (x,y,z) but not to scaling.

#include "Mathematics/MathematicsDll.h"

namespace Mathematics
{
	template <typename Real>
	class  IntpThinPlateSpline3
	{
	public:
		// Construction and destruction.  Data points are (x,y,z,f(x,y,z)).  The
		// smoothing parameter must be nonnegative.  If you want the class to
		// delete the input arrays during destruction, set owner to 'true';
		// otherwise, you own the arrays and must delete them yourself.
		IntpThinPlateSpline3(int quantity, Real* X, Real* Y, Real* Z,Real* F, Real smooth, bool owner, bool transformToUnitCube);

		~IntpThinPlateSpline3();

		// Check this after the constructor call to see if the thin plate spline
		// coefficients were successfully computed.  If so, then calls to
		// operator()(Real,Real,Real) will work properly.
		bool IsInitialized() const;

		// Member access.  There are 'quantity' A[] coefficients and 4 B[]
		// coefficients.  The A[] coefficients are associated with the Green's
		// functions G(x,y,z,*) and the B[] coefficients are associated with the
		// affine term (linear polynomial B[0]+B[1]*x+B[2]*y+B[3]*z).
		const Real* GetACoefficients() const;
		const Real* GetBCoefficients() const;
		Real GetSmooth() const;  // The smoothing parameter from the constructor.

		// Compute the functional value a^T*M*a when lambda is zero or
		// lambda*w^T*(M+lambda*I)*w when lambda is positive.  See the thin-plate
		// splines PDF for a description of these quantities.
		Real ComputeFunctional() const;

		// Evaluate the thin plate spline interpolator.  If IsInitialized()
		// returns 'false', this operator will always return MAX_REAL.
		Real operator() (Real x, Real y, Real z);

		// Kernel(t) = |t|
		static Real Kernel(Real t);

	private:
		bool mInitialized;
		int quantity;

		// Input data.
		Real* mX;
		Real* mY;
		Real* mZ;
		Real mSmooth;

		// Thin plate spline coefficients.
		Real* mA;
		Real mB[4];

		// Extent of input data.
		Real mXMin, mXMax, mXInvRange;
		Real mYMin, mYMax, mYInvRange;
		Real mZMin, mZMax, mZInvRange;
	};

	using IntpThinPlateSpline3f = IntpThinPlateSpline3<float>;
	using IntpThinPlateSpline3d = IntpThinPlateSpline3<double>;
}

#endif // MATHEMATICS_INTERPOLATION_INTP_THIN_PLATE_SPLINE3_H
