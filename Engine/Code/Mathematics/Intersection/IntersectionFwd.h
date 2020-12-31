///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/15 17:39)

#ifndef MATHEMATICS_INTERSECTION_FWD_H
#define MATHEMATICS_INTERSECTION_FWD_H

// 目录对象间的相交计算，包括静态和动态查询、相交测试查询以及相交信息查询。
namespace Mathematics
{
    enum class IntersectionType;
    enum class ContactSide;
    enum class VertexProjectionMap;

    template <typename Real, template <typename> class Vector>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Intersector;

    template <typename Real, template <typename> class Vector>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticIntersector;

    template <typename Real, template <typename> class Vector>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DynamicIntersector;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Intersector1;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticTestIntersector1;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersector1;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DynamicTestIntersector1;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DynamicFindIntersector1;

    // 2D
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DynamicFindIntersectorBox2Circle2;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DynamicFindIntersectorTriangle2Triangle2;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DynamicTestIntersectorTriangle2Triangle2;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorTriangle2Triangle2;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorArc2Arc2;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorArc2Circle2;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorCircle2Circle2;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorEllipse2Ellipse2;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorLine2Arc2;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorLine2Box2;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorLine2Circle2;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorLine2Line2;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorLine2Ray2;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorLine2Segment2;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorLine2Triangle2;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorRay2Arc2;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorRay2Box2;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorRay2Circle2;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorRay2Ray2;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorRay2Segment2;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorRay2Triangle2;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorSegment2Arc2;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorSegment2Box2;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorSegment2Circle2;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorSegment2Segment2;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorSegment2Triangle2;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticTestIntersectorBox2Box2;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticTestIntersectorBox2Circle2;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticTestIntersectorLine2Box2;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticTestIntersectorLine2Classify;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticTestIntersectorLine2Line2;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticTestIntersectorLine2Ray2;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticTestIntersectorLine2Segment2;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticTestIntersectorLine2Triangle2;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticTestIntersectorRay2Box2;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticTestIntersectorRay2Ray2;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticTestIntersectorRay2Segment2;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticTestIntersectorRay2Triangle2;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticTestIntersectorSegment2Box2;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticTestIntersectorSegment2Segment2;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticTestIntersectorSegment2Triangle2;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticTestIntersectorTriangle2Triangle2;

    // 3D
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE IntersectorUtility3;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE IntersectorConfiguration;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE FindContactSet;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE TestIntersectorAxis;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE FindIntersectorAxis;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DynamicAngularTestIntersectorBox3Box3;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DynamicFindIntersectorBox3Box3;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DynamicFindIntersectorBox3Sphere3;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DynamicFindIntersectorHalfspace3Box3;

    template <typename Real>
    class DynamicFindIntersectorHalfspace3Segment3;

    template <typename Real>
    class DynamicFindIntersectorHalfspace3Triangle3;

    template <typename Real>
    class DynamicFindIntersectorPlane3Plane3;

    template <typename Real>
    class DynamicFindIntersectorSegment3Box3;

    template <typename Real>
    class DynamicFindIntersectorSegment3Sphere3;

    template <typename Real>
    class DynamicFindIntersectorSegment3Triangle3;

    template <typename Real>
    class DynamicFindIntersectorSphere3Sphere3;

    template <typename Real>
    class DynamicFindIntersectorTriangle3Box3;

    template <typename Real>
    class DynamicFindIntersectorTriangle3Sphere3;

    template <typename Real>
    class DynamicFindIntersectorTriangle3Triangle3;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DynamicTestIntersectorBox3Box3;

    template <typename Real>
    class DynamicTestIntersectorHalfspace3Box3;

    template <typename Real>
    class DynamicTestIntersectorHalfspace3Segment3;

    template <typename Real>
    class DynamicTestIntersectorHalfspace3Sphere3;

    template <typename Real>
    class DynamicTestIntersectorHalfspace3Triangle3;

    template <typename Real>
    class DynamicTestIntersectorPlane3Plane3;

    template <typename Real>
    class DynamicTestIntersectorSegment3Box3;

    template <typename Real>
    class DynamicTestIntersectorSegment3Sphere3;

    template <typename Real>
    class DynamicTestIntersectorSegment3Triangle3;

    template <typename Real>
    class DynamicTestIntersectorSphere3Sphere3;

    template <typename Real>
    class DynamicTestIntersectorTriangle3Box3;

    template <typename Real>
    class DynamicTestIntersectorTriangle3Triangle3;

    template <typename Real>
    class StaticFindIntersectorCircle3Plane3;

    template <typename Real>
    class StaticFindIntersectorHalfspace3Segment3;

    template <typename Real>
    class StaticFindIntersectorHalfspace3Triangle3;

    template <typename Real>
    class StaticFindIntersectorLine3Box3;

    template <typename Real>
    class StaticFindIntersectorLine3Capsule3;

    template <typename Real>
    class StaticFindIntersectorLine3Cone3;

    template <typename Real>
    class StaticFindIntersectorLine3Cylinder3;

    template <typename Real>
    class StaticFindIntersectorLine3Ellipsoid3;

    template <typename Real>
    class StaticFindIntersectorLine3Plane3;

    template <typename Real>
    class StaticFindIntersectorLine3Sphere3;

    template <typename Real>
    class StaticFindIntersectorLine3Torus3;

    template <typename Real>
    class StaticFindIntersectorLine3Triangle3;

    template <typename Real>
    class StaticFindIntersectorPlane3Cylinder3;

    template <typename Real>
    class StaticFindIntersectorPlane3Plane3;

