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
    class StaticFindIntersectorSegment3Triangle3 : public StaticIntersector<Real, Vector3>
    {
    public:
        using ClassType = StaticFindIntersectorSegment3Triangle3<Real>;
        using ParentType = StaticIntersector<Real, Vector3>;
        using Vector3 = Vector3<Real>;
        using Segment3 = Segment3<Real>;
        using Triangle3 = Triangle3<Real>;
        using Vector3Tools = Vector3Tools<Real>;
        using Math = typename ParentType::Math;

    public:
        StaticFindIntersectorSegment3Triangle3(const Segment3& segment, const Triangle3& triangle, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD const Segment3 GetSegment() const noexcept;
        NODISCARD const Triangle3 GetTriangle() const noexcept;

        // 查找交叉点查询。 相交点为 P = origin + t * direction = b0 * V0 + b1 * V1 + b2 * V2
        NODISCARD Real GetSegmentParameter() const noexcept;
        NODISCARD Real GetTriBary0() const noexcept;
        NODISCARD Real GetTriBary1() const noexcept;
        NODISCARD Real GetTriBary2() const noexcept;

        /// 注意：这些函数旨在在动态查找相交查询之后调用。
        /// 对于“ bool Find()”查询，您打算使用GetSegmentParameter()或三个GetTriBary?()函数自己计算接触点。
        ///  现在，这些函数还支持“bool Find()”查询。
        NODISCARD int GetQuantity() const noexcept;
        NODISCARD const Vector3 GetPoint(int index) const;

    private:
        void Find();

        Segment3 segment;
        Triangle3 triangle;

        // 有关固定交集的信息。
        Real segmentParameter;
        Real triBary0;
        Real triBary1;
        Real triBary2;

        int quantity;
        Vector3 point0;
        Vector3 point1;
    };
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_TRIANGLE3_H
