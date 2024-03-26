/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/07 09:47)

#ifndef MATHEMATICS_RATIONAL_BINARY_SCIENTIFIC_NUMBER_DETAIL_H
#define MATHEMATICS_RATIONAL_BINARY_SCIENTIFIC_NUMBER_DETAIL_H

#include "BinaryScientificNumber.h"
#include "IeeeBinary.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Base/BitHacks.h"

#include <cfenv>

template <typename UInteger>
Mathematics::BinaryScientificNumber<UInteger>::BinaryScientificNumber(CoreTools::DisableNotThrow disableNotThrow) noexcept(noexcept(UInteger::CreateZero()))
    : sign{}, biasedExponent{}, uInteger{ UInteger::CreateZero() }
{
    System::UnusedFunction(disableNotThrow);

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename UInteger>
Mathematics::BinaryScientificNumber<UInteger> Mathematics::BinaryScientificNumber<UInteger>::CreateZero() noexcept(noexcept(UInteger::CreateZero()))
{
    return BinaryScientificNumber{ CoreTools::DisableNotThrow::Disable };
}

template <typename UInteger>
Mathematics::BinaryScientificNumber<UInteger>::BinaryScientificNumber(float number)
    : sign{}, biasedExponent{}, uInteger{ UInteger::CreateZero() }
{
    ConvertFrom<IeeeBinary32>(number);

#if defined(MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE)

    value = static_cast<double>(number);

#endif  // MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename UInteger>
Mathematics::BinaryScientificNumber<UInteger>::BinaryScientificNumber(double number) requires(!std::is_same_v<UIntegerFixedPrecision32<1>, UInteger>)
    : sign{}, biasedExponent{}, uInteger{ UInteger::CreateZero() }
{
    ConvertFrom<IeeeBinary64>(number);

#if defined(MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE)

    value = number;

#endif  // MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename UInteger>
Mathematics::BinaryScientificNumber<UInteger>::BinaryScientificNumber(int32_t number)
    : sign{}, biasedExponent{}, uInteger{ UInteger::CreateZero() }
{
#if defined(MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE)

    value = static_cast<double>(number);

#endif  // MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE

    if (number == 0)
    {
        sign = 0;
        biasedExponent = 0;
    }
    else
    {
        if (number < 0)
        {
            sign = -1;
            number = -number;
        }
        else
        {
            sign = 1;
        }

        biasedExponent = BitHacks::GetTrailingBit(number);
        uInteger = UInteger{ boost::numeric_cast<uint32_t>(number) };
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename UInteger>
Mathematics::BinaryScientificNumber<UInteger>::BinaryScientificNumber(uint32_t number)
    : sign{}, biasedExponent{}, uInteger{ UInteger::CreateZero() }
{
    if (number == 0)
    {
        sign = 0;
        biasedExponent = 0;
    }
    else
    {
        sign = 1;
        biasedExponent = BitHacks::GetTrailingBit(number);
        uInteger = UInteger{ number };
    }

#if defined(MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE)

    value = static_cast<double>(number);

#endif  // MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename UInteger>
Mathematics::BinaryScientificNumber<UInteger>::BinaryScientificNumber(int64_t number) requires(!std::is_same_v<UIntegerFixedPrecision32<1>, UInteger>)
    : sign{}, biasedExponent{}, uInteger{ UInteger::CreateZero() }
{
#if defined(MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE)

    value = static_cast<double>(number);

#endif  // MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE

    if (number == 0)
    {
        sign = 0;
        biasedExponent = 0;
    }
    else
    {
        if (number < 0)
        {
            sign = -1;
            number = -number;
        }
        else
        {
            sign = 1;
        }

        biasedExponent = BitHacks::GetTrailingBit(number);
        uInteger = UInteger{ boost::numeric_cast<uint64_t>(number) };
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename UInteger>
Mathematics::BinaryScientificNumber<UInteger>::BinaryScientificNumber(uint64_t number) requires(!std::is_same_v<UIntegerFixedPrecision32<1>, UInteger>)
    : sign{}, biasedExponent{}, uInteger{ UInteger::CreateZero() }
{
    if (number == 0)
    {
        sign = 0;
        biasedExponent = 0;
    }
    else
    {
        sign = 1;
        biasedExponent = BitHacks::GetTrailingBit(number);
        uInteger = UInteger{ number };
    }

#if defined(MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE)

    value = static_cast<double>(number);

#endif  // MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename UInteger>
Mathematics::BinaryScientificNumber<UInteger>::BinaryScientificNumber(const std::string& number)
    : sign{}, biasedExponent{}, uInteger{ UInteger::CreateZero() }
{
    MATHEMATICS_ASSERTION_0(!number.empty(), "必须指定一个数字。");

    /// 获取前导'+'或'-'（如果存在）。
    std::string intNumber{};

    if (number.at(0) == '+')
    {
        intNumber = number.substr(1);
        sign = +1;
        MATHEMATICS_ASSERTION_0(!number.empty(), "无效的数字格式。");
    }
    else if (number.at(0) == '-')
    {
        intNumber = number.substr(1);
        sign = -1;
        MATHEMATICS_ASSERTION_0(!number.empty(), "无效的数字格式。");
    }
    else
    {
        intNumber = number;
        sign = +1;
    }

    *this = BinaryScientificNumber{ ConvertToInteger(intNumber) };

#if defined(MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE)

    SetValue();

#endif  // MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename UInteger>
bool Mathematics::BinaryScientificNumber<UInteger>::IsValid() const noexcept
{
    try
    {
        if (sign != 0)
        {
            return 0 < uInteger.GetNumBits() &&
                   0 < uInteger.GetSize() &&
                   (uInteger.GetBits().at(0) & 0x00000001u) == 1u;
        }
        else
        {
            return biasedExponent == 0 &&
                   uInteger.GetNumBits() == 0 &&
                   uInteger.GetSize() == 0;
        }
    }
    catch (...)
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

#if defined(MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE)

template <typename UInteger>
double Mathematics::BinaryScientificNumber<UInteger>::GetValue() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return value;
}

template <typename UInteger>
void Mathematics::BinaryScientificNumber<UInteger>::SetValue(double aValue) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    value = aValue;
}

template <typename UInteger>
void Mathematics::BinaryScientificNumber<UInteger>::SetValue()
{
    MATHEMATICS_CLASS_IS_VALID_1;

    value = static_cast<double>(*this);
}

#endif  // MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE

template <typename UInteger>
Mathematics::BinaryScientificNumber<UInteger>::operator float() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return ConvertTo<IeeeBinary32>();
}

template <typename UInteger>
Mathematics::BinaryScientificNumber<UInteger>::operator double() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return ConvertTo<IeeeBinary64>();
}

template <typename UInteger>
void Mathematics::BinaryScientificNumber<UInteger>::SetSign(int aSign) noexcept(!isBinaryScientificShowDouble)
{
    sign = aSign;

#if defined(MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE)

    SetValue();

#endif  // MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE
}

template <typename UInteger>
int Mathematics::BinaryScientificNumber<UInteger>::GetSign() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return sign;
}

template <typename UInteger>
void Mathematics::BinaryScientificNumber<UInteger>::Negate() noexcept(!isBinaryScientificShowDouble)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    sign = -sign;

#if defined(MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE)

    SetValue();

#endif  // MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE
}

template <typename UInteger>
void Mathematics::BinaryScientificNumber<UInteger>::SetBiasedExponent(int aBiasedExponent) noexcept(!isBinaryScientificShowDouble)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    biasedExponent = aBiasedExponent;

#if defined(MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE)

    SetValue();

#endif  // MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE
}

template <typename UInteger>
int Mathematics::BinaryScientificNumber<UInteger>::GetBiasedExponent() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return biasedExponent;
}

template <typename UInteger>
int Mathematics::BinaryScientificNumber<UInteger>::GetExponent() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return biasedExponent + uInteger.GetNumBits() - 1;
}

template <typename UInteger>
void Mathematics::BinaryScientificNumber<UInteger>::SetExponent(int exponent) noexcept(!isBinaryScientificShowDouble)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    biasedExponent = exponent - uInteger.GetNumBits() + 1;

#if defined(MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE)

    SetValue();

#endif  // MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE
}

template <typename UInteger>
const UInteger& Mathematics::BinaryScientificNumber<UInteger>::GetUInteger() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return uInteger;
}

