///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/19 21:38)

#ifndef MATHEMATICS_DISTANCE_FWD_H
#define MATHEMATICS_DISTANCE_FWD_H

#include "Mathematics/MathematicsDll.h"

namespace Mathematics
{
    template <typename Real, typename Vector>
    class DistanceResult;

    template <typename Real, typename Vector>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistanceBase;

    // 2D
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistanceLine2Line2;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistanceRay2Ray2;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistanceSegment2Segment2;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistanceLine2Ray2;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistanceLine2Segment2;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistanceRay2Segment2;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistancePoint2Line2;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistancePoint2Ray2;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistancePoint2Segment2;

    template <typename Real>
    class DistancePoint2Ellipse2;

    template <typename Real>
    class DistancePoint2Box2;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistancePoint2Hyperbola2;

    // 3D
    template <typename Real>
    class DistancePoint3Ellipsoid3;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistanceLine3Line3;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistanceRay3Ray3;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistanceSegment3Segment3;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistanceLine3Ray3;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistanceRay3Segment3;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistanceLine3Segment3;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistancePoint3Line3;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistancePoint3Ray3;

    template <typename Real>
    class DistancePoint3Box3;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistanceCircle3Circle3;

    template <typename Real>
    class DistanceLine3Box3;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistanceLine3Circle3;

    template <typename Real>
    class DistanceLine3Rectangle3;

    template <typename Real>
    class DistanceLine3Triangle3;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistancePoint3Circle3;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistancePoint3Frustum3;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistancePoint3Plane3;

    template <typename Real>
    class DistancePoint3Rectangle3;

    template <typename Real>
    class DistancePoint3Tetrahedron3;

    template <typename Real>
    class DistancePoint3Triangle3;

    template <typename Real>
    class DistanceRay3Box3;

    template <typename Real>
    class DistanceRay3Rectangle3;

    template <typename Real>
    class DistanceRay3Triangle3;

    template <typename Real>
    class DistanceRectangle3Rectangle3;

    template <typename Real>
    class DistanceSegment3Box3;

    template <typename Real>
    class DistanceSegment3Rectangle3;

    template <typename Real>
    class DistanceSegment3Triangle3;

    template <typename Real>
    class DistanceTriangle3Rectangle3;

    template <typename Real>
    class DistanceTriangle3Triangle3;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistancePoint3Segment3;
}

#endif  // MATHEMATICS_DISTANCE_FWD_H