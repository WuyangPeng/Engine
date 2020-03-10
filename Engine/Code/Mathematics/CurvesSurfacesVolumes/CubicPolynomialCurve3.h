// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 18:00)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_CUBIC_POLYNOMIAL_CURVE3_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_CUBIC_POLYNOMIAL_CURVE3_H

#include "Mathematics/MathematicsDll.h"

#include "PolynomialCurve3.h"

namespace Mathematics
{
	template <typename Real>
	class  CubicPolynomialCurve3: public PolynomialCurve3<Real>
	{
	public:
		// Construction and destruction.  CubicPolynomialCurve3 accepts
		// responsibility for deleting the input polynomials.
		CubicPolynomialCurve3(Polynomial<Real>* xPoly, Polynomial<Real>* yPoly, Polynomial<Real>* zPoly);

		virtual ~CubicPolynomialCurve3();

		// Tessellation data.
		int GetNumVertices() const;
		const Vector3D<Real>* GetVertices() const;
		Vector3D<Real>* GetVertices();

		// Tessellation by recursive subdivision.
		void Tessellate(int level);

	protected:
		using PolynomialCurve3<Real>::mTMin;
		using PolynomialCurve3<Real>::mTMax;
		using PolynomialCurve3<Real>::GetPosition;
		using PolynomialCurve3<Real>::GetSecondDerivative;

		// Support for precomputation.
		class  IntervalParameters
		{
		public:
			int I0, I1;
			Vector3D<Real> Xuu[2];
		};

		// Subdivide curve into two halves.
		void Subdivide(int level, Real dsqr, Vector3D<Real>* X,
			IntervalParameters& IP);

		// Tessellation data.
		int mNumVertices;
		Vector3D<Real>* mVertices;
	};

	using CubicPolynomialCurve3f = CubicPolynomialCurve3<float>;
	using CubicPolynomialCurve3d = CubicPolynomialCurve3<double>;
}

#endif // MATHEMATICS_CURVES_SURFACES_VOLUMES_CUBIC_POLYNOMIAL_CURVE3_H
