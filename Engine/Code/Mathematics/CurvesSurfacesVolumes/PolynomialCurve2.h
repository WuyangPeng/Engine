// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 18:25)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_POLYNOMIAL_CURVE2_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_POLYNOMIAL_CURVE2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Polynomial.h"  
#include "SingleCurve2.h"

namespace Mathematics
{

	template <typename Real>
	class   PolynomialCurve2 : public SingleCurve2<Real>
	{
	public:
		// Construction and destruction.  PolynomialCurve2 accepts responsibility
		// for deleting the input polynomials.
		PolynomialCurve2(Polynomial<Real>* xPoly, Polynomial<Real>* yPoly);
		virtual ~PolynomialCurve2();

		int GetDegree() const;
		const Polynomial<Real>* GetXPolynomial() const;
		const Polynomial<Real>* GetYPolynomial() const;

		virtual Vector2<Real> GetPosition(Real t) const;
		virtual Vector2<Real> GetFirstDerivative(Real t) const;
		virtual Vector2<Real> GetSecondDerivative(Real t) const;
		virtual Vector2<Real> GetThirdDerivative(Real t) const;

	protected:
		Polynomial<Real>* mXPoly;
		Polynomial<Real>* mYPoly;
		Polynomial<Real> mXDer1, mYDer1;
		Polynomial<Real> mXDer2, mYDer2;
		Polynomial<Real> mXDer3, mYDer3;
	};

	using PolynomialCurve2f = PolynomialCurve2<float>;
	using PolynomialCurve2d = PolynomialCurve2<double>;
}

#endif // MATHEMATICS_CURVES_SURFACES_VOLUMES_POLYNOMIAL_CURVE2_H
