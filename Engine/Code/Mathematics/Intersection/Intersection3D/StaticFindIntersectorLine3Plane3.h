///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 15:06)

#ifndef MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_PLANE3_H
#define MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_PLANE3_H

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects3D/Line3.h"
#include "Mathematics/Objects3D/Plane3.h"

namespace Mathematics
{
    // 查找交叉点查询。 相交点为P = origin + t*direction。
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorLine3Plane3 : public StaticIntersector<Real, Vector3>
    {
    public:
        using ClassType = StaticFindIntersectorLine3Plane3<Real>;
        using ParentType = StaticIntersector<Real, Vector3>;

        using Vector3Type = Vector3<Real>;
        using Line3Type = Line3<Real>;
        using Plane3Type = Plane3<Real>;
        using Vector3ToolsType = Vector3Tools<Real>;
        using MathType = typename ParentType::MathType;

    public:
        StaticFindIntersectorLine3Plane3(const Line3Type& line, const Plane3Type& plane, const Real epsilon = MathType::GetZeroTolerance()) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Line3Type GetLine() const noexcept;
        NODISCARD Plane3Type GetPlane() const noexcept;

        NODISCARD Real GetLineParameter() const noexcept;

    private:
        void Find() noexcept;

    private:
        // 相交对象
        Line3Type line;
        Plane3Type plane;

        // 相交对象集信息
        Real lineParameter;
    };
}

#endif  // MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_LINE3_PLANE3_H
