///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.6 (2024/02/24 20:23)

#ifndef MATHEMATICS_OBJECTS_3D_ALGEBRA_ELLIPSE3_H
#define MATHEMATICS_OBJECTS_3D_ALGEBRA_ELLIPSE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector/Vector2.h"
#include "Mathematics/Algebra/Vector/Vector3.h"

namespace Mathematics::Algebra
{
    /// 包含椭圆的平面是Dot(N,X-C) = 0，
    /// 其中X是平面中的任何点，
    /// C是椭圆中心，
    /// N是垂直于平面的单位长度。
    /// 向量A0、A1和N形成正交右手集合。
    /// 平面中的椭圆由X = C + e0*cos(t)*A0 + e1*sin(t)*A1参数化，
    /// 其中A0是长轴，
    /// A1是短轴，
    /// e0和e1是沿这些轴的范围。
    /// 角度t在[-pi,pi)和e0 >= e1 > 0中。
    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    class Ellipse3
    {
    public:
        using ClassType = Ellipse3<Real>;

        using MathType = Math<Real>;
        using Vector2Type = Vector2<Real>;
        using Vector3Type = Vector3<Real>;
        using AxisType = std::array<Vector3Type, 2>;

    public:
        /// 默认构造函数将中心设置为(0,0,0)，
        /// A0设置为(1,0,0)，
        /// A1设置为(0,1,0)、
        /// 法线设置为(0,0,1)、
        /// e0设置为1，
        /// e1设置为1。
        Ellipse3() noexcept;

        Ellipse3(const Vector3Type& center, const Vector3Type& normal, const AxisType& axis, const Vector2Type& extent) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD Vector3Type GetCenter() const noexcept;
        NODISCARD Vector3Type GetNormal() const noexcept;
        NODISCARD AxisType GetAxis() const noexcept;
        NODISCARD Vector3Type GetAxis(int index) const;
        NODISCARD Vector2Type GetExtent() const noexcept;
        NODISCARD Real GetExtent(int index) const;

        void SetCenter(const Vector3Type& aCenter) noexcept;
        void SetNormal(const Vector3Type& aNormal) noexcept;
        void SetAxis(const AxisType& aAxis) noexcept;
        void SetExtent(const Vector2Type& aExtent) noexcept;
        void SetAxis(int index, const Vector3Type& aAxis);

    private:
        Vector3Type center;
        Vector3Type normal;
        AxisType axis;
        Vector2Type extent;
    };

    /// 与支持排序容器的比较。
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator==(const Ellipse3<Real>& lhs, const Ellipse3<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator!=(const Ellipse3<Real>& lhs, const Ellipse3<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator<(const Ellipse3<Real>& lhs, const Ellipse3<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator<=(const Ellipse3<Real>& lhs, const Ellipse3<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator>(const Ellipse3<Real>& lhs, const Ellipse3<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator>=(const Ellipse3<Real>& lhs, const Ellipse3<Real>& rhs);
}

#endif  // MATHEMATICS_OBJECTS_3D_ALGEBRA_ELLIPSE3_H
