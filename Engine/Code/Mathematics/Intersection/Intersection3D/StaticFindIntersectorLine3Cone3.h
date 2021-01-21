///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/18 14:28)

#ifndef MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_CONE3_H
#define MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_CONE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects3D/Cone3.h"
#include "Mathematics/Objects3D/Line3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorLine3Cone3 : public StaticIntersector<Real, Vector3D>
    {
    public:
        using ClassType = StaticFindIntersectorLine3Cone3<Real>;
        using ParentType = StaticIntersector<Real, Vector3D>;
        using Vector3D = Vector3D<Real>;
        using Line3 = Line3<Real>;
        using Cone3 = Cone3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;

    public:
        StaticFindIntersectorLine3Cone3(const Line3& line, const Cone3& cone, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Line3 GetLine() const noexcept;
        [[nodiscard]] const Cone3 GetCone() const noexcept;

        /// 相交集。 可能的相交点类型是
        /// IT_EMTPY：没有交集
        /// IT_POINT：m_Point0是交点
        /// IT_SEGMENT：<point0,point1>是相交线段
        /// IT_RAY：point0 + t * point1是相交射线
        [[nodiscard]] int GetQuantity() const noexcept;
        [[nodiscard]] const Vector3D GetPoint(int index) const;

    private:
        void Find();

        Line3 m_Line;
        Cone3 m_Cone;

        int m_Quantity;
        Vector3D m_Point0;
        Vector3D m_Point1;
    };

    using FloatStaticFindIntersectorLine3Cone3 = StaticFindIntersectorLine3Cone3<float>;
    using DoubleStaticFindIntersectorLine3Cone3 = StaticFindIntersectorLine3Cone3<double>;
}

#endif  // MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_CONE3_H
