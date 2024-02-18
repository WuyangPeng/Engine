///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.5 (2024/02/01 19:07)

#ifndef MATHEMATICS_ALGEBRA_ALGEBRA_MATRIX_4_X_4_DETAIL_H
#define MATHEMATICS_ALGEBRA_ALGEBRA_MATRIX_4_X_4_DETAIL_H

#include "Matrix4x4.h"
#include "MatrixDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Algebra::Matrix4x4<Real> Mathematics::Algebra::Inverse(const Matrix4x4<Real>& matrix, bool* reportInvertibility)
{
    Matrix4x4<Real> inverse{};
    auto invertible = false;
    const auto a0 = matrix(0, 0) * matrix(1, 1) - matrix(0, 1) * matrix(1, 0);
    const auto a1 = matrix(0, 0) * matrix(1, 2) - matrix(0, 2) * matrix(1, 0);
    const auto a2 = matrix(0, 0) * matrix(1, 3) - matrix(0, 3) * matrix(1, 0);
    const auto a3 = matrix(0, 1) * matrix(1, 2) - matrix(0, 2) * matrix(1, 1);
    const auto a4 = matrix(0, 1) * matrix(1, 3) - matrix(0, 3) * matrix(1, 1);
    const auto a5 = matrix(0, 2) * matrix(1, 3) - matrix(0, 3) * matrix(1, 2);
    const auto b0 = matrix(2, 0) * matrix(3, 1) - matrix(2, 1) * matrix(3, 0);
    const auto b1 = matrix(2, 0) * matrix(3, 2) - matrix(2, 2) * matrix(3, 0);
    const auto b2 = matrix(2, 0) * matrix(3, 3) - matrix(2, 3) * matrix(3, 0);
    const auto b3 = matrix(2, 1) * matrix(3, 2) - matrix(2, 2) * matrix(3, 1);
    const auto b4 = matrix(2, 1) * matrix(3, 3) - matrix(2, 3) * matrix(3, 1);
    const auto b5 = matrix(2, 2) * matrix(3, 3) - matrix(2, 3) * matrix(3, 2);
    const auto det = a0 * b5 - a1 * b4 + a2 * b3 + a3 * b2 - a4 * b1 + a5 * b0;
    if (!Math<Real>::Approximate(det, Real{}))
    {
        const auto invDet = Math<Real>::GetValue(1) / det;
        inverse = Matrix4x4<Real>{ (+matrix(1, 1) * b5 - matrix(1, 2) * b4 + matrix(1, 3) * b3) * invDet,
                                   (-matrix(0, 1) * b5 + matrix(0, 2) * b4 - matrix(0, 3) * b3) * invDet,
                                   (+matrix(3, 1) * a5 - matrix(3, 2) * a4 + matrix(3, 3) * a3) * invDet,
                                   (-matrix(2, 1) * a5 + matrix(2, 2) * a4 - matrix(2, 3) * a3) * invDet,
                                   (-matrix(1, 0) * b5 + matrix(1, 2) * b2 - matrix(1, 3) * b1) * invDet,
                                   (+matrix(0, 0) * b5 - matrix(0, 2) * b2 + matrix(0, 3) * b1) * invDet,
                                   (-matrix(3, 0) * a5 + matrix(3, 2) * a2 - matrix(3, 3) * a1) * invDet,
                                   (+matrix(2, 0) * a5 - matrix(2, 2) * a2 + matrix(2, 3) * a1) * invDet,
                                   (+matrix(1, 0) * b4 - matrix(1, 1) * b2 + matrix(1, 3) * b0) * invDet,
                                   (-matrix(0, 0) * b4 + matrix(0, 1) * b2 - matrix(0, 3) * b0) * invDet,
                                   (+matrix(3, 0) * a4 - matrix(3, 1) * a2 + matrix(3, 3) * a0) * invDet,
                                   (-matrix(2, 0) * a4 + matrix(2, 1) * a2 - matrix(2, 3) * a0) * invDet,
                                   (-matrix(1, 0) * b3 + matrix(1, 1) * b1 - matrix(1, 2) * b0) * invDet,
                                   (+matrix(0, 0) * b3 - matrix(0, 1) * b1 + matrix(0, 2) * b0) * invDet,
                                   (-matrix(3, 0) * a3 + matrix(3, 1) * a1 - matrix(3, 2) * a0) * invDet,
                                   (+matrix(2, 0) * a3 - matrix(2, 1) * a1 + matrix(2, 2) * a0) * invDet };

        invertible = true;
    }

    if (reportInvertibility != nullptr)
    {
        *reportInvertibility = invertible;
    }

    return inverse;
}

