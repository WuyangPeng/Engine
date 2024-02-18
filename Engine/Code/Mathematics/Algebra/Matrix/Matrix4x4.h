///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.5 (2024/02/01 19:06)

#ifndef MATHEMATICS_ALGEBRA_ALGEBRA_MATRIX_4_X_4_H
#define MATHEMATICS_ALGEBRA_ALGEBRA_MATRIX_4_X_4_H

#include "Mathematics/MathematicsDll.h"

#include "Matrix.h"
#include "Mathematics/Algebra/Vector/Vector4.h"

namespace Mathematics::Algebra
{
    template <typename Real>
    using Matrix4x4 = Matrix<4, 4, Real>;

    /// 几何运算。
    template <typename Real>
    NODISCARD Matrix4x4<Real> Inverse(const Matrix4x4<Real>& matrix, bool* reportInvertibility = nullptr);

    template <typename Real>
    NODISCARD Matrix4x4<Real> Adjoint(const Matrix4x4<Real>& matrix);

    template <typename Real>
    NODISCARD Real Determinant(const Matrix4x4<Real>& matrix);

    template <typename Real>
    NODISCARD Real Trace(const Matrix4x4<Real>& matrix);

    /// 根据用户选择的惯例，将M和V相乘。
    /// 如果是MATHEMATICS_USE_MATRIX_VECTOR，则函数返回M*V。
    /// 如果是MATHEMATICS_USE_VECTOR_MATRIX，则函数返回V*M。
    /// 提供此函数是为了隐藏示例应用程序中的预处理器符号。
    template <typename Real>
    NODISCARD Vector4<Real> DoTransform(const Matrix4x4<Real>& matrix, const Vector4<Real>& vector);

    template <typename Real>
    NODISCARD Matrix4x4<Real> DoTransform(const Matrix4x4<Real>& lhs, const Matrix4x4<Real>& rhs);

    /// 对于MATHEMATICS_USE_MATRIX_VECTOR，可逆矩阵的列形成矩阵范围的基础。
    /// 对于MATHEMATICS_USE_VECTOR_MATRIX，可逆矩阵的行形成矩阵范围的基础。
    /// 这些函数允许您访问基向量。
    /// 调用者负责确保矩阵是可逆的（尽管逆不是由这些函数计算的）。
    template <typename Real>
    void SetBasis(Matrix4x4<Real>& matrix, int index, const Vector4<Real>& vector);

    template <typename Real>
    NODISCARD Vector4<Real> GetBasis(const Matrix4x4<Real>& matrix, int index);

    /// 特殊矩阵。在注释中，使用MATHEMATICS_USE_MATRIX_VECTOR乘法约定显示矩阵。

    /// 投影平面是Dot(N,X-P) = 0，其中N是3-by-1单位长度的法向量，P是平面上的3-by-1。
    /// 投影在3-by-1矢量D的方向上倾斜于平面。
    /// Dot(N,D)必须不为零，这样投影才有意义。
    /// 给定一个3-by-1的点U，计算线U+t*D与平面的交点，
    /// 得到t = -Dot(N,U-P)/Dot(N,D)，然后
    ///
    ///   projection(U) = P + [I - D*N^T/Dot(N,D)]*(U-P)
    ///
    /// 表示投影的4-by-4齐次变换是
    ///
    ///       +-                               -+
    ///   M = | D*N^T - Dot(N,D)*I   -Dot(N,P)D |
    ///       |          0^T          -Dot(N,D) |
    ///       +-                               -+
    ///
    /// 其中M通过M*[U^T 1]^T应用于[U^T 1]^T。
    /// 选择矩阵使得每当Dot(N,D) < 0时M[3][3] > 0；
    /// 投影在平面的“正侧”。
    template <typename Real>
    NODISCARD Matrix4x4<Real> MakeObliqueProjection(const Vector4<Real>& origin, const Vector4<Real>& normal, const Vector4<Real>& direction);

    /// 点在平面上的透视投影是
    ///
    ///     +-                                                 -+
    /// M = | Dot(N,E-P)*I - E*N^T    -(Dot(N,E-P)*I - E*N^T)*E |
    ///     |        -N^t                      Dot(N,E)         |
    ///     +-                                                 -+
    ///
    /// 其中E是眼点，P是平面上的点，N是单位长度的平面法线。
    template <typename Real>
    NODISCARD Matrix4x4<Real> MakePerspectiveProjection(const Vector4<Real>& origin, const Vector4<Real>& normal, const Vector4<Real>& eye);

    /// 点通过平面的反射是
    ///     +-                         -+
    /// M = | I-2*N*N^T    2*Dot(N,P)*N |
    ///     |     0^T            1      |
    ///     +-                         -+
    ///
    /// 其中P是平面上的点，N是单位长度的平面法线。
    template <typename Real>
    NODISCARD Matrix4x4<Real> MakeReflection(const Vector4<Real>& origin, const Vector4<Real>& normal);
}

#endif  // MATHEMATICS_ALGEBRA_ALGEBRA_MATRIX_4_X_4_H
