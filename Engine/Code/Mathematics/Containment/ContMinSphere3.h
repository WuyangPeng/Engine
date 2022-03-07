// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 16:18)

#ifndef MATHEMATICS_CONTAINMENT_CONT_MIN_SPHERE3_H
#define MATHEMATICS_CONTAINMENT_CONT_MIN_SPHERE3_H

// Compute the minimum volume sphere containing the input set of points.  The
// algorithm randomly permutes the input points so that the construction
// occurs in 'expected' O(N) time.

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Sphere3.h"   

namespace Mathematics
{
	template <typename Real>
	class MinSphere3
	{
	public:
		// The epsilon value is a floating-point tolerance used for various
		// computations.
		MinSphere3 (int numPoints, const Vector3<Real>* points,Sphere3<Real>& minimal, Real epsilon = static_cast<Real>(1e-03));
		
	private:
		// Indices of points that support current minimum volume sphere.
		class Support
		{
		public:
			bool Contains (int index, Vector3<Real>** points, Real epsilon);
			
			int Quantity;
			int Index[4];
		};
		
		// Test whether point P is inside sphere S.
		bool Contains (const Vector3<Real>& point, const Sphere3<Real>& sphere,  Real& distDiff);
		
		Sphere3<Real> ExactSphere1 (const Vector3<Real>& P);
		Sphere3<Real> ExactSphere2 (const Vector3<Real>& P0,const Vector3<Real>& P1);
		Sphere3<Real> ExactSphere3 (const Vector3<Real>& P0, const Vector3<Real>& P1, const Vector3<Real>& P2);
		Sphere3<Real> ExactSphere4 (const Vector3<Real>& P0,const Vector3<Real>& P1,  const Vector3<Real>& P2,   const Vector3<Real>& P3);
		
		Sphere3<Real> UpdateSupport1 (int i, Vector3<Real>** permuted, Support& support);
		Sphere3<Real> UpdateSupport2 (int i, Vector3<Real>** permuted,Support& support);
		Sphere3<Real> UpdateSupport3 (int i, Vector3<Real>** permuted,Support& support);
		Sphere3<Real> UpdateSupport4 (int i, Vector3<Real>** permuted,Support& support);
		
		typedef Sphere3<Real> (MinSphere3<Real>::*UpdateFunction)(int, Vector3<Real>**, Support&);
		
		Real mEpsilon;
		UpdateFunction mUpdate[5];
	};
	
	using MinSphere3f = MinSphere3<float>;
	using MinSphere3d = MinSphere3<double>;
}

#endif // MATHEMATICS_CONTAINMENT_CONT_MIN_SPHERE3_H
