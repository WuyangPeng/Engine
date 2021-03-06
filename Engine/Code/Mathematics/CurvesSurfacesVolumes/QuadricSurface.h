// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/17 18:26)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_QUADRIC_SURFACE_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_QUADRIC_SURFACE_H

#include "Mathematics/MathematicsDll.h"

#include "ImplicitSurface.h"
#include "Mathematics/Rational/RationalVector3.h"

namespace Mathematics
{
	template <typename Real>
	class   QuadricSurface : public ImplicitSurface<Real>
	{
	public:
		// A quadric surface is defined implicitly by
		//
		//   0 = a0 + a1*x[0] + a2*x[1] + a3*x[2] + a4*x[0]^2 + a5*x[0]*x[1] +
		//       a6*x[0]*x[2] + a7*x[1]^2 + a8*x[1]*x[2] + a9*x[2]^2
		//
		//     = a0 + [a1 a2 a3]*X + X^T*[a4   a5/2 a6/2]*X
		//                               [a5/2 a7   a8/2]
		//                               [a6/2 a8/2 a9  ]
		//     = C + B^T*X + X^T*A*X
		//
		// The matrix A is symmetric.

		QuadricSurface();  // all coefficients zero
		QuadricSurface(const Real coeff[10]);

		// Member access.
		const Real* GetCoefficients() const;
		const Matrix3<Real>& GetA() const;
		const Vector3D<Real>& GetB() const;
		Real GetC() const;

		// The quadric function.
		virtual Real F(const Vector3D<Real>& pos) const;

		// First-order partial derivatives.
		virtual Real FX(const Vector3D<Real>& pos) const;
		virtual Real FY(const Vector3D<Real>& pos) const;
		virtual Real FZ(const Vector3D<Real>& pos) const;

		// Second-order partial derivatives.
		virtual Real FXX(const Vector3D<Real>& pos) const;
		virtual Real FXY(const Vector3D<Real>& pos) const;
		virtual Real FXZ(const Vector3D<Real>& pos) const;
		virtual Real FYY(const Vector3D<Real>& pos) const;
		virtual Real FYZ(const Vector3D<Real>& pos) const;
		virtual Real FZZ(const Vector3D<Real>& pos) const;

		enum  // solution type
		{
			QT_NONE,
			QT_POINT,
			QT_LINE,
			QT_PLANE,
			QT_TWO_PLANES,
			QT_PARABOLIC_CYLINDER,
			QT_ELLIPTIC_CYLINDER,
			QT_HYPERBOLIC_CYLINDER,
			QT_ELLIPTIC_PARABOLOID,
			QT_HYPERBOLIC_PARABOLOID,
			QT_ELLIPTIC_CONE,
			QT_HYPERBOLOID_ONE_SHEET,
			QT_HYPERBOLOID_TWO_SHEETS,
			QT_ELLIPSOID
		};

		// Classification of the equation using exact arithmetic.
		int GetType() const;

	protected:
		Real mCoeff[10];
		Matrix3<Real> mA;
		Vector3D<Real> mB;
		Real mC;

	private:
		using QRational = SignRational<4 * sizeof(Real)>;
		using QSVector = RationalVector3<4 * sizeof(Real)>;

		class RReps
		{
		public:
			RReps(const Real coeff[10]);

			// Quadratic coefficients.
			QRational A00, A01, A02, A11, A12, A22, B0, B1, B2, C;

			// 2-by-2 determinants
			QRational Sub00, Sub01, Sub02, Sub11, Sub12, Sub22;

			// Characteristic polynomial L^3 - C2*L^2 + C1*L - C0.
			QRational C0, C1, C2;

			// For Sturm sequences.
			QRational C3, C4, C5;
		};

		static void GetRootSigns(RReps& reps, int& positiveRoots, int& negativeRoots, int& zeroRoots);
		static int GetSignChanges(int quantity, const QRational* value);
		static int ClassifyZeroRoots0(const RReps& reps, int positiveRoots);
		static int ClassifyZeroRoots1(const RReps& reps, int positiveRoots);
		static int ClassifyZeroRoots1(const RReps& reps, int positiveRoots, const QSVector& P0, const QSVector& P1, const QSVector& P2);
		static int ClassifyZeroRoots2(const RReps& reps, int positiveRoots);
		static int ClassifyZeroRoots2(const RReps& reps, int positiveRoots, const QSVector& P0, const QSVector& P1, const QSVector& P2);
		static int ClassifyZeroRoots3(const RReps& reps);
	};

	using QuadricSurfacef = QuadricSurface<float>;
	using QuadricSurfaced = QuadricSurface<double>;
}

#endif // MATHEMATICS_CURVES_SURFACES_VOLUMES_QUADRIC_SURFACE_H
