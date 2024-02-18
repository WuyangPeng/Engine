///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.5 (2024/02/01 17:14)

#ifndef MATHEMATICS_ALGEBRA_ALGEBRA_MATRIX_3_X_3_H
#define MATHEMATICS_ALGEBRA_ALGEBRA_MATRIX_3_X_3_H

#include "Mathematics/MathematicsDll.h"

#include "Matrix.h"
#include "Mathematics/Algebra/Vector/Vector3.h"

namespace Mathematics::Algebra
{
    template <typename Real>
    using Matrix3x3 = Matrix<3, 3, Real>;

    /// 几何运算。
    template <typename Real>
    NODISCARD Matrix3x3<Real> Inverse(const Matrix3x3<Real>& matrix, bool* reportInvertibility = nullptr);

    template <typename Real>
    NODISCARD Matrix3x3<Real> Adjoint(const Matrix3x3<Real>& matrix);

    template <typename Real>
    NODISCARD Real Determinant(const Matrix3x3<Real>& matrix);

    template <typename Real>
    NODISCARD Real Trace(const Matrix3x3<Real>& matrix);

    /// 根据用户选择的惯例，将M和V相乘。
    /// 如果是MATHEMATICS_USE_MATRIX_VECTOR，则函数返回M*V。
    /// 如果是MATHEMATICS_USE_VECTOR_MATRIX，则函数返回V*M。
    /// 提供此函数是为了隐藏示例应用程序中的预处理器符号。
    template <typename Real>
    NODISCARD Vector3<Real> DoTransform(const Matrix3x3<Real>& matrix, const Vector3<Real>& vector);

    template <typename Real>
    NODISCARD Matrix3x3<Real> DoTransform(const Matrix3x3<Real>& lhs, const Matrix3x3<Real>& rhs);

    /// 对于MATHEMATICS_USE_MATRIX_VECTOR，可逆矩阵的列形成矩阵范围的基础。
    /// 对于MATHEMATICS_USE_VECTOR_MATRIX，可逆矩阵的行形成矩阵范围的基础。
    /// 这些函数允许您访问基向量。
    /// 调用者负责确保矩阵是可逆的（尽管逆不是由这些函数计算的）。
    template <typename Real>
    void SetBasis(Matrix3x3<Real>& matrix, int index, const Vector3<Real>& vector);

    template <typename Real>
    NODISCARD Vector3<Real> GetBasis(const Matrix3x3<Real>& matrix, int index);
}

#endif  // MATHEMATICS_ALGEBRA_ALGEBRA_MATRIX_3_X_3_H
