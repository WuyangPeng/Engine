// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 16:17)

#ifndef MATHEMATICS_CONTAINMENT_CONT_ELLIPSE2_MINCR_H
#define MATHEMATICS_CONTAINMENT_CONT_ELLIPSE2_MINCR_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Matrix2.h"

// Compute the minimum-area ellipse, (X-C)^T Real D Real^T (X-C) = 1, given the
// center C and the orientation matrix Real.  The columns of Real are the axes of
// the ellipse.  The algorithm computes the diagonal matrix D.  The minimum
// area is pi/sqrt(D[0]*D[1]), where D = diag(D[0],D[1]).  The problem is
// equivalent to maximizing the product D[0]*D[1] for a given C and Real, and
// subject to the constraints
//   (P[i]-C)^T Real D Real^T (P[i]-C) <= 1
// for all input points P[i] with 0 <= i < N.  Each constraint has the form
//   A[0]*D[0] + A[1]*D[1] <= 1
// where A[0] >= 0 and A[1] >= 0.

namespace Mathematics
{
	template <typename Real>
	class ContEllipse2MinCR
	{
	public:
		ContEllipse2MinCR (int numPoints, const Vector2<Real>* points, const Vector2<Real>& C, const Matrix2<Real>& R, Real D[2]);
		
	private:
		static bool XGreater (const Vector2<Real>& P0, const Vector2<Real>& P1);
		static bool XEqual (const Vector2<Real>& P0, const Vector2<Real>& P1);
		static bool YGreater (const Vector2<Real>& P0, const Vector2<Real>& P1);
		static bool YEqual (const Vector2<Real>& P0, const Vector2<Real>& P1);
		static void MaxProduct (std::vector<Vector2<Real> >& A, Real D[2]);
	};
	
	using ContEllipse2MinCRf = ContEllipse2MinCR<float>;
	using ContEllipse2MinCRd = ContEllipse2MinCR<double>;
}

#endif // MATHEMATICS_CONTAINMENT_CONT_ELLIPSE2_MINCR_H
