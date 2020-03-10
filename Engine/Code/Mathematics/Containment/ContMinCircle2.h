// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 16:18)

#ifndef MATHEMATICS_CONTAINMENT_CONT_MIN_CIRCLE2_H
#define MATHEMATICS_CONTAINMENT_CONT_MIN_CIRCLE2_H

// Compute the minimum area circle containing the input set of points.  The
// algorithm randomly permutes the input points so that the construction
// occurs in 'expected' O(N) time.

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects2D/Circle2.h"    

namespace Mathematics
{
	template <typename Real>
	class MinCircle2
	{
	public:
		// The epsilon value is a floating-point tolerance used for various
		// computations.
		MinCircle2 (int numPoints, const Vector2D<Real>* points,Circle2<Real>& minimal, Real epsilon = (Real)1e-05);
		
	private:
		// Indices of points that support current minimum area circle.
		class Support
		{
		public:
			bool Contains (int index, Vector2D<Real>** points, Real epsilon);
			
			int Quantity;
			int Index[3];
		};
		
		// Test whether point P is inside circle C.
		bool Contains (const Vector2D<Real>& point, const Circle2<Real>& circle, Real& distDiff);
		
		Circle2<Real> ExactCircle1 (const Vector2D<Real>& P);
		Circle2<Real> ExactCircle2 (const Vector2D<Real>& P0, const Vector2D<Real>& P1);
		Circle2<Real> ExactCircle3 (const Vector2D<Real>& P0, const Vector2D<Real>& P1, const Vector2D<Real>& P2);
		
		Circle2<Real> UpdateSupport1 (int i, Vector2D<Real>** permuted, Support& support);
		Circle2<Real> UpdateSupport2 (int i, Vector2D<Real>** permuted,Support& support);
		Circle2<Real> UpdateSupport3 (int i, Vector2D<Real>** permuted,Support& support);
		
		typedef Circle2<Real> (MinCircle2<Real>::*UpdateFunction)(int, Vector2D<Real>**, Support&);
		
		Real mEpsilon;
		UpdateFunction mUpdate[4];
	};
	
	using MinCircle2f = MinCircle2<float>;
	using MinCircle2d = MinCircle2<double>;
}

#endif // MATHEMATICS_CONTAINMENT_CONT_MIN_CIRCLE2_H