template <typename Real>
Mathematics::Algebra::Matrix4x4<Real> Mathematics::Algebra::Adjoint(const Matrix4x4<Real>& matrix)
{
    const auto a0 = matrix(0, 0) * matrix(1, 1) - matrix(0, 1) * matrix(1, 0);
    const auto a1 = matrix(0, 0) * matrix(1, 2) - matrix(0, 2) * matrix(1, 0);
    const auto a2 = matrix(0, 0) * matrix(1, 3) - matrix(0, 3) * matrix(1, 0);
    const auto a3 = matrix(0, 1) * matrix(1, 2) - matrix(0, 2) * matrix(1, 1);
    const auto a4 = matrix(0, 1) * matrix(1, 3) - matrix(0, 3) * matrix(1, 1);
    const auto a5 = matrix(0, 2) * matrix(1, 3) - matrix(0, 3) * matrix(1, 2);
    const auto b0 = matrix(2, 0) * matrix(3, 1) - matrix(2, 1) * matrix(3, 0);
    const auto b1 = matrix(2, 0) * matrix(3, 2) - matrix(2, 2) * matrix(3, 0);
    const auto b2 = matrix(2, 0) * matrix(3, 3) - matrix(2, 3) * matrix(3, 0);
    const auto b3 = matrix(2, 1) * matrix(3, 2) - matrix(2, 2) * matrix(3, 1);
    const auto b4 = matrix(2, 1) * matrix(3, 3) - matrix(2, 3) * matrix(3, 1);
    const auto b5 = matrix(2, 2) * matrix(3, 3) - matrix(2, 3) * matrix(3, 2);

    return Matrix4x4<Real>{ +matrix(1, 1) * b5 - matrix(1, 2) * b4 + matrix(1, 3) * b3,
                            -matrix(0, 1) * b5 + matrix(0, 2) * b4 - matrix(0, 3) * b3,
                            +matrix(3, 1) * a5 - matrix(3, 2) * a4 + matrix(3, 3) * a3,
                            -matrix(2, 1) * a5 + matrix(2, 2) * a4 - matrix(2, 3) * a3,
                            -matrix(1, 0) * b5 + matrix(1, 2) * b2 - matrix(1, 3) * b1,
                            +matrix(0, 0) * b5 - matrix(0, 2) * b2 + matrix(0, 3) * b1,
                            -matrix(3, 0) * a5 + matrix(3, 2) * a2 - matrix(3, 3) * a1,
                            +matrix(2, 0) * a5 - matrix(2, 2) * a2 + matrix(2, 3) * a1,
                            +matrix(1, 0) * b4 - matrix(1, 1) * b2 + matrix(1, 3) * b0,
                            -matrix(0, 0) * b4 + matrix(0, 1) * b2 - matrix(0, 3) * b0,
                            +matrix(3, 0) * a4 - matrix(3, 1) * a2 + matrix(3, 3) * a0,
                            -matrix(2, 0) * a4 + matrix(2, 1) * a2 - matrix(2, 3) * a0,
                            -matrix(1, 0) * b3 + matrix(1, 1) * b1 - matrix(1, 2) * b0,
                            +matrix(0, 0) * b3 - matrix(0, 1) * b1 + matrix(0, 2) * b0,
                            -matrix(3, 0) * a3 + matrix(3, 1) * a1 - matrix(3, 2) * a0,
                            +matrix(2, 0) * a3 - matrix(2, 1) * a1 + matrix(2, 2) * a0 };
}

