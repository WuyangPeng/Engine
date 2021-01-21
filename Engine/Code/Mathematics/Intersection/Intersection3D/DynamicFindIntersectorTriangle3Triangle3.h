///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/08 10:45)

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
    class FindIntersectorTriangle3Triangle3Impl;

    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<FindIntersectorTriangle3Triangle3Impl<float>>;
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<FindIntersectorTriangle3Triangle3Impl<double>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<FindIntersectorTriangle3Triangle3Impl<Real>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DynamicFindIntersectorTriangle3Triangle3 : public DynamicIntersector<Real, Vector3D>
    {
    public:
        using DynamicFindIntersectorTriangle3Triangle3Impl = FindIntersectorTriangle3Triangle3Impl<Real>;
        PERFORMANCE_UNSHARE_CLASSES_TYPE_DECLARE(DynamicFindIntersectorTriangle3Triangle3);

        using ParentType = DynamicIntersector<Real, Vector3D>;
        using Vector3D = Vector3D<Real>;
        using Triangle3 = Triangle3<Real>;
        using Plane3 = Plane3<Real>;
        using Line3 = Line3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;

    public:
        DynamicFindIntersectorTriangle3Triangle3(const Triangle3& triangle0, const Triangle3& triangle1, Real tmax,
                                                 const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Triangle3 GetTriangle0() const noexcept;
        [[nodiscard]] const Triangle3 GetTriangle1() const noexcept;

        [[nodiscard]] int GetQuantity() const;
        [[nodiscard]] const Vector3D GetPoint(int index) const;

    private:
        using Intersection = std::vector<Vector3D>;
        static constexpr auto sm_Size = 3;
        using Vector3DContainer = std::array<Vector3D, sm_Size>;

    private:
        // 动态查询。
        void Find();

        class Configuration final
        {
        public:
            static constexpr auto sm_IndexSize = 8;
            using IndexContainer = std::array<int, sm_IndexSize>;

            VertexProjectionMap m_Map;  // 顶点如何映射到投影间隔
            IndexContainer m_Index;  // 顶点的排序索引

            // 间隔是 [min,max]
            Real m_Min;
            Real m_Max;
        };

        struct IntersectInfo final
        {
            bool m_Result;
            ContactSide m_Side;
            Configuration m_TCfg0;
            Configuration m_TCfg1;
            Real m_TFirst;
            Real m_TLast;

            IntersectInfo() noexcept;
            IntersectInfo(bool result, ContactSide side, const Configuration& tCfg0, const Configuration& tCfg1, Real tFirst, Real tLast) noexcept;
        };

        [[nodiscard]] IntersectInfo FindOverlap(Real tmax, Real speed, const Configuration& uConfiguration, const Configuration& vConfiguration) noexcept;

        [[nodiscard]] IntersectInfo FindOverlap(const Vector3D& axis, Real tmax, const Vector3D& velocity);

        void FindContactSet(const Triangle3& triangle0, const Triangle3& triangle1, const ContactSide& side,
                            const Configuration& cfg0, const Configuration& cfg1);

        [[nodiscard]] static Configuration ProjectOntoAxis(const Triangle3& triangle, const Vector3D& axis);

        void GetEdgeEdgeIntersection(const Vector3D& u0, const Vector3D& u1, const Vector3D& v0, const Vector3D& v1);

        void GetEdgeFaceIntersection(const Vector3D& u0, const Vector3D& u1, const Triangle3& triangle);

        void GetCoplanarIntersection(const Plane3& plane, const Triangle3& triangle0, const Triangle3& triangle1);

    private:
        IMPL_TYPE_DECLARE(DynamicFindIntersectorTriangle3Triangle3);
    };

    using FloatDynamicFindIntersectorTriangle3Triangle3 = DynamicFindIntersectorTriangle3Triangle3<float>;
    using DoubleDynamicFindIntersectorTriangle3Triangle3 = DynamicFindIntersectorTriangle3Triangle3<double>;
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_TRIANGLE3_TRIANGLE3_H