template <typename UInteger>
UInteger& Mathematics::BinaryScientificNumber<UInteger>::GetUInteger() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    return uInteger;
}

template <typename UInteger>
Mathematics::BinaryScientificNumber<UInteger> Mathematics::BinaryScientificNumber<UInteger>::operator+() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return *this;
}

template <typename UInteger>
Mathematics::BinaryScientificNumber<UInteger> Mathematics::BinaryScientificNumber<UInteger>::operator-() const noexcept(!isBinaryScientificShowDouble)
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    auto result = *this;
    result.sign = -result.sign;

#if defined(MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE)

    result.SetValue();

#endif  // MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE

    return result;
}

template <typename UInteger>
Mathematics::BinaryScientificNumber<UInteger>& Mathematics::BinaryScientificNumber<UInteger>::operator+=(const BinaryScientificNumber& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    if (sign == 0)
    {
        *this = rhs;
        return *this;
    }

    if (rhs.sign == 0)
    {
        return *this;
    }

    if (0 < sign)
    {
        if (0 < rhs.sign)
        {
            /// n0 + n1 = |n0| + |n1|
            *this = AddIgnoreSign(*this, rhs, +1);

            return *this;
        }
        else  // n1.sign < 0
        {
            if (!EqualIgnoreSign(*this, rhs))
            {
                if (LessThanIgnoreSign(*this, rhs))
                {
                    /// n0 + n1 = |n0| - |n1| > 0
                    *this = SubIgnoreSign(*this, rhs, +1);
                }
                else
                {
                    /// n0 + n1 = -(|n1| - |n0|) < 0
                    *this = SubIgnoreSign(rhs, *this, -1);
                }

                return *this;
            }
            // else n0 + n1 = 0
        }
    }
    else  // n0.sign < 0
    {
        if (rhs.sign < 0)
        {
            /// n0 + n1 = -(|n0| + |n1|)
            *this = AddIgnoreSign(*this, rhs, -1);

            return *this;
        }
        else  // n1.sign > 0
        {
            if (!EqualIgnoreSign(*this, rhs))
            {
                if (LessThanIgnoreSign(rhs, *this))
                {
                    /// n0 + n1 = -(|n0| - |n1|) < 0
                    *this = SubIgnoreSign(*this, rhs, -1);
                }
                else
                {
                    /// n0 + n1 = |n1| - |n0| > 0
                    *this = SubIgnoreSign(rhs, *this, +1);
                }

                return *this;
            }
            // else n0 + n1 = 0
        }
    }

    *this = CreateZero();  // = 0

    return *this;
}

