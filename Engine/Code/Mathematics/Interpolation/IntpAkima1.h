// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/16 09:46)

#ifndef MATHEMATICS_INTERPOLATION_INTP_AKIMA1_H
#define MATHEMATICS_INTERPOLATION_INTP_AKIMA1_H

#include "Mathematics/MathematicsDll.h"

namespace Mathematics
{
	template <typename Real>
	class  IntpAkima1
	{
	public:
		// Abstract base class.
		virtual ~IntpAkima1 ();

		class  Polynomial
		{
		public:
			// P(x) = c[0] + c[1]*x + c[2]*x^2 + c[3]*x^3
			inline Real& operator[] (int i) { return mCoeff[i]; }
			Real operator() (Real x) const;
			Real operator() (int order, Real x) const;

		private:
			Real mCoeff[4];
		};

		int GetQuantity () const;
		const Real* GetF () const;
		const Polynomial* GetPolynomials () const;
		const Polynomial& GetPolynomial (int i) const;

		virtual Real GetXMin () const = 0;
		virtual Real GetXMax () const = 0;

		// Evaluate the function and its derivatives.  The application is
		// responsible for ensuring that xmin <= x <= xmax.  If x is outside the
		// extremes, the function returns MAXREAL.  The first operator is for
		// function evaluation.  The second operator is for function or derivative
		// evaluations.  The uiOrder argument is the order of the derivative, zero
		// for the function itself.
		Real operator() (Real x) const;
		Real operator() (int order, Real x) const;

	protected:
		// Construction.  IntpAkima1 does not accept responsibility for
		// deleting the input array.  The application must do so.
		IntpAkima1 (int quantity, Real* F);

		Real ComputeDerivative (Real* slope) const;
		virtual bool Lookup (Real x, int& index, Real& dx) const = 0;

		int m_Quantity;
		Real* mF;
		Polynomial* mPoly;
	};

	using IntpAkima1f = IntpAkima1<float>;
	using IntpAkima1d = IntpAkima1<double>;
}

#endif // MATHEMATICS_INTERPOLATION_INTP_AKIMA1_H
