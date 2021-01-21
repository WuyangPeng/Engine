///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/06 16:46)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SEGMENT3_TRIANGLE3_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SEGMENT3_TRIANGLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/DynamicIntersector.h"
#include "Mathematics/Objects3D/Segment3.h"
#include "Mathematics/Objects3D/Triangle3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DynamicFindIntersectorSegment3Triangle3 : public DynamicIntersector<Real, Vector3D>
    {
    public:
        using ClassType = DynamicFindIntersectorSegment3Triangle3<Real>;
        using ParentType = DynamicIntersector<Real, Vector3D>;
        using Vector3D = Vector3D<Real>;
        using Segment3 = Segment3<Real>;
        using Triangle3 = Triangle3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;

    public:
        DynamicFindIntersectorSegment3Triangle3(const Segment3& segment, const Triangle3& triangle, Real tmax,
                                                const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Segment3 GetSegment() const noexcept;
        [[nodiscard]] const Triangle3 GetTriangle() const noexcept;

        [[nodiscard]] Real GetSegmentParameter() const noexcept;
        [[nodiscard]] Real GetTriangleBary0() const noexcept;
        [[nodiscard]] Real GetTriangleBary1() const noexcept;
        [[nodiscard]] Real GetTriangleBary2() const noexcept;

        /// 这些函数旨在在动态查找交叉点查询之后调用。
        /// 对于“Find()”查询，您打算使用GetSegmentParameter()或三个GetTriangleBary?()函数自己计算接触点。
        [[nodiscard]] int GetQuantity() const noexcept;
        [[nodiscard]] const Vector3D GetPoint(int index) const;

    private:
        /// 动态查找交叉点查询。 当有单个交点时，可以通过GetPoint(0)访问第一个交点；
        /// 如果该交点是一个段，则可以通过GetPoint(0)和GetPoint(1)访问第一个交点，在这种情况下，获取的点是段端点。
        /// 第一次交点是通过GetContactTime()访问的。
        void Find();

        // 要相交的对象。
        Segment3 m_Segment;
        Triangle3 m_Triangle;

        // 有关固定交集的信息。
        Real m_SegmentParameter;
        Real m_TriangleBary0;
        Real m_TriangleBary1;
        Real m_TriangleBary2;

        // 有关动态交集的信息。
        int m_Quantity;
        Vector3D m_Point0;
        Vector3D m_Point1;
    };

    using FloatDynamicFindIntersectorSegment3Triangle3 = DynamicFindIntersectorSegment3Triangle3<float>;
    using DoubleDynamicFindIntersectorSegment3Triangle3 = DynamicFindIntersectorSegment3Triangle3<double>;
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SEGMENT3_TRIANGLE3_H
