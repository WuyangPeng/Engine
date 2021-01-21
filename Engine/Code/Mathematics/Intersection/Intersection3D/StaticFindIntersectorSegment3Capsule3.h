///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/06 14:06)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_CAPSULE3_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_CAPSULE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects3D/Capsule3.h"
#include "Mathematics/Objects3D/Segment3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorSegment3Capsule3 : public StaticIntersector<Real, Vector3D>
    {
    public:
        using ClassType = StaticFindIntersectorSegment3Capsule3<Real>;
        using ParentType = StaticIntersector<Real, Vector3D>;
        using Vector3D = Vector3D<Real>;
        using Segment3 = Segment3<Real>;
        using Capsule3 = Capsule3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;

    public:
        StaticFindIntersectorSegment3Capsule3(const Segment3& segment, const Capsule3& capsule, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Segment3 GetSegment() const noexcept;
        [[nodiscard]] const Capsule3 GetCapsule() const noexcept;

        [[nodiscard]] int GetQuantity() const noexcept;
        [[nodiscard]] const Vector3D GetPoint(int index) const;
        // 点的段参数
        [[nodiscard]] Real GetParameter0() const noexcept;
        [[nodiscard]] Real GetParameter1() const noexcept;

    private:
        void Find();

        Segment3 m_Segment;
        Capsule3 m_Capsule;

        int m_Quantity;
        Vector3D m_Point0;
        Vector3D m_Point1;
        Real m_Parameter0;
        Real m_Parameter1;
    };

    using FloatStaticFindIntersectorSegment3Capsule3 = StaticFindIntersectorSegment3Capsule3<float>;
    using DoubleStaticFindIntersectorSegment3Capsule3 = StaticFindIntersectorSegment3Capsule3<double>;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_CAPSULE3_H
