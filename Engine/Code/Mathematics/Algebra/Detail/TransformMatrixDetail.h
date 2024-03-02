/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.6 (2024/02/20 09:16)

#ifndef MATHEMATICS_DATA_TYPES_TRANSFORM_MATRIX_DETAIL_H
#define MATHEMATICS_DATA_TYPES_TRANSFORM_MATRIX_DETAIL_H

#include "TransformMatrix.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/AlgebraStreamSize.h"

template <typename Real>
Mathematics::TransformMatrix<Real>::TransformMatrix() noexcept
    : transformMatrix{ MatrixInitType::Identity }, isIdentity{ true }, isRotationOrScaleMatrix{ true }, isUniformScale{ true }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::TransformMatrix<Real>::TransformMatrix(Real scale) noexcept
    : transformMatrix{ scale, scale, scale }, isIdentity{ false }, isRotationOrScaleMatrix{ true }, isUniformScale{ true }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::TransformMatrix<Real>::TransformMatrix(Real s0, Real s1, Real s2) noexcept
    : transformMatrix{ s0, s1, s2 }, isIdentity{ false }, isRotationOrScaleMatrix{ true }, isUniformScale{ false }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::TransformMatrix<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
void Mathematics::TransformMatrix<Real>::MakeIdentity() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    isIdentity = true;
    isRotationOrScaleMatrix = true;
    isUniformScale = true;

    transformMatrix.MakeIdentity();
}

template <typename Real>
void Mathematics::TransformMatrix<Real>::MakeUnitScale()
{
    MATHEMATICS_CLASS_IS_VALID_9;

    MATHEMATICS_ASSERTION_0(isRotationOrScaleMatrix, "Matrix不是旋转矩阵。\n");

    isUniformScale = true;

    transformMatrix.MakeIdentity();
}

template <typename Real>
void Mathematics::TransformMatrix<Real>::Modification(const APoint& translate) noexcept
{
    /// 对于仿射变换，transformMatrix的最后一行总是(0,0,0,1)，
    /// 因此在构造函数中设置一次。没有必要在此处重置它。

#if defined(MATHEMATICS_USE_MATRIX_VECTOR)

    transformMatrix.SetValue<0, 3>(translate.GetX());
    transformMatrix.SetValue<1, 3>(translate.GetY());
    transformMatrix.SetValue<2, 3>(translate.GetZ());

#else  // !defined(MATHEMATICS_USE_MATRIX_VECTOR)

    transformMatrix.SetValue<3, 0>(translate.GetX());
    transformMatrix.SetValue<3, 1>(translate.GetY());
    transformMatrix.SetValue<3, 2>(translate.GetZ());

#endif  // defined(MATHEMATICS_USE_MATRIX_VECTOR)
}

template <typename Real>
void Mathematics::TransformMatrix<Real>::Modification(const Matrix& matrix) noexcept
{
    transformMatrix.SetValue<0, 0>(matrix.template GetValue<0, 0>());
    transformMatrix.SetValue<0, 1>(matrix.template GetValue<0, 1>());
    transformMatrix.SetValue<0, 2>(matrix.template GetValue<0, 2>());

    transformMatrix.SetValue<1, 0>(matrix.template GetValue<1, 0>());
    transformMatrix.SetValue<1, 1>(matrix.template GetValue<1, 1>());
    transformMatrix.SetValue<1, 2>(matrix.template GetValue<1, 2>());

    transformMatrix.SetValue<2, 0>(matrix.template GetValue<2, 0>());
    transformMatrix.SetValue<2, 1>(matrix.template GetValue<2, 1>());
    transformMatrix.SetValue<2, 2>(matrix.template GetValue<2, 2>());
}

