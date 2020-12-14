///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/18 14:19)

#ifndef MATHEMATICS_RATIONAL_CONVERSION_INTEGER_DETAIL_H
#define MATHEMATICS_RATIONAL_CONVERSION_INTEGER_DETAIL_H

#include "ConversionInteger.h"
#include "FloatingPointAnalysisDetail.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

#include <type_traits>

template <typename T>
Mathematics::ConversionInteger<T>::ConversionInteger(T value)
    : m_Shifting{ 0 },
      m_Mantissa{ 0 },
      m_Symbol{ NumericalValueSymbol::Zero },
      m_MaxMantissaBit{ 0 },
      m_ShiftingMantissa{ 0 }
{
    Init(value, TraitsType{});
    Amendment();
    ShiftingMantissa();

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

// private
template <typename T>
void Mathematics::ConversionInteger<T>::Init(T value, const SignedIntegerType&)
{
    static_assert(std::is_integral_v<T>, "T isn't integral.");

    if (0 <= value)
    {
        m_Mantissa = value;
        m_Symbol = NumericalValueSymbol::Positive;
    }
    else
    {
        m_Mantissa = -value;
        m_Symbol = NumericalValueSymbol::Negative;
    }

    const FloatingPointAnalysis<double> floatingPointAnalysis{ boost::numeric_cast<double>(m_Mantissa) };
    m_Shifting = floatingPointAnalysis.GetRealExponent();

    m_MaxMantissaBit = m_Shifting;
}

// private
template <typename T>
void Mathematics::ConversionInteger<T>::Init(T value, const UnsignedIntegerType&)
{
    static_assert(std::is_integral_v<T>, "T isn't integral.");

    m_Mantissa = value;
    m_Symbol = NumericalValueSymbol::Positive;

    const FloatingPointAnalysis<double> floatingPointAnalysis{ boost::numeric_cast<double>(m_Mantissa) };
    m_Shifting = floatingPointAnalysis.GetRealExponent();

    m_MaxMantissaBit = m_Shifting;
}

// private
template <typename T>
void Mathematics::ConversionInteger<T>::Init(T value, const FloatType&)
{
    static_assert(std::is_floating_point_v<T>, "T isn't floating_point.");

    const FloatingPointAnalysis<T> floatingPointAnalysis{ value };

    const auto floatingPointAnalysisType = floatingPointAnalysis.GetType();

    if (floatingPointAnalysisType == FloatingPointAnalysisType::Valid || floatingPointAnalysisType == FloatingPointAnalysisType::Zero)
    {
        m_Shifting = floatingPointAnalysis.GetRealExponent();
        m_Mantissa = floatingPointAnalysis.GetRealMantissa();
        m_Symbol = floatingPointAnalysis.GetSymbol();
        m_MaxMantissaBit = TraitsType::g_ExponentShifting;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("传入的浮点数无效！"s));
    }
}

// private
template <typename T>
void Mathematics::ConversionInteger<T>::Init(T value, const DoubleType&)
{
    static_assert(std::is_floating_point_v<T>, "T isn't floating_point.");

    const FloatingPointAnalysis<T> floatingPointAnalysis{ value };

    const auto floatingPointAnalysisType = floatingPointAnalysis.GetType();

    if (floatingPointAnalysisType == FloatingPointAnalysisType::Valid || floatingPointAnalysisType == FloatingPointAnalysisType::Zero)
    {
        m_Shifting = floatingPointAnalysis.GetRealExponent();
        m_Mantissa = floatingPointAnalysis.GetRealMantissa();
        m_Symbol = floatingPointAnalysis.GetSymbol();
        m_MaxMantissaBit = TraitsType::g_ExponentShifting;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("传入的浮点数无效！"s));
    }
}

// private
template <typename T>
void Mathematics::ConversionInteger<T>::Amendment() noexcept
{
    // 对于（-1，1）之间的数，截断为0
    if (m_Shifting < 0)
    {
        m_Mantissa = 0;
        m_Shifting = 0;
        m_MaxMantissaBit = 0;
        m_Symbol = NumericalValueSymbol::Positive;
    }

    // 截断小数点后的数值
    const auto difference = m_MaxMantissaBit - m_Shifting;

    if (0 < difference)
    {
        m_Mantissa >>= difference;
        m_MaxMantissaBit -= difference;
    }
}

template <typename T>
void Mathematics::ConversionInteger<T>::ShiftingMantissa() noexcept
{
    // 对齐个位的数值
    const auto difference = m_Shifting - m_MaxMantissaBit;
    const auto newShifting = difference % sm_BlockSize;

    m_ShiftingMantissa = m_Mantissa << newShifting;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename T>
bool Mathematics::ConversionInteger<T>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename T>
int Mathematics::ConversionInteger<T>::GetShifting() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Shifting;
}

template <typename T>
uint64_t Mathematics::ConversionInteger<T>::GetMantissa() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Mantissa;
}

template <typename T>
int Mathematics::ConversionInteger<T>::GetMaxMantissaBit() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_MaxMantissaBit;
}

template <typename T>
int Mathematics::ConversionInteger<T>::GetMantissaSize() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return (m_Shifting + 1) / sm_BlockSize + 1;
}

template <typename T>
int Mathematics::ConversionInteger<T>::GetCopySize() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    auto shiftingMantissa = m_ShiftingMantissa;
    auto copySize = 0;

    do
    {
        shiftingMantissa >>= (sm_BlockSize / 2);
        ++copySize;

    } while (shiftingMantissa != 0);

    return copySize;
}

template <typename T>
Mathematics::NumericalValueSymbol Mathematics::ConversionInteger<T>::GetSymbol() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Symbol;
}

template <typename T>
uint64_t Mathematics::ConversionInteger<T>::GetShiftingMantissa() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_ShiftingMantissa;
}

template <typename T>
int Mathematics::ConversionInteger<T>::GetBeginBlock() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto difference = m_Shifting - m_MaxMantissaBit;

    return difference / sm_BlockSize;
}

#endif  // MATHEMATICS_RATIONAL_CONVERSION_INTEGER_DETAIL_H