template <typename UInteger>
Mathematics::BinaryScientificNumber<UInteger>& Mathematics::BinaryScientificNumber<UInteger>::operator-=(const BinaryScientificNumber& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    if (sign == 0)
    {
        *this = -rhs;
        return *this;
    }

    if (rhs.sign == 0)
    {
        return *this;
    }

    if (sign > 0)
    {
        if (rhs.sign < 0)
        {
            /// n0 - n1 = |n0| + |n1|
            *this = AddIgnoreSign(*this, rhs, +1);

            return *this;
        }
        else  /// n1.sign > 0
        {
            if (!EqualIgnoreSign(*this, rhs))
            {
                if (LessThanIgnoreSign(rhs, *this))
                {
                    /// n0 - n1 = |n0| - |n1| > 0
                    *this = SubIgnoreSign(*this, rhs, +1);
                }
                else
                {
                    /// n0 - n1 = -(|n1| - |n0|) < 0
                    *this = SubIgnoreSign(rhs, *this, -1);
                }

                return *this;
            }
            // else n0 - n1 = 0
        }
    }
    else  // n0.sign < 0
    {
        if (rhs.sign > 0)
        {
            /// n0 - n1 = -(|n0| + |n1|)
            *this = AddIgnoreSign(*this, rhs, -1);
            return *this;
        }
        else  /// n1.sign < 0
        {
            if (!EqualIgnoreSign(*this, rhs))
            {
                if (LessThanIgnoreSign(rhs, *this))
                {
                    /// n0 - n1 = -(|n0| - |n1|) < 0
                    *this = SubIgnoreSign(*this, rhs, -1);
                }
                else
                {
                    /// n0 - n1 = |n1| - |n0| > 0
                    *this = SubIgnoreSign(rhs, *this, +1);
                }

                return *this;
            }
            // else n0 - n1 = 0
        }
    }

    *this = CreateZero();  // = 0

    return *this;
}

template <typename UInteger>
Mathematics::BinaryScientificNumber<UInteger>& Mathematics::BinaryScientificNumber<UInteger>::operator*=(const BinaryScientificNumber& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    auto result = BinaryScientificNumber::CreateZero();  // = 0
    const auto resultSign = sign * rhs.sign;
    if (resultSign != 0)
    {
        result.sign = resultSign;
        result.biasedExponent = biasedExponent + rhs.biasedExponent;
        result.uInteger.Mul(uInteger, rhs.uInteger);
    }

#if defined(MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE)

    result.SetValue();

#endif  // MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE

    *this = result;

    return *this;
}

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

template <typename UInteger>
bool Mathematics::BinaryScientificNumber<UInteger>::Write(std::ostream& output) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (output.write(reinterpret_cast<const char*>(&sign), sizeof(sign)).bad())
    {
        return false;
    }

    if (output.write(reinterpret_cast<const char*>(&biasedExponent), sizeof(biasedExponent)).bad())
    {
        return false;
    }

    return uInteger.Write(output);
}

template <typename UInteger>
bool Mathematics::BinaryScientificNumber<UInteger>::Read(std::istream& input)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    if (input.read(reinterpret_cast<char*>(&sign), sizeof(sign)).bad())
    {
        return false;
    }

    if (input.read(reinterpret_cast<char*>(&biasedExponent), sizeof(biasedExponent)).bad())
    {
        return false;
    }

    return uInteger.Read(input);
}

#include SYSTEM_WARNING_POP

template <typename UInteger>
Mathematics::BinaryScientificNumber<UInteger> Mathematics::BinaryScientificNumber<UInteger>::ConvertToInteger(const std::string& number)
{
    auto digit = static_cast<int32_t>(number.back()) - static_cast<int32_t>('0');
    BinaryScientificNumber x{ digit };
    if (1 < number.size())
    {
        MATHEMATICS_ASSERTION_0(number.find_first_of("123456789") == 0, "无效的数字格式。");
        MATHEMATICS_ASSERTION_0(number.find_first_not_of("0123456789") == std::string::npos, "无效的数字格式。");

        BinaryScientificNumber ten{ 10 };
        BinaryScientificNumber pow10{ 10 };
        for (size_t i{ 1u }, j = number.size() - 2; i < number.size(); ++i, --j)
        {
            digit = static_cast<int32_t>(number.at(j)) - static_cast<int32_t>('0');
            if (0 < digit)
            {
                x += BinaryScientificNumber{ digit } * pow10;
            }
            pow10 *= ten;
        }
    }

#if defined(MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE)

    x.SetValue();

#endif  // MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE

    return x;
}

template <typename UInteger>
bool Mathematics::EqualIgnoreSign(const BinaryScientificNumber<UInteger>& lhs, const BinaryScientificNumber<UInteger>& rhs)
{
    return lhs.GetBiasedExponent() == rhs.GetBiasedExponent() && lhs.GetUInteger() == rhs.GetUInteger();
}

template <typename UInteger>
bool Mathematics::LessThanIgnoreSign(const BinaryScientificNumber<UInteger>& lhs, const BinaryScientificNumber<UInteger>& rhs)
{
    const auto e0 = lhs.GetExponent();
    const auto e1 = rhs.GetExponent();
    if (e0 < e1)
    {
        return true;
    }

    if (e1 < e0)
    {
        return false;
    }

    return lhs.GetUInteger() < rhs.GetUInteger();
}

template <typename UInteger>
Mathematics::BinaryScientificNumber<UInteger> Mathematics::BinaryScientificNumber<UInteger>::AddIgnoreSign(const BinaryScientificNumber& lhs, const BinaryScientificNumber& rhs, int resultSign)
{
    auto result = BinaryScientificNumber::CreateZero();
    auto temp = BinaryScientificNumber::CreateZero();

    const auto diff = lhs.biasedExponent - rhs.biasedExponent;
    if (0 < diff)
    {
        temp.uInteger.ShiftLeft(lhs.uInteger, diff);
        result.uInteger.Add(temp.uInteger, rhs.uInteger);
        result.biasedExponent = rhs.biasedExponent;
    }
    else if (diff < 0)
    {
        temp.uInteger.ShiftLeft(rhs.uInteger, -diff);
        result.uInteger.Add(lhs.uInteger, temp.uInteger);
        result.biasedExponent = lhs.biasedExponent;
    }
    else
    {
        temp.uInteger.Add(lhs.uInteger, rhs.uInteger);
        const auto shift = result.uInteger.ShiftRightToOdd(temp.uInteger);
        result.biasedExponent = lhs.biasedExponent + shift;
    }

    result.sign = resultSign;

#if defined(MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE)

    result.SetValue();

#endif  // MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE

    return result;
}