template <typename Real>
Real Mathematics::Algebra::Determinant(const Matrix4x4<Real>& matrix)
{
    const auto a0 = matrix(0, 0) * matrix(1, 1) - matrix(0, 1) * matrix(1, 0);
    const auto a1 = matrix(0, 0) * matrix(1, 2) - matrix(0, 2) * matrix(1, 0);
    const auto a2 = matrix(0, 0) * matrix(1, 3) - matrix(0, 3) * matrix(1, 0);
    const auto a3 = matrix(0, 1) * matrix(1, 2) - matrix(0, 2) * matrix(1, 1);
    const auto a4 = matrix(0, 1) * matrix(1, 3) - matrix(0, 3) * matrix(1, 1);
    const auto a5 = matrix(0, 2) * matrix(1, 3) - matrix(0, 3) * matrix(1, 2);
    const auto b0 = matrix(2, 0) * matrix(3, 1) - matrix(2, 1) * matrix(3, 0);
    const auto b1 = matrix(2, 0) * matrix(3, 2) - matrix(2, 2) * matrix(3, 0);
    const auto b2 = matrix(2, 0) * matrix(3, 3) - matrix(2, 3) * matrix(3, 0);
    const auto b3 = matrix(2, 1) * matrix(3, 2) - matrix(2, 2) * matrix(3, 1);
    const auto b4 = matrix(2, 1) * matrix(3, 3) - matrix(2, 3) * matrix(3, 1);
    const auto b5 = matrix(2, 2) * matrix(3, 3) - matrix(2, 3) * matrix(3, 2);
    const auto det = a0 * b5 - a1 * b4 + a2 * b3 + a3 * b2 - a4 * b1 + a5 * b0;

    return det;
}

template <typename Real>
Real Mathematics::Algebra::Trace(const Matrix4x4<Real>& matrix)
{
    const auto trace = matrix(0, 0) + matrix(1, 1) + matrix(2, 2) + matrix(3, 3);
    return trace;
}

template <typename Real>
Mathematics::Algebra::Vector4<Real> Mathematics::Algebra::DoTransform(const Matrix4x4<Real>& matrix, const Vector4<Real>& vector)
{
#if defined(MATHEMATICS_USE_MATRIX_VECTOR)

    return matrix * vector;

#else  // !MATHEMATICS_USE_MATRIX_VECTOR

    return vector * matrix;

#endif  // MATHEMATICS_USE_MATRIX_VECTOR
}

template <typename Real>
Mathematics::Algebra::Matrix4x4<Real> Mathematics::Algebra::DoTransform(const Matrix4x4<Real>& lhs, const Matrix4x4<Real>& rhs)
{
#if defined(MATHEMATICS_USE_MATRIX_VECTOR)

    return lhs * rhs;

#else  // !MATHEMATICS_USE_MATRIX_VECTOR

    return rhs * lhs;

#endif  // MATHEMATICS_USE_MATRIX_VECTOR
}

template <typename Real>
void Mathematics::Algebra::SetBasis(Matrix4x4<Real>& matrix, int index, const Vector4<Real>& vector)
{
#if defined(MATHEMATICS_USE_MATRIX_VECTOR)

    return matrix.SetColumn(index, vector);

#else  // !MATHEMATICS_USE_MATRIX_VECTOR

    return matrix.SetRow(index, vector);

#endif  // MATHEMATICS_USE_MATRIX_VECTOR
}

template <typename Real>
Mathematics::Algebra::Vector4<Real> Mathematics::Algebra::GetBasis(const Matrix4x4<Real>& matrix, int index)
{
#if defined(MATHEMATICS_USE_MATRIX_VECTOR)

    return matrix.GetColumn(index);

#else  // !MATHEMATICS_USE_MATRIX_VECTOR

    return matrix.GetRow(index);

#endif  // MATHEMATICS_USE_MATRIX_VECTOR
}

