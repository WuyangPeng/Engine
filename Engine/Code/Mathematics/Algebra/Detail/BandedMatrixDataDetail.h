///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/05 11:11)

#ifndef MATHEMATICS_ALGEBRA_BANDED_MATRIX_DATA_DETAIL_H
#define MATHEMATICS_ALGEBRA_BANDED_MATRIX_DATA_DETAIL_H

#include "BandedMatrixData.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/StreamMacro.h"

#include <gsl/gsl_util>

template <typename Real>
Mathematics::BandedMatrixData<Real>::BandedMatrixData(int size, int bandsNumber)
    : m_Size{ size }, m_Bands{}
{
    Allocate(bandsNumber);

    MATHEMATICS_SELF_CLASS_IS_VALID_3;
}

// private
template <typename Real>
void Mathematics::BandedMatrixData<Real>::Allocate(int bandsNumber)
{
    for (auto i = 0; i < bandsNumber; ++i)
    {
        const auto bandsSize = m_Size - 1 - i;

        m_Bands.emplace_back(ContainerType(bandsSize));
    }
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::BandedMatrixData<Real>::IsValid() const noexcept
{
    if (m_Size <= 0 || m_Size <= gsl::narrow_cast<int>(m_Bands.size()))
    {
        return false;
    }
    else
    {
        auto index = 0;
        for (const auto& value : m_Bands)
        {
            const auto bandsSize = m_Size - 1 - index;

            if (bandsSize != gsl::narrow_cast<int>(value.size()))
                return false;

            ++index;
        }
    }

    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
int Mathematics::BandedMatrixData<Real>::GetSize() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Size;
}

template <typename Real>
int Mathematics::BandedMatrixData<Real>::GetBandsNumber() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;

    return boost::numeric_cast<int>(m_Bands.size());
}

template <typename Real>
int Mathematics::BandedMatrixData<Real>::GetStreamSize() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;

    auto size = CoreTools::GetStreamSize<int32_t>();

    const auto bandsNumber = GetBandsNumber();
    for (auto i = 0; i < bandsNumber; ++i)
    {
        const auto bandsSize = m_Size - 1 - i;
        size += CoreTools::GetStreamSize<Real>() * bandsSize;
    }

    return size;
}

template <typename Real>
void Mathematics::BandedMatrixData<Real>::ResetSize(int size, int bandsNumber)
{
    MATHEMATICS_CLASS_IS_VALID_3;

    m_Size = size;
    m_Bands.clear();
    Allocate(bandsNumber);

    m_Bands.shrink_to_fit();
}

template <typename Real>
int Mathematics::BandedMatrixData<Real>::GetBandMax(int index) const noexcept(g_Assert < 1 || g_MathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;
    MATHEMATICS_ASSERTION_1(0 <= index && index < GetBandsNumber(), "无效索引在 GetBandMax\n");

    return m_Size - 1 - index;
}

template <typename Real>
typename Mathematics::BandedMatrixData<Real>::ContainerType Mathematics::BandedMatrixData<Real>::GetBand(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;

    return m_Bands.at(index);
}

template <typename Real>
void Mathematics::BandedMatrixData<Real>::SetBand(int index, const ContainerType& band)
{
    MATHEMATICS_CLASS_IS_VALID_3;

    auto& bands = m_Bands.at(index);

    if (bands.size() != band.size())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("元素大小不相等。"s));
    }

    bands = band;
}

template <typename Real>
Real& Mathematics::BandedMatrixData<Real>::operator()(int row, int column)
{
    MATHEMATICS_CLASS_IS_VALID_3;
    MATHEMATICS_ASSERTION_0(0 <= row && row < m_Size && 0 <= column && column < m_Size, "无效 row 或 column 在 BandedMatrixData::operator\n");

    return const_cast<Real&>(static_cast<const ClassType&>(*this)(row, column));
}

template <typename Real>
const Real& Mathematics::BandedMatrixData<Real>::operator()(int row, int column) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;
    MATHEMATICS_ASSERTION_0(0 <= row && row < m_Size && 0 <= column && column < m_Size, "无效 row 或 column 在 BandedMatrixData::operator\n");

    auto band = column - row;
    if (0 < band)
    {
        --band;
        if (band < GetBandsNumber() && row < m_Size - 1 - band)
        {
            return m_Bands.at(band).at(row);
        }
    }
    else if (band < 0)
    {
        band = -band - 1;

        if (band < GetBandsNumber() && column < m_Size - 1 - band)
        {
            return m_Bands.at(band).at(column);
        }
    }

    static auto s_Dummy = Math::GetValue(0);

    MATHEMATICS_ASSERTION_1(Math::FAbs(s_Dummy) <= Math::GetZeroTolerance(), "静态变量s_Dummy值被修改！s_Dummy值必须为零！");

    s_Dummy = Math::GetValue(0);

    return s_Dummy;
}

template <typename Real>
void Mathematics::BandedMatrixData<Real>::SetZero()  
{
    MATHEMATICS_CLASS_IS_VALID_3;

    for (auto& bands : m_Bands)
    {
        fill(bands.begin(), bands.end(), Math::GetValue(0));
    }
}

#endif  // MATHEMATICS_ALGEBRA_BANDED_MATRIX_DATA_DETAIL_H
