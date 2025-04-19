///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 15:08)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_CYLINDER3_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_CYLINDER3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects3D/Cylinder3.h"
#include "Mathematics/Objects3D/Segment3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorSegment3Cylinder3 : public StaticIntersector<Real, Vector3>
    {
    public:
        using ClassType = StaticFindIntersectorSegment3Cylinder3<Real>;
        using ParentType = StaticIntersector<Real, Vector3>;

        using Vector3Type = Vector3<Real>;
        using Segment3Type = Segment3<Real>;
        using Cylinder3Type = Cylinder3<Real>;
        using Vector3ToolsType = Vector3Tools<Real>;
        using MathType = typename ParentType::MathType;

    public:
        StaticFindIntersectorSegment3Cylinder3(const Segment3Type& segment, const Cylinder3Type& cylinder, const Real epsilon = MathType::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Segment3Type GetSegment() const noexcept;
        NODISCARD Cylinder3Type GetCylinder() const noexcept;

        NODISCARD int GetQuantity() const noexcept;
        NODISCARD Vector3Type GetPoint(int index) const;

    private:
        void Find();

    private:
        Segment3Type segment;
        Cylinder3Type cylinder;

        int quantity;
        Vector3Type point0;
        Vector3Type point1;
    };
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_CYLINDER3_H
