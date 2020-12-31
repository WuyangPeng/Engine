///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/24 17:11)

#ifndef MATHEMATICS_INTERSECTION_INTERSECTOR_LINE3_TRIANGLE3_DATA_H
#define MATHEMATICS_INTERSECTION_INTERSECTOR_LINE3_TRIANGLE3_DATA_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3DTools.h"
#include "Mathematics/Objects3D/Line3.h"
#include "Mathematics/Objects3D/Triangle3.h"

namespace Mathematics
{
    template <typename Real>
    class IntersectorLine3Triangle3Data final
    {
    public:
        using ClassType = IntersectorLine3Triangle3Data<Real>;
        using Vector3D = Vector3D<Real>;
        using Line3 = Line3<Real>;
        using Triangle3 = Triangle3<Real>;
        using Vector3DTools = Vector3DTools<Real>;

    public:
        IntersectorLine3Triangle3Data(const Line3& line, const Triangle3& triangle);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const Line3 GetLine() const;
        [[nodiscard]] const Triangle3 GetTriangle() const;
        [[nodiscard]] Real GetDirectionDotNormal() const noexcept;

        [[nodiscard]] Vector3D GetOriginCrossEdge2() const noexcept;
        [[nodiscard]] Vector3D GetEdge1CrossOrigin() const noexcept;
        [[nodiscard]] Real GetOriginDotNormal() const noexcept;

    private:
        void CalculateDirectionDotNormal();

    private:
        // 相交对象
        Line3 m_Line;
        Triangle3 m_Triangle;
        Vector3D m_Origin;
        Vector3D m_Edge1;
        Vector3D m_Edge2;
        Vector3D m_Normal;
        Real m_DirectionDotNormal;
    };
}

#endif  // MATHEMATICS_INTERSECTION_INTERSECTOR_LINE3_TRIANGLE3_DATA_H