template <typename Real>
void Mathematics::TransformMatrix<Real>::Modification(const Matrix& rotate, const APoint& scale) noexcept
{
#if defined(MATHEMATICS_USE_MATRIX_VECTOR)

    transformMatrix.SetValue<0, 0>(rotate.template GetValue<0, 0>() * scale.GetX());
    transformMatrix.SetValue<0, 1>(rotate.template GetValue<0, 1>() * scale.GetY());
    transformMatrix.SetValue<0, 2>(rotate.template GetValue<0, 2>() * scale.GetZ());

    transformMatrix.SetValue<1, 0>(rotate.template GetValue<1, 0>() * scale.GetX());
    transformMatrix.SetValue<1, 1>(rotate.template GetValue<1, 1>() * scale.GetY());
    transformMatrix.SetValue<1, 2>(rotate.template GetValue<1, 2>() * scale.GetZ());

    transformMatrix.SetValue<2, 0>(rotate.template GetValue<2, 0>() * scale.GetX());
    transformMatrix.SetValue<2, 1>(rotate.template GetValue<2, 1>() * scale.GetY());
    transformMatrix.SetValue<2, 2>(rotate.template GetValue<2, 2>() * scale.GetZ());

#else  // !defined(MATHEMATICS_USE_MATRIX_VECTOR)

    transformMatrix.SetValue<0, 0>(scale.GetX() * rotate.template GetValue<0, 0>());
    transformMatrix.SetValue<0, 1>(scale.GetY() * rotate.template GetValue<0, 1>());
    transformMatrix.SetValue<0, 2>(scale.GetZ() * rotate.template GetValue<0, 2>());

    transformMatrix.SetValue<1, 0>(scale.GetX() * rotate.template GetValue<1, 0>());
    transformMatrix.SetValue<1, 1>(scale.GetY() * rotate.template GetValue<1, 1>());
    transformMatrix.SetValue<1, 2>(scale.GetZ() * rotate.template GetValue<1, 2>());

    transformMatrix.SetValue<2, 0>(scale.GetX() * rotate.template GetValue<2, 0>());
    transformMatrix.SetValue<2, 1>(scale.GetY() * rotate.template GetValue<2, 1>());
    transformMatrix.SetValue<2, 2>(scale.GetZ() * rotate.template GetValue<2, 2>());

#endif  // defined(MATHEMATICS_USE_MATRIX_VECTOR)
}

template <typename Real>
bool Mathematics::TransformMatrix<Real>::IsIdentity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return isIdentity;
}

template <typename Real>
bool Mathematics::TransformMatrix<Real>::IsRotationOrScaleMatrix() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return isRotationOrScaleMatrix;
}

template <typename Real>
bool Mathematics::TransformMatrix<Real>::IsUniformScale() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return isRotationOrScaleMatrix && isUniformScale;
}

template <typename Real>
void Mathematics::TransformMatrix<Real>::SetRotate(const Matrix& rotate, const APoint& scale) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    isIdentity = false;
    isRotationOrScaleMatrix = true;
    isUniformScale = false;

    Modification(rotate, scale);
}

template <typename Real>
void Mathematics::TransformMatrix<Real>::SetMatrix(const Matrix& matrix) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    isIdentity = false;
    isRotationOrScaleMatrix = false;
    isUniformScale = false;

    Modification(matrix);
}

template <typename Real>
void Mathematics::TransformMatrix<Real>::SetTranslate(const APoint& translate) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    isIdentity = false;

    Modification(translate);
}

template <typename Real>
void Mathematics::TransformMatrix<Real>::SetScale(const Matrix& rotate, const APoint& scale)
{
    MATHEMATICS_CLASS_IS_VALID_9;
    MATHEMATICS_ASSERTION_0(isRotationOrScaleMatrix, "Matrix不是旋转矩阵。\n");

    isIdentity = false;
    isUniformScale = false;

    Modification(rotate, scale);
}

template <typename Real>
void Mathematics::TransformMatrix<Real>::SetUniformScale(const Matrix& rotate, Real scale)
{
    MATHEMATICS_CLASS_IS_VALID_9;
    MATHEMATICS_ASSERTION_0(isRotationOrScaleMatrix, "Matrix不是旋转矩阵。\n");

    isIdentity = false;
    isUniformScale = true;

    Modification(rotate, APoint{ scale, scale, scale });
}

template <typename Real>
typename Mathematics::TransformMatrix<Real>::Matrix Mathematics::TransformMatrix<Real>::GetMatrix() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return transformMatrix;
}

template <typename Real>
int Mathematics::TransformMatrix<Real>::GetStreamingSize() const noexcept
{
    return Mathematics::GetStreamSize(transformMatrix) + CoreTools::GetStreamSize(isIdentity) + CoreTools::GetStreamSize(isRotationOrScaleMatrix) + CoreTools::GetStreamSize(isUniformScale);
}

#endif  // MATHEMATICS_DATA_TYPES_TRANSFORM_MATRIX_DETAIL_H
