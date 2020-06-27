// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 14:50)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE3_SPHERE3_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE3_SPHERE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h" 
#include "Mathematics/Objects3D/Line3.h"  
#include "Mathematics/Objects3D/Sphere3.h"  

namespace Mathematics
{
	template <typename Real>
	class StaticFindIntersectorLine3Sphere3 : public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticFindIntersectorLine3Sphere3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Line3 = Line3<Real>;
		using Sphere3 = Sphere3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = Math<Real>;

	public:
		StaticFindIntersectorLine3Sphere3(const Line3& line, const Sphere3& sphere);

		// Object access.
		const Line3 GetLine() const;
		const Sphere3 GetSphere() const;

		// The intersection set.
		int GetQuantity() const;
		const Vector3D GetPoint(int i) const;
		Real GetLineParameter(int i) const;

	private:
		// Static intersection queries.
		void Find();

		// The objects to intersect.
		Line3 mLine;
		Sphere3 mSphere;

		// Information about the intersection set.
		int mQuantity;
		Vector3D mPoint[2];
		Real mLineParameter[2];
	};

	using StaticFindIntersectorLine3Sphere3f = StaticFindIntersectorLine3Sphere3<float>;
	using StaticFindIntersectorLine3Sphere3d = StaticFindIntersectorLine3Sphere3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE3_SPHERE3_H
