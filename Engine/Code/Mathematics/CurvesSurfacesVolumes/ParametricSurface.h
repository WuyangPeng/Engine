// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 18:23)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_PARAMETRIC_SURFACE_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_PARAMETRIC_SURFACE_H

#include "Mathematics/MathematicsDll.h"

#include "Surface.h"
#include "Mathematics/Algebra/Vector3.h"

namespace Mathematics
{
	template <typename Real>
	class ParametricSurface : public Surface<Real>
	{
	public:
	 

		// The parametric domain is either rectangular or triangular.  Valid (u,v)
		// values for a rectangular domain satisfy
		//   umin <= u <= umax,  vmin <= v <= vmax
		// Valid (u,v) values for a triangular domain satisfy
		//   umin <= u <= umax,  vmin <= v <= vmax,
		//   (vmax-vmin)*(u-umin)+(umax-umin)*(v-vmax) <= 0
            Real GetUMin() const noexcept;
            Real GetUMax() const noexcept;
            Real GetVMin() const noexcept;
            Real GetVMax() const noexcept;
            bool IsRectangular() const noexcept;

		// position and derivatives up to second order
		virtual Vector3<Real> P(Real u, Real v) const = 0;
		virtual Vector3<Real> PU(Real u, Real v) const = 0;
		virtual Vector3<Real> PV(Real u, Real v) const = 0;
		virtual Vector3<Real> PUU(Real u, Real v) const = 0;
		virtual Vector3<Real> PUV(Real u, Real v) const = 0;
		virtual Vector3<Real> PVV(Real u, Real v) const = 0;

		// Compute a coordinate frame.  The set {T0,T1,N} is a right-handed
		// orthonormal set.
		void GetFrame(Real u, Real v, Vector3<Real>& position,Vector3<Real>& tangent0, Vector3<Real>& tangent1,Vector3<Real>& normal) const;

		// Differential geometric quantities.  The returned scalars are the
		// principal curvatures and the returned vectors are the corresponding
		// principal directions.
		void ComputePrincipalCurvatureInfo(Real u, Real v, Real& curv0,Real& curv1, Vector3<Real>& dir0, Vector3<Real>& dir1);

	protected:
		ParametricSurface(Real umin, Real umax, Real vmin, Real vmax,bool rectangular);

		Real mUMin, mUMax, mVMin, mVMax;
		bool mRectangular;
	};

	using ParametricSurfacef = ParametricSurface<float>;
	using ParametricSurfaced = ParametricSurface<double>;
}

#endif // MATHEMATICS_CURVES_SURFACES_VOLUMES_PARAMETRIC_SURFACE_H
