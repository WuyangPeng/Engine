///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/08 15:46)

#ifndef MATHEMATICS_OBJECTS_3D_RECTANGLE3_H
#define MATHEMATICS_OBJECTS_3D_RECTANGLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3.h"

#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class Rectangle3 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Rectangle3<Real>;
        using Math = Math<Real>;
        using Vector3 = Vector3<Real>;
        using VerticesType = std::vector<Vector3>;

    public:
        // 点Real(s,t) = C + s0 * U0 + s1 * U1，其中C是矩形的中心，U0和U1是单位长度的垂直轴。
        // 参数s0和s1是由约束|s0| <= e0 和|s1| <= e1，
        // 其中e0 > 0和e1 > 0称为矩形的范围。
        Rectangle3(const Vector3& center, const Vector3& axis0, const Vector3& axis1, Real extent0, Real extent1, Real epsilon = Math::GetZeroTolerance()) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD Vector3 GetCenter() const noexcept;
        NODISCARD Vector3 GetAxis0() const noexcept;
        NODISCARD Vector3 GetAxis1() const noexcept;
        NODISCARD Real GetExtent0() const noexcept;
        NODISCARD Real GetExtent1() const noexcept;

        NODISCARD Vector3 GetAxis(int index) const;
        NODISCARD Real GetExtent(int index) const;

        // 返回矩形的四个顶点
        NODISCARD VerticesType ComputeVertices() const;

        // 获取矩形角。
        NODISCARD Vector3 GetPPCorner() const;  // C + e0 * A0 + e1 * A1
        NODISCARD Vector3 GetPMCorner() const;  // C + e0 * A0 - e1 * A1
        NODISCARD Vector3 GetMPCorner() const;  // C - e0 * A0 + e1 * A1
        NODISCARD Vector3 GetMMCorner() const;  // C - e0 * A0 - e1 * A1

        NODISCARD Rectangle3 GetMove(Real t, const Vector3& velocity) const;

    private:
        static constexpr auto axisSize = 2;

        using AxisType = std::array<Vector3, axisSize>;
        using ExtentType = std::array<Real, axisSize>;

    private:
        Vector3 center;
        AxisType axis;
        ExtentType extent;

        Real epsilon;
    };

    using Rectangle3F = Rectangle3<float>;
    using Rectangle3D = Rectangle3<double>;
}

#endif  // MATHEMATICS_OBJECTS_3D_RECTANGLE3_H
