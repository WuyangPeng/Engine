/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.6 (2024/02/23 15:25)

#ifndef MATHEMATICS_OBJECTS_3D_CYLINDER3_H
#define MATHEMATICS_OBJECTS_3D_CYLINDER3_H

#include "Mathematics/MathematicsDll.h"

#include "Line3.h"
#include "Mathematics/Primitives/Line.h"

#include <type_traits>

namespace Mathematics
{
    /// 圆柱体轴是一条直线。
    /// 圆柱体的原点被选择为直线原点。
    /// 气缸壁与轴的距离为R个单位。
    /// 无限的圆柱体有无限的高度。
    /// 有限圆柱体的中心C在直线原点处，并且具有有限高度H。
    /// 有限圆柱体的线段具有端点C-(H/2)*D 和C+(H/2)*D，
    /// 其中D是直线的单位长度方向。
    ///
    /// 注意：一些几何查询涉及无限圆柱体。
    /// 为了支持精确的算术，
    /// 有必要避免std::numeric_limits成员，如infinity()和 max()。
    /// 相反，查询要求您将无限圆柱体的“高度”设置为-1。
    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Cylinder3 final
    {
    public:
        using ClassType = Cylinder3<Real>;

        using Math = Math<Real>;
        using Line3 = Line3<Real>;
        using Vector3 = Vector3<Real>;
        using AlgebraLine3 = Algebra::Line3<Real>;

    public:
        /// 默认构造函数将轴设置为(0,0,1)，将半径设置为1，将高度设置为1。
        Cylinder3() noexcept;

        /// 缸体轴线是一条线。缸体的原点被选择为线原点。
        /// 缸体壁是在距离轴线Real单元。无限的缸体有无限的高度。
        /// 一个有限缸体有中点C在线的起点和具有有限的高度H
        /// 线段为有限圆柱体端点C-(H/2)*D 和 C+(H/2)*D，其中D是线的单位长度方向。
        Cylinder3(const Line3& axis, Real radius, Real height) noexcept;
        Cylinder3(const AlgebraLine3& axis, Real radius, Real height);

        CLASS_INVARIANT_DECLARE;

        NODISCARD Line3 GetAxis() const noexcept;
        NODISCARD Real GetRadius() const noexcept;
        NODISCARD Real GetHeight() const noexcept;
        NODISCARD AlgebraLine3 GetAlgebraAxis() const noexcept;

        // 请阅读本文件开头关于为无限圆柱体设置“高度”构件的注释。
        void MakeInfiniteCylinder() noexcept;

        void MakeFiniteCylinder(Real aHeight) noexcept;

        NODISCARD bool IsFinite() const noexcept;

        NODISCARD bool IsInfinite() const noexcept;

    private:
        Line3 axis;
        Real radius;
        Real height;
    };

    /// 与支持排序容器的比较。
    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    NODISCARD bool operator==(const Cylinder3<Real>& lhs, const Cylinder3<Real>& rhs);

    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    NODISCARD bool operator!=(const Cylinder3<Real>& lhs, const Cylinder3<Real>& rhs);

    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    NODISCARD bool operator<(const Cylinder3<Real>& lhs, const Cylinder3<Real>& rhs);

    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    NODISCARD bool operator<=(const Cylinder3<Real>& lhs, const Cylinder3<Real>& rhs);

    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    NODISCARD bool operator>(const Cylinder3<Real>& lhs, const Cylinder3<Real>& rhs);

    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    NODISCARD bool operator>=(const Cylinder3<Real>& lhs, const Cylinder3<Real>& rhs);

    using Cylinder3F = Cylinder3<float>;
    using Cylinder3D = Cylinder3<double>;
}

#endif  // MATHEMATICS_OBJECTS_3D_CYLINDER3_H
