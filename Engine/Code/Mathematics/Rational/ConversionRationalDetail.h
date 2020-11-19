///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/18 16:47)

#ifndef MATHEMATICS_RATIONAL_CONVERSION_RATIONAL_DETAIL_H
#define MATHEMATICS_RATIONAL_CONVERSION_RATIONAL_DETAIL_H

#include "ConversionRational.h"
#include "FloatingPointAnalysisDetail.h"
#include "IntegerDetail.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

#include <type_traits>

template <typename T>
Mathematics::ConversionRational<T>::ConversionRational(T value)
    : m_NumeratorShifting{ 0 },
      m_DenominatorShifting{ 0 },
      m_NumeratorMantissa{ 0 },
      m_DenominatorMantissa{ 0 },
      m_Symbol{ NumericalValueSymbol::Zero },
      m_MaxShifting{ 0 },
      m_ReducibilityShifting{ 0 }
{
    Init(value, TraitsType{});

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

// private
template <typename T>
void Mathematics::ConversionRational<T>::Init(T value, const SignedIntegerType&)
{
    static_assert(std::is_integral_v<T>, "T isn't integral.");

    if (0 <= value)
    {
        m_NumeratorMantissa = value;
        m_DenominatorMantissa = 1;
        m_Symbol = NumericalValueSymbol::Positive;
        m_NumeratorShifting = 0;
        m_DenominatorShifting = 0;
    }
    else
    {
        m_NumeratorMantissa = -value;
        m_DenominatorMantissa = 1;
        m_Symbol = NumericalValueSymbol::Negative;
        m_NumeratorShifting = 0;
        m_DenominatorShifting = 0;
    }

    const FloatingPointAnalysis<double> floatingPointAnalysis{ boost::numeric_cast<double>(m_NumeratorMantissa) };
    m_MaxShifting = floatingPointAnalysis.GetRealExponent();
    if (m_MaxShifting < 0)
    {
        m_MaxShifting = 0;
    }
    m_ReducibilityShifting = 0;
}

// private
template <typename T>
void Mathematics::ConversionRational<T>::Init(T value, const UnsignedIntegerType&)
{
    static_assert(std::is_integral_v<T>, "T isn't integral.");

    m_NumeratorMantissa = value;
    m_DenominatorMantissa = 1;
    m_Symbol = NumericalValueSymbol::Positive;
    m_NumeratorShifting = 0;
    m_DenominatorShifting = 0;

    FloatingPointAnalysis<double> floatingPointAnalysis{ boost::numeric_cast<double>(m_NumeratorMantissa) };
    m_MaxShifting = floatingPointAnalysis.GetRealExponent();
    if (m_MaxShifting < 0)
    {
        m_MaxShifting = 0;
    }
    m_ReducibilityShifting = 0;
}

// private
template <typename T>
void Mathematics::ConversionRational<T>::Init(T value, const FloatType&)
{
    static_assert(std::is_floating_point_v<T>, "T isn't floating_point.");

    InitFloatingPoint(value);
}

// private
template <typename T>
void Mathematics::ConversionRational<T>::Init(T value, const DoubleType&)
{
    static_assert(std::is_floating_point_v<T>, "T isn't floating_point.");

    InitFloatingPoint(value);
}

template <typename T>
void Mathematics::ConversionRational<T>::InitFloatingPoint(T value)
{
    static_assert(std::is_floating_point_v<T>, "T isn't floating_point.");

    FloatingPointAnalysis<T> floatingPointAnalysis{ value };

    if (floatingPointAnalysis.GetType() == FloatingPointAnalysisType::Valid || floatingPointAnalysis.GetType() == FloatingPointAnalysisType::Zero)
    {
        m_NumeratorMantissa = floatingPointAnalysis.GetRealMantissa();
        m_DenominatorMantissa = uint64_t(1) << TraitsType::g_ExponentShifting;
        m_Symbol = floatingPointAnalysis.GetSymbol();

        auto shifting = floatingPointAnalysis.GetRealExponent();

        if (0 < shifting)
        {
            m_ReducibilityShifting = TraitsType::g_ExponentShifting - shifting;

            if (0 < m_ReducibilityShifting)
            {
                m_DenominatorMantissa >>= shifting;
                shifting = 0;
            }
            else
            {
                m_ReducibilityShifting = 0;
            }

            m_NumeratorShifting = shifting;
            m_MaxShifting = TraitsType::g_ExponentShifting + m_NumeratorShifting;
        }
        else if (shifting < 0)
        {
            m_DenominatorShifting = -shifting;
            m_MaxShifting = TraitsType::g_ExponentShifting - shifting;
            m_ReducibilityShifting = -static_cast<int>(TraitsType::g_ExponentShifting);
        }

        if (floatingPointAnalysis.GetExponent() == 0)
        {
            --m_DenominatorShifting;
            --m_MaxShifting;
        }
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("传入的浮点数无效！"s));
    }
}

#ifdef OPEN_CLASS_INVARIANT
template <typename T>
bool Mathematics::ConversionRational<T>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename T>
uint64_t Mathematics::ConversionRational<T>::GetNumeratorMantissa() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_NumeratorMantissa;
}

template <typename T>
uint64_t Mathematics::ConversionRational<T>::GetDenominatorMantissa() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_DenominatorMantissa;
}

template <typename T>
Mathematics::NumericalValueSymbol Mathematics::ConversionRational<T>::GetSymbol() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Symbol;
}

template <typename T>
int Mathematics::ConversionRational<T>::GetNumeratorShifting() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_NumeratorShifting;
}

