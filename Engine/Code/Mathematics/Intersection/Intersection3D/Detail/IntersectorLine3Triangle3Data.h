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

        using Vector3Type = Vector3<Real>;
        using Line3Type = Line3<Real>;
        using Triangle3Type = Triangle3<Real>;
        using Vector3ToolsType = Vector3Tools<Real>;

    public:
        IntersectorLine3Triangle3Data(const Line3Type& line, const Triangle3Type& triangle);

        CLASS_INVARIANT_DECLARE;

        NODISCARD Line3Type GetLine() const;
        NODISCARD Triangle3Type GetTriangle() const;
        NODISCARD Real GetDirectionDotNormal() const noexcept;

        NODISCARD Vector3Type GetOriginCrossEdge2() const noexcept;
        NODISCARD Vector3Type GetEdge1CrossOrigin() const noexcept;
        NODISCARD Real GetOriginDotNormal() const noexcept;

    private:
        void CalculateDirectionDotNormal();

    private:
        // 相交对象
        Line3Type line;
        Triangle3Type triangle;
        Vector3Type origin;
        Vector3Type edge1;
        Vector3Type edge2;
        Vector3Type normal;
        Real directionDotNormal;
    };
}

#endif  // MATHEMATICS_INTERSECTION_INTERSECTOR_LINE3_TRIANGLE3_DATA_H