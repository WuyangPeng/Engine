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

        using Vector3 = Vector3<Real>;
        using Line3 = Line3<Real>;
        using Box3 = Box3<Real>;
        using Vector3Tools = Vector3Tools<Real>;
        using MathType = typename ParentType::MathType;

    public:
        StaticFindIntersectorLine3Box3(const Line3& line, const Box3& box, const Real epsilon = MathType::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Line3 GetLine() const noexcept;
        NODISCARD Box3 GetBox() const noexcept;

        NODISCARD int GetQuantity() const noexcept;
        NODISCARD Vector3 GetPoint(int index) const;

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
        Line3 line;
        Box3 box;

        int quantity;
        Vector3 point0;
        Vector3 point1;

    public:
        // 由IntersectorRay3Box3和IntersectorSegment3Box3共享。
        struct FindShared
        {
            int quantity;
            Vector3 point0;
            Vector3 point1;
            IntersectionType intersectionType;
        };

        NODISCARD static FindShared DoClipping(Real t0, Real t1, const Vector3& origin, const Vector3& direction, const Box3& box, bool solid);
    };
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE3_BOX3_H