template <typename UInteger>
Mathematics::BinaryScientificNumber<UInteger> Mathematics::BinaryScientificNumber<UInteger>::SubIgnoreSign(const BinaryScientificNumber& lhs, const BinaryScientificNumber& rhs, int resultSign)
{
    auto result = BinaryScientificNumber::CreateZero();
    auto temp = BinaryScientificNumber::CreateZero();

    const auto diff = lhs.biasedExponent - rhs.biasedExponent;
    if (0 < diff)
    {
        temp.uInteger.ShiftLeft(lhs.uInteger, diff);
        result.uInteger.Sub(temp.uInteger, rhs.uInteger);
        result.biasedExponent = rhs.biasedExponent;
    }
    else if (diff < 0)
    {
        temp.uInteger.ShiftLeft(rhs.uInteger, -diff);
        result.uInteger.Sub(lhs.uInteger, temp.uInteger);
        result.biasedExponent = lhs.biasedExponent;
    }
    else
    {
        temp.uInteger.Sub(lhs.uInteger, rhs.uInteger);
        const auto shift = result.uInteger.ShiftRightToOdd(temp.uInteger);
        result.biasedExponent = lhs.biasedExponent + shift;
    }

    result.sign = resultSign;

#if defined(MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE)

    result.SetValue();

#endif  // MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE

    return result;
}

template <typename UInteger>
template <typename Ieee>
void Mathematics::BinaryScientificNumber<UInteger>::ConvertFrom(typename Ieee::FloatType number)
{
    Ieee x{ number };

    /// 提取符号s、有偏指数e和尾部有效位t。
    const auto s = x.GetSign();
    const auto e = x.GetBiased();
    const auto t = x.GetTrailing();

    if (e == 0)
    {
        if (t == 0)  // 零
        {
            /// x = (-1)^s * 0
            sign = 0;
            biasedExponent = 0;
        }
        else  // 次正规数
        {
            /// x = (-1)^s * 0.t * 2^{1-EXPONENT_BIAS}
            const auto last = BitHacks::GetTrailingBit(t);
            const auto diff = Ieee::numTrailingBits - last;
            sign = (s > 0 ? -1 : 1);
            biasedExponent = Ieee::minSubExponent - diff;
            uInteger = UInteger{ t >> last };
        }
    }
    else if (e < Ieee::maxBiasedExponent)  // 正规数
    {
        /// x = (-1)^s * 1.t * 2^{e-EXPONENT_BIAS}
        if (0 < t)
        {
            const auto last = BitHacks::GetTrailingBit(t);
            const auto diff = Ieee::numTrailingBits - last;
            sign = (s > 0 ? -1 : 1);
            biasedExponent = boost::numeric_cast<int>(e) - Ieee::exponentBias - diff;
            uInteger = UInteger{ (t | Ieee::supTrailing) >> last };
        }
        else
        {
            sign = (s > 0 ? -1 : 1);
            biasedExponent = boost::numeric_cast<int>(e) - Ieee::exponentBias;
            uInteger = UInteger{ 1u };
        }
    }
    else  // e == MAX_BIASED_EXPONENT, 特殊数字
    {
        if (t == 0)  // 无穷大
        {
            /// x = (-1)^s * infinity

#if defined(MATHEMATICS_THROW_ON_CONVERT_FROM_INFINITY_OR_NAN)

            THROW_EXCEPTION(SYSTEM_TEXT("BinaryScientificNumber没有表示无穷大。"))

#else  // !MATHEMATICS_THROW_ON_CONVERT_FROM_INFINITY_OR_NAN

            /// 返回(-1)^s * 2^{1+EXPONENT_BIAS}以获得优美的退出。
            sign = (s > 0 ? -1 : 1);
            biasedExponent = 1 + Ieee::exponentBias;
            uInteger = UInteger{ 1u };

#endif  // MATHEMATICS_THROW_ON_CONVERT_FROM_INFINITY_OR_NAN
        }
        else  // 非数字 (NaN)
        {
#if defined(MATHEMATICS_THROW_ON_CONVERT_FROM_INFINITY_OR_NAN)

            THROW_EXCEPTION(SYSTEM_TEXT("BinaryScientificNumber没有NaN的表示形式"))

#else  // !MATHEMATICS_THROW_ON_CONVERT_FROM_INFINITY_OR_NAN

            /// 返回0以获得优美的退出。
            sign = 0;
            biasedExponent = 0;

#endif  // MATHEMATICS_THROW_ON_CONVERT_FROM_INFINITY_OR_NAN
        }
    }
}

