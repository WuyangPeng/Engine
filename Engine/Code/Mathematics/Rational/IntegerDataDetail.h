// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎版本：0.0.2.5 (2020/03/20 10:12)

#ifndef MATHEMATICS_RATIONAL_INTEGER_DATA_DETAIL_H
#define MATHEMATICS_RATIONAL_INTEGER_DATA_DETAIL_H

#include "ConversionIntegerDetail.h"
#include "IntegerData.h"
#include "IntegerDataAmendDetail.h"
#include "IntegerDataAnalysisDetail.h"
#include "System/Helper/PragmaWarning/Format.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

#include "System/Helper/PragmaWarning.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26485)
#include SYSTEM_WARNING_DISABLE(26455)
#include SYSTEM_WARNING_DISABLE(26482)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26429)
template <int N>
Mathematics::IntegerData<N>::IntegerData()
    : m_Buffer{}
{
    SetZero();

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int N>
void Mathematics::IntegerData<N>::SetZero() noexcept
{
    for (auto i = 0; i < sm_IntSize; ++i)
    {
        m_Buffer[i] = 0;
    }
}

template <int N>
Mathematics::IntegerData<N>::IntegerData(const std::vector<uint16_t>& data)
    : m_Buffer{}
{
    SetZero();
    Init(boost::numeric_cast<int>(data.size()), &data[0]);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int N>
template <int Other>
Mathematics::IntegerData<N>::IntegerData(const IntegerData<Other>& rhs)
    : m_Buffer{}
{
    SetZero();
    Init(2 * Other, &rhs[0]);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int N>
template <typename T>
Mathematics::IntegerData<N>::IntegerData(T value)
    : m_Buffer{}
{
    SetZero();
    Init(value);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

// private
template <int N>
template <typename T>
void Mathematics::IntegerData<N>::Init(T value)
{
    const ConversionInteger<T> conversion{ value };

    auto beginBlock = boost::numeric_cast<uint32_t>(conversion.GetBeginBlock());
    const auto mantissa = conversion.GetShiftingMantissa();
    const auto mantissaSize = conversion.GetMantissaSize();
    const auto copySize = conversion.GetCopySize();

    std::vector<uint16_t> data(mantissaSize);
    const auto temp = copySize + 1;
    const auto endBlock = beginBlock + temp / sizeof(uint16_t);

    if (beginBlock < data.size() && beginBlock < endBlock && endBlock <= data.size() && copySize <= sizeof(uint64_t) / sizeof(uint8_t))
    {
        memcpy(&data[beginBlock], &mantissa, copySize);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("数组越界！"));
    }

    Init(boost::numeric_cast<int>(data.size()), &data[0]);

    const auto symbol = conversion.GetSymbol();
    if (symbol == NumericalValueSymbol::Negative)
    {
        IntegerDataAmend<N> amend{ *this };
        amend.Negative();
    }
}

template <int N>
bool Mathematics::IntegerData<N>::IsZero() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    for (auto i = 0u; i < sm_IntSize; ++i)
    {
        if (m_Buffer[i] != 0)
        {
            return false;
        }
    }

    return true;
}

template <int N>
void Mathematics::IntegerData<N>::Init(int count, const uint16_t* data)
{
    if (count <= sm_IntSize)
    {
        const auto sizeBytes = count * sizeof(uint16_t);

        memcpy(m_Buffer, &data[0], sizeBytes);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("传入的值溢出！"s));
    }
}

template <int N>
Mathematics::IntegerData<N>::IntegerData(int count, const uint16_t* data)
    : m_Buffer{}
{
    SetZero();
    Init(count, data);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int N>
Mathematics::IntegerData<N>::IntegerData(const IntegerData& rhs) noexcept
{
    memcpy(m_Buffer, rhs.m_Buffer, sm_IntBytes);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int N>
Mathematics::IntegerData<N>& Mathematics::IntegerData<N>::operator=(const IntegerData& rhs) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    memcpy(m_Buffer, rhs.m_Buffer, sm_IntBytes);

    return *this;
}

#ifdef OPEN_CLASS_INVARIANT
template <int N>
bool Mathematics::IntegerData<N>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <int N>
void Mathematics::IntegerData<N>::SwapBigEndian()
{
    MATHEMATICS_CLASS_IS_VALID_9;

#ifdef CORE_TOOLS_BIG_ENDIAN
    for (auto i = 0u; i <= N; ++i)
    {
        std::swap(m_Buffer[2 * i], m_Buffer[2 * i + 1]);
    }
#endif  // CORE_TOOLS_BIG_ENDIAN
}

template <int N>
void Mathematics::IntegerData<N>::SetBit(int index, bool on)
{
    MATHEMATICS_CLASS_IS_VALID_9;
    MATHEMATICS_ASSERTION_0(0 <= index && index < sm_IntSize * 16, "索引错误！");

    auto block = index / 16;
    auto bit = index % 16;
    if (on)
    {
        m_Buffer[block] |= (1 << bit);
    }
    else
    {
        m_Buffer[block] &= ~(1 << bit);
    }
}

template <int N>
bool Mathematics::IntegerData<N>::GetBit(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;
    MATHEMATICS_ASSERTION_0(0 <= index && index < sm_IntSize * 16, "索引错误！");

    auto block = index / 16;
    auto bit = index % 16;

    return (m_Buffer[block] & (1 << bit)) != 0;
}

template <int N>
uint16_t& Mathematics::IntegerData<N>::operator[](int index)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (0 <= index && index <= sm_IntLast)
    {
        return m_Buffer[index];
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("索引错误！"));
    }
}

template <int N>
const uint16_t& Mathematics::IntegerData<N>::operator[](int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (0 <= index && index <= sm_IntLast)
    {
        return m_Buffer[index];
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("索引错误！"));
    }
}

template <int N>
Mathematics::NumericalValueSymbol Mathematics::IntegerData<N>::GetSign() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return (m_Buffer[sm_IntLast] & 0x8000) ? NumericalValueSymbol::Negative : NumericalValueSymbol::Positive;
}

template <int N>
Mathematics::NumericalValueSymbol Mathematics::IntegerData<N>::UnsignedDataCompare(const IntegerData& lhs, const IntegerData& rhs)
{
    for (int index = boost::numeric_cast<int>(sm_IntLast); 0 <= index; --index)
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
bool Mathematics ::operator==(const IntegerData<N>& lhs, const IntegerData<N>& rhs)
{
    return IntegerData<N>::UnsignedDataCompare(lhs, rhs) == NumericalValueSymbol::Zero;
}

template <int N>
bool Mathematics ::operator<(const IntegerData<N>& lhs, const IntegerData<N>& rhs)
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
std::ostream& Mathematics ::operator<<(std::ostream& os, const IntegerData<N>& integerData)
{
    auto symbol = integerData.GetSign();

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
            IntegerDataAnalysis<N> integerDataAnalysis{ integerData };

            os << integerDataAnalysis;
        }
        else
        {
            os << "0";
        }

        return os;
    }
}
#include STSTEM_WARNING_POP
#endif  // MATHEMATICS_RATIONAL_INTEGER_DATA_DETAIL_H
