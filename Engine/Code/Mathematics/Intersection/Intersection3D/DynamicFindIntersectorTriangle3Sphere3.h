///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/07 16:07)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_TRIANGLE3_SPHERE3_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_TRIANGLE3_SPHERE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/DynamicIntersector.h"
#include "Mathematics/Objects3D/Sphere3.h"
#include "Mathematics/Objects3D/Triangle3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DynamicFindIntersectorTriangle3Sphere3 : public DynamicIntersector<Real, Vector3D>
    {
    public:
        using ClassType = DynamicFindIntersectorTriangle3Sphere3<Real>;
        using ParentType = DynamicIntersector<Real, Vector3D>;
        using Vector3D = Vector3D<Real>;
        using Triangle3 = Triangle3<Real>;
        using Sphere3 = Sphere3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;

    public:
        DynamicFindIntersectorTriangle3Sphere3(const Triangle3& triangle, const Sphere3& sphere, Real tmax,
                                               const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Triangle3 GetTriangle() const noexcept;
        [[nodiscard]] const Sphere3 GetSphere() const noexcept;

        // 接触点。
        [[nodiscard]] const Vector3D GetPoint() const noexcept;

    private:
        using VertexType = std::vector<Vector3D>;

    private:
        /// 动态查找交叉点查询。 如果查询返回“ true”，请使用GetContactTime()获取第一次相交。
        /// 如果该时间为零，则三角形已经与球体相交，并且不计算任何相交集。
        /// 如果这个时间是正数，请使用GetPoint()获取第一个相交点。
        void Find();

    private:
        // 支持动态查询。
        [[nodiscard]] bool FindTriangleSphereCoplanarIntersection(int index, const VertexType& vertexs, const Vector3D& sideNorm, const Vector3D& side, Real tmax, const Vector3D& velocity0, const Vector3D& velocity1);

        [[nodiscard]] bool FindSphereVertexIntersection(const Vector3D& vertex, Real tmax, const Vector3D& velocity0, const Vector3D& velocity1);

        // 要相交的对象。
        Triangle3 m_Triangle;
        Sphere3 m_Sphere;

        // 动态查询的相交点。
        Vector3D m_Point;
    };

    using FloatDynamicFindIntersectorTriangle3Sphere3 = DynamicFindIntersectorTriangle3Sphere3<float>;
    using DoubleDynamicFindIntersectorTriangle3Sphere3 = DynamicFindIntersectorTriangle3Sphere3<double>;
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_TRIANGLE3_SPHERE3_H
