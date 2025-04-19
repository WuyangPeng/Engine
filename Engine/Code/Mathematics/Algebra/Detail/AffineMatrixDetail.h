/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.6 (2024/02/20 09:15)

#ifndef MATHEMATICS_ALGEBRA_AFFINE_MATRIX_DETAIL_H
#define MATHEMATICS_ALGEBRA_AFFINE_MATRIX_DETAIL_H

#include "AffineMatrix.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/AlgebraStreamSize.h"

template <typename Real>
Mathematics::AffineMatrix<Real>::AffineMatrix() noexcept
    : rotationOrGeneralMatrix{ Mathematics::MatrixInitType::Identity },
      translate{},
      scale{ MathType::GetValue(1), MathType::GetValue(1), MathType::GetValue(1) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::AffineMatrix<Real>::AffineMatrix(Real scale) noexcept
    : rotationOrGeneralMatrix{ Mathematics::MatrixInitType::Identity },
      translate{},
      scale{ scale, scale, scale }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::AffineMatrix<Real>::AffineMatrix(Real s0, Real s1, Real s2) noexcept
    : rotationOrGeneralMatrix{ Mathematics::MatrixInitType::Identity },
      translate{},
      scale{ s0, s1, s2 }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::AffineMatrix<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
void Mathematics::AffineMatrix<Real>::MakeIdentity() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    rotationOrGeneralMatrix.MakeIdentity();

    translate = APointType::GetOrigin();
    scale = APointType{ MathType::GetValue(1), MathType::GetValue(1), MathType::GetValue(1) };
}

template <typename Real>
void Mathematics::AffineMatrix<Real>::MakeUnitScale() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    scale = APointType{ MathType::GetValue(1), MathType::GetValue(1), MathType::GetValue(1) };
}

template <typename Real>
typename Mathematics::AffineMatrix<Real>::MatrixType Mathematics::AffineMatrix<Real>::GetRotationOrGeneralMatrix() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return rotationOrGeneralMatrix;
}

template <typename Real>
typename Mathematics::AffineMatrix<Real>::APointType Mathematics::AffineMatrix<Real>::GetTranslate() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return translate;
}

template <typename Real>
typename Mathematics::AffineMatrix<Real>::APointType Mathematics::AffineMatrix<Real>::GetScale() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return scale;
}

template <typename Real>
void Mathematics::AffineMatrix<Real>::SetRotationOrGeneralMatrix(const MatrixType& aRotationOrGeneralMatrix) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    rotationOrGeneralMatrix = aRotationOrGeneralMatrix;
}

template <typename Real>
void Mathematics::AffineMatrix<Real>::SetTranslate(const APointType& aTranslate) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    translate = aTranslate;
}

template <typename Real>
void Mathematics::AffineMatrix<Real>::SetScale(const APointType& aScale) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    scale = aScale;
}

#endif  // MATHEMATICS_ALGEBRA_AFFINE_MATRIX_DETAIL_H