template <typename T>
int Mathematics::ConversionRational<T>::GetDenominatorShifting() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_DenominatorShifting;
}

template <typename T>
int Mathematics::ConversionRational<T>::GetMaxShifting() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_MaxShifting;
}

template <typename T>
int Mathematics::ConversionRational<T>::GetReducibilityShifting() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_ReducibilityShifting;
}

template <typename T>
template <int N>
bool Mathematics::ConversionRational<T>::IsCanConversion() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto bit = m_MaxShifting - N * 32 - 1;

    if (0 < bit && 0 <= m_ReducibilityShifting && m_ReducibilityShifting < bit)
    {
        return false;
    }
    else
    {
        return true;
    }
}

template <typename T>
template <int N>
const Mathematics::Integer<N> Mathematics::ConversionRational<T>::GetNumerator() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto bit = m_MaxShifting - N * 32 - 1;
    auto numeratorShifting = m_NumeratorShifting;
    auto numeratorMantissa = m_NumeratorMantissa;

    if (0 < bit)
    {
        numeratorShifting = GetAssignmentNumeratorShifting(bit);
        numeratorMantissa = GetAssignmentNumeratorMantissa(bit);
    }

    auto numerator = Integer<N>{ numeratorMantissa };
    numerator <<= numeratorShifting;

    if (m_Symbol == NumericalValueSymbol::Negative)
    {
        numerator = -numerator;
    }

    return numerator;
}

template <typename T>
template <int N>
const Mathematics::Integer<N> Mathematics::ConversionRational<T>::GetDenominator() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto bit = m_MaxShifting - N * 32 - 1;
    auto denominatorShifting = m_DenominatorShifting;
    auto denominatorMantissa = m_DenominatorMantissa;

    if (0 < bit)
    {
        denominatorShifting = GetAssignmentDenominatorShifting(bit);
        denominatorMantissa = GetAssignmentDenominatorMantissa(bit);
    }

    auto denominator = Integer<N>{ denominatorMantissa };
    denominator <<= denominatorShifting;

    return denominator;
}

// private
template <typename T>
int Mathematics::ConversionRational<T>::GetAssignmentNumeratorShifting(int bit) const
{
    MATHEMATICS_ASSERTION_0(0 < bit, "需要移位的字节数应该为正数");

    if (bit <= m_ReducibilityShifting)
    {
        const auto shifting = m_NumeratorShifting - m_ReducibilityShifting;

        if (0 <= shifting)
        {
            return m_NumeratorShifting >> m_ReducibilityShifting;
        }
        else
        {
            return m_NumeratorShifting >> (-shifting);
        }
    }
    else if (m_ReducibilityShifting < 0)
    {
        if (-m_ReducibilityShifting <= bit)
        {
            return 0;
        }
        else
        {
            return m_NumeratorShifting;
        }
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("传入的值溢出！"s));
    }
}

// private
template <typename T>
int Mathematics::ConversionRational<T>::GetAssignmentDenominatorShifting(int bit) const
{
    MATHEMATICS_ASSERTION_0(0 < bit, "需要移位的字节数应该为正数");

    if (bit <= m_ReducibilityShifting)
    {
        return m_DenominatorShifting;
    }
    else if (m_ReducibilityShifting < 0)
    {
        if (-m_ReducibilityShifting <= bit)
        {
            return 0;
        }
        else
        {
            const auto shifting = m_DenominatorShifting + m_ReducibilityShifting;

            if (0 <= shifting)
            {
                return m_DenominatorShifting >> m_ReducibilityShifting;
            }
            else
            {
                return m_DenominatorShifting >> (-shifting);
            }
        }
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("传入的值溢出！"s));
    }
}

// private
template <typename T>
uint64_t Mathematics::ConversionRational<T>::GetAssignmentNumeratorMantissa(int bit) const
{
    MATHEMATICS_ASSERTION_0(0 < bit, "需要移位的字节数应该为正数");

    if (bit <= m_ReducibilityShifting)
    {
        const auto shifting = m_NumeratorShifting - m_ReducibilityShifting;

        if (0 <= shifting)
        {
            return m_NumeratorMantissa;
        }
        else
        {
            return m_NumeratorMantissa >> (m_ReducibilityShifting + shifting);
        }
    }
    else if (m_ReducibilityShifting < 0)
    {
        if (-m_ReducibilityShifting <= bit)
        {
            return 0;
        }
        else
        {
            return m_NumeratorMantissa >> (-m_ReducibilityShifting);
        }
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("传入的值溢出！"s));
    }
}

// private
template <typename T>
uint64_t Mathematics::ConversionRational<T>::GetAssignmentDenominatorMantissa(int bit) const
{
    MATHEMATICS_ASSERTION_0(0 < bit, "需要移位的字节数应该为正数");

    if (bit <= m_ReducibilityShifting)
    {
        return m_DenominatorMantissa >> m_ReducibilityShifting;
    }
    else if (m_ReducibilityShifting < 0)
    {
        if (-m_ReducibilityShifting <= bit)
        {
            return 1;
        }
        else
        {
            const auto shifting = m_DenominatorShifting + m_ReducibilityShifting;

            if (0 <= shifting)
            {
                return m_DenominatorMantissa;
            }
            else
            {
                return m_DenominatorMantissa >> (-m_ReducibilityShifting + shifting);
            }
        }
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("传入的值溢出！"s));
    }
}

#endif  // MATHEMATICS_RATIONAL_CONVERSION_RATIONAL_DETAIL_H
