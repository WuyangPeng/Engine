/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 23:18)

#ifndef MATHEMATICS_RATIONAL_INTEGER_DATA_DETAIL_H
#define MATHEMATICS_RATIONAL_INTEGER_DATA_DETAIL_H

#include "ConversionIntegerDetail.h"
#include "IntegerData.h"
#include "IntegerDataAmendDetail.h"
#include "IntegerDataAnalysisDetail.h"
#include "System/Helper/Tools.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <int N>
Mathematics::IntegerData<N>::IntegerData(Special special) noexcept
    : buffer{ 1 }
{
    static_assert(0 < N);

    System::UnusedFunction(special);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int N>
Mathematics::IntegerData<N>::IntegerData() noexcept
    : buffer{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int N>
void Mathematics::IntegerData<N>::SetZero()
{
    buffer.fill(0);
}

template <int N>
Mathematics::IntegerData<N>::IntegerData(const DataType& data)
    : buffer{}
{
    Init(data);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int N>
template <typename T>
Mathematics::IntegerData<N>::IntegerData(T value)
    : buffer{}
{
    Init(value);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int N>
template <typename T>
void Mathematics::IntegerData<N>::Init(T value)
{
    const ConversionInteger<T> conversion{ value };

    const auto beginBlock = boost::numeric_cast<size_t>(conversion.GetBeginBlock());
    const auto mantissa = conversion.GetShiftingMantissa();
    const auto mantissaSize = conversion.GetMantissaSize();
    const auto copySize = conversion.GetCopySize();

    DataType data(mantissaSize);
    const auto copySizePlus1 = copySize + 1;
    const auto endBlock = beginBlock + copySizePlus1 / sizeof(uint16_t);

    if (beginBlock < data.size() && beginBlock < endBlock && endBlock <= data.size() && copySize <= sizeof(uint64_t) / sizeof(uint8_t))
    {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

        memcpy(data.data() + beginBlock, &mantissa, copySize);

#include SYSTEM_WARNING_POP
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("数组越界！"s));
    }

    Init(data);

    const auto symbol = conversion.GetSymbol();
    if (symbol == NumericalValueSymbol::Negative)
    {
        IntegerDataAmend<N> amend{ *this };
        amend.Negative();
    }
}

template <int N>
void Mathematics::IntegerData<N>::Init(const DataType& data)
{
    for (auto i = 0; i < boost::numeric_cast<int>(data.size()) && i < intSize; ++i)
    {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)

        buffer[i] = data[i];

#include SYSTEM_WARNING_POP
    }
}

template <int N>
bool Mathematics::IntegerData<N>::IsZero() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    for (auto value : buffer)
    {
        if (value != 0)
        {
            return false;
        }
    }

    return true;
}

#ifdef OPEN_CLASS_INVARIANT

template <int N>
bool Mathematics::IntegerData<N>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <int N>
void Mathematics::IntegerData<N>::SwapBigEndian() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

#ifdef CORE_TOOLS_BIG_ENDIAN

    for (auto i = 0; i <= N; ++i)
    {
        std::swap(buffer[2 * i], buffer[2 * i + 1]);
    }

#endif  // CORE_TOOLS_BIG_ENDIAN
}

template <int N>
void Mathematics::IntegerData<N>::SetBit(int index, bool on)
{
    MATHEMATICS_CLASS_IS_VALID_9;
    MATHEMATICS_ASSERTION_0(0 <= index && index < intSize * blockSize, "索引错误！");

    const auto block = index / blockSize;
    const auto bit = index % blockSize;
    if (on)
    {
        buffer.at(block) |= (1 << bit);
    }
    else
    {
        buffer.at(block) &= ~(1 << bit);
    }
}

template <int N>
bool Mathematics::IntegerData<N>::GetBit(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;
    MATHEMATICS_ASSERTION_0(0 <= index && index < intSize * blockSize, "索引错误！");

    const auto block = index / blockSize;
    const auto bit = index % blockSize;

    return (buffer.at(block) & (1 << bit)) != 0;
}

template <int N>
uint16_t& Mathematics::IntegerData<N>::operator[](int index)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return OPERATOR_SQUARE_BRACKETS(uint16_t, index);
}

template <int N>
const uint16_t& Mathematics::IntegerData<N>::operator[](int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return buffer.at(index);
}

template <int N>
Mathematics::NumericalValueSymbol Mathematics::IntegerData<N>::GetSign() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    return (buffer[intLast] & 0x8000) ? NumericalValueSymbol::Negative : NumericalValueSymbol::Positive;

#include SYSTEM_WARNING_POP
}

template <int N>
Mathematics::NumericalValueSymbol Mathematics::IntegerData<N>::UnsignedDataCompare(const IntegerData& lhs, const IntegerData& rhs)
{
    for (auto index = intLast; 0 <= index; --index)
    {
        if (lhs[index] < rhs[index])
        {
            return NumericalValueSymbol::Negative;
        }
        else if (rhs[index] < lhs[index])
        {
            return NumericalValueSymbol::Positive;
        }
    }

    return NumericalValueSymbol::Zero;
}

template <int N>
bool Mathematics::operator==(const IntegerData<N>& lhs, const IntegerData<N>& rhs)
{
    return IntegerData<N>::UnsignedDataCompare(lhs, rhs) == NumericalValueSymbol::Zero;
}

template <int N>
bool Mathematics::operator<(const IntegerData<N>& lhs, const IntegerData<N>& rhs)
{
    const auto lhsSymbol = lhs.GetSign();
    const auto rhsSymbol = rhs.GetSign();

    if (lhsSymbol == NumericalValueSymbol::Positive)
    {
        if (rhsSymbol == NumericalValueSymbol::Positive)
        {
            return IntegerData<N>::UnsignedDataCompare(lhs, rhs) == NumericalValueSymbol::Negative;
        }
        else
        {
            return false;
        }
    }
    else
    {
        if (rhsSymbol == NumericalValueSymbol::Positive)
        {
            return true;
        }
        else
        {
            return IntegerData<N>::UnsignedDataCompare(lhs, rhs) == NumericalValueSymbol::Negative;
        }
    }
}

template <int N>
std::ostream& Mathematics::operator<<(std::ostream& os, const IntegerData<N>& integerData)
{
    const auto symbol = integerData.GetSign();

    if (symbol == NumericalValueSymbol::Negative)
    {
        IntegerData<N> negativeIntegerData{ integerData };
        IntegerDataAmend<N> amend{ negativeIntegerData };
        amend.Negative();
        os << "-" << negativeIntegerData;

        return os;
    }
    else
    {
        if (!integerData.IsZero())
        {
            const IntegerDataAnalysis<N> integerDataAnalysis{ integerData };

            os << integerDataAnalysis;
        }
        else
        {
            os << "0";
        }

        return os;
    }
}

#endif  // MATHEMATICS_RATIONAL_INTEGER_DATA_DETAIL_H
