///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 15:01)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_TRIANGLE3_TRIANGLE3_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_TRIANGLE3_TRIANGLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/DynamicIntersector.h"
#include "Mathematics/Intersection/IntersectionFwd.h"
#include "Mathematics/Objects3D/Line3.h"
#include "Mathematics/Objects3D/Plane3.h"
#include "Mathematics/Objects3D/Triangle3.h"

namespace Mathematics
{
    template <typename Real>
    class DynamicFindIntersectorTriangle3Triangle3 : public DynamicIntersector<Real, Vector3>
    {
    public:
        using ClassType = DynamicFindIntersectorTriangle3Triangle3<Real>;
        using ParentType = DynamicIntersector<Real, Vector3>;

        using Vector3 = Vector3<Real>;
        using Triangle3 = Triangle3<Real>;
        using Plane3 = Plane3<Real>;
        using Line3 = Line3<Real>;
        using Vector3Tools = Vector3Tools<Real>;
        using MathType = typename ParentType::MathType;
        using Container = std::vector<Vector3>;

    public:
        DynamicFindIntersectorTriangle3Triangle3(const Triangle3& triangle0,
                                                 const Triangle3& triangle1,
                                                 Real tmax,
                                                 const Vector3& lhsVelocity,
                                                 const Vector3& rhsVelocity,
                                                 const Real epsilon = MathType::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Triangle3 GetTriangle0() const noexcept;
        NODISCARD Triangle3 GetTriangle1() const noexcept;

        NODISCARD int GetQuantity() const;
        NODISCARD Vector3 GetPoint(int index) const;

    private:
        using Intersection = std::vector<Vector3>;
        static constexpr auto vectorSize = 3;
        using Vector3Container = std::array<Vector3, vectorSize>;

    private:
        // 动态查询。
        void Find();

        class Configuration final
        {
        public:
            static constexpr auto indexSize = 8;
            using IndexContainer = std::array<int, indexSize>;

            VertexProjectionMap vertexProjectionMap;  // 顶点如何映射到投影间隔
            IndexContainer index;  // 顶点的排序索引

            // 间隔是 [min,max]
            Real min;
            Real max;
        };

        struct IntersectInfo final
        {
            bool result;
            ContactSide side;
            Configuration tCfg0;
            Configuration tCfg1;
            Real tFirst;
            Real tLast;

            IntersectInfo() noexcept;
            IntersectInfo(bool result, ContactSide side, const Configuration& tCfg0, const Configuration& tCfg1, Real tFirst, Real tLast) noexcept;
        };

        NODISCARD IntersectInfo FindOverlap(Real tmax, Real speed, const Configuration& uConfiguration, const Configuration& vConfiguration) noexcept;

        NODISCARD IntersectInfo FindOverlap(const Vector3& axis, Real tmax, const Vector3& velocity);

        void FindContactSet(const Triangle3& moveTriangle0,
                            const Triangle3& moveTriangle1,
                            const ContactSide& side,
                            const Configuration& cfg0,
                            const Configuration& cfg1);

        NODISCARD static Configuration ProjectOntoAxis(const Triangle3& triangle, const Vector3& axis);

        void GetEdgeEdgeIntersection(const Vector3& u0, const Vector3& u1, const Vector3& v0, const Vector3& v1);

        void GetEdgeFaceIntersection(const Vector3& u0, const Vector3& u1, const Triangle3& triangle);

        void GetCoplanarIntersection(const Plane3& plane, const Triangle3& moveTriangle0, const Triangle3& moveTriangle1);

    private:
        Triangle3 triangle0;
        Triangle3 triangle1;

        Container point;
    };
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_TRIANGLE3_TRIANGLE3_H
