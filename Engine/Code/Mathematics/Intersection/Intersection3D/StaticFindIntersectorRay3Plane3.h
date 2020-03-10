// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/12 11:23)

#ifndef MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_RAY3_PLANE3_H
#define MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_RAY3_PLANE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Ray3.h"
#include "Mathematics/Objects3D/Plane3.h"
#include "Mathematics/Intersection/StaticIntersector.h"

namespace Mathematics
{
	template <typename Real>
	class StaticFindIntersectorRay3Plane3 : public StaticIntersector<Real, Vector3D>
	{
	public:		
		using ClassType = StaticFindIntersectorRay3Plane3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Ray3 = Ray3<Real>;
		using Plane3 = Plane3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = Math<Real>;		
		
	public:
		StaticFindIntersectorRay3Plane3(const Ray3& ray, const Plane3& plane,const Real epsilon = Math::sm_ZeroTolerance);

		virtual ~StaticFindIntersectorRay3Plane3();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
		
		const Ray3 GetRay() const;
		const Plane3 GetPlane() const;
		
		Real GetRayParameter() const; 

	private:	
		void Find();
		
	private: 
		// 相交对象
		Ray3 m_Ray;
		Plane3 m_Plane;
		
		// 相交对象集信息
		Real m_RayParameter;
	};

	using StaticFindIntersectorRay3Plane3f = StaticFindIntersectorRay3Plane3<float>;
	using StaticFindIntersectorRay3Plane3d = StaticFindIntersectorRay3Plane3<double>;
}

#endif // MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_RAY3_PLANE3_H
