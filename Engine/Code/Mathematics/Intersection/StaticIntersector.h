///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/08 19:14)

#ifndef MATHEMATICS_INTERSECTION_STATIC_INTERSECTOR_H
#define MATHEMATICS_INTERSECTION_STATIC_INTERSECTOR_H

#include "Intersector.h"

namespace Mathematics
{
    // 静态相交查询。默认实现返回“false”。Find查询生成一个相交集合。
    // 派生类负责提供集合,因为集合的性质依赖于对象类型。
    template <typename Real, template <typename> class Vector>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticIntersector : public Intersector<Real, Vector>
    {
    public:
        using ClassType = StaticIntersector<Real, Vector>;
        using ParentType = Intersector<Real, Vector>;
        using Math = typename ParentType::Math;

    public:
        explicit StaticIntersector(const Real epsilon = Math::GetZeroTolerance()) noexcept;
        ~StaticIntersector() noexcept = 0;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26434)

        StaticIntersector(const StaticIntersector& rhs) noexcept = default;
        StaticIntersector(StaticIntersector&& rhs) noexcept = default;

#include STSTEM_WARNING_POP

        StaticIntersector& operator=(const StaticIntersector& rhs) noexcept = default;
        StaticIntersector& operator=(StaticIntersector&& rhs) noexcept = default;

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };

    using StaticIntersector2F = StaticIntersector<float, Vector2>;
    using StaticIntersector3F = StaticIntersector<float, Vector3>;
    using StaticIntersector2D = StaticIntersector<double, Vector2>;
    using StaticIntersector3D = StaticIntersector<double, Vector3>;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_INTERSECTOR_H
