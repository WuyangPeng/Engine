///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 15:05)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE3_BOX3_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE3_BOX3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects3D/Box3.h"
#include "Mathematics/Objects3D/Line3.h"

namespace Mathematics
{
    template <typename Real>
    class StaticFindIntersectorLine3Box3 : public StaticIntersector<Real, Vector3>
    {
    public:
        using ClassType = StaticFindIntersectorLine3Box3<Real>;
        using ParentType = StaticIntersector<Real, Vector3>;

        using Vector3Type = Vector3<Real>;
        using Line3Type = Line3<Real>;
        using Box3Type = Box3<Real>;
        using Vector3ToolsType = Vector3Tools<Real>;
        using MathType = typename ParentType::MathType;

    public:
        StaticFindIntersectorLine3Box3(const Line3Type& line, const Box3Type& box, const Real epsilon = MathType::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Line3Type GetLine() const noexcept;
        NODISCARD Box3Type GetBox() const noexcept;

        NODISCARD int GetQuantity() const noexcept;
        NODISCARD Vector3Type GetPoint(int index) const;

    private:
        void Find();

        struct ClipType
        {
            bool result;
            Real t0;
            Real t1;
        };

        NODISCARD static ClipType Clip(Real denom, Real numer, Real t0, Real t1) noexcept;

    private:
        Line3Type line;
        Box3Type box;

        int quantity;
        Vector3Type point0;
        Vector3Type point1;

    public:
        // 由IntersectorRay3Box3和IntersectorSegment3Box3共享。
        struct FindShared
        {
            int quantity;
            Vector3Type point0;
            Vector3Type point1;
            IntersectionType intersectionType;
        };

        NODISCARD static FindShared DoClipping(Real t0, Real t1, const Vector3Type& origin, const Vector3Type& direction, const Box3Type& box, bool solid);
    };
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE3_BOX3_H