template <typename Real>
Mathematics::Algebra::Matrix4x4<Real> Mathematics::Algebra::MakeObliqueProjection(const Vector4<Real>& origin, const Vector4<Real>& normal, const Vector4<Real>& direction)
{
    Matrix4x4<Real> matrix{};

    const auto dotNormalDirection = Dot(normal, direction);
    const auto dotNormalOrigin = Dot(origin, normal);

#if defined(MATHEMATICS_USE_MATRIX_VECTOR)

    matrix(0, 0) = direction[0] * normal[0] - dotNormalDirection;
    matrix(0, 1) = direction[0] * normal[1];
    matrix(0, 2) = direction[0] * normal[2];
    matrix(0, 3) = -dotNormalOrigin * direction[0];
    matrix(1, 0) = direction[1] * normal[0];
    matrix(1, 1) = direction[1] * normal[1] - dotNormalDirection;
    matrix(1, 2) = direction[1] * normal[2];
    matrix(1, 3) = -dotNormalOrigin * direction[1];
    matrix(2, 0) = direction[2] * normal[0];
    matrix(2, 1) = direction[2] * normal[1];
    matrix(2, 2) = direction[2] * normal[2] - dotNormalDirection;
    matrix(2, 3) = -dotNormalOrigin * direction[2];
    matrix(3, 0) = Real{};
    matrix(3, 1) = Real{};
    matrix(3, 2) = Real{};
    matrix(3, 3) = -dotNormalDirection;

#else  // !MATHEMATICS_USE_MATRIX_VECTOR

    matrix(0, 0) = direction[0] * normal[0] - dotNormalDirection;
    matrix(1, 0) = direction[0] * normal[1];
    matrix(2, 0) = direction[0] * normal[2];
    matrix(3, 0) = -dotNormalOrigin * direction[0];
    matrix(0, 1) = direction[1] * normal[0];
    matrix(1, 1) = direction[1] * normal[1] - dotNormalDirection;
    matrix(2, 1) = direction[1] * normal[2];
    matrix(3, 1) = -dotNormalOrigin * direction[1];
    matrix(0, 2) = direction[2] * normal[0];
    matrix(1, 2) = direction[2] * normal[1];
    matrix(2, 2) = direction[2] * normal[2] - dotNormalDirection;
    matrix(3, 2) = -dotNormalOrigin * direction[2];
    matrix(0, 2) = Real{};
    matrix(1, 3) = Real{};
    matrix(2, 3) = Real{};
    matrix(3, 3) = -dotNormalDirection;

#endif  // MATHEMATICS_USE_MATRIX_VECTOR

    return matrix;
}

template <typename Real>
Mathematics::Algebra::Matrix4x4<Real> Mathematics::Algebra::MakePerspectiveProjection(const Vector4<Real>& origin, const Vector4<Real>& normal, const Vector4<Real>& eye)
{
    Matrix4x4<Real> matrix{};

    const auto dotNormalDirection = Dot(normal, eye - origin);

#if defined(MATHEMATICS_USE_MATRIX_VECTOR)

    matrix(0, 0) = dotNormalDirection - eye[0] * normal[0];
    matrix(0, 1) = -eye[0] * normal[1];
    matrix(0, 2) = -eye[0] * normal[2];
    matrix(0, 3) = -(matrix(0, 0) * eye[0] + matrix(0, 1) * eye[1] + matrix(0, 2) * eye[2]);
    matrix(1, 0) = -eye[1] * normal[0];
    matrix(1, 1) = dotNormalDirection - eye[1] * normal[1];
    matrix(1, 2) = -eye[1] * normal[2];
    matrix(1, 3) = -(matrix(1, 0) * eye[0] + matrix(1, 1) * eye[1] + matrix(1, 2) * eye[2]);
    matrix(2, 0) = -eye[2] * normal[0];
    matrix(2, 1) = -eye[2] * normal[1];
    matrix(2, 2) = dotNormalDirection - eye[2] * normal[2];
    matrix(2, 3) = -(matrix(2, 0) * eye[0] + matrix(2, 1) * eye[1] + matrix(2, 2) * eye[2]);
    matrix(3, 0) = -normal[0];
    matrix(3, 1) = -normal[1];
    matrix(3, 2) = -normal[2];
    matrix(3, 3) = Dot(eye, normal);

#else  // !MATHEMATICS_USE_MATRIX_VECTOR

    matrix(0, 0) = dotNormalDirection - eye[0] * normal[0];
    matrix(1, 0) = -eye[0] * normal[1];
    matrix(2, 0) = -eye[0] * normal[2];
    matrix(3, 0) = -(matrix(0, 0) * eye[0] + matrix(0, 1) * eye[1] + matrix(0, 2) * eye[2]);
    matrix(0, 1) = -eye[1] * normal[0];
    matrix(1, 1) = dotNormalDirection - eye[1] * normal[1];
    matrix(2, 1) = -eye[1] * normal[2];
    matrix(3, 1) = -(matrix(1, 0) * eye[0] + matrix(1, 1) * eye[1] + matrix(1, 2) * eye[2]);
    matrix(0, 2) = -eye[2] * normal[0];
    matrix(1, 2) = -eye[2] * normal[1];
    matrix(2, 2) = dotNormalDirection - eye[2] * normal[2];
    matrix(3, 2) = -(matrix(2, 0) * eye[0] + matrix(2, 1) * eye[1] + matrix(2, 2) * eye[2]);
    matrix(0, 3) = -normal[0];
    matrix(1, 3) = -normal[1];
    matrix(2, 3) = -normal[2];
    matrix(3, 3) = Dot(eye, normal);

#endif  // MATHEMATICS_USE_MATRIX_VECTOR

    return matrix;
}

