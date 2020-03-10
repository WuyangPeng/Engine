// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/12 11:17)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY3_ELLIPSOID3_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY3_ELLIPSOID3_H

#include "Mathematics/MathematicsDll.h"


#include "Mathematics/Objects3D/Ray3.h"  
#include "Mathematics/Objects3D/Ellipsoid3.h" 
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticFindIntersectorRay3Ellipsoid3: public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticFindIntersectorRay3Ellipsoid3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Ray3 = Ray3<Real>;
		using Ellipsoid3 = Ellipsoid3<Real>;
		using Vector3DTools = Vector3DTools<Real>; 
		using Math = Math<Real>;		
 
	public:
		StaticFindIntersectorRay3Ellipsoid3 (const Ray3& ray,const Ellipsoid3& ellipsoid);
		
		// Object access.
		const Ray3 GetRay () const;
		const Ellipsoid3 GetEllipsoid () const;

		// The intersection set.
		int GetQuantity () const;
		const Vector3D GetPoint (int i) const;    
		
	private:
		// Static intersection queries.
		void Find ();
		
		// The objects to intersect.
		Ray3 mRay;
		Ellipsoid3 mEllipsoid;
		
		// Information about the intersection set.
		int mQuantity;
		Vector3D mPoint[2];
	};
	
	using StaticFindIntersectorRay3Ellipsoid3f = StaticFindIntersectorRay3Ellipsoid3<float>;
	using StaticFindIntersectorRay3Ellipsoid3d = StaticFindIntersectorRay3Ellipsoid3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_RAY3_ELLIPSOID3_H