    template <typename Real>
    class StaticFindIntersectorPlane3Sphere3;

    template <typename Real>
    class StaticFindIntersectorPlane3Triangle3;

    template <typename Real>
    class StaticFindIntersectorRay3Box3;

    template <typename Real>
    class StaticFindIntersectorRay3Capsule3;

    template <typename Real>
    class StaticFindIntersectorRay3Cylinder3;

    template <typename Real>
    class StaticFindIntersectorRay3Ellipsoid3;

    template <typename Real>
    class StaticFindIntersectorRay3Plane3;

    template <typename Real>
    class StaticFindIntersectorRay3Sphere3;

    template <typename Real>
    class StaticFindIntersectorRay3Triangle3;

    template <typename Real>
    class StaticFindIntersectorSegment3Box3;

    template <typename Real>
    class StaticFindIntersectorSegment3Capsule3;

    template <typename Real>
    class StaticFindIntersectorSegment3Cylinder3;

    template <typename Real>
    class StaticFindIntersectorSegment3Ellipsoid3;

    template <typename Real>
    class StaticFindIntersectorSegment3Plane3;

    template <typename Real>
    class StaticFindIntersectorSegment3Sphere3;

    template <typename Real>
    class StaticFindIntersectorSegment3Triangle3;

    template <typename Real>
    class StaticFindIntersectorSphere3Cone3;

    template <typename Real>
    class StaticFindIntersectorSphere3Sphere3;

    template <typename Real>
    class StaticFindIntersectorTetrahedron3Tetrahedron3;

    template <typename Real>
    class StaticFindIntersectorTriangle3Box3;

    template <typename Real>
    class StaticFindIntersectorTriangle3Triangle3;

    template <typename Real>
    class StaticTestIntersectorBox3Box3;

    template <typename Real>
    class StaticTestIntersectorBox3Frustum3;

    template <typename Real>
    class StaticTestIntersectorBox3Sphere3;

    template <typename Real>
    class StaticTestIntersectorCapsule3Capsule3;

    template <typename Real>
    class StaticTestIntersectorCircle3Plane3;

    template <typename Real>
    class StaticTestIntersectorEllipsoid3Ellipsoid3;

    template <typename Real>
    class StaticTestIntersectorHalfspace3Box3;

    template <typename Real>
    class StaticTestIntersectorHalfspace3Segment3;

    template <typename Real>
    class StaticTestIntersectorHalfspace3Sphere3;

    template <typename Real>
    class StaticTestIntersectorHalfspace3Triangle3;

    template <typename Real>
    class StaticTestIntersectorLine3Box3;

    template <typename Real>
    class StaticTestIntersectorLine3Capsule3;

    template <typename Real>
    class StaticTestIntersectorLine3Ellipsoid3;

    template <typename Real>
    class StaticTestIntersectorLine3Lozenge3;

    template <typename Real>
    class StaticTestIntersectorLine3Plane3;

    template <typename Real>
    class StaticTestIntersectorLine3Sphere3;

    template <typename Real>
    class StaticTestIntersectorLine3Triangle3;

    template <typename Real>
    class StaticTestIntersectorLozenge3Lozenge3;

    template <typename Real>
    class StaticTestIntersectorPlane3Box3;

    template <typename Real>
    class StaticTestIntersectorPlane3Capsule3;

    template <typename Real>
    class StaticTestIntersectorPlane3Cylinder3;

    template <typename Real>
    class StaticTestIntersectorPlane3Ellipsoid3;

    template <typename Real>
    class StaticTestIntersectorPlane3Lozenge3;

    template <typename Real>
    class StaticTestIntersectorPlane3Plane3;

    template <typename Real>
    class StaticTestIntersectorPlane3Sphere3;

    template <typename Real>
    class StaticTestIntersectorPlane3Triangle3;

    template <typename Real>
    class StaticTestIntersectorRay3Box3;

    template <typename Real>
    class StaticTestIntersectorRay3Capsule3;

    template <typename Real>
    class StaticTestIntersectorRay3Ellipsoid3;

    template <typename Real>
    class StaticTestIntersectorRay3Lozenge3;

    template <typename Real>
    class StaticTestIntersectorRay3Plane3;

    template <typename Real>
    class StaticTestIntersectorRay3Sphere3;

    template <typename Real>
    class StaticTestIntersectorRay3Triangle3;

    template <typename Real>
    class StaticTestIntersectorSegment3Box3;

    template <typename Real>
    class StaticTestIntersectorSegment3Capsule3;

    template <typename Real>
    class StaticTestIntersectorSegment3Ellipsoid3;

    template <typename Real>
    class StaticTestIntersectorSegment3Lozenge3;

    template <typename Real>
    class StaticTestIntersectorSegment3Plane3;

    template <typename Real>
    class StaticTestIntersectorSegment3Sphere3;

    template <typename Real>
    class StaticTestIntersectorSegment3Triangle3;

    template <typename Real>
    class StaticTestIntersectorSphere3Cone3;

    template <typename Real>
    class StaticTestIntersectorSphere3Frustum3;

    template <typename Real>
    class StaticTestIntersectorSphere3Sphere3;

    template <typename Real>
    class StaticTestIntersectorTriangle3Box3;

    template <typename Real>
    class StaticTestIntersectorTriangle3Cone3;

    template <typename Real>
    class StaticTestIntersectorTriangle3Cylinder3;

    template <typename Real>
    class StaticTestIntersectorTriangle3Sphere3;

    template <typename Real>
    class StaticTestIntersectorTriangle3Triangle3;
}

#endif  // MATHEMATICS_INTERSECTION_FWD_H