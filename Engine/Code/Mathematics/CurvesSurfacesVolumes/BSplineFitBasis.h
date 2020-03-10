// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/17 17:57)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_FIT_BASIS_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_FIT_BASIS_H

#include "Mathematics/MathematicsDll.h"

namespace Mathematics
{
	template <typename Real>
	class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE BSplineFitBasis
	{
	public:
		// Construction and destruction.  This class is only for open uniform
		// B-spline basis functions.  The input is the number of control points
		// for a B-spline curve using this basis and the degree of that curve.
		BSplineFitBasis (int quantity, int degree);
		~BSplineFitBasis ();
		
		// Data member access.
		int GetQuantity () const;
		int GetDegree () const;
		
		// Evaluate the basis functions.  This function fills in the values
		// returned by GetValue(i) for 0 <= i <= degree.  The return indices iMin
		// and iMax are relative to the array of control points.  The GetValue(i)
		// are the coefficients for the control points ctrl[iMin] throught
		// ctrl[iMax] in the curve evaluation (i.e. the curve has local control).
		void Compute (Real t, int& imin, int& imax) const;
		Real GetValue (int i) const;
		
	private:
		// The number of control points and degree for the curve.
		int mQuantity, mDegree;
		
		// The storage for knots and basis evaluation.
		mutable Real* mValue;  // mValue[0..degree]
		mutable Real* mKnot;   // mKnot[2*degree]
	};
	
	using BSplineFitBasisf = BSplineFitBasis<float>;
	using BSplineFitBasisd = BSplineFitBasis<double>;
}

#endif // MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_FIT_BASIS_H
