/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 11:06)

#include "Mathematics/MathematicsExport.h"

#include "UIntegerArbitraryPrecision32Impl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Base/BitHacks.h"

Mathematics::UIntegerArbitraryPrecision32Impl::UIntegerArbitraryPrecision32Impl() noexcept
    : numBits{ 0 }, bits{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

Mathematics::UIntegerArbitraryPrecision32Impl::UIntegerArbitraryPrecision32Impl(uint32_t number)
    : numBits{ 0 }, bits{}
{
    if (0 < number)
    {
        const auto first = BitHacks::GetLeadingBit(number);
        const auto last = BitHacks::GetTrailingBit(number);
        numBits = first - last + 1;
        bits.emplace_back(number >> last);
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

Mathematics::UIntegerArbitraryPrecision32Impl::UIntegerArbitraryPrecision32Impl(uint64_t number)
    : numBits{ 0 }, bits{}
{
    if (0 < number)
    {
        const auto first = BitHacks::GetLeadingBit(number);
        const auto last = BitHacks::GetTrailingBit(number);
        number >>= last;
        numBits = first - last + 1;
        const auto size = 1 + (numBits - 1) / 32;
        bits.resize(size);
        bits.at(0) = boost::numeric_cast<uint32_t>(number & 0x00000000FFFFFFFFull);
        if (1 < bits.size())
        {
            bits.at(1) = boost::numeric_cast<uint32_t>((number >> 32) & 0x00000000FFFFFFFFull);
        }
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Mathematics, UIntegerArbitraryPrecision32Impl)

void Mathematics::UIntegerArbitraryPrecision32Impl::SetNumBits(int aNumBits)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (aNumBits > 0)
    {
        numBits = aNumBits;
        const auto size = 1 + (numBits - 1) / 32;
        bits.resize(size);
    }
    else if (numBits == 0)
    {
        numBits = 0;
        bits.clear();
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("位数必须是非负的"))
    }
}

int Mathematics::UIntegerArbitraryPrecision32Impl::GetNumBits() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return numBits;
}

const Mathematics::UIntegerArbitraryPrecision32Impl::BitsType& Mathematics::UIntegerArbitraryPrecision32Impl::GetBits() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return bits;
}

Mathematics::UIntegerArbitraryPrecision32Impl::BitsType& Mathematics::UIntegerArbitraryPrecision32Impl::GetBits() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return bits;
}

void Mathematics::UIntegerArbitraryPrecision32Impl::SetBack(uint32_t value) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    bits.back() = value;
}

uint32_t Mathematics::UIntegerArbitraryPrecision32Impl::GetBack() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return bits.back();
}

int Mathematics::UIntegerArbitraryPrecision32Impl::GetSize() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(bits.size());
}

void Mathematics::UIntegerArbitraryPrecision32Impl::SetAllBitsToZero()
{
    MATHEMATICS_CLASS_IS_VALID_9;

    std::ranges::fill(bits, 0u);
}

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

bool Mathematics::UIntegerArbitraryPrecision32Impl::Write(std::ostream& output) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (output.write(reinterpret_cast<const char*>(&numBits), sizeof(numBits)).bad())
    {
        return false;
    }

    const auto size = bits.size();
    if (output.write(reinterpret_cast<const char*>(&size), sizeof(size)).bad())
    {
        return false;
    }

    if (size == 0)
    {
        return true;
    }

    const auto bitsSize = boost::numeric_cast<int64_t>(size * sizeof(bits[0]));

    return output.write(reinterpret_cast<const char*>(bits.data()), bitsSize).good();
}

bool Mathematics::UIntegerArbitraryPrecision32Impl::Read(std::istream& input)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (input.read(reinterpret_cast<char*>(&numBits), sizeof(numBits)).bad())
    {
        return false;
    }

    size_t size{};
    if (input.read(reinterpret_cast<char*>(&size), sizeof(size)).bad())
    {
        return false;
    }

    bits.resize(size);

    if (size == 0)
    {
        return true;
    }

    const auto bitsSize = boost::numeric_cast<int64_t>(size * sizeof(bits[0]));

    return input.read(reinterpret_cast<char*>(bits.data()), bitsSize).good();
}

#include SYSTEM_WARNING_POP
