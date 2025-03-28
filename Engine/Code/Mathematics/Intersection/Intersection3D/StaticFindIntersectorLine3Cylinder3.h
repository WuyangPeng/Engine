///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 15:06)

#ifndef MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_CYLINDER3_H
#define MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_CYLINDER3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects3D/Cylinder3.h"
#include "Mathematics/Objects3D/Line3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorLine3Cylinder3 : public StaticIntersector<Real, Vector3>
    {
    public:
        using ClassType = StaticFindIntersectorLine3Cylinder3<Real>;
        using ParentType = StaticIntersector<Real, Vector3>;

        using Vector3Type = Vector3<Real>;
        using Line3Type = Line3<Real>;
        using Cylinder3Type = Cylinder3<Real>;
        using Vector3ToolsType = Vector3Tools<Real>;
        using MathType = typename ParentType::MathType;

    public:
        StaticFindIntersectorLine3Cylinder3(const Line3Type& line, const Cylinder3Type& cylinder, const Real epsilon = MathType::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Line3Type GetLine() const noexcept;
        NODISCARD Cylinder3Type GetCylinder() const noexcept;

        NODISCARD int GetQuantity() const noexcept;
        NODISCARD Vector3Type GetPoint(int index) const;

    private:
        void Find();

    private:
        Line3Type line;
        Cylinder3Type cylinder;

        int quantity;
        Vector3Type point0;
        Vector3Type point1;

    public:
        // 由IntersectorRay3Cylinder3和IntersectorSegment3Cylinder3共享。
        struct FindShared
        {
            int quantity;
            Real parameter0;
            Real parameter1;
        };

        NODISCARD static FindShared Find(const Vector3Type& origin, const Vector3Type& dir, const Cylinder3Type& cylinder);
    };
}

#endif  // MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_CYLINDER3_H
