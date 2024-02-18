///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.5 (2024/01/30 09:50)

#ifndef MATHEMATICS_ALGEBRA_ALGEBRA_VECTOR2_H
#define MATHEMATICS_ALGEBRA_ALGEBRA_VECTOR2_H

#include "Mathematics/MathematicsDll.h"

#include "Vector.h"

namespace Mathematics::Algebra
{
    template <typename Real>
    using Vector2 = Vector<2, Real>;

    /// 使用形式行列式计算垂直线，
    /// perp = det{{e0,e1},{x0,x1}} = (x1,-x0)
    /// 其中e0 = (1,0), e1 = (0,1), 和 v = (x0,x1)。
    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    NODISCARD Vector2<Real> Perp(const Vector2<Real>& vector);

    /// 计算归一化的垂直线。
    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    NODISCARD Vector2<Real> UnitPerp(const Vector2<Real>& vector, bool robust = false);

    /// 计算Dot((x0,x1),Perp(y0,y1)) = x0 * y1 - x1 * y0, 这里 v0 = (x0,x1) 和 v1 = (y0,y1).
    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    NODISCARD Real DotPerp(const Vector2<Real>& lhs, const Vector2<Real>& rhs);

    /// 计算输入向量的正交补码的右手正交正规基。
    /// 函数返回过程中计算的未规范化矢量的最小长度。
    /// 如果该值几乎为零，则输入可能是线性相关的（在数值舍入误差内）。
    /// 在输入时，numInputs必须为1，并且必须初始化vector[0]。在输出时，向量vector[0]和vector[1]形成正交集。
    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    NODISCARD Real ComputeOrthogonalComplement(int numInputs, std::vector<Vector2<Real>>& vector, bool robust = false);

    /// 计算点P相对于三角形的重心坐标<V0，V1，V2>，
    /// P = b0*V0 + b1*V1 + b2*V2，其中b0 + b1 + b2 = 1。
    /// 当{V0,V1,V2}是一个线性独立集时，返回值为“true”。
    /// 从数字上讲，这是通过|det[V0 V1 V2]| <= epsilon来测量的。
    /// 值bary[]仅当返回值为“true”时有效，但当返回值是“false”时设置为零。
    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    NODISCARD bool ComputeBarycentric(const Vector2<Real>& point,
                                      const Vector2<Real>& v0,
                                      const Vector2<Real>& v1,
                                      const Vector2<Real>& v2,
                                      std::array<Real, 3>& bary,
                                      Real epsilon = Real{});
}

#endif  // MATHEMATICS_ALGEBRA_ALGEBRA_VECTOR2_H
