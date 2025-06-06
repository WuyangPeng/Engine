///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 15:00)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SEGMENT3_TRIANGLE3_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SEGMENT3_TRIANGLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/DynamicIntersector.h"
#include "Mathematics/Objects3D/Segment3.h"
#include "Mathematics/Objects3D/Triangle3.h"

namespace Mathematics
{
    template <typename Real>
    class DynamicFindIntersectorSegment3Triangle3 : public DynamicIntersector<Real, Vector3>
    {
    public:
        using ClassType = DynamicFindIntersectorSegment3Triangle3<Real>;
        using ParentType = DynamicIntersector<Real, Vector3>;

        using Vector3Type = Vector3<Real>;
        using Segment3Type = Segment3<Real>;
        using Triangle3Type = Triangle3<Real>;
        using Vector3ToolsType = Vector3Tools<Real>;
        using MathType = typename ParentType::MathType;

    public:
        DynamicFindIntersectorSegment3Triangle3(const Segment3Type& segment,
                                                const Triangle3Type& triangle,
                                                Real tmax,
                                                const Vector3Type& lhsVelocity,
                                                const Vector3Type& rhsVelocity,
                                                const Real epsilon = MathType::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Segment3Type GetSegment() const noexcept;
        NODISCARD Triangle3Type GetTriangle() const noexcept;

        NODISCARD Real GetSegmentParameter() const noexcept;
        NODISCARD Real GetTriangleBary0() const noexcept;
        NODISCARD Real GetTriangleBary1() const noexcept;
        NODISCARD Real GetTriangleBary2() const noexcept;

        /// 这些函数旨在在动态查找交叉点查询之后调用。
        /// 对于“Find()”查询，您打算使用GetSegmentParameter()或三个GetTriangleBary?()函数自己计算接触点。
        NODISCARD int GetQuantity() const noexcept;
        NODISCARD Vector3Type GetPoint(int index) const;

    private:
        /// 动态查找交叉点查询。 当有单个交点时，可以通过GetPoint(0)访问第一个交点；
        /// 如果该交点是一个段，则可以通过GetPoint(0)和GetPoint(1)访问第一个交点，在这种情况下，获取的点是段端点。
        /// 第一次交点是通过GetContactTime()访问的。
        void Find();

    private:
        // 要相交的对象。
        Segment3Type segment;
        Triangle3Type triangle;

        // 有关固定交集的信息。
        Real segmentParameter;
        Real triangleBary0;
        Real triangleBary1;
        Real triangleBary2;

        // 有关动态交集的信息。
        int quantity;
        Vector3Type point0;
        Vector3Type point1;
    };
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SEGMENT3_TRIANGLE3_H
