///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 15:07)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_TRIANGLE3_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_TRIANGLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects3D/Plane3.h"
#include "Mathematics/Objects3D/Triangle3.h"

namespace Mathematics
{
    template <typename Real>
    class StaticFindIntersectorPlane3Triangle3 : public StaticIntersector<Real, Vector3>
    {
    public:
        using ClassType = StaticFindIntersectorPlane3Triangle3<Real>;
        using ParentType = StaticIntersector<Real, Vector3>;

        using Vector3 = Vector3<Real>;
        using Plane3 = Plane3<Real>;
        using Triangle3 = Triangle3<Real>;
        using Vector3Tools = Vector3Tools<Real>;
        using MathType = typename ParentType::MathType;

    public:
        // 如果要进行模糊确定，请将epsilon值设置为较小的正数。
        StaticFindIntersectorPlane3Triangle3(const Plane3& plane, const Triangle3& triangle, Real epsilon = MathType::GetValue(0));

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Plane3 GetPlane() const noexcept;
        NODISCARD Triangle3 GetTriangle() const noexcept;

        // 相交集，它是空的，点，线段或整个三角形（GetQuantity返回0、1、2或3）
        NODISCARD int GetQuantity() const noexcept;
        NODISCARD Vector3 GetPoint(int index) const;

    private:
        void Find();

        Plane3 plane;
        Triangle3 triangle;

        int quantity;
        Vector3 point0;
        Vector3 point1;
        Vector3 point2;
    };
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_TRIANGLE3_H
