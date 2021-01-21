///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/06 10:46)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SEGMENT3_SPHERE3_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SEGMENT3_SPHERE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/DynamicIntersector.h"
#include "Mathematics/Objects3D/Segment3.h"
#include "Mathematics/Objects3D/Sphere3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DynamicFindIntersectorSegment3Sphere3 : public DynamicIntersector<Real, Vector3D>
    {
    public:
        using ClassType = DynamicFindIntersectorSegment3Sphere3<Real>;
        using ParentType = DynamicIntersector<Real, Vector3D>;
        using Vector3D = Vector3D<Real>;
        using Segment3 = Segment3<Real>;
        using Sphere3 = Sphere3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;

    public:
        DynamicFindIntersectorSegment3Sphere3(const Segment3& segment, const Sphere3& sphere, Real tmax,
                                              const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Segment3 GetSegment() const noexcept;
        [[nodiscard]] const Sphere3 GetSphere() const noexcept;

        [[nodiscard]] int GetQuantity() const noexcept;
        [[nodiscard]] const Vector3D GetPoint(int index) const;
        [[nodiscard]] Real GetSegmentParameter0() const noexcept;
        [[nodiscard]] Real GetSegmentParameter1() const noexcept;

    private:
        /// 动态查找交叉点查询。 GetPoint(0)访问第一个交点。 第一次联系是通过GetContactTime()访问的。
        void Find();

        Segment3 m_Segment;
        Sphere3 m_Sphere;

        int m_Quantity;
        Vector3D m_Point0;
        Vector3D m_Point1;
        Real m_SegmentParameter0;
        Real m_SegmentParameter1;
    };

    using FloatDynamicFindIntersectorSegment3Sphere3 = DynamicFindIntersectorSegment3Sphere3<float>;
    using DoubleDynamicFindIntersectorSegment3Sphere3 = DynamicFindIntersectorSegment3Sphere3<double>;
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SEGMENT3_SPHERE3_H
