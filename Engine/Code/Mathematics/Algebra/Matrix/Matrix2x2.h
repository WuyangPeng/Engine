///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.5 (2024/02/01 13:25)

#ifndef MATHEMATICS_ALGEBRA_ALGEBRA_MATRIX_2_X_2_H
#define MATHEMATICS_ALGEBRA_ALGEBRA_MATRIX_2_X_2_H

#include "Mathematics/MathematicsDll.h"

#include "Matrix.h"
#include "Mathematics/Algebra/Vector/Vector2.h"

namespace Mathematics::Algebra
{
    template <typename Real>
    using Matrix2x2 = Matrix<2, 2, Real>;

    /// 从一个角度（以弧度为单位）创建旋转矩阵。矩阵是
    /// [MATHEMATICS_USE_MATRIX_VECTOR]
    ///   R(t) = {{c,-s},{s,c}}
    /// [MATHEMATICS_USE_VECTOR_MATRIX]
    ///   R(t) = {{c,s},{-s,c}}
    /// 这里 c = cos(t), s = sin(t),并且内部支架对是矩阵的行。
    template <typename Real>
    NODISCARD Matrix2x2<Real> MakeRotation(Real angle);

    /// 从旋转矩阵中获取角度（弧度）。
    /// 调用方负责确保矩阵是一个旋转矩阵。
    template <typename Real>
    NODISCARD Real GetRotationAngle(const Matrix2x2<Real>& rotation);

    /// 几何运算
    template <typename Real>
    NODISCARD Matrix2x2<Real> Inverse(const Matrix2x2<Real>& matrix, bool* reportInvertibility = nullptr);

    template <typename Real>
    NODISCARD Matrix2x2<Real> Adjoint(const Matrix2x2<Real>& matrix);

    template <typename Real>
    NODISCARD Real Determinant(const Matrix2x2<Real>& matrix);

    template <typename Real>
    NODISCARD Real Trace(const Matrix2x2<Real>& matrix);

    /// 根据用户选择的惯例，将M和V相乘。
    /// 如果是MATHEMATICS_USE_MATRIX_VECTOR，则函数返回M*V。
    /// 如果不是M*V，则函数返回V*M。
    /// 提供此函数是为了隐藏示例应用程序中的预处理器符号。
    template <typename Real>
    NODISCARD Vector2<Real> DoTransform(const Matrix2x2<Real>& matrix, const Vector2<Real>& vector);

    template <typename Real>
    NODISCARD Matrix2x2<Real> DoTransform(const Matrix2x2<Real>& lhs, const Matrix2x2<Real>& rhs);

    /// 对于MATHEMATICS_USE_MATRIX_VECTOR，可逆矩阵的列形成矩阵范围的基础。
    /// 对于MATHEMATICS_USE_VECTOR_MATRIX，可逆矩阵的行形成矩阵范围的基础。
    /// 这些函数允许您访问基向量。
    /// 调用者负责确保矩阵是可逆的（尽管逆不是由这些函数计算的）。
    template <typename Real>
    void SetBasis(Matrix2x2<Real>& matrix, int index, const Vector2<Real>& vector);

    template <typename Real>
    NODISCARD Vector2<Real> GetBasis(const Matrix2x2<Real>& matrix, int index);
}

#endif  // MATHEMATICS_ALGEBRA_ALGEBRA_MATRIX_2_X_2_H
