///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.6 (2024/02/22 14:44)

#ifndef MATHEMATICS_OBJECTS_2D_SECTOR2_H
#define MATHEMATICS_OBJECTS_2D_SECTOR2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Algebra/Vector/Vector2.h"

/// 实心扇区是圆盘和二维圆锥体的交点。
/// 圆盘的中心为C，半径为R，包含|X-C| <= R的点X。
/// 2D圆锥体的顶点为C，单位长度轴方向为D，从D测量的角度为(0,pi)，
/// 包含点X，Dot(D,(X-C)/|X-C|) >= cos(A)。
/// 扇形点X满足这两个不等式约束。
namespace Mathematics
{
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class Sector2
    {
    public:
        using ClassType = Sector2<Real>;

        using Vector2Type = Algebra::Vector2<Real>;
        using MathType = Math<Real>;

    public:
        /// 默认构造函数将顶点设置为(0,0)，半径设置为1，
        /// 轴方向设置为(1,0)，
        /// 角度设置为pi，
        /// 所有这些都定义了一个圆盘。
        Sector2() noexcept;

        Sector2(const Vector2Type& inVertex,
                Real inRadius,
                const Vector2Type& inDirection,
                Real inAngle) noexcept;

        CLASS_INVARIANT_DECLARE;

        /// 同时设置角度和cos(angle)。
        void SetAngle(Real inAngle) noexcept;

        NODISCARD Vector2Type GetVertex() const noexcept;
        NODISCARD Real GetRadius() const noexcept;
        NODISCARD Vector2Type GetDirection() const noexcept;
        NODISCARD Real GetAngle() const noexcept;
        NODISCARD Real GetCosAngle() const noexcept;
        NODISCARD Real GetSinAngle() const noexcept;

        void SetVertex(const Vector2Type& aVertex) noexcept;
        void SetRadius(Real aRadius) noexcept;
        void SetDirection(const Vector2Type& aDirection) noexcept;

        /// 测试P是否在扇区中。
        NODISCARD bool Contains(const Vector2Type& point) const;

    private:
        /// 在查询中使用角度的余弦和正弦，
        /// 因此存储所有的o角度、cos(angle)和 sin(angle)。
        /// 您可以调用 SetAngle(...) 以确保一致性。
        Vector2Type vertex;
        Real radius;
        Vector2Type direction;
        Real angle;
        Real cosAngle;
        Real sinAngle;
    };

    /// 与支持排序容器的比较。
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator==(const Sector2<Real>& lhs, const Sector2<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator!=(const Sector2<Real>& lhs, const Sector2<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator<(const Sector2<Real>& lhs, const Sector2<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator<=(const Sector2<Real>& lhs, const Sector2<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator>(const Sector2<Real>& lhs, const Sector2<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator>=(const Sector2<Real>& lhs, const Sector2<Real>& rhs);
}

#endif  // MATHEMATICS_OBJECTS_2D_SECTOR2_H
