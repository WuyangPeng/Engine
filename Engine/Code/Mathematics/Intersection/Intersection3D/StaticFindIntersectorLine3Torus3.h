///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/20 13:22)

#ifndef MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_TORUS3_H
#define MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_TORUS3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects3D/Line3.h"
#include "Mathematics/Objects3D/Torus3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorLine3Torus3 : public StaticIntersector<Real, Vector3D>
    {
    public:
        using ClassType = StaticFindIntersectorLine3Torus3<Real>;
        using ParentType = StaticIntersector<Real, Vector3D>;
        using Vector3D = Vector3D<Real>;
        using Line3 = Line3<Real>;
        using Torus3 = Torus3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;

    public:
        StaticFindIntersectorLine3Torus3(const Line3& line, const Torus3& torus, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Line3 GetLine() const noexcept;
        [[nodiscard]] const Torus3 GetTorus() const noexcept;

        // 相交集（数量最多为4）。
        [[nodiscard]] int GetQuantity() const noexcept;
        [[nodiscard]] const Vector3D GetPoint(int index) const;

    private:
        void Find();

        Line3 m_Line;
        Torus3 m_Torus;

        int m_Quantity;
        Vector3D m_Point0;
        Vector3D m_Point1;
        Vector3D m_Point2;
        Vector3D m_Point3;
    };

    using FloatStaticFindIntersectorLine3Torus3 = StaticFindIntersectorLine3Torus3<float>;
    using DoubleStaticFindIntersectorLine3Torus3 = StaticFindIntersectorLine3Torus3<double>;
}

#endif  // MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_TORUS3_H
