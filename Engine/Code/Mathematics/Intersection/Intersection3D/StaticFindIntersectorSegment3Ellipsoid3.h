///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/21 9:50)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_ELLIPSOID3_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_ELLIPSOID3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects3D/Ellipsoid3.h"
#include "Mathematics/Objects3D/Segment3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorSegment3Ellipsoid3 : public StaticIntersector<Real, Vector3D>
    {
    public:
        using ClassType = StaticFindIntersectorSegment3Ellipsoid3<Real>;
        using ParentType = StaticIntersector<Real, Vector3D>;
        using Vector3D = Vector3D<Real>;
        using Segment3 = Segment3<Real>;
        using Ellipsoid3 = Ellipsoid3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;

    public:
        StaticFindIntersectorSegment3Ellipsoid3(const Segment3& segment, const Ellipsoid3& ellipsoid, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Segment3 GetSegment() const noexcept;
        [[nodiscard]] const Ellipsoid3 GetEllipsoid() const noexcept;

        /// 相交集。 椭圆体被认为是实体，因此如果线段严格位于椭圆体内部，
        /// 则交点类型为IT_SEGMENT，函数GetPoint(i)返回线段终点。
        /// 如果您希望椭球只是表面本身，并且当线段严格位于椭球内时希望得到“无交集”的结果，
        /// 则只要将IT_SEGMENT作为类型，就将线段终点与GetPoint(i)的值进行比较。 如果它们相同，则将其视为“无交集”。
        [[nodiscard]] int GetQuantity() const noexcept;
        [[nodiscard]] const Vector3D GetPoint(int index) const;

    private:
        void Find();

        Segment3 m_Segment;
        Ellipsoid3 m_Ellipsoid;

        int m_Quantity;
        Vector3D m_Point0;
        Vector3D m_Point1;
    };

    using FloatStaticFindIntersectorSegment3Ellipsoid3 = StaticFindIntersectorSegment3Ellipsoid3<float>;
    using DoubleStaticFindIntersectorSegment3Ellipsoid3 = StaticFindIntersectorSegment3Ellipsoid3<double>;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_ELLIPSOID3_H