template <typename UInteger>
template <typename Ieee>
typename Ieee::FloatType Mathematics::BinaryScientificNumber<UInteger>::ConvertTo() const
{
    const auto s = (sign < 0 ? 1u : 0u);
    typename Ieee::UIntType e{};
    typename Ieee::UIntType t{};

    if (sign != 0)
    {
        /// 转换使用四舍五入到最近的偶数关系语义。
        const auto exponent = GetExponent();
        if (exponent < Ieee::minExponent)
        {
            if (exponent < Ieee::minExponent - 1 || uInteger.GetNumBits() == 1)
            {
                /// x = 1.0*2^{minExponent-1},四舍五入到零。
                e = 0;
                t = 0;
            }
            else
            {
                /// 四舍五入到最小低于正常值。
                e = 0;
                t = 1;
            }
        }
        else if (exponent < Ieee::minSubExponent)
        {
            /// 第二个输入在{0, ..., NUM_TRAILING_BITS-1}中。
            t = GetTrailing<Ieee>(0, Ieee::minSubExponent - exponent - 1);
            if (t & Ieee::supTrailing)
            {
                /// 前导NUM_SIGNIFICAND_BITS位均为1，因此四舍五入到最小正常值。
                e = 1;
                t = 0;
            }
            else
            {
                e = 0;
            }
        }
        else if (exponent <= Ieee::exponentBias)
        {
            e = boost::numeric_cast<uint32_t>(boost::numeric_cast<typename Ieee::UIntType>(exponent) + Ieee::exponentBias);
            t = GetTrailing<Ieee>(1, 0);
            if (t & (Ieee::supTrailing << 1))
            {
                /// 执行发生了，所以将指数增加1并向右移动进行补偿。
                ++e;
                t >>= 1;
            }

            /// 消除前导1（对于法线隐含）。
            t &= ~Ieee::supTrailing;
        }
        else
        {
            /// 设置为无穷大。
            e = Ieee::maxBiasedExponent;
            t = 0;
        }
    }
    else
    {
        /// 输入为零。
        e = 0;
        t = 0;
    }

    Ieee x{ s, e, t };

    return x.GetNumber();
}

template <typename UInteger>
template <typename Ieee>
typename Ieee::UIntType Mathematics::BinaryScientificNumber<UInteger>::GetTrailing(int normal, int sigma) const
{
    const auto numRequested = Ieee::numSignificandBits + normal;

    /// 我们需要numRequested位来确定舍入方向。
    /// 这些存储在“前缀”的高阶位中。
    const auto prefix = uInteger.GetPrefix(numRequested);

    /// 用于舍入的隐含二进制点之后的第一个位索引。
    const auto diff = numRequested - sigma;
    const auto roundBitIndex = 64 - diff;

    /// 根据四舍五入到偶数的关系确定值。
    const auto mask = (1ull << roundBitIndex);
    auto round = 0ull;
    if (prefix & mask)
    {
        /// 余数的第一位是1。
        if (uInteger.GetNumBits() == diff)
        {
            /// 余数的第一个比特是bits[0]的最低阶比特。
            /// 将平局应用于偶数规则。
            if (prefix & (mask << 1))
            {
                /// 尾部有效位的最后一位是奇数，所以向上取整。
                round = 1;
            }
            else
            {
                /// 尾部有效位的最后一位是偶数，所以向下取整。
                round = 0;
            }
        }
        else
        {
            /// 余数的第一个比特不是bits[0]的最低阶比特。
            /// 余数作为一个分数大于1/2，所以四舍五入。
            round = 1;
        }
    }
    else
    {
        /// 余数的第一位是0，所以向下取整。
        round = 0;
    }

    /// 获取未舍入的尾随有效位。
    auto trailing = prefix >> (roundBitIndex + 1);

    /// 应用舍入。
    trailing += round;

    return boost::numeric_cast<typename Ieee::UIntType>(trailing);
}

template <typename UInteger>
bool Mathematics::operator==(const BinaryScientificNumber<UInteger>& lhs, const BinaryScientificNumber<UInteger>& rhs)
{
    return (lhs.GetSign() == rhs.GetSign() ? EqualIgnoreSign(lhs, rhs) : false);
}

template <typename UInteger>
bool Mathematics::operator!=(const BinaryScientificNumber<UInteger>& lhs, const BinaryScientificNumber<UInteger>& rhs)
{
    return !(lhs == rhs);
}

template <typename UInteger>
bool Mathematics::operator<(const BinaryScientificNumber<UInteger>& lhs, const BinaryScientificNumber<UInteger>& rhs)
{
    if (0 < lhs.GetSign())
    {
        if (rhs.GetSign() <= 0)
        {
            return false;
        }

        /// 这两个数字都是正数。
        return LessThanIgnoreSign(lhs, rhs);
    }
    else if (lhs.GetSign() < 0)
    {
        if (0 <= rhs.GetSign())
        {
            return true;
        }

        /// 这两个数字都是负数。
        return LessThanIgnoreSign(lhs, rhs);
    }
    else
    {
        return 0 < rhs.GetSign();
    }
}

template <typename UInteger>
bool Mathematics::operator<=(const BinaryScientificNumber<UInteger>& lhs, const BinaryScientificNumber<UInteger>& rhs)
{
    return !(rhs < lhs);
}

template <typename UInteger>
bool Mathematics::operator>(const BinaryScientificNumber<UInteger>& lhs, const BinaryScientificNumber<UInteger>& rhs)
{
    return rhs < lhs;
}

template <typename UInteger>
bool Mathematics::operator>=(const BinaryScientificNumber<UInteger>& lhs, const BinaryScientificNumber<UInteger>& rhs)
{
    return !(lhs < rhs);
}

template <typename UInteger>
Mathematics::BinaryScientificNumber<UInteger> Mathematics::operator+(const BinaryScientificNumber<UInteger>& lhs, const BinaryScientificNumber<UInteger>& rhs)
{
    return BinaryScientificNumber<UInteger>{ lhs } += rhs;
}

template <typename UInteger>
Mathematics::BinaryScientificNumber<UInteger> Mathematics::operator-(const BinaryScientificNumber<UInteger>& lhs, const BinaryScientificNumber<UInteger>& rhs)
{
    return BinaryScientificNumber<UInteger>{ lhs } -= rhs;
}