template <typename Real>
Mathematics::Algebra::Matrix4x4<Real> Mathematics::Algebra::MakeReflection(const Vector4<Real>& origin, const Vector4<Real>& normal)
{
    Matrix4x4<Real> matrix{};

    Real twoDotNormalOrigin = Math<Real>::GetValue(2) * Dot(origin, normal);

#if defined(MATHEMATICS_USE_MATRIX_VECTOR)

    matrix(0, 0) = Math<Real>::GetValue(1) - Math<Real>::GetValue(2) * normal[0] * normal[0];
    matrix(0, 1) = -Math<Real>::GetValue(2) * normal[0] * normal[1];
    matrix(0, 2) = -Math<Real>::GetValue(2) * normal[0] * normal[2];
    matrix(0, 3) = twoDotNormalOrigin * normal[0];
    matrix(1, 0) = matrix(0, 1);
    matrix(1, 1) = Math<Real>::GetValue(1) - Math<Real>::GetValue(2) * normal[1] * normal[1];
    matrix(1, 2) = -Math<Real>::GetValue(2) * normal[1] * normal[2];
    matrix(1, 3) = twoDotNormalOrigin * normal[1];
    matrix(2, 0) = matrix(0, 2);
    matrix(2, 1) = matrix(1, 2);
    matrix(2, 2) = Math<Real>::GetValue(1) - Math<Real>::GetValue(2) * normal[2] * normal[2];
    matrix(2, 3) = twoDotNormalOrigin * normal[2];
    matrix(3, 0) = Real{};
    matrix(3, 1) = Real{};
    matrix(3, 2) = Real{};
    matrix(3, 3) = Math<Real>::GetValue(1);

#else  // !MATHEMATICS_USE_MATRIX_VECTOR

    matrix(0, 0) = Math<Real>::GetValue(1) - Math<Real>::GetValue(2) * normal[0] * normal[0];
    matrix(1, 0) = -Math<Real>::GetValue(2) * normal[0] * normal[1];
    matrix(2, 0) = -Math<Real>::GetValue(2) * normal[0] * normal[2];
    matrix(3, 0) = twoDotNormalOrigin * normal[0];
    matrix(0, 1) = matrix(1, 0);
    matrix(1, 1) = Math<Real>::GetValue(1) - Math<Real>::GetValue(2) * normal[1] * normal[1];
    matrix(2, 1) = -Math<Real>::GetValue(2) * normal[1] * normal[2];
    matrix(3, 1) = twoDotNormalOrigin * normal[1];
    matrix(0, 2) = matrix(2, 0);
    matrix(1, 2) = matrix(2, 1);
    matrix(2, 2) = Math<Real>::GetValue(1) - Math<Real>::GetValue(2) * normal[2] * normal[2];
    matrix(3, 2) = twoDotNormalOrigin * normal[2];
    matrix(0, 3) = Real{};
    matrix(1, 3) = Real{};
    matrix(2, 3) = Real{};
    matrix(3, 3) = Math<Real>::GetValue(1);

#endif  // MATHEMATICS_USE_MATRIX_VECTOR

    return matrix;
}

#endif  // MATHEMATICS_ALGEBRA_ALGEBRA_MATRIX_4_X_4_DETAIL_H
