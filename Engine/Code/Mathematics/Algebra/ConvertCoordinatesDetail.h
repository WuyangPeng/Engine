///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.6 (2024/02/20 16:25)

#ifndef MATHEMATICS_ALGEBRA_CONVERT_COORDINATES_DETAIL_H
#define MATHEMATICS_ALGEBRA_CONVERT_COORDINATES_DETAIL_H

#include "ConvertCoordinates.h"
#include "Matrix/MatrixDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/NumericalAnalysis/GaussianEliminationDetail.h"

template <int N, typename Real>
Mathematics::ConvertCoordinates<N, Real>::ConvertCoordinates(const Matrix& u,
                                                             bool vectorOnRightU,
                                                             const Matrix& v,
                                                             bool vectorOnRightV)
    : c{ Matrix::Identity() },
      inverseC{ Matrix::Identity() },
      isVectorOnRightU{ vectorOnRightU },
      isVectorOnRightV{ vectorOnRightV },
      isRightHandedU{ true },
      isRightHandedV{ true }
{
    GaussianElimination<Real> gaussianEliminationU{ N, u.GetBaseContainer(), true };

    if (!gaussianEliminationU.IsInverse())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("获取逆矩阵失败。"))
    }

    const Matrix inverseU{ gaussianEliminationU.GetInverse() };
    const auto determinantU = gaussianEliminationU.GetDeterminant();

    GaussianElimination<Real> gaussianEliminationV{ N, v.GetBaseContainer(), true };

    if (!gaussianEliminationV.IsInverse())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("获取逆矩阵失败。"))
    }

    const Matrix inverseV{ gaussianEliminationV.GetInverse() };
    const auto determinantV = gaussianEliminationV.GetDeterminant();

    c = inverseU * v;
    inverseC = inverseV * u;

    isRightHandedU = Real{} < determinantU;
    isRightHandedV = Real{} < determinantV;

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <int N, typename Real>
bool Mathematics::ConvertCoordinates<N, Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <int N, typename Real>
typename Mathematics::ConvertCoordinates<N, Real>::Matrix Mathematics::ConvertCoordinates<N, Real>::GetC() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return c;
}

template <int N, typename Real>
typename Mathematics::ConvertCoordinates<N, Real>::Matrix Mathematics::ConvertCoordinates<N, Real>::GetInverseC() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return inverseC;
}

template <int N, typename Real>
bool Mathematics::ConvertCoordinates<N, Real>::IsVectorOnRightU() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return isVectorOnRightU;
}

template <int N, typename Real>
bool Mathematics::ConvertCoordinates<N, Real>::IsVectorOnRightV() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return isVectorOnRightV;
}

template <int N, typename Real>
bool Mathematics::ConvertCoordinates<N, Real>::IsRightHandedU() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return isRightHandedU;
}

template <int N, typename Real>
bool Mathematics::ConvertCoordinates<N, Real>::IsRightHandedV() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return isRightHandedV;
}

template <int N, typename Real>
typename Mathematics::ConvertCoordinates<N, Real>::Vector Mathematics::ConvertCoordinates<N, Real>::UToV(const Vector& x) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return inverseC * x;
}

template <int N, typename Real>
typename Mathematics::ConvertCoordinates<N, Real>::Vector Mathematics::ConvertCoordinates<N, Real>::VToU(const Vector& y) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return c * y;
}

template <int N, typename Real>
typename Mathematics::ConvertCoordinates<N, Real>::Matrix Mathematics::ConvertCoordinates<N, Real>::UToV(const Matrix& a) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    Matrix product{};

    if (isVectorOnRightU)
    {
        product = inverseC * a * c;
        if (isVectorOnRightV)
        {
            return product;
        }
        else
        {
            return Transpose(product);
        }
    }
    else
    {
        product = inverseC * TranspositionMultiply(a, c);
        if (isVectorOnRightV)
        {
            return product;
        }
        else
        {
            return Transpose(product);
        }
    }
}

template <int N, typename Real>
typename Mathematics::ConvertCoordinates<N, Real>::Matrix Mathematics::ConvertCoordinates<N, Real>::VToU(const Matrix& b) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    Matrix product{};

    if (isVectorOnRightV)
    {
        product = c * b * inverseC;
        if (isVectorOnRightU)
        {
            return product;
        }
        else
        {
            return Transpose(product);
        }
    }
    else
    {
        product = c * TranspositionMultiply(b, inverseC);
        if (isVectorOnRightU)
        {
            return product;
        }
        else
        {
            return Transpose(product);
        }
    }
}

#endif  // MATHEMATICS_ALGEBRA_CONVERT_COORDINATES_DETAIL_H
