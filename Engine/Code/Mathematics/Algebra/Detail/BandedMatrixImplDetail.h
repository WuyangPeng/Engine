///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/05 13:14)

#ifndef MATHEMATICS_ALGEBRA_BANDED_MATRIX_IMPL_DETAIL_H
#define MATHEMATICS_ALGEBRA_BANDED_MATRIX_IMPL_DETAIL_H

#include "BandedMatrixDataDetail.h"
#include "BandedMatrixImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include <gsl/util>

template <typename Real>
Mathematics::BandedMatrixImpl<Real>::BandedMatrixImpl(int size, int lowerBandsNumber, int upperBandsNumber)
    : m_DiagonalBand(size), m_LowerBand{ size, lowerBandsNumber }, m_UpperBand{ size, upperBandsNumber }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::BandedMatrixImpl<Real>::IsValid() const noexcept
{
    if (!m_DiagonalBand.empty() && gsl::narrow_cast<int>(m_DiagonalBand.size()) == m_LowerBand.GetSize() && gsl::narrow_cast<int>(m_DiagonalBand.size()) == m_UpperBand.GetSize())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
int Mathematics::BandedMatrixImpl<Real>::GetSize() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return boost::numeric_cast<int>(m_DiagonalBand.size());
}

template <typename Real>
int Mathematics::BandedMatrixImpl<Real>::GetLowerBandsNumber() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_LowerBand.GetBandsNumber();
}

template <typename Real>
int Mathematics::BandedMatrixImpl<Real>::GetUpperBandsNumber() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_UpperBand.GetBandsNumber();
}

template <typename Real>
int Mathematics::BandedMatrixImpl<Real>::GetStreamSize() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return CORE_TOOLS_STREAM_SIZE(m_DiagonalBand) + m_LowerBand.GetStreamSize() + m_UpperBand.GetStreamSize();
}

template <typename Real>
void Mathematics::BandedMatrixImpl<Real>::ResetSize(int size, int lowerBandsNumber, int upperBandsNumber)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    m_DiagonalBand.resize(size, Math::GetValue(0));
    m_LowerBand.ResetSize(size, lowerBandsNumber);
    m_UpperBand.ResetSize(size, upperBandsNumber);
}

template <typename Real>
typename Mathematics::BandedMatrixImpl<Real>::ContainerType Mathematics::BandedMatrixImpl<Real>::GetDiagonalBand() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_DiagonalBand;
}

template <typename Real>
void Mathematics::BandedMatrixImpl<Real>::SetDiagonalBand(const ContainerType& diagonalBand)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    if (diagonalBand.size() != m_DiagonalBand.size())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("对角线元素大小不相等。"s));
    }

    m_DiagonalBand = diagonalBand;
}

template <typename Real>
int Mathematics::BandedMatrixImpl<Real>::GetLowerBandMax(int index) const noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_LowerBand.GetBandMax(index);
}

template <typename Real>
typename Mathematics::BandedMatrixImpl<Real>::ContainerType Mathematics::BandedMatrixImpl<Real>::GetLowerBand(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_LowerBand.GetBand(index);
}

template <typename Real>
void Mathematics::BandedMatrixImpl<Real>::SetLowerBand(int index, const ContainerType& lowerBand)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    m_LowerBand.SetBand(index, lowerBand);
}

template <typename Real>
void Mathematics::BandedMatrixImpl<Real>::SetLowerBandZero()
{
    MATHEMATICS_CLASS_IS_VALID_1;

    m_LowerBand.SetZero();
}

template <typename Real>
int Mathematics::BandedMatrixImpl<Real>::GetUpperBandMax(int index) const noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_UpperBand.GetBandMax(index);
}

template <typename Real>
typename Mathematics::BandedMatrixImpl<Real>::ContainerType Mathematics::BandedMatrixImpl<Real>::GetUpperBand(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_UpperBand.GetBand(index);
}

template <typename Real>
void Mathematics::BandedMatrixImpl<Real>::SetUpperBand(int index, const ContainerType& upperBand)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    m_UpperBand.SetBand(index, upperBand);
}

template <typename Real>
void Mathematics::BandedMatrixImpl<Real>::SetUpperBandZero()
{
    MATHEMATICS_CLASS_IS_VALID_1;

    m_UpperBand.SetZero();
}

template <typename Real>
Real& Mathematics::BandedMatrixImpl<Real>::operator()(int row, int column)
{
    MATHEMATICS_CLASS_IS_VALID_1;
    MATHEMATICS_ASSERTION_0(0 <= row && row < GetSize() && 0 <= column && column < GetSize(), "无效 row 或 column 在 BandedMatrixImpl::operator\n");

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26492)
    return const_cast<Real&>(static_cast<const ClassType&>(*this)(row, column));
#include STSTEM_WARNING_POP
}

template <typename Real>
const Real& Mathematics::BandedMatrixImpl<Real>::operator()(int row, int column) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    MATHEMATICS_ASSERTION_0(0 <= row && row < GetSize() && 0 <= column && column < GetSize(), "无效 row 或 column 在 BandedMatrixImpl::operator\n");

    if (column == row)
    {
        return m_DiagonalBand.at(row);
    }
    else if (row < column)
    {
        return m_UpperBand(row, column);
    }
    else
    {
        return m_LowerBand(row, column);
    }
}

template <typename Real>
void Mathematics::BandedMatrixImpl<Real>::SetZero()
{
    MATHEMATICS_CLASS_IS_VALID_1;

    fill(m_DiagonalBand.begin(), m_DiagonalBand.end(), Math::GetValue(0));
    m_UpperBand.SetZero();
    m_LowerBand.SetZero();
}

template <typename Real>
void Mathematics::BandedMatrixImpl<Real>::SetIdentity()
{
    MATHEMATICS_CLASS_IS_VALID_1;

    fill(m_DiagonalBand.begin(), m_DiagonalBand.end(), Math::GetValue(1));
    m_UpperBand.SetZero();
    m_LowerBand.SetZero();
}

template <typename Real>
const typename Mathematics::BandedMatrixImpl<Real>::VariableMatrix Mathematics::BandedMatrixImpl<Real>::ToVariableMatrix() const
{
    const auto size = GetSize();
    VariableMatrix variableMatrix{ size, size };

    for (auto row = 0; row < size; ++row)
    {
        for (auto column = 0; column < size; ++column)
        {
            variableMatrix(row, column) = (*this)(row, column);
        }
    }

    return variableMatrix;
}

#endif  // MATHEMATICS_ALGEBRA_BANDED_MATRIX_IMPL_DETAIL_H
