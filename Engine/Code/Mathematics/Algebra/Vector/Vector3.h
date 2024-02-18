///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.5 (2024/01/30 11:33)

#ifndef MATHEMATICS_ALGEBRA_ALGEBRA_VECTOR3_H
#define MATHEMATICS_ALGEBRA_ALGEBRA_VECTOR3_H

#include "Mathematics/MathematicsDll.h"

#include "Vector.h"

namespace Mathematics::Algebra
{
    template <typename Real>
    using Vector3 = Vector<3, Real>;

    /// Cross、UnitCross和DotCross的模板参数N应为3或4。
    /// 当您想使用4元组和4x4矩阵进行仿射代数时，
    /// 后一种情况支持4D中的仿射向量（最后一个分量w=0）。

    /// 使用格式行列式计算叉积：
    /// cross = det{{e0,e1,e2},{x0,x1,x2},{y0,y1,y2}}
    ///         = (x1*y2-x2*y1, x2*y0-x0*y2, x0*y1-x1*y0)
    /// 这里 e0 = (1,0,0), e1 = (0,1,0), e2 = (0,0,1), v0 = (x0,x1,x2), 和
    /// v1 = (y0,y1,y2).
    template <int N, typename Real>
    requires(3 <= N && N <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Vector<N, Real> Cross(const Vector<N, Real>& lhs, const Vector<N, Real>& rhs);

    /// 计算归一化的叉积。
    template <int N, typename Real>
    requires(3 <= N && N <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Vector<N, Real> UnitCross(const Vector<N, Real>& lhs, const Vector<N, Real>& rhs, bool robust = false);

    /// 计算三个矢量的三重标量乘积Dot((x0,x1,x2),Cross((y0,y1,y2),(z0,z1,z2)，
    /// 其中 v0 = (x0,x1,x2), v1 = (y0,y1,y2), 和
    /// v2 =  (z0,z1,z2).
    template <int N, typename Real>
    requires(3 <= N && N <= 4 && std::is_arithmetic_v<Real>)
    NODISCARD Real DotCross(const Vector<N, Real>& v0, const Vector<N, Real>& v1, const Vector<N, Real>& v2);

    /// 计算输入向量的正交补码的右手正交正规基。
    /// 函数返回过程中计算的未规范化矢量的最小长度。
    /// 如果该值几乎为零，则输入可能是线性相关的（在数值舍入误差内）。
    /// 在输入时，numInputs必须为1或2，并且必须初始化vector[0]到vector[numInputs-1]。
    /// 在输出时，向量vector[0]到vector[2]形成正交集。
    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    NODISCARD Real ComputeOrthogonalComplement(int numInputs, std::vector<Vector3<Real>>& vector, bool robust = false);

    /// 计算单位长度向量v2的正交补码的右手正交基{v0，v1，v2}。
    template <typename Real>
    void FastComputeOrthogonalComplement(const Vector3<Real>& v2, Vector3<Real>& v0, Vector3<Real>& v1);

    /// 计算点P相对于四面体的重心坐标<V0,V1,V2,V3>，
    /// P = b0*V0 + b1*V1 + b2*V2 + b3*V3，
    /// 其中b0 + b1 + b2 + b3 = 1。
    /// 返回值为“true”，当｛V0，V1，V2，V3｝是线性独立集时。
    /// 从数字上讲，这是通过|det[V0 V1 V2 V3]| <= epsilon来测量的。
    /// 值bary[]仅当返回值为“true”时有效，但当返回值是“false”时设置为零。
    template <typename Real>
    NODISCARD bool ComputeBarycentric(const Vector3<Real>& point,
                                      const Vector3<Real>& v0,
                                      const Vector3<Real>& v1,
                                      const Vector3<Real>& v2,
                                      const Vector3<Real>& v3,
                                      std::array<Real, 4>& bary,
                                      Real epsilon = Real{});
}

#endif  // MATHEMATICS_ALGEBRA_ALGEBRA_VECTOR3_H
