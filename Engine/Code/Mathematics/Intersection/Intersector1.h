///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.3 (2022/02/23 13:47)

#ifndef MATHEMATICS_INTERSECTION_INTERSECTOR1_H
#define MATHEMATICS_INTERSECTION_INTERSECTOR1_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector2.h"
#include "Mathematics/Base/MathDetail.h"

#include <array>
#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Intersector1
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Intersector1<Real>;
        using Math = Math<Real>;
        using Vector2 = Vector2<Real>;

    public:
        // 间隔[u0,u1]和[v0,v1]交集的类。
        // 终点必须排序：u0 <= u1和v0 <= v1。
        // 允许sm_MaxReal和-sm_MaxReal的值，
        // 允许退化间隔：u0 = u1或v0 = v1。
        Intersector1(Real u0, Real u1, Real v0, Real v1, const Real epsilon = Math::GetZeroTolerance()) noexcept;
        virtual ~Intersector1() = default;
        Intersector1(const Intersector1& rhs) noexcept = default;
        Intersector1& operator=(const Intersector1& rhs) noexcept = default;
        Intersector1(Intersector1&& rhs) noexcept = default;
        Intersector1& operator=(Intersector1&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD Real GetU(int index) const;
        NODISCARD Real GetV(int index) const;

        NODISCARD virtual bool IsIntersection() const = 0;

        NODISCARD Real GetEpsilon() const noexcept;

    protected:
        virtual void Swap(Intersector1& rhs) noexcept;

    private:
        // 相交的间隔。
        Vector2 u;
        Vector2 v;

        Real epsilon;
    };

    using Intersector1F = Intersector1<float>;
    using Intersector1D = Intersector1<double>;
}

#endif  // MATHEMATICS_INTERSECTION_INTERSECTOR1_H
