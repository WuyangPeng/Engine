// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 17:59)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_VOLUME_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_VOLUME_H

#include "Mathematics/MathematicsDll.h"

#include "BSplineBasis.h"
#include "Mathematics/Algebra/Vector3D.h"

namespace Mathematics
{
	template <typename Real>
	class  BSplineVolume
	{
	public:
		// Construction and destruction of an open uniform B-spline volume.  The
		// class will allocate space for the control points.  The caller is
		// responsible for setting the values with the member function
		// ControlPoint.

		BSplineVolume(int numUCtrlPoints, int numVCtrlPoints, int numWCtrlPoints, int uDegree, int vDegree, int wDegree);

		~BSplineVolume();
		
		BSplineVolume(const BSplineVolume&)= default;
		BSplineVolume& operator=(const BSplineVolume&)= default;
		BSplineVolume(BSplineVolume&&)= default;
		BSplineVolume& operator=(BSplineVolume&&)= default;

		int GetNumCtrlPoints(int dim) const noexcept;
		int GetDegree(int dim) const noexcept;

		// Control points may be changed at any time.  If any input index is
		// invalid, the returned point is a vector whose components are all
		// MAX_REAL.
		void SetControlPoint(int uIndex, int vIndex, int wIndex, const Vector3D<Real>& ctrlPoint) noexcept;
		Vector3D<Real> GetControlPoint(int uIndex, int vIndex, int wIndex) const noexcept;

		// The spline is defined for 0 <= u <= 1, 0 <= v <= 1, and 0 <= w <= 1.
		// The input values should be in this domain.  Any inputs smaller than 0
		// are clamped to 0.  Any inputs larger than 1 are clamped to 1.
		Vector3D<Real> GetPosition(Real u, Real v, Real w) const;
		Vector3D<Real> GetDerivativeU(Real u, Real v, Real w) const;
		Vector3D<Real> GetDerivativeV(Real u, Real v, Real w) const;
		Vector3D<Real> GetDerivativeW(Real u, Real v, Real w) const;

		// for array indexing:  i = 0 for u, i = 1 for v, i = 2 for w
		Vector3D<Real> GetPosition(Real pos[3]) const;
		Vector3D<Real> GetDerivative(int i, Real pos[3]) const;

	private:
		Vector3D<Real>*** mCtrlPoint;  // ctrl[unum][vnum][wnum]
		BSplineBasis<Real> mBasis[3];
	};

	using BSplineVolumef = BSplineVolume<float>;
	using BSplineVolumed = BSplineVolume<double>;
}

#endif // MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_VOLUME_H
