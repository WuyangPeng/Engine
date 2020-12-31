//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.0.1 (2020/09/05 20:34)

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

    m_IsIdentity = true;
    m_IsRotationOrScaleMatrix = true;
    m_IsUniformScale = true;

    m_Matrix.MakeIdentity();
}

template <typename Real>
void Rendering::TransformMatrix<Real>::MakeUnitScale(const Matrix& rotate) noexcept(g_Assert < 2 || g_RenderingAssert < 2)
{
    RENDERING_CLASS_IS_VALID_9;

    RENDERING_ASSERTION_2(m_IsRotationOrScaleMatrix, "Matrix不是旋转矩阵。\n");

    m_IsUniformScale = true;

    Modification(rotate);
}

// private
template <typename Real>
void Rendering::TransformMatrix<Real>::Modification(const APoint& translate) noexcept
{
    m_Matrix.SetValue<3>(translate.GetX());
    m_Matrix.SetValue<7>(translate.GetY());
    m_Matrix.SetValue<11>(translate.GetZ());
}

// private
template <typename Real>
void Rendering::TransformMatrix<Real>::Modification(const Matrix& matrix) noexcept
{
    m_Matrix.SetValue<0>(matrix.GetValue<0>());
    m_Matrix.SetValue<1>(matrix.GetValue<1>());
    m_Matrix.SetValue<2>(matrix.GetValue<2>());

    m_Matrix.SetValue<4>(matrix.GetValue<4>());
    m_Matrix.SetValue<5>(matrix.GetValue<5>());
    m_Matrix.SetValue<6>(matrix.GetValue<6>());

    m_Matrix.SetValue<8>(matrix.GetValue<8>());
    m_Matrix.SetValue<9>(matrix.GetValue<9>());
    m_Matrix.SetValue<10>(matrix.GetValue<10>());
}

// private
template <typename Real>
void Rendering::TransformMatrix<Real>::Modification(const Matrix& rotate, const APoint& scale) noexcept
{
    m_Matrix.SetValue<0>(rotate.GetValue<0>() * scale.GetX());
    m_Matrix.SetValue<1>(rotate.GetValue<1>() * scale.GetY());
    m_Matrix.SetValue<2>(rotate.GetValue<2>() * scale.GetZ());

    m_Matrix.SetValue<4>(rotate.GetValue<4>() * scale.GetX());
    m_Matrix.SetValue<5>(rotate.GetValue<5>() * scale.GetY());
    m_Matrix.SetValue<6>(rotate.GetValue<6>());

    m_Matrix.SetValue<8>(rotate.GetValue<8>() * scale.GetX());
    m_Matrix.SetValue<9>(rotate.GetValue<9>() * scale.GetY());
    m_Matrix.SetValue<10>(rotate.GetValue<10>() * scale.GetZ());
}

template <typename Real>
bool Rendering::TransformMatrix<Real>::IsIdentity() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return m_IsIdentity;
}

template <typename Real>
bool Rendering::TransformMatrix<Real>::IsRotationOrScaleMatrix() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return m_IsRotationOrScaleMatrix;
}

template <typename Real>
bool Rendering::TransformMatrix<Real>::IsUniformScale() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return m_IsRotationOrScaleMatrix && m_IsUniformScale;
}

template <typename Real>
void Rendering::TransformMatrix<Real>::SetRotate(const Matrix& rotate, const APoint& scale) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    m_IsIdentity = false;
    m_IsRotationOrScaleMatrix = true;

    Modification(rotate, scale);
}

template <typename Real>
void Rendering::TransformMatrix<Real>::SetMatrix(const Matrix& matrix) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    m_IsIdentity = false;
    m_IsRotationOrScaleMatrix = false;
    m_IsUniformScale = false;

    Modification(matrix);
}

template <typename Real>
void Rendering::TransformMatrix<Real>::SetTranslate(const APoint& translate) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    m_IsIdentity = false;

    Modification(translate);
}

template <typename Real>
void Rendering::TransformMatrix<Real>::SetScale(const Matrix& rotate, const APoint& scale) noexcept(g_Assert < 2 || g_RenderingAssert < 2)
{
    RENDERING_CLASS_IS_VALID_9;
    RENDERING_ASSERTION_2(m_IsRotationOrScaleMatrix, "Matrix不是旋转矩阵。\n");

    m_IsIdentity = false;
    m_IsUniformScale = false;

    Modification(rotate, scale);
}

template <typename Real>
void Rendering::TransformMatrix<Real>::SetUniformScale(const Matrix& rotate, Real scale) noexcept(g_Assert < 2 || g_RenderingAssert < 2)
{
    RENDERING_CLASS_IS_VALID_9;
    RENDERING_ASSERTION_2(m_IsRotationOrScaleMatrix, "Matrix不是旋转矩阵。\n");

    m_IsIdentity = false;
    m_IsUniformScale = true;

    Modification(rotate, APoint{ scale, scale, scale });
}

template <typename Real>
const typename Rendering::TransformMatrix<Real>::Matrix Rendering::TransformMatrix<Real>::GetMatrix() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return m_Matrix;
}

template <typename Real>
int Rendering::TransformMatrix<Real>::GetStreamingSize() const
{
    return MATHEMATICS_STREAM_SIZE(m_Matrix) + CORE_TOOLS_STREAM_SIZE(m_IsIdentity) + CORE_TOOLS_STREAM_SIZE(m_IsRotationOrScaleMatrix) + CORE_TOOLS_STREAM_SIZE(m_IsUniformScale);
}

#endif  // RENDERING_DATA_TYPES_TRANSFORM_MATRIX_DETAIL_H
