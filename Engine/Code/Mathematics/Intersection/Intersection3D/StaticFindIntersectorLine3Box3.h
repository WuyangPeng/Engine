///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/18 13:08)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE3_BOX3_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE3_BOX3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects3D/Box3.h"
#include "Mathematics/Objects3D/Line3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorLine3Box3 : public StaticIntersector<Real, Vector3D>
    {
    public:
        using ClassType = StaticFindIntersectorLine3Box3<Real>;
        using ParentType = StaticIntersector<Real, Vector3D>;
        using Vector3D = Vector3D<Real>;
        using Line3 = Line3<Real>;
        using Box3 = Box3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;

    public:
        StaticFindIntersectorLine3Box3(const Line3& line, const Box3& box, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Line3 GetLine() const noexcept;
        [[nodiscard]] const Box3 GetBox() const noexcept;

        [[nodiscard]] int GetQuantity() const noexcept;
        [[nodiscard]] const Vector3D GetPoint(int index) const;

    private:
        void Find();

        struct ClipType
        {
            bool m_Result;
            Real m_T0;
            Real m_T1;
        };

        [[nodiscard]] static ClipType Clip(Real denom, Real numer, Real t0, Real t1) noexcept;

    private:
        Line3 m_Line;
        Box3 m_Box;

        int m_Quantity;
        Vector3D m_Point0;
        Vector3D m_Point1;

    public:
        // 由IntersectorRay3Box3和IntersectorSegment3Box3共享。
        struct FindShared
        {
            int m_Quantity;
            Vector3D m_Point0;
            Vector3D m_Point1;
            IntersectionType m_IntersectionType;
        };

        [[nodiscard]] static FindShared DoClipping(Real t0, Real t1, const Vector3D& origin, const Vector3D& direction, const Box3& box, bool solid);
    };

    using FloatStaticFindIntersectorLine3Box3 = StaticFindIntersectorLine3Box3<float>;
    using DoubleStaticFindIntersectorLine3Box3 = StaticFindIntersectorLine3Box3<double>;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE3_BOX3_H
