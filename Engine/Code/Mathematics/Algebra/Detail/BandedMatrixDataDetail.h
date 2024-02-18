/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.5 (2024/02/18 13:19)

#ifndef MATHEMATICS_ALGEBRA_BANDED_MATRIX_DATA_DETAIL_H
#define MATHEMATICS_ALGEBRA_BANDED_MATRIX_DATA_DETAIL_H

#include "BandedMatrixData.h"
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
void Mathematics::BandedMatrixData<Real>::ResetSize(int aSize, int bandsNumber)
{
    MATHEMATICS_CLASS_IS_VALID_3;

    size = aSize;
    bands.clear();
    Allocate(bandsNumber);

    bands.shrink_to_fit();
}

template <typename Real>
requires std::is_arithmetic_v<Real>
int Mathematics::BandedMatrixData<Real>::GetBandMax(int index) const noexcept(gAssert < 1 || gMathematicsAssert < 1)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_3;
    MATHEMATICS_ASSERTION_1(0 <= index && index < GetBandsNumber(), "��Ч������ GetBandMax\n");

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

    auto& element = bands.at(index);

    if (element.size() != band.size())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("Ԫ�ش�С����ȡ�"s))
    }

    element = band;
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

    /// ����operator(int,int)���صĲ��ڴ��е���Ч������
    /// ����������£�������Ϊ�㡣
    static Real zero{};

    MATHEMATICS_ASSERTION_1(Math::FAbs(zero) <= Math::GetZeroTolerance(), "��̬����dummyֵ���޸ģ�dummyֵ����Ϊ�㣡");

    /// ����ֵ����Ϊ�㣬
    /// �Է�������ǰһ�ε���operator(int,int)ʱ�������޸���dummy��
    zero = Math::GetValue(0);

    return zero;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
void Mathematics::BandedMatrixData<Real>::SetZero()
{
    MATHEMATICS_CLASS_IS_VALID_3;

    for (auto& element : bands)
    {
        std::ranges::fill(element, Math::GetValue(0));
    }
}

#endif  // MATHEMATICS_ALGEBRA_BANDED_MATRIX_DATA_DETAIL_H
