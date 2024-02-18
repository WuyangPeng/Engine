///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.5 (2024/02/01 13:25)

#ifndef MATHEMATICS_ALGEBRA_ALGEBRA_MATRIX_2_X_2_DETAIL_H
#define MATHEMATICS_ALGEBRA_ALGEBRA_MATRIX_2_X_2_DETAIL_H

#include "Matrix2x2.h"
#include "MatrixDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector/Vector2Detail.h"

template <typename Real>
Mathematics::Algebra::Matrix2x2<Real> Mathematics::Algebra::MakeRotation(Real angle)
{
    Matrix2x2<Real> rotation{};

    Real cos = Math<Real>::Cos(angle);
    Real sin = Math<Real>::Sin(angle);

#if defined(MATHEMATICS_USE_MATRIX_VECTOR)

    rotation(0, 0) = cos;
    rotation(0, 1) = -sin;
    rotation(1, 0) = sin;
    rotation(1, 1) = cos;

#else  // !MATHEMATICS_USE_MATRIX_VECTOR

    rotation(0, 0) = cs;
    rotation(0, 1) = sn;
    rotation(1, 0) = -sn;
    rotation(1, 1) = cs;

#endif  // MATHEMATICS_USE_MATRIX_VECTOR

    return rotation;
}

template <typename Real>
Real Mathematics::Algebra::GetRotationAngle(const Matrix2x2<Real>& rotation)
{
#if defined(MATHEMATICS_USE_MATRIX_VECTOR)

    return Math<Real>::ATan2(rotation(1, 0), rotation(0, 0));

#else  // !MATHEMATICS_USE_MATRIX_VECTOR

    return Math<Real>::ATan2(rotation(0, 1), rotation(0, 0));

#endif  // MATHEMATICS_USE_MATRIX_VECTOR
}

template <typename Real>
Mathematics::Algebra::Matrix2x2<Real> Mathematics::Algebra::Inverse(const Matrix2x2<Real>& matrix, bool* reportInvertibility)
{
    Matrix2x2<Real> inverse{};
    auto invertible = false;
    const auto det = matrix(0, 0) * matrix(1, 1) - matrix(0, 1) * matrix(1, 0);
    if (!Math<Real>::Approximate(det, Real{}))
    {
        const auto invDet = Math<Real>::GetValue(1) / det;
        inverse = Matrix2x2<Real>{ matrix(1, 1) * invDet, -matrix(0, 1) * invDet, -matrix(1, 0) * invDet, matrix(0, 0) * invDet };
        invertible = true;
    }

    if (reportInvertibility != nullptr)
    {
        *reportInvertibility = invertible;
    }

    return inverse;
}

template <typename Real>
Mathematics::Algebra::Matrix2x2<Real> Mathematics::Algebra::Adjoint(const Matrix2x2<Real>& matrix)
{
    return Matrix2x2<Real>{ matrix(1, 1), -matrix(0, 1), -matrix(1, 0), matrix(0, 0) };
}

template <typename Real>
Real Mathematics::Algebra::Determinant(const Matrix2x2<Real>& matrix)
{
    const auto det = matrix(0, 0) * matrix(1, 1) - matrix(0, 1) * matrix(1, 0);

    return det;
}

template <typename Real>
Real Mathematics::Algebra::Trace(const Matrix2x2<Real>& matrix)
{
    const auto trace = matrix(0, 0) + matrix(1, 1);

    return trace;
}

template <typename Real>
Mathematics::Algebra::Vector2<Real> Mathematics::Algebra::DoTransform(const Matrix2x2<Real>& matrix, const Vector2<Real>& vector)
{
#if defined(MATHEMATICS_USE_MATRIX_VECTOR)

    return matrix * vector;

#else  // !MATHEMATICS_USE_MATRIX_VECTOR

    return vector * matrix;

#endif  // MATHEMATICS_USE_MATRIX_VECTOR
}

template <typename Real>
Mathematics::Algebra::Matrix2x2<Real> Mathematics::Algebra::DoTransform(const Matrix2x2<Real>& lhs, const Matrix2x2<Real>& rhs)
{
#if defined(MATHEMATICS_USE_MATRIX_VECTOR)

    return lhs * rhs;

#else  // !MATHEMATICS_USE_MATRIX_VECTOR

    return rhs * lhs;

#endif  // MATHEMATICS_USE_MATRIX_VECTOR
}

template <typename Real>
void Mathematics::Algebra::SetBasis(Matrix2x2<Real>& matrix, int index, const Vector2<Real>& vector)
{
#if defined(MATHEMATICS_USE_MATRIX_VECTOR)

    return matrix.SetColumn(index, vector);

#else  // !MATHEMATICS_USE_MATRIX_VECTOR

    return matrix.SetRow(index, vector);

#endif  // MATHEMATICS_USE_MATRIX_VECTOR
}

template <typename Real>
Mathematics::Algebra::Vector2<Real> Mathematics::Algebra::GetBasis(const Matrix2x2<Real>& matrix, int index)
{
#if defined(MATHEMATICS_USE_MATRIX_VECTOR)

    return matrix.GetColumn(index);

#else  // !MATHEMATICS_USE_MATRIX_VECTOR

    return matrix.GetRow(index);

#endif  // MATHEMATICS_USE_MATRIX_VECTOR
}

#endif  // MATHEMATICS_ALGEBRA_ALGEBRA_MATRIX_2_X_2_DETAIL_H
