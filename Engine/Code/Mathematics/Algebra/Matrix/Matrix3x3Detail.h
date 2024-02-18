///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.5 (2024/02/01 17:14)

#ifndef MATHEMATICS_ALGEBRA_ALGEBRA_MATRIX3_X_3_DETAIL_H
#define MATHEMATICS_ALGEBRA_ALGEBRA_MATRIX3_X_3_DETAIL_H

#include "Matrix3x3.h"
#include "MatrixDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector/VectorDetail.h"

template <typename Real>
Mathematics::Algebra::Matrix3x3<Real> Mathematics::Algebra::Inverse(const Matrix3x3<Real>& matrix, bool* reportInvertibility)
{
    Matrix3x3<Real> inverse{};
    auto invertible = false;
    const auto c00 = matrix(1, 1) * matrix(2, 2) - matrix(1, 2) * matrix(2, 1);
    const auto c10 = matrix(1, 2) * matrix(2, 0) - matrix(1, 0) * matrix(2, 2);
    const auto c20 = matrix(1, 0) * matrix(2, 1) - matrix(1, 1) * matrix(2, 0);
    const auto det = matrix(0, 0) * c00 + matrix(0, 1) * c10 + matrix(0, 2) * c20;

    if (!Math<Real>::Approximate(det, Real{}))
    {
        const auto invDet = Math<Real>::GetValue(1) / det;
        inverse = Matrix3x3<Real>{ c00 * invDet,
                                   (matrix(0, 2) * matrix(2, 1) - matrix(0, 1) * matrix(2, 2)) * invDet,
                                   (matrix(0, 1) * matrix(1, 2) - matrix(0, 2) * matrix(1, 1)) * invDet,
                                   c10 * invDet,
                                   (matrix(0, 0) * matrix(2, 2) - matrix(0, 2) * matrix(2, 0)) * invDet,
                                   (matrix(0, 2) * matrix(1, 0) - matrix(0, 0) * matrix(1, 2)) * invDet,
                                   c20 * invDet,
                                   (matrix(0, 1) * matrix(2, 0) - matrix(0, 0) * matrix(2, 1)) * invDet,
                                   (matrix(0, 0) * matrix(1, 1) - matrix(0, 1) * matrix(1, 0)) * invDet };
        invertible = true;
    }

    if (reportInvertibility != nullptr)
    {
        *reportInvertibility = invertible;
    }

    return inverse;
}

template <typename Real>
Mathematics::Algebra::Matrix3x3<Real> Mathematics::Algebra::Adjoint(const Matrix3x3<Real>& matrix)
{
    return Matrix3x3<Real>{ matrix(1, 1) * matrix(2, 2) - matrix(1, 2) * matrix(2, 1),
                            matrix(0, 2) * matrix(2, 1) - matrix(0, 1) * matrix(2, 2),
                            matrix(0, 1) * matrix(1, 2) - matrix(0, 2) * matrix(1, 1),
                            matrix(1, 2) * matrix(2, 0) - matrix(1, 0) * matrix(2, 2),
                            matrix(0, 0) * matrix(2, 2) - matrix(0, 2) * matrix(2, 0),
                            matrix(0, 2) * matrix(1, 0) - matrix(0, 0) * matrix(1, 2),
                            matrix(1, 0) * matrix(2, 1) - matrix(1, 1) * matrix(2, 0),
                            matrix(0, 1) * matrix(2, 0) - matrix(0, 0) * matrix(2, 1),
                            matrix(0, 0) * matrix(1, 1) - matrix(0, 1) * matrix(1, 0) };
}

template <typename Real>
Real Mathematics::Algebra::Determinant(const Matrix3x3<Real>& matrix)
{
    const auto c00 = matrix(1, 1) * matrix(2, 2) - matrix(1, 2) * matrix(2, 1);
    const auto c10 = matrix(1, 2) * matrix(2, 0) - matrix(1, 0) * matrix(2, 2);
    const auto c20 = matrix(1, 0) * matrix(2, 1) - matrix(1, 1) * matrix(2, 0);
    const auto det = matrix(0, 0) * c00 + matrix(0, 1) * c10 + matrix(0, 2) * c20;

    return det;
}

template <typename Real>
Real Mathematics::Algebra::Trace(const Matrix3x3<Real>& matrix)
{
    const auto trace = matrix(0, 0) + matrix(1, 1) + matrix(2, 2);

    return trace;
}

template <typename Real>
Mathematics::Algebra::Vector3<Real> Mathematics::Algebra::DoTransform(const Matrix3x3<Real>& matrix, const Vector3<Real>& vector)
{
#if defined(MATHEMATICS_USE_MATRIX_VECTOR)

    return matrix * vector;

#else  // !MATHEMATICS_USE_MATRIX_VECTOR

    return vector * matrix;

#endif  // MATHEMATICS_USE_MATRIX_VECTOR
}

template <typename Real>
Mathematics::Algebra::Matrix3x3<Real> Mathematics::Algebra::DoTransform(const Matrix3x3<Real>& lhs, const Matrix3x3<Real>& rhs)
{
#if defined(MATHEMATICS_USE_MATRIX_VECTOR)

    return lhs * rhs;

#else  // !MATHEMATICS_USE_MATRIX_VECTOR

    return rhs * lhs;

#endif  // MATHEMATICS_USE_MATRIX_VECTOR
}

template <typename Real>
void Mathematics::Algebra::SetBasis(Matrix3x3<Real>& matrix, int index, const Vector3<Real>& vector)
{
#if defined(MATHEMATICS_USE_MATRIX_VECTOR)

    return matrix.SetColumn(index, vector);

#else  // !MATHEMATICS_USE_MATRIX_VECTOR

    return matrix.SetRow(index, vector);

#endif  // MATHEMATICS_USE_MATRIX_VECTOR
}

template <typename Real>
Mathematics::Algebra::Vector3<Real> Mathematics::Algebra::GetBasis(const Matrix3x3<Real>& matrix, int index)
{
#if defined(MATHEMATICS_USE_MATRIX_VECTOR)

    return matrix.GetColumn(index);

#else  // !MATHEMATICS_USE_MATRIX_VECTOR

    return matrix.GetRow(index);

#endif  // MATHEMATICS_USE_MATRIX_VECTOR
}

#endif  // MATHEMATICS_ALGEBRA_ALGEBRA_MATRIX3_X_3_DETAIL_H
