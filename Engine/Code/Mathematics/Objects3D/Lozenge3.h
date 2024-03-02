/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.6 (2024/02/26 15:32)

#ifndef MATHEMATICS_OBJECTS_3D_LOZENGE3_H
#define MATHEMATICS_OBJECTS_3D_LOZENGE3_H

#include "Mathematics/MathematicsDll.h"

#include "Rectangle3.h"
#include "Mathematics/Primitives/Rectangle.h"

namespace Mathematics
{
    /// 菱形是一组是等距的矩形的点，共同的距离称为半径。
    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    class Lozenge3 final
    {
    public:
        using ClassType = Lozenge3<Real>;

        using Math = Math<Real>;
        using Rectangle3 = Rectangle3<Real>;
        using AlgebraRectangle3 = Algebra::Rectangle3<Real>;

    public:
        /// 默认构造函数将矩形设置为原点(0,0,0)、
        /// 轴(1,0,0)和 (0,1,0)以及范围均为1。
        /// 默认半径为1。
        Lozenge3() noexcept;
        Lozenge3(const Rectangle3& rectangle, Real radius) noexcept;
        Lozenge3(const AlgebraRectangle3& rectangle, Real radius);

        CLASS_INVARIANT_DECLARE;

        NODISCARD Rectangle3 GetRectangle() const noexcept;
        NODISCARD AlgebraRectangle3 GetAlgebraRectangle() const noexcept;
        NODISCARD Real GetRadius() const noexcept;

    private:
        Rectangle3 rectangle;
        Real radius;
    };

    /// 与支持排序容器的比较。
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator==(const Lozenge3<Real>& lhs, const Lozenge3<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator!=(const Lozenge3<Real>& lhs, const Lozenge3<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator<(const Lozenge3<Real>& lhs, const Lozenge3<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator<=(const Lozenge3<Real>& lhs, const Lozenge3<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator>(const Lozenge3<Real>& lhs, const Lozenge3<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator>=(const Lozenge3<Real>& lhs, const Lozenge3<Real>& rhs);

    using Lozenge3F = Lozenge3<float>;
    using Lozenge3D = Lozenge3<double>;
}

#endif  // MATHEMATICS_OBJECTS_3D_LOZENGE3_H
