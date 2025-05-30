///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 16:03)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_INTERSECTOR_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_INTERSECTOR_H

#include "Mathematics/MathematicsDll.h"

#include "Intersector.h"

namespace Mathematics
{
    // 动态相交查询。默认实现返回“false”。
    // Find查询生成一个第一次接触的相交集合。
    // 派生类负责提供集合,因为集合的性质依赖于对象类型。
    template <typename Real, template <typename> class Vector>
    class DynamicIntersector : public Intersector<Real, Vector>
    {
    public:
        using ClassType = DynamicIntersector<Real, Vector>;
        using ParentType = Intersector<Real, Vector>;

        using MathType = typename ParentType::MathType;
        using VectorType = typename ParentType::VectorType;

    public:
        explicit DynamicIntersector(Real tMax, const VectorType& lhsVelocity, const VectorType& rhsVelocity, const Real epsilon = MathType::GetZeroTolerance()) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        // 两个物体在第一次接触时动态相交查询的时间。
        NODISCARD Real GetContactTime() const noexcept;
        NODISCARD Real GetTMax() const noexcept;
        NODISCARD VectorType GetLhsVelocity() const noexcept;
        NODISCARD VectorType GetRhsVelocity() const noexcept;

    protected:
        void SetContactTime(Real newContactTime) noexcept;

    private:
        Real contactTime;
        Real tMax;
        VectorType lhsVelocity;
        VectorType rhsVelocity;
    };

    using DynamicIntersector2F = DynamicIntersector<float, Vector2>;
    using DynamicIntersector3F = DynamicIntersector<float, Vector3>;
    using DynamicIntersector2D = DynamicIntersector<double, Vector2>;
    using DynamicIntersector3D = DynamicIntersector<double, Vector3>;
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_INTERSECTOR_H
