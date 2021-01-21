///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/06 15:21)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE3_CAPSULE3_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE3_CAPSULE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects3D/Capsule3.h"
#include "Mathematics/Objects3D/Line3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorLine3Capsule3 : public StaticIntersector<Real, Vector3D>
    {
    public:
        using ClassType = StaticFindIntersectorLine3Capsule3<Real>;
        using ParentType = StaticIntersector<Real, Vector3D>;
        using Vector3D = Vector3D<Real>;
        using Line3 = Line3<Real>;
        using Capsule3 = Capsule3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;

    public:
        StaticFindIntersectorLine3Capsule3(const Line3& line, const Capsule3& capsule, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Line3 GetLine() const noexcept;
        [[nodiscard]] const Capsule3 GetCapsule() const noexcept;

        [[nodiscard]] int GetQuantity() const noexcept;
        [[nodiscard]] const Vector3D GetPoint(int index) const;

    private:
        void Find();

        Line3 m_Line;
        Capsule3 m_Capsule;

        int m_Quantity;
        Vector3D m_Point0;
        Vector3D m_Point1;

    public:
        // 由IntersectorRay3Capsule3和IntersectorSegment3Capsule3共享。
        struct FindShared
        {
            int m_Quantity;
            Real m_Parameter0;
            Real m_Parameter1;
        };

        [[nodiscard]] static FindShared Find(const Vector3D& origin, const Vector3D& direction, const Capsule3& capsule);
    };

    using FloatStaticFindIntersectorLine3Capsule3 = StaticFindIntersectorLine3Capsule3<float>;
    using DoubleStaticFindIntersectorLine3Capsule3 = StaticFindIntersectorLine3Capsule3<double>;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE3_CAPSULE3_H
