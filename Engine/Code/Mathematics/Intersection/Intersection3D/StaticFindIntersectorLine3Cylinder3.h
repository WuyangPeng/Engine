///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/18 18:06)

#ifndef MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_CYLINDER3_H
#define MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_CYLINDER3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects3D/Cylinder3.h"
#include "Mathematics/Objects3D/Line3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorLine3Cylinder3 : public StaticIntersector<Real, Vector3D>
    {
    public:
        using ClassType = StaticFindIntersectorLine3Cylinder3<Real>;
        using ParentType = StaticIntersector<Real, Vector3D>;
        using Vector3D = Vector3D<Real>;
        using Line3 = Line3<Real>;
        using Cylinder3 = Cylinder3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;

    public:
        StaticFindIntersectorLine3Cylinder3(const Line3& line, const Cylinder3& cylinder, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Line3 GetLine() const noexcept;
        [[nodiscard]] const Cylinder3 GetCylinder() const noexcept;

        [[nodiscard]] int GetQuantity() const noexcept;
        [[nodiscard]] const Vector3D GetPoint(int index) const;

    private:
        void Find();

        Line3 m_Line;
        Cylinder3 m_Cylinder;

        int m_Quantity;
        Vector3D m_Point0;
        Vector3D m_Point1;

    public:
        // 由IntersectorRay3Cylinder3和IntersectorSegment3Cylinder3共享。
        struct FindShared
        {
            int m_Quantity;
            Real m_Parameter0;
            Real m_Parameter1;
        };

        [[nodiscard]] static FindShared Find(const Vector3D& origin, const Vector3D& dir, const Cylinder3& cylinder);
    };

    using FloatStaticFindIntersectorLine3Cylinder3 = StaticFindIntersectorLine3Cylinder3<float>;
    using DoubleStaticFindIntersectorLine3Cylinder3 = StaticFindIntersectorLine3Cylinder3<double>;

}

#endif  // MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_CYLINDER3_H
