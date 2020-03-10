// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/12 14:10)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY3_ELLIPSOID3_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY3_ELLIPSOID3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Ray3.h"   
#include "Mathematics/Objects3D/Ellipsoid3.h" 
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticTestIntersectorRay3Ellipsoid3: public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticTestIntersectorRay3Ellipsoid3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Ray3 = Ray3<Real>;
		using Ellipsoid3 = Ellipsoid3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = Math<Real>;   		
		
	public:
		StaticTestIntersectorRay3Ellipsoid3 (const Ray3& ray,const Ellipsoid3& ellipsoid);
		
		// Object access.
		const Ray3 GetRay () const;
		const Ellipsoid3 GetEllipsoid () const;

	private:
		// Static intersection queries.
		void Test ();		
		
		// The objects to intersect.
		Ray3 mRay;
		Ellipsoid3 mEllipsoid;
	};
	
	using StaticTestIntersectorRay3Ellipsoid3f = StaticTestIntersectorRay3Ellipsoid3<float>;
	using StaticTestIntersectorRay3Ellipsoid3d = StaticTestIntersectorRay3Ellipsoid3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_RAY3_ELLIPSOID3_H
