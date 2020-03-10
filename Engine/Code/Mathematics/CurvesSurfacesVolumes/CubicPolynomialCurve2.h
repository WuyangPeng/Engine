// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 17:59)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_CUBIC_POLYNOMIAL_CURVE2_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_CUBIC_POLYNOMIAL_CURVE2_H

#include "Mathematics/MathematicsDll.h"

#include "PolynomialCurve2.h"

namespace Mathematics
{
	template <typename Real>
	class   CubicPolynomialCurve2: public PolynomialCurve2<Real>
	{
	public:
		// Construction and destruction.  CubicPolynomialCurve2 accepts
		// responsibility for deleting the input polynomials.
		CubicPolynomialCurve2(Polynomial<Real>* xPoly, Polynomial<Real>* yPoly);
		virtual ~CubicPolynomialCurve2();

		// Tessellation data.
		int GetNumVertices() const;
		const Vector2D<Real>* GetVertices() const;
		Vector2D<Real>* GetVertices();

		// Tessellation by recursive subdivision.
		void Tessellate(int level);

	protected:
		using PolynomialCurve2<Real>::mTMin;
		using PolynomialCurve2<Real>::mTMax;
		using PolynomialCurve2<Real>::GetPosition;
		using PolynomialCurve2<Real>::GetSecondDerivative;

		// Support for precomputation.
		class   IntervalParameters
		{
		public:
			int I0, I1;
			Vector2D<Real> Xuu[2];
		};

		// Subdivide curve into two halves.
		void Subdivide(int level, Real dsqr, Vector2D<Real>* X, IntervalParameters& IP);

		// Tessellation data.
		int mNumVertices;
		Vector2D<Real>* mVertices;
	};

	using CubicPolynomialCurve2f = CubicPolynomialCurve2<float>;
	using CubicPolynomialCurve2d = CubicPolynomialCurve2<double>;
}

#endif // MATHEMATICS_CURVES_SURFACES_VOLUMES_CUBIC_POLYNOMIAL_CURVE2_H
