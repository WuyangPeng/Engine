// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/16 09:47)

#ifndef MATHEMATICS_INTERPOLATION_INTP_AKIMA_UNIFORM2_H
#define MATHEMATICS_INTERPOLATION_INTP_AKIMA_UNIFORM2_H

#include "Mathematics/MathematicsDll.h"

namespace Mathematics
{
	template <typename Real>
	class  IntpAkimaUniform2
	{
	public:
		// Construction and destruction.  IntpAkimaUniform2 does not accept
		// responsibility for deleting the input array.  The application must do
		// so.  The interpolator is for uniformly spaced (x,y)-values.  The
		// function values are assumed to be organized as f(x,y) = F[y][x].
		IntpAkimaUniform2(int xBound, int yBound, Real xMin, Real xSpacing,
			Real yMin, Real ySpacing, Real** F);

		~IntpAkimaUniform2();

		class  Polynomial
		{
		public:
			Polynomial();

			// P(x,y) = (1,x,x^2,x^3)*A*(1,y,y^2,y^3).  The matrix term A[ix][iy]
			// corresponds to the polynomial term x^{ix} y^{iy}.
			Real& A(int ix, int iy);

			Real operator() (Real x, Real y) const;
			Real operator() (int xOrder, int yOrder, Real x, Real y) const;

		protected:
			Real mCoeff[4][4];
		};

		int GetXBound() const;
		int GetYBound() const;
		int GetQuantity() const;
		Real** GetF() const;
		Polynomial** GetPolynomials() const;
		const Polynomial& GetPolynomial(int ix, int iy) const;

		Real GetXMin() const;
		Real GetXMax() const;
		Real GetXSpacing() const;
		Real GetYMin() const;
		Real GetYMax() const;
		Real GetYSpacing() const;

		// Evaluate the function and its derivatives.  The application is
		// responsible for ensuring that xmin <= x <= xmax and ymin <= y <= ymax.
		// If (x,y) is outside the extremes, the function returns MAXREAL.  The
		// first operator is for function evaluation.  The second operator is for
		// function or derivative evaluations.  The uiXOrder argument is the order
		// of the x-derivative and the uiYOrder argument is the order of the
		// y-derivative.  Both orders are zero to get the function value itself.
		Real operator() (Real x, Real y) const;
		Real operator() (int xOrder, int yOrder, Real x, Real y) const;

	private:
		Real ComputeDerivative(Real* slope) const;
		void Construct(Polynomial& poly, Real F[2][2], Real FX[2][2],
			Real FY[2][2], Real FXY[2][2]);

		bool XLookup(Real x, int& xIndex, Real& dx) const;
		bool YLookup(Real y, int& yIndex, Real& dy) const;

		int mXBound, mYBound, quantity;
		Real** mF;
		Polynomial** mPoly;
		Real mXMin, mXMax, mXSpacing;
		Real mYMin, mYMax, mYSpacing;
	};

	using IntpAkimaUniform2f = IntpAkimaUniform2<float>;
	using IntpAkimaUniform2d = IntpAkimaUniform2<double>;
}

#endif // MATHEMATICS_INTERPOLATION_INTP_AKIMA_UNIFORM2_H
