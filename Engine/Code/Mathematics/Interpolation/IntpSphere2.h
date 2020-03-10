// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/16 09:55)

#ifndef MATHEMATICS_INTERPOLATION_INTP_SPHERE2_H
#define MATHEMATICS_INTERPOLATION_INTP_SPHERE2_H

// Interpolation of a scalar-valued function defined on a sphere.  Although
// the sphere lives in 3D, the interpolation is a 2D method whose input
// points are angles (theta,phi) from spherical coordinates.  The domains of
// the angles are -PI <= theta <= PI and 0 <= phi <= PI.

#include "Mathematics/MathematicsDll.h"

#include "IntpQdrNonuniform2.h"

namespace Mathematics
{
	template <typename Real>
	class  IntpSphere2
	{
	public:
		// Construction and destruction.  If you want IntpSphere2 to delete the
		// input arrays during destruction, set owner to 'true'.  Otherwise, you
		// own the arrays and must delete them yourself.
		//
		// For complete spherical coverage, include the two antipodal (theta,phi)
		// points (-PI,0,F(-PI,0)) and (-PI,PI,F(-PI,PI)) in the input data.
		// These correspond to the sphere poles x = 0, y = 0, and |z| = 1.
		//
		// The computation type is for the Delaunay triangulation and should be
		// one of Query::{QT_INT64,QT_INTEGER,QT_RATIONAL,QT_REAL}.
		IntpSphere2(int quantity, Real* theta, Real* phi, Real* F,bool owner, QueryType queryType);

		~IntpSphere2();

		// Spherical coordinates are
		//   x = cos(theta)*sin(phi)
		//   y = sin(theta)*sin(phi)
		//   z = cos(phi)
		// for -PI <= theta <= PI, 0 <= phi <= PI.  The application can use this
		// function to convert unit length vectors (x,y,z) to (theta,phi).
		static void GetSphericalCoords(Real x, Real y, Real z,Real& theta, Real& phi);

		bool Evaluate(Real theta, Real phi, Real& F);

	private:
		Delaunay2<Real>* mDT;
		IntpQdrNonuniform2<Real>* mInterp;
	};

	using IntpSphere2f = IntpSphere2<float>;
	using IntpSphere2d = IntpSphere2<double>;
}

#endif // MATHEMATICS_INTERPOLATION_INTP_SPHERE2_H
