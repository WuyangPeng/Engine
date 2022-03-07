// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 18:25)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_POLYNOMIAL_CURVE3_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_POLYNOMIAL_CURVE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Polynomial.h"  
#include "SingleCurve3.h"

namespace Mathematics
{
	template <typename Real>
	class  PolynomialCurve3 : public SingleCurve3<Real>
	{
	public:
		// Construction and destruction.  PolynomialCurve3 accepts responsibility
		// for deleting the input polynomials.
		PolynomialCurve3(Polynomial<Real>* xPoly, Polynomial<Real>* yPoly, Polynomial<Real>* zPoly);

		virtual ~PolynomialCurve3();

		int GetDegree() const;
		const Polynomial<Real>* GetXPolynomial() const;
		const Polynomial<Real>* GetYPolynomial() const;
		const Polynomial<Real>* GetZPolynomial() const;

		virtual Vector3<Real> GetPosition(Real t) const;
		virtual Vector3<Real> GetFirstDerivative(Real t) const;
		virtual Vector3<Real> GetSecondDerivative(Real t) const;
		virtual Vector3<Real> GetThirdDerivative(Real t) const;

	protected:
		Polynomial<Real>* mXPoly;
		Polynomial<Real>* mYPoly;
		Polynomial<Real>* mZPoly;
		Polynomial<Real> mXDer1, mYDer1, mZDer1;
		Polynomial<Real> mXDer2, mYDer2, mZDer2;
		Polynomial<Real> mXDer3, mYDer3, mZDer3;
	};

	using PolynomialCurve3f = PolynomialCurve3<float>;
	using PolynomialCurve3d = PolynomialCurve3<double>;
}

#endif // MATHEMATICS_CURVES_SURFACES_VOLUMES_POLYNOMIAL_CURVE3_H
