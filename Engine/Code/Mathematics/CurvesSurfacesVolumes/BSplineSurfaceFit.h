// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 17:58)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_SURFACE_FIT_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_SURFACE_FIT_H

#include "Mathematics/MathematicsDll.h"

#include "BSplineFitBasis.h" 
#include "Mathematics/Algebra/Vector3D.h"
#include "Mathematics/Algebra/BandedMatrix.h"

namespace Mathematics
{
	template <typename Real>
	class BSplineSurfaceFit
	{
	public:
		// Construction and destruction.  The preconditions for calling the
		// constructor are
		//   1 <= degree0 && degree0 + 1 < numControls0 <= numSamples0
		//   1 <= degree1 && degree1 + 1 < numControls1 <= numSamples1
		BSplineSurfaceFit(int degree0, int numControls0, int numSamples0,int degree1, int numControls1, int numSamples1,Vector3D<Real>** samples);

		~BSplineSurfaceFit();

		// Access to input sample information.
		int GetSampleQuantity(int i) const;
		Vector3D<Real>** GetSamplePoints() const;

		// Access to output control point and surface information.
		int GetDegree(int i) const;
		int GetControlQuantity(int i) const;
		Vector3D<Real>** GetControlPoints() const;
		const BSplineFitBasis<Real>& GetBasis(int i) const;

		// Evaluation of the B-spline surface.  It is defined for 0 <= u <= 1
		// and 0 <= v <= 1.  If a parameter value is outside [0,1], it is clamped
		// to [0,1].
		Vector3D<Real> GetPosition(Real u, Real v) const;

	private:
		// Input sample information.
		int mNumSamples[2];
		Vector3D<Real>** mSamples;

		// The fitted B-spline surface, open and with uniform knots.
		int mDegree[2];
		int mNumControls[2];
		Vector3D<Real>** mControls;
		BSplineFitBasis<Real>* mBasis[2];
	};

	using BSplineSurfaceFitf = BSplineSurfaceFit<float>;
	using BSplineSurfaceFitd = BSplineSurfaceFit<double>;
}

#endif // MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_SURFACE_FIT_H
