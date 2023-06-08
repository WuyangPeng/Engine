///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/05/31 09:24)

#ifndef MATHEMATICS_ALGEBRA_BANDED_MATRIX_DATA_DETAIL_H
#define MATHEMATICS_ALGEBRA_BANDED_MATRIX_DATA_DETAIL_H

#include "BandedMatrixData.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

#include <gsl/util>

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::BandedMatrixData<Real>::BandedMatrixData(int size, int bandsNumber)
    : size{ size }, bands{}
{
    Allocate(bandsNumber);

    MATHEMATICS_SELF_CLASS_IS_VALID_3;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::BandedMatrixData<Real>::Allocate(int bandsNumber)
{
    for (auto i = 0; i < bandsNumber; ++i)
    {
        const auto bandsSize = size - 1 - i;

        bands.emplace_back(bandsSize);
    }
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires std::is_arithmetic_v<Real> bool Mathematics::BandedMatrixData<Real>::IsValid() const noexcept
{
    if (size <= 0 || size <= gsl::narrow_cast<int>(bands.size()))
    {
        return false;
    }
    else
    {
        auto index = 0;
        for (const auto& value : bands)
        {
            const auto bandsSize = size - 1 - index;

            if (bandsSize != gsl::narrow_cast<int>(value.size()))
            {
                return false;
            }

            ++index;
        }
    }

    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires std::is_arithmetic_v<Real>
int Mathematics::BandedMatrixData<Real>::GetSize() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;

    return size;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
int Mathematics::BandedMatrixData<Real>::GetBandsNumber() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;

    return boost::numeric_cast<int>(bands.size());
}

template <typename Real>
requires std::is_arithmetic_v<Real>
int Mathematics::BandedMatrixData<Real>::GetStreamSize() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;

    auto streamSize = CoreTools::GetStreamSize<int32_t>();

    const auto bandsNumber = GetBandsNumber();
    for (auto i = 0; i < bandsNumber; ++i)
    {
        const auto bandsSize = size - 1 - i;
        streamSize += CoreTools::GetStreamSize<Real>() * bandsSize;
    }

    return streamSize;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::BandedMatrixData<Real>::ResetSize(int newSize, int bandsNumber)
{
    MATHEMATICS_CLASS_IS_VALID_3;

    size = newSize;
    bands.clear();
    Allocate(bandsNumber);

    bands.shrink_to_fit();
}

template <typename Real>
requires std::is_arithmetic_v<Real>
int Mathematics::BandedMatrixData<Real>::GetBandMax(int index) const noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;
    MATHEMATICS_ASSERTION_1(0 <= index && index < GetBandsNumber(), "无效索引在 GetBandMax\n");

    return size - 1 - index;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::BandedMatrixData<Real>::ContainerType Mathematics::BandedMatrixData<Real>::GetBand(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;

    return bands.at(index);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::BandedMatrixData<Real>::SetBand(int index, const ContainerType& band)
{
    MATHEMATICS_CLASS_IS_VALID_3;

    auto& value = bands.at(index);

    if (value.size() != band.size())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("元素大小不相等。"s))
    }

    value = band;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real& Mathematics::BandedMatrixData<Real>::operator()(int row, int column)
{
    MATHEMATICS_CLASS_IS_VALID_3;

    return const_cast<Real&>(static_cast<const ClassType&>(*this)(row, column));
}

template <typename Real>
requires std::is_arithmetic_v<Real>
const Real& Mathematics::BandedMatrixData<Real>::operator()(int row, int column) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;
    MATHEMATICS_ASSERTION_0(0 <= row && row < size && 0 <= column && column < size, "无效 row 或 column 在 BandedMatrixData::operator\n");

    if (auto band = column - row;
        0 < band)
    {
        --band;
        if (band < GetBandsNumber() && row < size - 1 - band)
        {
            return bands.at(band).at(row);
        }
    }
    else if (band < 0)
    {
        band = -band - 1;

        if (band < GetBandsNumber() && column < size - 1 - band)
        {
            return bands.at(band).at(column);
        }
    }

    static auto dummy = Math::GetValue(0);

    MATHEMATICS_ASSERTION_1(Math::FAbs(dummy) <= Math::GetZeroTolerance(), "静态变量dummy值被修改！dummy值必须为零！");

    dummy = Math::GetValue(0);

    return dummy;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::BandedMatrixData<Real>::SetZero()
{
    MATHEMATICS_CLASS_IS_VALID_3;

    for (auto& value : bands)
    {
        std::ranges::fill(value, Math::GetValue(0));
    }
}

#endif  // MATHEMATICS_ALGEBRA_BANDED_MATRIX_DATA_DETAIL_H
