// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 14:59)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_TRIANGLE3_CYLINDER3_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_TRIANGLE3_CYLINDER3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Triangle3.h"   
#include "Mathematics/Objects3D/Cylinder3.h" 
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticTestIntersectorTriangle3Cylinder3 : public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticTestIntersectorTriangle3Cylinder3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Triangle3 = Triangle3<Real>;
		using Cylinder3 = Cylinder3<Real>;
		using Vector2D = Vector2D<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = Math<Real>;

	public:
		StaticTestIntersectorTriangle3Cylinder3(const Triangle3& triangle, const Cylinder3& cylinder);

		// Object access.
		const Triangle3 GetTriangle() const;
		const Cylinder3 GetCylinder() const;

	private:
		// Static query.
		void Test();

	private:
		// Support for the static test query.
		bool DiskOverlapsPoint(const Vector2D& Q) const;
		bool DiskOverlapsSegment(const Vector2D& Q0, const Vector2D& Q1) const;
		bool DiskOverlapsPolygon(int numVertices, const Vector2D* Q) const;

		// The objects to intersect.
		Triangle3 mTriangle;
		Cylinder3 mCylinder;
	};

	using StaticTestIntersectorTriangle3Cylinder3f = StaticTestIntersectorTriangle3Cylinder3<float>;
	using StaticTestIntersectorTriangle3Cylinder3d = StaticTestIntersectorTriangle3Cylinder3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_TRIANGLE3_CYLINDER3_H
