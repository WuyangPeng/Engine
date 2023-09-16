///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/08 16:12)

#ifndef MATHEMATICS_RATIONAL_INTEGER_DETAIL_H
#define MATHEMATICS_RATIONAL_INTEGER_DETAIL_H

#include "Integer.h"
#include "IntegerDataAnalysisDetail.h"
#include "IntegerDataConversionDetail.h"
#include "IntegerDataDetail.h"
#include "IntegerDataOperatorDetail.h"
#include "IntegerDivisionModuloDetail.h"
#include "IntegerMultiplicationDetail.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <int N>
Mathematics::Integer<N> Mathematics::Integer<N>::CreateOne() noexcept
{
    return Integer{ Special::One };
}

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26434)

template <int N>
Mathematics::Integer<N>::Integer(Special special) noexcept
    : integerData{ IntegerData::Special::One }
{
    System::UnusedFunction(special);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#include SYSTEM_WARNING_POP

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26434)

template <int N>
Mathematics::Integer<N>::Integer() noexcept
    : integerData{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#include SYSTEM_WARNING_POP

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26434)

template <int N>
Mathematics::Integer<N>::Integer(const DataType& data)
    : integerData{ data }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#include SYSTEM_WARNING_POP

template <int N>
template <typename T>
Mathematics::Integer<N>::Integer(T value)
    : integerData{ value }
{
    static_assert(std::is_arithmetic_v<T>);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26434)

template <int N>
Mathematics::Integer<N>::Integer(const IntegerData& data) noexcept
    : integerData{ data }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#include SYSTEM_WARNING_POP

#ifdef OPEN_CLASS_INVARIANT
template <int N>
bool Mathematics::Integer<N>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <int N>
bool Mathematics::Integer<N>::IsZero() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return integerData.IsZero();
}

template <int N>
void Mathematics::Integer<N>::SetZero()
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return integerData.SetZero();
}

template <int N>
Mathematics::NumericalValueSymbol Mathematics::Integer<N>::GetSign() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return integerData.GetSign();
}

template <int N>
uint16_t& Mathematics::Integer<N>::operator[](int index)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return OPERATOR_SQUARE_BRACKETS(uint16_t, index);
}

template <int N>
const uint16_t& Mathematics::Integer<N>::operator[](int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return integerData[index];
}

template <int N>
Mathematics::Integer<N> Mathematics::Integer<N>::operator-() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const IntegerDataAnalysis<N> analysis{ integerData };
    Integer integer{ -analysis };

    return integer;
}

template <int N>
Mathematics::Integer<N> Mathematics::Integer<N>::GetAbsoluteValue() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const IntegerDataAnalysis<N> analysis{ integerData };
    Integer integer{ analysis.GetAbsoluteValue() };

    return integer;
}

template <int N>
Mathematics::Integer<N>& Mathematics::Integer<N>::operator+=(const Integer& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    IntegerDataOperator<N> integerDataOperator{ integerData };

    integerDataOperator += rhs.integerData;

    return *this;
}

template <int N>
Mathematics::Integer<N>& Mathematics::Integer<N>::operator-=(const Integer& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    *this += (-rhs);

    return *this;
}

template <int N>
Mathematics::Integer<N>& Mathematics::Integer<N>::operator*=(const Integer& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    IntegerMultiplication<N> multiplication{ integerData, rhs.integerData };

    integerData = multiplication.GetMultiplication();

    return *this;
}

template <int N>
Mathematics::Integer<N>& Mathematics::Integer<N>::operator/=(const Integer& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const IntegerDivisionModulo divisionModulo{ integerData, rhs.integerData };

    integerData = divisionModulo.GetQuotient();

    return *this;
}

template <int N>
Mathematics::Integer<N>& Mathematics::Integer<N>::operator%=(const Integer& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const IntegerDivisionModulo divisionModulo(integerData, rhs.integerData);

    integerData = divisionModulo.GetRemainder();

    return *this;
}

template <int N>
Mathematics::IntegerDivisionModulo<N> Mathematics::Integer<N>::GetDivisionModulo(const Integer& rhs) const
{
    MATHEMATICS_CLASS_IS_VALID_9;

    IntegerDivisionModulo divisionModulo{ integerData, rhs.integerData };

    return divisionModulo;
}

template <int N>
Mathematics::Integer<N>& Mathematics::Integer<N>::operator<<=(int shift)
{
    MATHEMATICS_CLASS_IS_VALID_9;
    MATHEMATICS_ASSERTION_1(0 <= shift, "shift必须大于或等于零");

    IntegerDataOperator<N> integerDataOperator{ integerData };

    integerDataOperator <<= shift;

    return *this;
}

template <int N>
Mathematics::Integer<N>& Mathematics::Integer<N>::operator>>=(int shift)
{
    MATHEMATICS_CLASS_IS_VALID_9;
    MATHEMATICS_ASSERTION_1(0 <= shift, "shift必须大于或等于零");

    IntegerDataOperator<N> integerDataOperator{ integerData };

    integerDataOperator >>= shift;

    return *this;
}

template <int N>
int Mathematics::Integer<N>::GetLeadingBit() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const IntegerDataAnalysis<N> analysis{ integerData };

    return analysis.GetLeadingBit();
}

template <int N>
int Mathematics::Integer<N>::GetTrailingBit() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const IntegerDataAnalysis<N> analysis{ integerData };

    return analysis.GetTrailingBit();
}

template <int N>
int Mathematics::Integer<N>::GetLeadingBit(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const IntegerDataAnalysis<N> analysis{ integerData };

    return analysis.GetLeadingBit(index);
}

template <int N>
int Mathematics::Integer<N>::GetTrailingBit(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const IntegerDataAnalysis<N> analysis{ integerData };

    return analysis.GetTrailingBit(index);
}

template <int N>
int Mathematics::Integer<N>::GetLeadingBlock() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const IntegerDataAnalysis<N> analysis{ integerData };

    return analysis.GetLeadingBlock();
}

template <int N>
int Mathematics::Integer<N>::GetTrailingBlock() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const IntegerDataAnalysis<N> analysis{ integerData };

    return analysis.GetTrailingBlock();
}

template <int N>
void Mathematics::Integer<N>::SetBit(int index, bool on)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    integerData.SetBit(index, on);
}

template <int N>
bool Mathematics::Integer<N>::GetBit(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return integerData.GetBit(index);
}

template <int N>
bool Mathematics::Integer<N>::operator==(const Integer& rhs) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return integerData == rhs.integerData;
}

template <int N>
bool Mathematics::Integer<N>::operator<(const Integer& rhs) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return integerData < rhs.integerData;
}

template <int N>
template <typename T>
T Mathematics::Integer<N>::GetValue() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const IntegerDataConversion<N, T> conversion{ integerData };

    return conversion.GetValue();
}

template <int N>
void Mathematics::Integer<N>::Print(std::ostream& os) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    os << integerData;
}

template <int N>
std::ostream& Mathematics::operator<<(std::ostream& os, const Integer<N>& integer)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    integer.Print(os);

    return os;
}

#endif  // MATHEMATICS_RATIONAL_INTEGER_DETAIL_H