template <typename UInteger>
Mathematics::BinaryScientificNumber<UInteger> Mathematics::operator*(const BinaryScientificNumber<UInteger>& lhs, const BinaryScientificNumber<UInteger>& rhs)
{
    return BinaryScientificNumber<UInteger>{ lhs } *= rhs;
}

template <typename UInteger>
void Mathematics::Convert(const BinaryScientificNumber<UInteger>& input, int precision, int roundingMode, BinaryScientificNumber<UInteger>& output)
{
    if (precision <= 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("精度必须为正。"));
    }

    const auto maxSize = boost::numeric_cast<int64_t>(UInteger::GetMaxSize());
    const auto excess = 32LL * maxSize - static_cast<int64_t>(precision);
    if (excess <= 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("已超过最大精度。"));
    }

    if (input.GetSign() == 0)
    {
        output = BinaryScientificNumber<UInteger>{ 0 };
        return;
    }

    /// 设p = precision，n+1是输入的位数。
    /// 计算n+1-p。
    /// 如果它是非正的，那么输入已经满足了要求的精度。
    const auto np1Mp = input.GetUInteger().GetNumBits() - precision;
    if (np1Mp <= 0)
    {
        output = input;
        return;
    }

    /// 在这一点上，所请求的比特数小于输入中的比特数。
    /// 使用指定的舍入模式将输入舍入为较小的位数。
    auto& outW = output.GetUInteger();
    outW.SetNumBits(precision);
    outW.SetAllBitsToZero();
    const auto outSize = outW.GetSize();
    const auto precisionM1 = precision - 1;
    const auto outLeading = precisionM1 % 32;
    auto outMask = (1 << outLeading);
    auto& outBits = outW.GetBits();
    auto outCurrent = outSize - 1;

    const auto& inW = input.GetUInteger();
    const auto inSize = inW.GetSize();
    const auto inLeading = (inW.GetNumBits() - 1) % 32;
    auto inMask = (1 << inLeading);
    const auto& inBits = inW.GetBits();
    auto inCurrent = inSize - 1;

    auto lastBit = -1;
    for (auto i = precisionM1; i >= 0; --i)
    {
        if (inBits.at(inCurrent) & inMask)
        {
            outBits.at(outCurrent) |= outMask;
            lastBit = 1;
        }
        else
        {
            lastBit = 0;
        }

        if (inMask == 0x00000001u)
        {
            --inCurrent;
            inMask = 0x80000000u;
        }
        else
        {
            inMask >>= 1;
        }

        if (outMask == 0x00000001u)
        {
            --outCurrent;
            outMask = 0x80000000u;
        }
        else
        {
            outMask >>= 1;
        }
    }

    /// 在这一点上，作为一个比特序列，r = u_{n-p} ... u_0。
    auto sign = input.GetSign();
    auto outExponent = input.GetExponent();
    if (roundingMode == FE_TONEAREST)
    {
        /// 确定u_{n-p}是否为正。
        auto positive = (inBits.at(inCurrent) & inMask) != 0u;
        if (positive && (np1Mp > 1 || lastBit == 1))
        {
            /// 四舍五入
            outExponent += outW.RoundUp();
        }
        /// 否则四舍五入，相当于截断r位
    }
    else if (roundingMode == FE_UPWARD)
    {
        /// 余数r必须是正的，因为n-p >= 0并且u_0 = 1。
        if (sign > 0)
        {
            /// 四舍五入
            outExponent += outW.RoundUp();
        }
        // 否则四舍五入，相当于截断r位
    }
    else if (roundingMode == FE_DOWNWARD)
    {
        /// 余数r必须是正的，因为n-p >= 0并且u_0 = 1。
        if (sign < 0)
        {
            /// 四舍五入这是应用于w的四舍五入运算，
            /// 但最终符号为负数，相当于四舍五进。
            outExponent += outW.RoundUp();
        }
        // 否则四舍五入，相当于截断r位
    }
    else if (roundingMode != FE_TOWARDZERO)
    {
        /// 目前，四舍五入不支持其他依赖于实现的模式。
        THROW_EXCEPTION(SYSTEM_TEXT("Implementation-dependent rounding mode not supported."));
    }
    /// else roundingMode == FE_TOWARDZERO.
    /// 截断r位，这不需要额外的工作。

    /// 如果需要，请移位位，
    /// 以获得BinaryScientificNumber对象具有奇数整数位模式的不变量。
    if (outW.GetNumBits() > 0 && (outW.GetBits().at(0) & 1u) == 0)
    {
        auto temp = outW;
        outExponent += outW.ShiftRightToOdd(temp);
    }

    /// 在此步骤中不要使用SetExponent(outExponent)。
    /// 请求的位数为'precision。当四舍五入发生时，
    /// outW.GetNumBits()将不同，
    /// 并且SetExponent访问ooutW.GetNumBits().。
    output.SetSign(sign);
    output.SetBiasedExponent(outExponent - boost::numeric_cast<int>(precisionM1));

#if defined(MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE)

    output.SetValue();

#endif  // MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE
}

template <typename UInteger>
Mathematics::BinaryScientificNumber<UInteger> Mathematics::AtanDivPi(const BinaryScientificNumber<UInteger>& x)
{
    return BinaryScientificNumber<UInteger>{ AtanDivPi(static_cast<double>(x)) };
}

template <typename UInteger>
Mathematics::BinaryScientificNumber<UInteger> Mathematics::Atan2DivPi(const BinaryScientificNumber<UInteger>& y, const BinaryScientificNumber<UInteger>& x)
{
    return BinaryScientificNumber<UInteger>{ AtanDivPi(static_cast<double>(y), static_cast<double>(x)) };
}

