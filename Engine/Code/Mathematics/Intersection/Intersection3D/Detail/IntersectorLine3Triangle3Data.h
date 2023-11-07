///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 14:55)

#ifndef MATHEMATICS_INTERSECTION_INTERSECTOR_LINE3_TRIANGLE3_DATA_H
#define MATHEMATICS_INTERSECTION_INTERSECTOR_LINE3_TRIANGLE3_DATA_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3Tools.h"
#include "Mathematics/Objects3D/Line3.h"
#include "Mathematics/Objects3D/Triangle3.h"

namespace Mathematics
{
    template <typename Real>
    class IntersectorLine3Triangle3Data final
    {
    public:
        using ClassType = IntersectorLine3Triangle3Data<Real>;

        using Vector3 = Vector3<Real>;
        using Line3 = Line3<Real>;
        using Triangle3 = Triangle3<Real>;
        using Vector3Tools = Vector3Tools<Real>;

    public:
        IntersectorLine3Triangle3Data(const Line3& line, const Triangle3& triangle);

        CLASS_INVARIANT_DECLARE;

        NODISCARD Line3 GetLine() const;
        NODISCARD Triangle3 GetTriangle() const;
        NODISCARD Real GetDirectionDotNormal() const noexcept;

        NODISCARD Vector3 GetOriginCrossEdge2() const noexcept;
        NODISCARD Vector3 GetEdge1CrossOrigin() const noexcept;
        NODISCARD Real GetOriginDotNormal() const noexcept;

    private:
        void CalculateDirectionDotNormal();

    private:
        // 相交对象
        Line3 line;
        Triangle3 triangle;
        Vector3 origin;
        Vector3 edge1;
        Vector3 edge2;
        Vector3 normal;
        Real directionDotNormal;
    };
}

#endif  // MATHEMATICS_INTERSECTION_INTERSECTOR_LINE3_TRIANGLE3_DATA_H