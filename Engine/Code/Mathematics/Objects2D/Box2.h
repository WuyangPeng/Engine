/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 11:17)

#ifndef MATHEMATICS_OBJECTS_2D_BOX2_H
#define MATHEMATICS_OBJECTS_2D_BOX2_H

#include "Mathematics/MathematicsDll.h"

#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "Mathematics/Algebra/Vector2.h"

#include <iosfwd>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class Box2 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Box2<Real>;

        using MathType = Math<Real>;
        using Vector2Type = Vector2<Real>;
        using VerticesType = std::vector<Vector2Type>;

    public:
        // 一个盒子有中心点C，轴方向U[0]和U[1]（垂直和单位长度的向量），
        // 和范围e[0]和e[1]（非负数）。
        // A point X = C + y[0] * U[0] + y[1] * U[1]是在内部或在盒子上，
        // 每当|y[i]| <= e[i]对于所有的i
        Box2() noexcept;
        Box2(const Vector2Type& center, const Vector2Type& axis0, const Vector2Type& axis1, const Real extent0, const Real extent1, const Real epsilon = MathType::GetZeroTolerance()) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD VerticesType ComputeVertices() const;
        NODISCARD Vector2Type GetCenter() const noexcept;
        NODISCARD Vector2Type GetAxis0() const noexcept;
        NODISCARD Vector2Type GetAxis1() const noexcept;
        NODISCARD Real GetExtent0() const noexcept;
        NODISCARD Real GetExtent1() const noexcept;
        NODISCARD Real GetEpsilon() const noexcept;

        NODISCARD Box2 GetMove(Real t, const Vector2Type& velocity) const;

    private:
        static constexpr auto axisSize = 2;

        using AxisType = std::array<Vector2Type, axisSize>;
        using ExtentType = std::array<Real, axisSize>;

    private:
        Vector2Type center;
        AxisType axis;
        ExtentType extent;
        Real epsilon;
    };

    using Box2F = Box2<float>;
    using Box2D = Box2<double>;

    template <typename Real>
    NODISCARD bool Approximate(const Box2<Real>& lhs, const Box2<Real>& rhs, Real epsilon) noexcept(gAssert < 1 || gMathematicsAssert < 1);

    // 调试输出
    template <typename Real>
    std::ostream& operator<<(std::ostream& outFile, const Box2<Real>& box);
}

#endif  // MATHEMATICS_OBJECTS_2D_BOX2_H
