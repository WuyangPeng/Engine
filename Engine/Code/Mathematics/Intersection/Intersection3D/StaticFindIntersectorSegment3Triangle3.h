///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/21 9:53)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_TRIANGLE3_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_TRIANGLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects3D/Segment3.h"
#include "Mathematics/Objects3D/Triangle3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorSegment3Triangle3 : public StaticIntersector<Real, Vector3D>
    {
    public:
        using ClassType = StaticFindIntersectorSegment3Triangle3<Real>;
        using ParentType = StaticIntersector<Real, Vector3D>;
        using Vector3D = Vector3D<Real>;
        using Segment3 = Segment3<Real>;
        using Triangle3 = Triangle3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;

    public:
        StaticFindIntersectorSegment3Triangle3(const Segment3& segment, const Triangle3& triangle, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Segment3 GetSegment() const noexcept;
        [[nodiscard]] const Triangle3 GetTriangle() const noexcept;

        // 查找交叉点查询。 相交点为 P = origin + t * direction = b0 * V0 + b1 * V1 + b2 * V2
        [[nodiscard]] Real GetSegmentParameter() const noexcept;
        [[nodiscard]] Real GetTriBary0() const noexcept;
        [[nodiscard]] Real GetTriBary1() const noexcept;
        [[nodiscard]] Real GetTriBary2() const noexcept;

        /// 注意：这些函数旨在在动态查找相交查询之后调用。
        /// 对于“ bool Find()”查询，您打算使用GetSegmentParameter()或三个GetTriBary?()函数自己计算接触点。
        ///  现在，这些函数还支持“bool Find()”查询。
        [[nodiscard]] int GetQuantity() const noexcept;
        [[nodiscard]] const Vector3D GetPoint(int index) const;

    private:
        void Find();

        Segment3 m_Segment;
        Triangle3 m_Triangle;

        // 有关固定交集的信息。
        Real m_SegmentParameter;
        Real m_TriBary0;
        Real m_TriBary1;
        Real m_TriBary2;

        int m_Quantity;
        Vector3D m_Point0;
        Vector3D m_Point1;
    };

    using FloatStaticFindIntersectorSegment3Triangle3 = StaticFindIntersectorSegment3Triangle3<float>;
    using DoubleStaticFindIntersectorSegment3Triangle3 = StaticFindIntersectorSegment3Triangle3<double>;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_TRIANGLE3_H
