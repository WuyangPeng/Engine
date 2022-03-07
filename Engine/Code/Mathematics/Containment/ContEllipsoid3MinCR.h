// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 16:17)

#ifndef MATHEMATICS_CONTAINMENT_CONT_ELLIPSOID3_MINCR_H
#define MATHEMATICS_CONTAINMENT_CONT_ELLIPSOID3_MINCR_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Matrix3.h" 

namespace Mathematics
{
	// Compute the minimum-volume ellipsoid, (X-C)^T Real D Real^T (X-C) = 1, given the
	// center C and orientation matrix Real.  The columns of Real are the axes of the
	// ellipsoid.  The algorithm computes the diagonal matrix D.  The minimum
	// volume is (4*pi/3)/sqrt(D[0]*D[1]*D[2]), where D = diag(D[0],D[1],D[2]).
	// The problem is equivalent to maximizing the product D[0]*D[1]*D[2] for a
	// given C and Real, and subject to the constraints
	//   (P[i]-C)^T Real D Real^T (P[i]-C) <= 1
	// for all input points P[i] with 0 <= i < N.  Each constraint has the form
	//   A[0]*D[0] + A[1]*D[1] + A[2]*D[2] <= 1
	// where A[0] >= 0, A[1] >= 0, and A[2] >= 0.
	
	template <typename Real>
	class ContEllipsoid3MinCR
	{
	public:
		ContEllipsoid3MinCR (int numPoints, const Vector3<Real>* points, const Vector3<Real>& C, const Matrix3<Real>& R, Real D[3]);
		
	private:
		void FindEdgeMax (std::vector<Vector3<Real> >& A, int& plane0, int& plane1, Real D[3]);
		
		void FindFacetMax (std::vector<Vector3<Real> >& A, int& plane0,  Real D[3]);
		
		void MaxProduct (std::vector<Vector3<Real> >& A, Real D[3]);
	};
	
	using ContEllipsoid3MinCRf = ContEllipsoid3MinCR<float>;
	using ContEllipsoid3MinCRd = ContEllipsoid3MinCR<double>;
}

#endif // MATHEMATICS_CONTAINMENT_CONT_ELLIPSOID3_MINCR_H
