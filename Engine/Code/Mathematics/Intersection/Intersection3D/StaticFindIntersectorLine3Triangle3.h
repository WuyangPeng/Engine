// Copyright (c) 2010-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎版本：0.0.2.5 (2020/03/24 14:50)

#ifndef MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_TRIANGLE3_H
#define MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_TRIANGLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects3D/Line3.h"
#include "Mathematics/Objects3D/Triangle3.h"

namespace Mathematics
{
    // 查找相交查询。这个相交点是
    // P = origin + t * direction = b0 * V0 + b1 * V1 + b2 * V2
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorLine3Triangle3 : public StaticIntersector<Real, Vector3D>
    {
    public:
        using ClassType = StaticFindIntersectorLine3Triangle3<Real>;
        using ParentType = StaticIntersector<Real, Vector3D>;
        using Vector3D = Vector3D<Real>;
        using Line3 = Line3<Real>;
        using Triangle3 = Triangle3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;

    public:
        StaticFindIntersectorLine3Triangle3(const Line3& line, const Triangle3& triangle, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Line3 GetLine() const noexcept;
        [[nodiscard]] const Triangle3 GetTriangle() const noexcept;

        [[nodiscard]] Real GetLineParameter() const noexcept;
        [[nodiscard]] Real GetTriangleBary0() const noexcept;
        [[nodiscard]] Real GetTriangleBary1() const noexcept;
        [[nodiscard]] Real GetTriangleBary2() const noexcept;

    private:
        void Find();

    private:
        // 相交对象
        Line3 m_Line;
        Triangle3 m_Triangle;

        // 相交对象集信息
        Real m_LineParameter;
        Real m_TriangleBary0;
        Real m_TriangleBary1;
        Real m_TriangleBary2;
    };

    using FloatStaticFindIntersectorLine3Triangle3 = StaticFindIntersectorLine3Triangle3<float>;
    using DoubleStaticFindIntersectorLine3Triangle3 = StaticFindIntersectorLine3Triangle3<double>;
}

#endif  // MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_TRIANGLE3_H
