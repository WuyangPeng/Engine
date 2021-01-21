///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/20 16:57)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_PLANE3_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_PLANE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects3D/Line3.h"
#include "Mathematics/Objects3D/Plane3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorPlane3Plane3 : public StaticIntersector<Real, Vector3D>
    {
    public:
        using ClassType = StaticFindIntersectorPlane3Plane3<Real>;
        using ParentType = StaticIntersector<Real, Vector3D>;
        using Vector3D = Vector3D<Real>;
        using Plane3 = Plane3<Real>;
        using Line3 = Line3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;

    public:
        StaticFindIntersectorPlane3Plane3(const Plane3& plane0, const Plane3& plane1, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Plane3 GetPlane0() const noexcept;
        [[nodiscard]] const Plane3 GetPlane1() const noexcept;

        /// 有关交集的信息。 仅获取与交点类型（IT_LINE或IT_PLANE）相对应的交点的特定对象。
        [[nodiscard]] const Line3 GetIntersectionLine() const noexcept;
        [[nodiscard]] const Plane3 GetIntersectionPlane() const noexcept;

    private:
        void Find();

        Plane3 m_Plane0;
        Plane3 m_Plane1;

        Line3 m_IntrLine;
        Plane3 m_IntrPlane;
    };

    using FloatStaticFindIntersectorPlane3Plane3 = StaticFindIntersectorPlane3Plane3<float>;
    using DoubleStaticFindIntersectorPlane3Plane3 = StaticFindIntersectorPlane3Plane3<double>;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_PLANE3_H
