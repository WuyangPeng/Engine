///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/16 14:34)

#ifndef MATHEMATICS_INTERSECTION_INTERSECTOR1_H
#define MATHEMATICS_INTERSECTION_INTERSECTOR1_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Algebra/Vector2D.h"

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
        using Vector2D = Vector2D<Real>;

    public:
        // 间隔[u0,u1]和[v0,v1]交集的类。
        // 终点必须排序：u0 <= u1和v0 <= v1。
        // 允许sm_MaxReal和-sm_MaxReal的值，
        // 允许退化间隔：u0 = u1或v0 = v1。
        Intersector1(Real u0, Real u1, Real v0, Real v1, const Real epsilon = Math::GetZeroTolerance()) noexcept;
        virtual ~Intersector1() = default;
        Intersector1(const Intersector1& rhs) noexcept = default;
        virtual Intersector1& operator=(const Intersector1& rhs) noexcept = default;
        Intersector1(Intersector1&& rhs) noexcept = default;
        virtual Intersector1& operator=(Intersector1&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        [[nodiscard]] Real GetU(int index) const;
        [[nodiscard]] Real GetV(int index) const;

        [[nodiscard]] virtual bool IsIntersection() const = 0;

        [[nodiscard]] Real GetEpsilon() const noexcept;

    protected:
        virtual void Swap(Intersector1& rhs) noexcept;

    private:
        // 相交的间隔。
        Vector2D m_U;
        Vector2D m_V;

        Real m_Epsilon;
    };

    using FloatIntersector1 = Intersector1<float>;
    using DoubleIntersector1 = Intersector1<double>;
}

#endif  // MATHEMATICS_INTERSECTION_INTERSECTOR1_H
