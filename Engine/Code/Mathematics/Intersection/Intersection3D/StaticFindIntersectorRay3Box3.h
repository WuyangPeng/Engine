// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/12 11:04)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY3_BOX3_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY3_BOX3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Ray3.h"  
#include "Mathematics/Objects3D/Triangle3.h" 
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticFindIntersectorRay3Box3: public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticFindIntersectorRay3Box3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Ray3 = Ray3<Real>;
		using Box3 = Box3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = Math<Real>;   		
		
	public:
		StaticFindIntersectorRay3Box3 (const Ray3& ray, const Box3& box);
		
		// Object access.
		const Ray3 GetRay () const;
		const Box3 GetBox () const;

		// The intersection set.
		int GetQuantity () const;
		const Vector3D GetPoint (int i) const;

	private:
		// Static intersection queries.
		void Find ();
		
		// The objects to intersect.
		Ray3 mRay;
		Box3 mBox;
		
		// Information about the intersection set.
		int mQuantity;
		Vector3D mPoint[2];
	};
	
	using StaticFindIntersectorRay3Box3f = StaticFindIntersectorRay3Box3<float>;
	using StaticFindIntersectorRay3Box3d = StaticFindIntersectorRay3Box3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY3_BOX3_H
