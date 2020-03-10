// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/12 11:05)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY3_CAPSULE3_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY3_CAPSULE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Ray3.h"  
#include "Mathematics/Objects3D/Capsule3.h" 
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticFindIntersectorRay3Capsule3: public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticFindIntersectorRay3Capsule3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Ray3 = Ray3<Real>;
		using Capsule3 = Capsule3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = Math<Real>;   
				
	public:
		StaticFindIntersectorRay3Capsule3 (const Ray3& ray, const Capsule3& capsule);
		
		// Object access.
		const Ray3 GetRay () const;
		const Capsule3 GetCapsule () const;

		// The intersection set.
		int GetQuantity () const;
		const Vector3D GetPoint (int i) const;

	private:
		// Static intersection queries.
		void Find ();
		
		// The objects to intersect.
		Ray3 mRay;
		Capsule3 mCapsule;
		
		// Information about the intersection set.
		int mQuantity;
		Vector3D mPoint[2];
	};
	
	using StaticFindIntersectorRay3Capsule3f = StaticFindIntersectorRay3Capsule3<float>;
	using StaticFindIntersectorRay3Capsule3d = StaticFindIntersectorRay3Capsule3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY3_CAPSULE3_H