template <typename UInteger>
Mathematics::BinaryScientificNumber<UInteger> Mathematics::Clamp(const BinaryScientificNumber<UInteger>& x, const BinaryScientificNumber<UInteger>& xMin, const BinaryScientificNumber<UInteger>& xMax)
{
    return BinaryScientificNumber<UInteger>{ Clamp(static_cast<double>(x), static_cast<double>(xMin), static_cast<double>(xMax)) };
}

template <typename UInteger>
Mathematics::BinaryScientificNumber<UInteger> Mathematics::CosPi(const BinaryScientificNumber<UInteger>& x)
{
    return BinaryScientificNumber<UInteger>{ CosPi(static_cast<double>(x)) };
}

template <typename UInteger>
Mathematics::BinaryScientificNumber<UInteger> Mathematics::Exp10(const BinaryScientificNumber<UInteger>& x)
{
    return BinaryScientificNumber<UInteger>{ Exp10(static_cast<double>(x)) };
}

template <typename UInteger>
Mathematics::BinaryScientificNumber<UInteger> Mathematics::InvSqrt(const BinaryScientificNumber<UInteger>& x)
{
    return BinaryScientificNumber<UInteger>{ InvSqrt(static_cast<double>(x)) };
}

template <typename UInteger>
int Mathematics::SignToInt(const BinaryScientificNumber<UInteger>& x)
{
    return BinaryScientificNumber<UInteger>{ SignToInt(static_cast<double>(x)) };
}

template <typename UInteger>
Mathematics::BinaryScientificNumber<UInteger> Mathematics::Saturate(const BinaryScientificNumber<UInteger>& x)
{
    return BinaryScientificNumber<UInteger>{ Saturate(static_cast<double>(x)) };
}

template <typename UInteger>
Mathematics::BinaryScientificNumber<UInteger> Mathematics::Sign(const BinaryScientificNumber<UInteger>& x)
{
    return BinaryScientificNumber<UInteger>{ Sign(static_cast<double>(x)) };
}

template <typename UInteger>
Mathematics::BinaryScientificNumber<UInteger> Mathematics::SinPi(const BinaryScientificNumber<UInteger>& x)
{
    return BinaryScientificNumber<UInteger>{ SinPi(static_cast<double>(x)) };
}

template <typename UInteger>
Mathematics::BinaryScientificNumber<UInteger> Mathematics::Sqr(const BinaryScientificNumber<UInteger>& x)
{
    return BinaryScientificNumber<UInteger>{ Sqr(static_cast<double>(x)) };
}

template <typename UInteger>
Mathematics::BinaryScientificNumber<UInteger> Mathematics::Fma(const BinaryScientificNumber<UInteger>& u, const BinaryScientificNumber<UInteger>& v, const BinaryScientificNumber<UInteger>& w)
{
    return u * v + w;
}

template <typename UInteger>
Mathematics::BinaryScientificNumber<UInteger> Mathematics::RobustSop(const BinaryScientificNumber<UInteger>& u, const BinaryScientificNumber<UInteger>& v, const BinaryScientificNumber<UInteger>& w, const BinaryScientificNumber<UInteger>& z)
{
    return u * v + w * z;
}

template <typename UInteger>
Mathematics::BinaryScientificNumber<UInteger> Mathematics::RobustDop(const BinaryScientificNumber<UInteger>& u, const BinaryScientificNumber<UInteger>& v, const BinaryScientificNumber<UInteger>& w, const BinaryScientificNumber<UInteger>& z)
{
    return u * v - w * z;
}

template <typename UInteger>
Mathematics::BinaryScientificNumber<UInteger> Mathematics::Acos(const BinaryScientificNumber<UInteger>& x)
{
    return BinaryScientificNumber<UInteger>{ Acos(static_cast<double>(x)) };
}

template <typename UInteger>
Mathematics::BinaryScientificNumber<UInteger> Mathematics::Acosh(const BinaryScientificNumber<UInteger>& x)
{
    return BinaryScientificNumber<UInteger>{ Acosh(static_cast<double>(x)) };
}

template <typename UInteger>
Mathematics::BinaryScientificNumber<UInteger> Mathematics::Asin(const BinaryScientificNumber<UInteger>& x)
{
    return BinaryScientificNumber<UInteger>{ Asin(static_cast<double>(x)) };
}

template <typename UInteger>
Mathematics::BinaryScientificNumber<UInteger> Mathematics::Asinh(const BinaryScientificNumber<UInteger>& x)
{
    return BinaryScientificNumber<UInteger>{ Asinh(static_cast<double>(x)) };
}

template <typename UInteger>
Mathematics::BinaryScientificNumber<UInteger> Mathematics::Atan(const BinaryScientificNumber<UInteger>& x)
{
    return BinaryScientificNumber<UInteger>{ Atan(static_cast<double>(x)) };
}

template <typename UInteger>
Mathematics::BinaryScientificNumber<UInteger> Mathematics::Atanh(const BinaryScientificNumber<UInteger>& x)
{
    return BinaryScientificNumber<UInteger>{ Atanh(static_cast<double>(x)) };
}

template <typename UInteger>
Mathematics::BinaryScientificNumber<UInteger> Mathematics::Atan2(const BinaryScientificNumber<UInteger>& y, const BinaryScientificNumber<UInteger>& x)
{
    return BinaryScientificNumber<UInteger>{ Atanh(static_cast<double>(y), static_cast<double>(x)) };
}

template <typename UInteger>
Mathematics::BinaryScientificNumber<UInteger> Mathematics::Ceil(const BinaryScientificNumber<UInteger>& x)
{
    return BinaryScientificNumber<UInteger>{ Ceil(static_cast<double>(x)) };
}

