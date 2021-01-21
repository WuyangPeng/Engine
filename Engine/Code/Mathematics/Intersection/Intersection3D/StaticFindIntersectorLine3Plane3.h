///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/20 10:45)

#ifndef MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_PLANE3_H
#define MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_PLANE3_H

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects3D/Line3.h"
#include "Mathematics/Objects3D/Plane3.h"

namespace Mathematics
{
    // 查找交叉点查询。 相交点为P = origin + t*direction。
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorLine3Plane3 : public StaticIntersector<Real, Vector3D>
    {
    public:
        using ClassType = StaticFindIntersectorLine3Plane3<Real>;
        using ParentType = StaticIntersector<Real, Vector3D>;
        using Vector3D = Vector3D<Real>;
        using Line3 = Line3<Real>;
        using Plane3 = Plane3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;

    public:
        StaticFindIntersectorLine3Plane3(const Line3& line, const Plane3& plane, const Real epsilon = Math::GetZeroTolerance()) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Line3 GetLine() const noexcept;
        [[nodiscard]] const Plane3 GetPlane() const noexcept;

        [[nodiscard]] Real GetLineParameter() const noexcept;

    private:
        void Find() noexcept;

    private:
        // 相交对象
        Line3 m_Line;
        Plane3 m_Plane;

        // 相交对象集信息
        Real m_LineParameter;
    };

    using FloatStaticFindIntersectorLine3Plane3 = StaticFindIntersectorLine3Plane3<float>;
    using DoubleStaticFindIntersectorLine3Plane3 = StaticFindIntersectorLine3Plane3<double>;
}

#endif  // MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_PLANE3_H
