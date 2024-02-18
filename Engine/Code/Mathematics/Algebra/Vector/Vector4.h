///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.5 (2024/01/30 14:05)

#ifndef MATHEMATICS_ALGEBRA_ALGEBRA_VECTOR4_H
#define MATHEMATICS_ALGEBRA_ALGEBRA_VECTOR4_H

#include "Mathematics/MathematicsDll.h"

#include "Vector3.h"

namespace Mathematics::Algebra
{
    template <typename Real>
    using Vector4 = Vector<4, Real>;

    /// 在Vector3.h中，Vector3 Cross、UnitCross和DotCross的模板参数N应为3或4。
    /// 当您想使用4元组和4x4矩阵进行仿射代数时，后一种情况支持4D中的仿射向量（最后一个分量w=0）。
    /// 因此，您可以将这些模板函数用于Vector4。

    /// 使用格式行列式计算超叉积：
    template <typename Real>
    NODISCARD Vector4<Real> HyperCross(const Vector4<Real>& v0, const Vector4<Real>& v1, const Vector4<Real>& v2);

    /// 计算归一化的超叉积。
    template <typename Real>
    NODISCARD Vector4<Real> UnitHyperCross(const Vector4<Real>& v0, const Vector4<Real>& v1, const Vector4<Real>& v2, bool robust = false);

    /// 计算 Dot(HyperCross((x0,x1,x2,x3),(y0,y1,y2,y3),(z0,z1,z2,z3)),
    /// (w0,w1,w2,w3)), 这里 v0 = (x0,x1,x2,x3), v1 = (y0,y1,y2,y3),
    /// v2 = (z0,z1,z2,z3), 和 v3 = (w0,w1,w2,w3).
    template <typename Real>
    NODISCARD Real DotHyperCross(const Vector4<Real>& v0, const Vector4<Real>& v1, const Vector4<Real>& v2, const Vector4<Real>& v3);

    /// 计算输入向量的正交补码的右手正交正规基。
    /// 函数返回过程中计算的未规范化矢量的最小长度。
    /// 如果该值几乎为零，则输入可能是线性相关的（在数值舍入误差内）。
    /// 在输入时，numInputs必须是1、2或3，并且必须初始化vector[0]到vector[numInputs-1]。
    /// 在输出时，向量vector[0]到vector[3]形成正交集。
    template <typename Real>
    NODISCARD Real ComputeOrthogonalComplement(int numInputs, std::vector<Vector4<Real>>& vector, bool robust = false);
}

#endif  // MATHEMATICS_ALGEBRA_ALGEBRA_VECTOR4_H