template <typename UInteger>
Mathematics::BinaryScientificNumber<UInteger> Mathematics::Cos(const BinaryScientificNumber<UInteger>& x)
{
    return BinaryScientificNumber<UInteger>{ Cos(static_cast<double>(x)) };
}

template <typename UInteger>
Mathematics::BinaryScientificNumber<UInteger> Mathematics::Cosh(const BinaryScientificNumber<UInteger>& x)
{
    return BinaryScientificNumber<UInteger>{ Cosh(static_cast<double>(x)) };
}

template <typename UInteger>
Mathematics::BinaryScientificNumber<UInteger> Mathematics::Exp(const BinaryScientificNumber<UInteger>& x)
{
    return BinaryScientificNumber<UInteger>{ Exp(static_cast<double>(x)) };
}

template <typename UInteger>
Mathematics::BinaryScientificNumber<UInteger> Mathematics::Exp2(const BinaryScientificNumber<UInteger>& x)
{
    return BinaryScientificNumber<UInteger>{ Exp2(static_cast<double>(x)) };
}

template <typename UInteger>
Mathematics::BinaryScientificNumber<UInteger> Mathematics::Fabs(const BinaryScientificNumber<UInteger>& x)
{
    return (0 <= x.GetSign() ? x : -x);
}

template <typename UInteger>
Mathematics::BinaryScientificNumber<UInteger> Mathematics::Floor(const BinaryScientificNumber<UInteger>& x)
{
    return BinaryScientificNumber<UInteger>{ Floor(static_cast<double>(x)) };
}

template <typename UInteger>
Mathematics::BinaryScientificNumber<UInteger> Mathematics::Fmod(const BinaryScientificNumber<UInteger>& x, const BinaryScientificNumber<UInteger>& y)
{
    return BinaryScientificNumber<UInteger>{ Fmod(static_cast<double>(x)) };
}

template <typename UInteger>
Mathematics::BinaryScientificNumber<UInteger> Mathematics::Frexp(const BinaryScientificNumber<UInteger>& x, int32_t* exponent)
{
    if (x.GetSign() != 0)
    {
        auto result = x;
        *exponent = result.GetExponent() + 1;
        result.SetExponent(-1);
        return result;
    }
    else
    {
        *exponent = 0;
        return BinaryScientificNumber<UInteger>::CreateZero();
    }
}

template <typename UInteger>
Mathematics::BinaryScientificNumber<UInteger> Mathematics::Ldexp(const BinaryScientificNumber<UInteger>& x, int32_t exponent)
{
    auto result = x;
    result.SetBiasedExponent(result.GetBiasedExponent() + exponent);

    return result;
}

template <typename UInteger>
Mathematics::BinaryScientificNumber<UInteger> Mathematics::Log(const BinaryScientificNumber<UInteger>& x)
{
    return BinaryScientificNumber<UInteger>{ Log(static_cast<double>(x)) };
}

template <typename UInteger>
Mathematics::BinaryScientificNumber<UInteger> Mathematics::Log2(const BinaryScientificNumber<UInteger>& x)
{
    return BinaryScientificNumber<UInteger>{ Log2(static_cast<double>(x)) };
}

template <typename UInteger>
Mathematics::BinaryScientificNumber<UInteger> Mathematics::Log10(const BinaryScientificNumber<UInteger>& x)
{
    return BinaryScientificNumber<UInteger>{ Log10(static_cast<double>(x)) };
}

template <typename UInteger>
Mathematics::BinaryScientificNumber<UInteger> Mathematics::Pow(const BinaryScientificNumber<UInteger>& x, const BinaryScientificNumber<UInteger>& y)
{
    return BinaryScientificNumber<UInteger>{ Pow(static_cast<double>(x), static_cast<double>(y)) };
}

template <typename UInteger>
Mathematics::BinaryScientificNumber<UInteger> Mathematics::Remainder(const BinaryScientificNumber<UInteger>& x, const BinaryScientificNumber<UInteger>& y)
{
    const auto dx = static_cast<double>(x);
    const auto dy = static_cast<double>(y);
    const auto result = std::remainder(dx, dy);

    return BinaryScientificNumber<UInteger>{ result };
}

template <typename UInteger>
Mathematics::BinaryScientificNumber<UInteger> Mathematics::Sin(const BinaryScientificNumber<UInteger>& x)
{
    return BinaryScientificNumber<UInteger>{ Sin(static_cast<double>(x)) };
}

template <typename UInteger>
Mathematics::BinaryScientificNumber<UInteger> Mathematics::Sinh(const BinaryScientificNumber<UInteger>& x)
{
    return BinaryScientificNumber<UInteger>{ Sinh(static_cast<double>(x)) };
}

template <typename UInteger>
Mathematics::BinaryScientificNumber<UInteger> Mathematics::Sqrt(const BinaryScientificNumber<UInteger>& x)
{
    return BinaryScientificNumber<UInteger>{ Sqrt(static_cast<double>(x)) };
}

template <typename UInteger>
Mathematics::BinaryScientificNumber<UInteger> Mathematics::Tan(const BinaryScientificNumber<UInteger>& x)
{
    return BinaryScientificNumber<UInteger>{ Tan(static_cast<double>(x)) };
}

template <typename UInteger>
Mathematics::BinaryScientificNumber<UInteger> Mathematics::Tanh(const BinaryScientificNumber<UInteger>& x)
{
    return BinaryScientificNumber<UInteger>{ Tanh(static_cast<double>(x)) };
}

#endif  // MATHEMATICS_RATIONAL_BINARY_SCIENTIFIC_NUMBER_DETAIL_H
