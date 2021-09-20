///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/16 11:32)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_INTERSECTOR_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_INTERSECTOR_H

#include "Mathematics/MathematicsDll.h"

#include "Intersector.h"

namespace Mathematics
{
    template <typename Real, template <typename> class Vector>
    class DynamicIntersectorImpl;

    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<DynamicIntersectorImpl<float, Vector2D>>;
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<DynamicIntersectorImpl<double, Vector2D>>;
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<DynamicIntersectorImpl<float, Vector3D>>;
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<DynamicIntersectorImpl<double, Vector3D>>;

    template <typename Real, template <typename> class Vector>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<DynamicIntersectorImpl<Real, Vector>>;

    // 动态相交查询。默认实现返回“false”。
    // Find查询生成一个第一次接触的相交集合。
    // 派生类负责提供集合,因为集合的性质依赖于对象类型。
    template <typename Real, template <typename> class Vector>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DynamicIntersector : public Intersector<Real, Vector>
    {
    public:
        using DynamicIntersectorImpl = DynamicIntersectorImpl<Real, Vector>;

    public:
        void Swap(DynamicIntersector& rhs) noexcept;

    public:
        TYPE_DECLARE(DynamicIntersector);
        using ClassShareType = CoreTools::CopyUnsharedClasses;
        ~DynamicIntersector() noexcept = default;
        DynamicIntersector(const DynamicIntersector& rhs);
        DynamicIntersector& operator=(const DynamicIntersector& rhs);
        DynamicIntersector(DynamicIntersector&& rhs) noexcept;
        DynamicIntersector& operator=(DynamicIntersector&& rhs) noexcept;

        using ClassType = DynamicIntersector<Real, Vector>;
        using ParentType = Intersector<Real, Vector>;
        using Math = typename ParentType::Math;
        using VectorType = typename ParentType::VectorType;

    public:
        explicit DynamicIntersector(Real tMax, const VectorType& lhsVelocity, const VectorType& rhsVelocity, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        // 两个物体在第一次接触时动态相交查询的时间。
        [[nodiscard]] Real GetContactTime() const noexcept;
        [[nodiscard]] Real GetTMax() const noexcept;
        [[nodiscard]] const VectorType GetLhsVelocity() const noexcept;
        [[nodiscard]] const VectorType GetRhsVelocity() const noexcept;

    protected:
        void SetContactTime(Real contactTime) noexcept;

    private:
        using ImplPtr = std::shared_ptr<ImplType>;
    private:
        ImplPtr impl;
    };

    using FloatDynamicIntersector2D = DynamicIntersector<float, Vector2D>;
    using FloatDynamicIntersector3D = DynamicIntersector<float, Vector3D>;
    using DoubleDynamicIntersector2D = DynamicIntersector<double, Vector2D>;
    using DoubleDynamicIntersector3D = DynamicIntersector<double, Vector3D>;
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_INTERSECTOR_H
