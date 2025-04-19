///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 15:01)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_TRIANGLE3_SPHERE3_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_TRIANGLE3_SPHERE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/DynamicIntersector.h"
#include "Mathematics/Objects3D/Sphere3.h"
#include "Mathematics/Objects3D/Triangle3.h"

namespace Mathematics
{
    template <typename Real>
    class DynamicFindIntersectorTriangle3Sphere3 : public DynamicIntersector<Real, Vector3>
    {
    public:
        using ClassType = DynamicFindIntersectorTriangle3Sphere3<Real>;
        using ParentType = DynamicIntersector<Real, Vector3>;

        using Vector3Type = Vector3<Real>;
        using Triangle3Type = Triangle3<Real>;
        using Sphere3Type = Sphere3<Real>;
        using Vector3ToolsType = Vector3Tools<Real>;
        using MathType = typename ParentType::MathType;

    public:
        DynamicFindIntersectorTriangle3Sphere3(const Triangle3Type& triangle,
                                               const Sphere3Type& sphere,
                                               Real tMax,
                                               const Vector3Type& lhsVelocity,
                                               const Vector3Type& rhsVelocity,
                                               const Real epsilon = MathType::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Triangle3Type GetTriangle() const noexcept;
        NODISCARD Sphere3Type GetSphere() const noexcept;

        // 接触点。
        NODISCARD Vector3Type GetPoint() const noexcept;

    private:
        using VertexType = std::vector<Vector3Type>;

    private:
        /// 动态查找交叉点查询。 如果查询返回“ true”，请使用GetContactTime()获取第一次相交。
        /// 如果该时间为零，则三角形已经与球体相交，并且不计算任何相交集。
        /// 如果这个时间是正数，请使用GetPoint()获取第一个相交点。
        void Find();

    private:
        // 支持动态查询。
        NODISCARD bool FindTriangleSphereCoplanarIntersection(int index, const VertexType& vertexs, const Vector3Type& sideNorm, const Vector3Type& side, Real tmax, const Vector3Type& velocity0, const Vector3Type& velocity1);

        NODISCARD bool FindSphereVertexIntersection(const Vector3Type& vertex, Real tmax, const Vector3Type& velocity0, const Vector3Type& velocity1);

    private:
        // 要相交的对象。
        Triangle3Type triangle;
        Sphere3Type sphere;

        // 动态查询的相交点。
        Vector3Type point;
    };
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_TRIANGLE3_SPHERE3_H
