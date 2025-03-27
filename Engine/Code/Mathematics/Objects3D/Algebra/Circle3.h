/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.6 (2024/02/22 16:38)

#ifndef MATHEMATICS_OBJECTS_3D_ALGEBRA_CIRCLE3_H
#define MATHEMATICS_OBJECTS_3D_ALGEBRA_CIRCLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector/Vector3.h"

namespace Mathematics::Algebra
{
    /// 圆是球体|X-C|^2 = r^2和平面Dot(N,X-C) = 0的交点，
    /// 其中C是圆心，r是半径，N是单位长度的平面法线。
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class Circle3
    {
    public:
        using ClassType = Circle3<Real>;

        using Vector3Type = Vector3<Real>;
        using MathType = Math<Real>;

    public:
        /// 默认构造函数将中心设置为(0,0,0)，法线设置为(0,0,1)，半径设置为1。
        Circle3() noexcept;

        Circle3(const Vector3Type& inCenter, const Vector3Type& inNormal, Real inRadius) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD Vector3Type GetCenter() const noexcept;
        NODISCARD Vector3Type GetNormal() const noexcept;
        NODISCARD Real GetRadius() const noexcept;

        NODISCARD void SetCenter(const Vector3Type& aCenter) noexcept;
        NODISCARD void SetNormal(const Vector3Type& aNormal) noexcept;
        NODISCARD void SetRadius(Real aRadius) noexcept;

    private:
        Vector3Type center;
        Vector3Type normal;
        Real radius;
    };

    /// 与支持排序容器的比较。
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator==(const Circle3<Real>& lhs, const Circle3<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator!=(const Circle3<Real>& lhs, const Circle3<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator<(const Circle3<Real>& lhs, const Circle3<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator<=(const Circle3<Real>& lhs, const Circle3<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator>(const Circle3<Real>& lhs, const Circle3<Real>& rhs);

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    NODISCARD bool operator>=(const Circle3<Real>& lhs, const Circle3<Real>& rhs);
}

#endif  // MATHEMATICS_OBJECTS_3D_ALGEBRA_CIRCLE3_H
