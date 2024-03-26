/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 13:28)

#ifndef MATHEMATICS_RATIONAL_RATIONAL_U_INTEGER_FIXED_PRECISION_32_DETAIL_H
#define MATHEMATICS_RATIONAL_RATIONAL_U_INTEGER_FIXED_PRECISION_32_DETAIL_H

#include "UIntegerFixedPrecision32.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Base/BitHacks.h"

template <int N>
requires(0 < N)
Mathematics::UIntegerFixedPrecision32<N> Mathematics::UIntegerFixedPrecision32<N>::CreateZero() noexcept
{
    return UIntegerFixedPrecision32{};
}

template <int N>
requires(0 < N)
Mathematics::UIntegerFixedPrecision32<N>::UIntegerFixedPrecision32() noexcept
    : numBits{ 0 }, size{ 0 }, bits{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int N>
requires(0 < N)
Mathematics::UIntegerFixedPrecision32<N>::UIntegerFixedPrecision32(uint32_t number)
    : numBits{ 0 }, size{ 0 }, bits{}
{
    if (0 < number)
    {
        const auto first = BitHacks::GetLeadingBit(number);
        const auto last = BitHacks::GetTrailingBit(number);
        numBits = first - last + 1;
        size = 1;
        bits.at(0) = number >> last;
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int N>
requires(0 < N)
Mathematics::UIntegerFixedPrecision32<N>::UIntegerFixedPrecision32(uint64_t number) requires(2 <= N)
    : numBits{ 0 }, size{ 0 }, bits{}
{
    if (0 < number)
    {
        const auto first = BitHacks::GetLeadingBit(number);
        const auto last = BitHacks::GetTrailingBit(number);
        number >>= last;
        numBits = first - last + 1;
        size = 1 + (numBits - 1) / 32;

        bits.at(0) = boost::numeric_cast<uint32_t>(number & 0x00000000FFFFFFFFull);
        if (1 < size)
        {
            bits.at(1) = boost::numeric_cast<uint32_t>((number >> 32) & 0x00000000FFFFFFFFull);
        }
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <int N>
requires(0 < N)
bool Mathematics::UIntegerFixedPrecision32<N>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <int N>
requires(0 < N)
void Mathematics::UIntegerFixedPrecision32<N>::SetNumBits(int aNumBits)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (0 < aNumBits)
    {
        numBits = aNumBits;
        size = 1 + (numBits - 1) / 32;
    }
    else if (numBits == 0)
    {
        numBits = 0;
        size = 0;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("位数必须是非负的"))
    }
}

template <int N>
requires(0 < N)
int Mathematics::UIntegerFixedPrecision32<N>::GetNumBits() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return numBits;
}

template <int N>
requires(0 < N)
const typename Mathematics::UIntegerFixedPrecision32<N>::BitsType& Mathematics::UIntegerFixedPrecision32<N>::GetBits() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return bits;
}

template <int N>
requires(0 < N)
typename Mathematics::UIntegerFixedPrecision32<N>::BitsType& Mathematics::UIntegerFixedPrecision32<N>::GetBits() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return bits;
}

template <int N>
requires(0 < N)
void Mathematics::UIntegerFixedPrecision32<N>::SetBack(uint32_t value)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    bits.at(boost::numeric_cast<size_t>(size) - 1) = value;
}

template <int N>
requires(0 < N)
uint32_t Mathematics::UIntegerFixedPrecision32<N>::GetBack() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return bits.at(boost::numeric_cast<size_t>(size) - 1);
}

template <int N>
requires(0 < N)
int Mathematics::UIntegerFixedPrecision32<N>::GetSize() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return size;
}

template <int N>
requires(0 < N)
int Mathematics::UIntegerFixedPrecision32<N>::GetMaxSize() noexcept
{
    return N;
}

template <int N>
requires(0 < N)
void Mathematics::UIntegerFixedPrecision32<N>::SetAllBitsToZero()
{
    MATHEMATICS_CLASS_IS_VALID_9;

    std::ranges::fill(bits, 0u);
}

template <int N>
requires(0 < N)
template <int NSource>
void Mathematics::UIntegerFixedPrecision32<N>::CopyFrom(const UIntegerFixedPrecision32<NSource>& source) requires(NSource <= N)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    numBits = source.GetNumBits();
    size = source.GetSize();
    const auto srcBits = source.GetBits();
    std::copy(srcBits.begin(), srcBits.end(), bits.begin());
}

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

template <int N>
requires(0 < N)
bool Mathematics::UIntegerFixedPrecision32<N>::Write(std::ostream& output) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (output.write(reinterpret_cast<const char*>(&numBits), sizeof(numBits)).bad())
    {
        return false;
    }

    if (output.write(reinterpret_cast<const char*>(&size), sizeof(size)).bad())
    {
        return false;
    }

    const auto bitsSize = boost::numeric_cast<int64_t>(size * sizeof(bits[0]));

    return output.write(reinterpret_cast<const char*>(bits.data()), bitsSize).good();
}

template <int N>
requires(0 < N)
bool Mathematics::UIntegerFixedPrecision32<N>::Read(std::istream& input)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (input.read(reinterpret_cast<char*>(&numBits), sizeof(numBits)).bad())
    {
        return false;
    }

    if (input.read(reinterpret_cast<char*>(&size), sizeof(size)).bad())
    {
        return false;
    }

    const auto bitsSize = boost::numeric_cast<int64_t>(size * sizeof(bits[0]));

    return input.read(reinterpret_cast<char*>(bits.data()), bitsSize).good();
}

#include SYSTEM_WARNING_POP

template <int N>
requires(0 < N)
const Mathematics::UIntegerFixedPrecision32<N>& Mathematics::UIntegerFixedPrecision32<N>::GetSelf() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return *this;
}

template <int N>
requires(0 < N)
Mathematics::UIntegerFixedPrecision32<N>& Mathematics::UIntegerFixedPrecision32<N>::GetSelf() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return *this;
}

#endif  // MATHEMATICS_RATIONAL_RATIONAL_U_INTEGER_FIXED_PRECISION_32_DETAIL_H
