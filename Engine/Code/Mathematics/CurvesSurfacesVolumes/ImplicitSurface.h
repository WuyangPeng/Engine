// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 18:03)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_IMPLICIT_SURFACE_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_IMPLICIT_SURFACE_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Matrix3.h"
#include "Surface.h"

namespace Mathematics
{
	template <typename Real>
	class  ImplicitSurface : public Surface<Real>
	{
	public:
		// Surface is defined by F(x,y,z) = 0.  In all member functions it is
		// the application's responsibility to ensure that (x,y,z) is a solution
		// to F = 0.

		// Abstract base class.
		virtual ~ImplicitSurface();

		// The implicit function.
		virtual Real F(const Vector3<Real>& pos) const = 0;

		// First-order partial derivatives.
		virtual Real FX(const Vector3<Real>& pos) const = 0;
		virtual Real FY(const Vector3<Real>& pos) const = 0;
		virtual Real FZ(const Vector3<Real>& pos) const = 0;

		// Second-order partial derivatives.
		virtual Real FXX(const Vector3<Real>& pos) const = 0;
		virtual Real FXY(const Vector3<Real>& pos) const = 0;
		virtual Real FXZ(const Vector3<Real>& pos) const = 0;
		virtual Real FYY(const Vector3<Real>& pos) const = 0;
		virtual Real FYZ(const Vector3<Real>& pos) const = 0;
		virtual Real FZZ(const Vector3<Real>& pos) const = 0;

		// Verify point is on surface (within the tolerance specified by epsilon).
		bool IsOnSurface(const Vector3<Real>& pos, Real epsilon) const;

		// First-order derivatives.
		Vector3<Real> GetGradient(const Vector3<Real>& pos) const;

		// Second-order derivatives.
		Matrix3<Real> GetHessian(const Vector3<Real>& pos) const;

		// Compute a coordinate frame.  The set {T0,T1,N} is a right-handed
		// orthonormal set.
		void GetFrame(const Vector3<Real>& pos, Vector3<Real>& tangent0, Vector3<Real>& tangent1, Vector3<Real>& normal) const;

		// Differential geometric quantities.  The returned scalars are the
		// principal curvatures and the returned vectors are the corresponding
		// principal directions.
		bool ComputePrincipalCurvatureInfo(const Vector3<Real>& pos, Real& curv0, Real& curv1, Vector3<Real>& dir0, Vector3<Real>& dir1);

	protected:
		ImplicitSurface();
	};

	using ImplicitSurfacef = ImplicitSurface<float>;
	using ImplicitSurfaced = ImplicitSurface<double>;
}

#endif // MATHEMATICS_CURVES_SURFACES_VOLUMES_IMPLICIT_SURFACE_H
