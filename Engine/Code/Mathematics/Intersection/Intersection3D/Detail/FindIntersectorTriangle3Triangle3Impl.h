///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/08 10:13)

#ifndef MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_TRIANGLE3_TRIANGLE3_IMPL_H
#define MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_TRIANGLE3_TRIANGLE3_IMPL_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Line3.h"
#include "Mathematics/Objects3D/Plane3.h"
#include "Mathematics/Objects3D/Triangle3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE FindIntersectorTriangle3Triangle3Impl final
    {
    public:
        using ClassType = FindIntersectorTriangle3Triangle3Impl<Real>;
        using Vector3D = Vector3D<Real>;
        using Triangle3 = Triangle3<Real>;
        using Plane3 = Plane3<Real>;
        using Line3 = Line3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = Math<Real>;
        using Container = std::vector<Vector3D>;

    public:
        FindIntersectorTriangle3Triangle3Impl(const Triangle3& triangle0, const Triangle3& triangle1) noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const Triangle3 GetTriangle0() const noexcept;
        [[nodiscard]] const Triangle3 GetTriangle1() const noexcept;

        [[nodiscard]] int GetQuantity() const;
        [[nodiscard]] const Vector3D GetPoint(int index) const;

        void SetPoint(const Container& point);
        void AddPoint(const Vector3D& point);

    private:
        Triangle3 m_Triangle0;
        Triangle3 m_Triangle1;

        Container m_Point;
    };
}

#endif  // MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_TRIANGLE3_TRIANGLE3_IMPL_H
