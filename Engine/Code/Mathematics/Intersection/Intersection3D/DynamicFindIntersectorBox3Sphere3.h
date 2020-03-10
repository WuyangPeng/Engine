// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/12 09:17)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_BOX3_SPHERE3_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_BOX3_SPHERE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Box3.h"
#include "Mathematics/Objects3D/Sphere3.h" 
#include "Mathematics/Intersection/DynamicIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class DynamicFindIntersectorBox3Sphere3 : public  DynamicIntersector<Real, Vector3D>
	{
	public:
		using ClassType = DynamicFindIntersectorBox3Sphere3<Real>;
		using ParentType = DynamicIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Box3 = Box3<Real>;
		using Sphere3 = Sphere3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = Math<Real>;

	public:
		DynamicFindIntersectorBox3Sphere3(const Box3& box, const Sphere3& sphere,Real tmax, 
										  const Vector3D& lhsVelocity,const Vector3D& rhsVelocity,const Real epsilon = Math::sm_ZeroTolerance);
		
		// Object access.
		const Box3 GetBox () const;
		const Sphere3 GetSphere () const;

		// Intersection set for dynamic find-intersection query.
		const Vector3D& GetContactPoint() const;
   
	private:
		// Find-intersection query.
		void Find ();		
		
		// Supporting functions for dynamic Find function.
		static Real GetVertexIntersection (Real dx, Real dy, Real dz, Real vx, Real vy, Real vz, Real rsqr);
		
		static Real GetEdgeIntersection (Real dx, Real dz, Real vx, Real vz, Real vsqr, Real rsqr);
		
		int FindFaceRegionIntersection (Real ex, Real ey, Real ez, Real cx, Real cy, Real cz, Real vx, Real vy, Real vz, Real& ix, Real& iy, Real& iz, bool aboveFace);
		
		int FindJustEdgeIntersection (Real cy, Real ex, Real ey, Real ez, Real dx, Real dz, Real vx, Real vy, Real vz, Real& ix, Real& iy, Real& iz);
		
		int FindEdgeRegionIntersection (Real ex, Real ey, Real ez, Real cx,Real cy, Real cz, Real vx, Real vy, Real vz, Real& ix, Real& iy, Real& iz, bool aboveEdge);
		
		int FindVertexRegionIntersection (Real ex, Real ey, Real ez, Real cx, Real cy, Real cz, Real vx, Real vy, Real vz, Real& ix, Real& iy, Real& iz);
		
		// The objects to intersect.
		Box3 mBox;
		Sphere3 mSphere;
		
		// Point of intersection.
		Vector3D mContactPoint;
	};

	using DynamicFindIntersectorBox3Sphere3f = DynamicFindIntersectorBox3Sphere3<float>;
	using DynamicFindIntersectorBox3Sphere3d = DynamicFindIntersectorBox3Sphere3<double>;
}

#endif // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_BOX3_SPHERE3_H
