///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/29 16:56)

#ifndef RENDERING_DATA_TYPES_TRANSFORM_MATRIX_DETAIL_H
#define RENDERING_DATA_TYPES_TRANSFORM_MATRIX_DETAIL_H

#include "TransformMatrix.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/StreamMacro.h"
#include "Mathematics/Algebra/AlgebraStreamSize.h"

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Rendering::TransformMatrix<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
void Rendering::TransformMatrix<Real>::MakeIdentity() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    isIdentity = true;
    isRotationOrScaleMatrix = true;
    isUniformScale = true;

    transformMatrix.MakeIdentity();
}

template <typename Real>
void Rendering::TransformMatrix<Real>::MakeUnitScale(const Matrix& rotate) noexcept(g_Assert < 2 || g_RenderingAssert < 2)
{
    RENDERING_CLASS_IS_VALID_9;

    RENDERING_ASSERTION_2(isRotationOrScaleMatrix, "Matrix不是旋转矩阵。\n");

    isUniformScale = true;

    Modification(rotate);
}

// private
template <typename Real>
void Rendering::TransformMatrix<Real>::Modification(const APoint& translate) noexcept
{
    transformMatrix.SetValue<3>(translate.GetX());
    transformMatrix.SetValue<7>(translate.GetY());
    transformMatrix.SetValue<11>(translate.GetZ());
}

// private
template <typename Real>
void Rendering::TransformMatrix<Real>::Modification(const Matrix& matrix) noexcept
{
    transformMatrix.SetValue<0>(matrix.GetValue<0>());
    transformMatrix.SetValue<1>(matrix.GetValue<1>());
    transformMatrix.SetValue<2>(matrix.GetValue<2>());

    transformMatrix.SetValue<4>(matrix.GetValue<4>());
    transformMatrix.SetValue<5>(matrix.GetValue<5>());
    transformMatrix.SetValue<6>(matrix.GetValue<6>());

    transformMatrix.SetValue<8>(matrix.GetValue<8>());
    transformMatrix.SetValue<9>(matrix.GetValue<9>());
    transformMatrix.SetValue<10>(matrix.GetValue<10>());
}

// private
template <typename Real>
void Rendering::TransformMatrix<Real>::Modification(const Matrix& rotate, const APoint& scale) noexcept
{
    transformMatrix.SetValue<0>(rotate.GetValue<0>() * scale.GetX());
    transformMatrix.SetValue<1>(rotate.GetValue<1>() * scale.GetY());
    transformMatrix.SetValue<2>(rotate.GetValue<2>() * scale.GetZ());

    transformMatrix.SetValue<4>(rotate.GetValue<4>() * scale.GetX());
    transformMatrix.SetValue<5>(rotate.GetValue<5>() * scale.GetY());
    transformMatrix.SetValue<6>(rotate.GetValue<6>());

    transformMatrix.SetValue<8>(rotate.GetValue<8>() * scale.GetX());
    transformMatrix.SetValue<9>(rotate.GetValue<9>() * scale.GetY());
    transformMatrix.SetValue<10>(rotate.GetValue<10>() * scale.GetZ());
}

template <typename Real>
bool Rendering::TransformMatrix<Real>::IsIdentity() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return isIdentity;
}

template <typename Real>
bool Rendering::TransformMatrix<Real>::IsRotationOrScaleMatrix() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return isRotationOrScaleMatrix;
}

template <typename Real>
bool Rendering::TransformMatrix<Real>::IsUniformScale() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return isRotationOrScaleMatrix && isUniformScale;
}

template <typename Real>
void Rendering::TransformMatrix<Real>::SetRotate(const Matrix& rotate, const APoint& scale) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    isIdentity = false;
    isRotationOrScaleMatrix = true;

    Modification(rotate, scale);
}

template <typename Real>
void Rendering::TransformMatrix<Real>::SetMatrix(const Matrix& matrix) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    isIdentity = false;
    isRotationOrScaleMatrix = false;
    isUniformScale = false;

    Modification(matrix);
}

template <typename Real>
void Rendering::TransformMatrix<Real>::SetTranslate(const APoint& translate) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    isIdentity = false;

    Modification(translate);
}

template <typename Real>
void Rendering::TransformMatrix<Real>::SetScale(const Matrix& rotate, const APoint& scale) noexcept(g_Assert < 2 || g_RenderingAssert < 2)
{
    RENDERING_CLASS_IS_VALID_9;
    RENDERING_ASSERTION_2(isRotationOrScaleMatrix, "Matrix不是旋转矩阵。\n");

    isIdentity = false;
    isUniformScale = false;

    Modification(rotate, scale);
}

template <typename Real>
void Rendering::TransformMatrix<Real>::SetUniformScale(const Matrix& rotate, Real scale) noexcept(g_Assert < 2 || g_RenderingAssert < 2)
{
    RENDERING_CLASS_IS_VALID_9;
    RENDERING_ASSERTION_2(isRotationOrScaleMatrix, "Matrix不是旋转矩阵。\n");

    isIdentity = false;
    isUniformScale = true;

    Modification(rotate, APoint{ scale, scale, scale });
}

template <typename Real>
typename Rendering::TransformMatrix<Real>::Matrix Rendering::TransformMatrix<Real>::GetMatrix() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return transformMatrix;
}

template <typename Real>
int Rendering::TransformMatrix<Real>::GetStreamingSize() const noexcept
{
    return MATHEMATICS_STREAM_SIZE(transformMatrix) + CORE_TOOLS_STREAM_SIZE(isIdentity) + CORE_TOOLS_STREAM_SIZE(isRotationOrScaleMatrix) + CORE_TOOLS_STREAM_SIZE(isUniformScale);
}

#endif  // RENDERING_DATA_TYPES_TRANSFORM_MATRIX_DETAIL_H
