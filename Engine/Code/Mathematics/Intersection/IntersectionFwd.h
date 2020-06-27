// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/24 14:32)

#ifndef MATHEMATICS_INTERSECTION_FWD_H
#define MATHEMATICS_INTERSECTION_FWD_H

// 目录对象间的相交计算，包括静态和动态查询、相交测试查询以及相交信息查询。
namespace Mathematics
{
	template <typename Real, template <typename> class Vector>
	class Intersector;

	template <typename Real, template <typename> class Vector>
	class StaticIntersector;

	template <typename Real, template <typename> class Vector>
	class DynamicIntersector;

	template <typename Real>
	class Intersector1;

	template <typename Real>
	class StaticTestIntersector1;

	template <typename Real>
	class StaticFindIntersector1;

	template <typename Real>
	class DynamicTestIntersector1;

	template <typename Real>
	class DynamicFindIntersector1;

	// 2D
	template <typename Real>
	class StaticFindIntersectorCircle2Circle2;

	template <typename Real>
	class StaticFindIntersectorArc2Arc2;

	template <typename Real>
	class StaticFindIntersectorArc2Circle2;

	template <typename Real>
	class StaticTestIntersectorBox2Box2;

	template <typename Real>
	class StaticTestIntersectorLine2Classify;

	template <typename Real>
	class StaticTestIntersectorLine2Line2;

	template <typename Real>
	class StaticFindIntersectorLine2Line2;

	template <typename Real>
	class StaticTestIntersectorRay2Ray2;

	template <typename Real>
	class StaticFindIntersectorRay2Ray2;

	template <typename Real>
	class StaticTestIntersectorSegment2Segment2;

	template <typename Real>
	class StaticFindIntersectorSegment2Segment2;

	template <typename Real>
	class StaticTestIntersectorLine2Ray2;

	template <typename Real>
	class StaticFindIntersectorLine2Ray2;

	template <typename Real>
	class StaticTestIntersectorLine2Segment2;

	template <typename Real>
	class StaticFindIntersectorLine2Segment2;

	template <typename Real>
	class StaticTestIntersectorRay2Segment2;

	template <typename Real>
	class StaticFindIntersectorRay2Segment2;

	// 3D
	template <typename Real>
	class StaticFindIntersectorLine3Triangle3;

	template <typename Real>
	class StaticTestIntersectorLine3Triangle3;

	template <typename Real>
	class TriangleProjectOntoAxis;

	template <typename Real>
	class StaticTestIntersectorTriangle3Triangle3;

	template <typename Real>
	class TrianglePlaneRelations;

	enum class IntersectionType;

	template <typename Real>
	class IntersectorConfiguration;
}

#endif // MATHEMATICS_INTERSECTION_FWD_H