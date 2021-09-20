///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/25 16:41)

#ifndef MATHEMATICS_INTERSECTION_FIND_CONTACT_SET_H
#define MATHEMATICS_INTERSECTION_FIND_CONTACT_SET_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/IntersectionFwd.h"
#include "Mathematics/Objects3D/Box3.h"
#include "Mathematics/Objects3D/Segment3.h"
#include "Mathematics/Objects3D/Triangle3.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
namespace Mathematics
{
    template <typename Real>
    class FindContactSetImpl;

    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE CoreTools::PerformanceUnsharedImpl<FindContactSetImpl<float>>;
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE CoreTools::PerformanceUnsharedImpl<FindContactSetImpl<double>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE CoreTools::PerformanceUnsharedImpl<FindContactSetImpl<Real>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE FindContactSet final
    {
    public:
        using FindContactSetImpl = FindContactSetImpl<Real>;
       
        TYPE_DECLARE(FindContactSet);
        using PackageType = CoreTools::PerformanceUnsharedImpl<ImplType>;
        using ClassShareType = typename PackageType::ClassShareType;
        using Vector3D = Vector3D<Real>;
        using Triangle3 = Triangle3<Real>;
        using Box3 = Box3<Real>;
        using IntersectorConfiguration = IntersectorConfiguration<Real>;
        using SegmentType = std::array<Vector3D, 2>;
        using TriangleType = std::array<Vector3D, 3>;
        using RectangleType = std::array<Vector3D, 4>;
        using PointType = std::vector<Vector3D>;

    public:
        FindContactSet(const SegmentType& segment,
                       const Triangle3& triangle,
                       ContactSide side,
                       const IntersectorConfiguration& segmentCfg,
                       const IntersectorConfiguration& triangleCfg,
                       const Vector3D& segmentVelocity,
                       const Vector3D& triangleVelocity,
                       Real tFirst);

        FindContactSet(const SegmentType& segment,
                       const Box3& box,
                       ContactSide side,
                       const IntersectorConfiguration& segmentCfg,
                       const IntersectorConfiguration& boxCfg,
                       const Vector3D& segmentVelocity,
                       const Vector3D& boxVelocity,
                       Real tFirst);

        FindContactSet(const Triangle3& triangle,
                       const Box3& box,
                       ContactSide side,
                       const IntersectorConfiguration& triangleCfg,
                       const IntersectorConfiguration& boxCfg,
                       const Vector3D& triangleVelocity,
                       const Vector3D& boxVelocity,
                       Real tFirst);

        FindContactSet(const Box3& box0,
                       const Box3& box1,
                       ContactSide side,
                       const IntersectorConfiguration& box0Cfg,
                       const IntersectorConfiguration& box1Cfg,
                       const Vector3D& box0Velocity,
                       const Vector3D& box1Velocity,
                       Real tFirst);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] PointType GetPoint() const;

    private:
        PackageType impl;
    };

    using FloatFindContactSet = FindContactSet<float>;
    using DoubleFindContactSet = FindContactSet<double>;
}

#endif  // MATHEMATICS_INTERSECTION_FIND_CONTACT_SET_H
