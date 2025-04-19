/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/07 17:28)

#ifndef MATHEMATICS_RATIONAL_BINARY_SCIENTIFIC_RATIONAL_DETAIL_H
#define MATHEMATICS_RATIONAL_BINARY_SCIENTIFIC_RATIONAL_DETAIL_H

#include "BinaryScientificNumberDetail.h"
#include "BinaryScientificRational.h"
#include "System/Helper/Tools.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename UInteger>
Mathematics::BinaryScientificRational<UInteger> Mathematics::BinaryScientificRational<UInteger>::CreateZero()
{
    return BinaryScientificRational{ CoreTools::DisableNotThrow::Disable };
}

template <typename UInteger>
Mathematics::BinaryScientificRational<UInteger>::BinaryScientificRational(CoreTools::DisableNotThrow disableNotThrow)
    : numerator{ BinaryScientificNumberType::CreateZero() }, denominator{ 1 }
{
    System::UnusedFunction(disableNotThrow);

#if defined(MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE)

    SetValue();

#endif  // MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename UInteger>
Mathematics::BinaryScientificRational<UInteger>::BinaryScientificRational(float numerator)
    : numerator{ numerator },
      denominator{ 1.0f }
{
#if defined(MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE)

    SetValue();

#endif  // MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename UInteger>
Mathematics::BinaryScientificRational<UInteger>::BinaryScientificRational(double numerator) requires(!std::is_same_v<UIntegerFixedPrecision32<1>, UInteger>)
    : numerator{ numerator },
      denominator{ 1.0 }
{
#if defined(MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE)

    SetValue();

#endif  // MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename UInteger>
Mathematics::BinaryScientificRational<UInteger>::BinaryScientificRational(int32_t numerator)
    : numerator{ numerator },
      denominator{ 1 }
{
#if defined(MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE)

    SetValue();

#endif  // MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename UInteger>
Mathematics::BinaryScientificRational<UInteger>::BinaryScientificRational(uint32_t numerator)
    : numerator{ numerator },
      denominator{ 1 }
{
#if defined(MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE)

    SetValue();

#endif  // MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename UInteger>
Mathematics::BinaryScientificRational<UInteger>::BinaryScientificRational(int64_t numerator) requires(!std::is_same_v<UIntegerFixedPrecision32<1>, UInteger>)
    : numerator{ numerator },
      denominator{ 1 }
{
#if defined(MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE)

    SetValue();

#endif  // MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}
template <typename UInteger>
Mathematics::BinaryScientificRational<UInteger>::BinaryScientificRational(uint64_t numerator) requires(!std::is_same_v<UIntegerFixedPrecision32<1>, UInteger>)
    : numerator{ numerator },
      denominator{ 1 }
{
#if defined(MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE)

    SetValue();

#endif  // MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename UInteger>
Mathematics::BinaryScientificRational<UInteger>::BinaryScientificRational(const BinaryScientificNumberType& numerator)
    : numerator{ numerator },
      denominator{ 1 }
{
#if defined(MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE)

    SetValue();

#endif  // MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename UInteger>
Mathematics::BinaryScientificRational<UInteger>::BinaryScientificRational(float numerator, float denominator)
    : numerator{ numerator },
      denominator{ denominator }
{
    if (this->denominator.GetSign() == 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("除以零"))
    }

    if (this->denominator.GetSign() < 0)
    {
        this->numerator.SetSign(-this->numerator.GetSign());
        this->denominator.SetSign(1);
    }

#if defined(MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE)

    SetValue();

#endif  // MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename UInteger>
Mathematics::BinaryScientificRational<UInteger>::BinaryScientificRational(double numerator, double denominator) requires(!std::is_same_v<UIntegerFixedPrecision32<1>, UInteger>)
    : numerator{ numerator },
      denominator{ denominator }
{
    if (this->denominator.GetSign() == 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("除以零"))
    }

    if (this->denominator.GetSign() < 0)
    {
        this->numerator.SetSign(-this->numerator.GetSign());
        this->denominator.SetSign(1);
    }

#if defined(MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE)

    SetValue();

#endif  // MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename UInteger>
Mathematics::BinaryScientificRational<UInteger>::BinaryScientificRational(int32_t numerator, int32_t denominator)
    : numerator{ numerator },
      denominator{ denominator }
{
    if (this->denominator.GetSign() == 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("除以零"))
    }

    if (this->denominator.GetSign() < 0)
    {
        this->numerator.SetSign(-this->numerator.GetSign());
        this->denominator.SetSign(1);
    }

#if defined(MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE)

    SetValue();

#endif  // MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename UInteger>
Mathematics::BinaryScientificRational<UInteger>::BinaryScientificRational(uint32_t numerator, uint32_t denominator)
    : numerator{ numerator },
      denominator{ denominator }
{
    if (this->denominator.GetSign() == 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("除以零"))
    }

    if (this->denominator.GetSign() < 0)
    {
        this->numerator.SetSign(-this->numerator.GetSign());
        this->denominator.SetSign(1);
    }

#if defined(MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE)

    SetValue();

#endif  // MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename UInteger>
Mathematics::BinaryScientificRational<UInteger>::BinaryScientificRational(int64_t numerator, int64_t denominator) requires(!std::is_same_v<UIntegerFixedPrecision32<1>, UInteger>)
    : numerator{ numerator },
      denominator{ denominator }
{
    if (this->denominator.GetSign() == 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("除以零"))
    }

    if (this->denominator.GetSign() < 0)
    {
        this->numerator.SetSign(-this->numerator.GetSign());
        this->denominator.SetSign(1);
    }

#if defined(MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE)

    SetValue();

#endif  // MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename UInteger>
Mathematics::BinaryScientificRational<UInteger>::BinaryScientificRational(uint64_t numerator, uint64_t denominator) requires(!std::is_same_v<UIntegerFixedPrecision32<1>, UInteger>)
    : numerator{ numerator },
      denominator{ denominator }
{
    if (this->denominator.GetSign() == 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("除以零"))
    }

    if (this->denominator.GetSign() < 0)
    {
        this->numerator.SetSign(-this->numerator.GetSign());
        this->denominator.SetSign(1);
    }

#if defined(MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE)

    SetValue();

#endif  // MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename UInteger>
Mathematics::BinaryScientificRational<UInteger>::BinaryScientificRational(const BinaryScientificNumberType& numerator, const BinaryScientificNumberType& denominator)
    : numerator{ numerator },
      denominator{ denominator }
{
    if (this->denominator.GetSign() == 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("除以零"))
    }

    if (this->denominator.GetSign() < 0)
    {
        this->numerator.SetSign(-this->numerator.GetSign());
        this->denominator.SetSign(1);
    }

    /// 将分母的指数设置为零，但只能通过修改有偏指数来实现。
    /// 相应地调整分子。这防止了分子和分母的指数同时大幅增长。
    this->numerator.SetBiasedExponent(this->numerator.GetBiasedExponent() - this->denominator.GetExponent());
    this->denominator.SetBiasedExponent(this->denominator.GetBiasedExponent() - (this->denominator.GetUInteger().GetNumBits() - 1));

#if defined(MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE)

    SetValue();

#endif  // MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename UInteger>
bool Mathematics::BinaryScientificRational<UInteger>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename UInteger>
Mathematics::BinaryScientificRational<UInteger>::operator float() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    float output{};

    Convert(*this, FE_TONEAREST, output);

    return output;
}

template <typename UInteger>
Mathematics::BinaryScientificRational<UInteger>::operator double() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    double output{};

    Convert(*this, FE_TONEAREST, output);

    return output;
}

template <typename UInteger>
void Mathematics::BinaryScientificRational<UInteger>::SetSign(int sign) noexcept(!isBinaryScientificShowDouble)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    numerator.SetSign(sign);
    denominator.SetSign(1);

#if defined(MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE)

    value = sign * std::fabs(value);

#endif  // MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE
}

template <typename UInteger>
int Mathematics::BinaryScientificRational<UInteger>::GetSign() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return numerator.GetSign() * denominator.GetSign();
}

template <typename UInteger>
void Mathematics::BinaryScientificRational<UInteger>::Negate() noexcept(!isBinaryScientificShowDouble)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    numerator.Negate();

#if defined(MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE)

    SetValue();

#endif  // MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE
}

template <typename UInteger>
const typename Mathematics::BinaryScientificRational<UInteger>::BinaryScientificNumberType& Mathematics::BinaryScientificRational<UInteger>::GetNumerator() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return numerator;
}

template <typename UInteger>
typename Mathematics::BinaryScientificRational<UInteger>::BinaryScientificNumberType& Mathematics::BinaryScientificRational<UInteger>::GetNumerator() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return numerator;
}

template <typename UInteger>
const typename Mathematics::BinaryScientificRational<UInteger>::BinaryScientificNumberType& Mathematics::BinaryScientificRational<UInteger>::GetDenominator() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return denominator;
}

template <typename UInteger>
typename Mathematics::BinaryScientificRational<UInteger>::BinaryScientificNumberType& Mathematics::BinaryScientificRational<UInteger>::GetDenominator() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return denominator;
}

template <typename UInteger>
Mathematics::BinaryScientificRational<UInteger> Mathematics::BinaryScientificRational<UInteger>::operator+() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return *this;
}

template <typename UInteger>
Mathematics::BinaryScientificRational<UInteger> Mathematics::BinaryScientificRational<UInteger>::operator-() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return BinaryScientificRational{ -numerator, denominator };
}

template <typename UInteger>
Mathematics::BinaryScientificRational<UInteger>& Mathematics::BinaryScientificRational<UInteger>::operator+=(const BinaryScientificRational& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const auto product0 = numerator * rhs.GetDenominator();
    const auto product1 = denominator * rhs.GetNumerator();

    /// 复杂表达式可能导致0/denom，其中denom不是1。
    if (const auto numeratorResult = product0 + product1;
        numeratorResult.GetSign() != 0)
    {
        const auto denominatorResult = denominator * rhs.GetDenominator();

        *this = BinaryScientificRational{ numeratorResult, denominatorResult };
    }
    else
    {
        *this = BinaryScientificRational{ 0 };
    }

    return *this;
}

template <typename UInteger>
Mathematics::BinaryScientificRational<UInteger>& Mathematics::BinaryScientificRational<UInteger>::operator-=(const BinaryScientificRational& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const auto product0 = numerator * rhs.GetDenominator();
    const auto product1 = denominator * rhs.GetNumerator();

    /// 复杂表达式可能导致0/denom，其中denom不是1。
    if (const auto numeratorResult = product0 - product1;
        numeratorResult.GetSign() != 0)
    {
        const auto denominatorResult = denominator * rhs.GetDenominator();

        *this = BinaryScientificRational(numeratorResult, denominatorResult);
    }
    else
    {
        *this = BinaryScientificRational{ 0 };
    }

    return *this;
}

template <typename UInteger>
Mathematics::BinaryScientificRational<UInteger>& Mathematics::BinaryScientificRational<UInteger>::operator*=(const BinaryScientificRational& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    /// 复杂表达式可能导致0/denom，其中denom不是1。
    if (const auto numeratorResult = numerator * rhs.GetNumerator();
        numeratorResult.GetSign() != 0)
    {
        const auto denominatorResult = denominator * rhs.GetDenominator();

        *this = BinaryScientificRational{ numeratorResult, denominatorResult };
    }
    else
    {
        *this = BinaryScientificRational{ 0 };
    }

    return *this;
}

template <typename UInteger>
Mathematics::BinaryScientificRational<UInteger>& Mathematics::BinaryScientificRational<UInteger>::operator/=(const BinaryScientificRational& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    MATHEMATICS_ASSERTION_0(rhs.GetNumerator().GetSign() != 0, "在BinaryScientificRational::operator/中除以零。");

    /// 复杂表达式可能导致0/denom，其中denom不是1。
    if (auto numeratorResult = numerator * rhs.GetDenominator();
        numeratorResult.GetSign() != 0)
    {
        auto denominatorResult = denominator * rhs.GetNumerator();
        if (denominatorResult.GetSign() < 0)
        {
            numeratorResult.SetSign(-numeratorResult.GetSign());
            denominatorResult.SetSign(1);
        }

        *this = BinaryScientificRational{ numeratorResult, denominatorResult };
    }
    else
    {
        *this = BinaryScientificRational{ 0 };
    }

    return *this;
}

template <typename UInteger>
bool Mathematics::BinaryScientificRational<UInteger>::Write(std::ostream& output) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return numerator.Write(output) && denominator.Write(output);
}

template <typename UInteger>
bool Mathematics::BinaryScientificRational<UInteger>::Read(std::istream& input)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return numerator.Read(input) && denominator.Read(input);
}

template <typename UInteger>
Mathematics::BinaryScientificRational<UInteger> Mathematics::BinaryScientificRational<UInteger>::ConvertToFraction(const std::string& number)
{
    MATHEMATICS_ASSERTION_0(number.find_first_not_of("0123456789") == std::string::npos, "Invalid number format.");

    BinaryScientificRational y{ 0 };
    BinaryScientificRational ten{ 10 };
    BinaryScientificRational pow10{ 10 };
    for (const char element : number)
    {
        if (const auto digit = boost::numeric_cast<int>(element) - boost::numeric_cast<int>('0');
            0 < digit)
        {
            y += BinaryScientificRational(digit) / pow10;
        }
        pow10 *= ten;
    }
    return y;
}

#if defined(MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE)

template <typename UInteger>
double Mathematics::BinaryScientificRational<UInteger>::GetValue() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return value;
}

template <typename UInteger>
void Mathematics::BinaryScientificRational<UInteger>::SetValue(double aValue) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    value = aValue;
}

template <typename UInteger>
void Mathematics::BinaryScientificRational<UInteger>::SetValue()
{
    MATHEMATICS_CLASS_IS_VALID_1;

    value = static_cast<double>(*this);
}

#endif  // MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE

template <typename UInteger>
void Mathematics::Convert(const BinaryScientificRational<UInteger>& input, int precision, int roundingMode, BinaryScientificNumber<UInteger>& output)
{
    if (precision <= 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("精度必须为正。"))
    }

    const auto maxNumBlocks = UInteger::GetMaxSize();
    const auto numPrecisionBlocks = (precision + 31) / 32;
    if (maxNumBlocks <= numPrecisionBlocks)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("已超过最大精度。"))
    }

    if (input.GetSign() == 0)
    {
        output = BinaryScientificNumber<UInteger>{ 0 };

        return;
    }

    auto n = input.GetNumerator();
    auto d = input.GetDenominator();

    /// 该比值抽象地为 n/d = (1.u*2^p)/(1.v*2^q).
    /// 转换为
    ///   (1.u/1.v)*2^{p-q}, if 1.u >= 1.v
    ///   2*(1.u/1.v)*2^{p-q-1} if 1.u < 1.v
    /// 在区间内 [1,2).
    const auto sign = n.GetSign() * d.GetSign();
    n.SetSign(1);
    d.SetSign(1);
    auto pmq = n.GetExponent() - d.GetExponent();
    n.SetExponent(0);
    d.SetExponent(0);
    if (n < d)
    {
        n.SetExponent(n.GetExponent() + 1);
        --pmq;
    }

    /// 设p = precision。
    /// 此时，在[1,2)中，n/d = 1.c。
    /// 定义比特序列w = 1c = w_{p-1} w_{p-2} ... w_0 r，
    /// 其中w_{p-1} = 1。
    /// w_0之后的比特r用于基于用户指定的舍入模式进行舍入。

    /// 计算w的p位，前导位保证为1，
    /// 并出现在索引(1 << (precision-1))处。
    BinaryScientificNumber<UInteger> one{ 1 };
    BinaryScientificNumber<UInteger> two{ 2 };
    auto& w = output.GetUInteger();
    w.SetNumBits(precision);
    w.SetAllBitsToZero();
    const auto size = w.GetSize();
    const auto precisionM1 = precision - 1;
    const auto leading = precisionM1 % 32;
    auto mask = boost::numeric_cast<size_t>(1 << leading);
    auto& bits = w.GetBits();
    auto current = size - 1;
    auto lastBit = -1;
    for (auto i = precisionM1; i >= 0; --i)
    {
        if (n < d)
        {
            n = two * n;
            lastBit = 0;
        }
        else
        {
            n = two * (n - d);
            bits.at(current) |= mask;
            lastBit = 1;
            if (n.GetSign() == 0)
            {
                /// 输入有理数在其表示中有有限数量的位，
                /// 因此它正是一个BinaryScientificRational。
                if (i > 0)
                {
                    /// 对于循环的剩余部分，数字n为零，
                    /// 因此p位精度模式的最后一位为零。
                    /// 没有必要继续循环。
                    lastBit = 0;
                }
                break;
            }
        }

        if (mask == 0x00000001u)
        {
            --current;
            mask = 0x80000000u;
        }
        else
        {
            mask >>= 1;
        }
    }

    /// 在这一点上，作为比特序列，r = n/d = r0 r1 ...
    if (roundingMode == FE_TONEAREST)
    {
        n = n - d;
        if (n.GetSign() > 0 || (n.GetSign() == 0 && lastBit == 1))
        {
            /// 使聚集
            pmq += w.RoundUp();
        }
        /// 否则四舍五入，相当于截断r位
    }
    else if (roundingMode == FE_UPWARD)
    {
        if (n.GetSign() > 0 && sign > 0)
        {
            /// 使聚集
            pmq += w.RoundUp();
        }
        /// 否则四舍五入，相当于截断r位
    }
    else if (roundingMode == FE_DOWNWARD)
    {
        if (n.GetSign() > 0 && sign < 0)
        {
            /// 四舍五入这是应用于w的四舍五入运算，
            /// 但最后的符号是负数，相当于四舍五进。
            pmq += w.RoundUp();
        }
        /// 否则四舍五入，相当于截断r位
    }
    else if (roundingMode != FE_TOWARDZERO)
    {
        /// 目前，四舍五入不支持其他依赖于实现的模式。
        THROW_EXCEPTION(SYSTEM_TEXT("不支持依赖于实现的舍入模式。"))
    }
    /// else roundingMode == FE_TOWARDZERO. 截断r位，这不需要额外的工作。

    /// 如果需要，请移位位，
    /// 以获得BinaryScientificRational对象具有奇数整数位模式的不变量。
    if ((w.GetBits().at(0) & 1) == 0)
    {
        auto temp = w;
        const auto shift = w.ShiftRightToOdd(temp);
        pmq += shift;
    }

    /// 在此步骤中不要使用SetExponent(pmq) 。
    /// 请求的位数是'precision'，但当进行四舍五入时，
    /// w.GetNumBits()将不同，并且SetExponent访问w.GetNumBits()。
    output.SetSign(sign);
    output.SetBiasedExponent(pmq - precisionM1);

#if defined(MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE)

    output.SetValue();

#endif  // MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE
}

template <typename UInteger>
void Mathematics::Convert(const BinaryScientificRational<UInteger>& input, int precision, int roundingMode, BinaryScientificRational<UInteger>& output)
{
    auto numerator = BinaryScientificNumber<UInteger>::CreateZero();

    Convert(input, precision, roundingMode, numerator);

    output = BinaryScientificRational<UInteger>(numerator);
}

template <typename UInteger, typename FloatingPointType>
void Mathematics::Convert(const BinaryScientificRational<UInteger>& input, int roundingMode, FloatingPointType& output)
{
    static_assert(std::is_floating_point_v<FloatingPointType>, "Invalid floating-point type.");

    auto number = BinaryScientificNumber<UInteger>::CreateZero();

    Convert(input, std::numeric_limits<FloatingPointType>::digits, roundingMode, number);

    output = boost::numeric_cast<FloatingPointType>(number);
}

template <typename UInteger>
Mathematics::BinaryScientificRational<UInteger> Mathematics::operator+(const BinaryScientificRational<UInteger>& lhs, const BinaryScientificRational<UInteger>& rhs)
{
    return BinaryScientificRational<UInteger>{ lhs } += rhs;
}

template <typename UInteger>
Mathematics::BinaryScientificRational<UInteger> Mathematics::operator-(const BinaryScientificRational<UInteger>& lhs, const BinaryScientificRational<UInteger>& rhs)
{
    return BinaryScientificRational<UInteger>{ lhs } -= rhs;
}

template <typename UInteger>
Mathematics::BinaryScientificRational<UInteger> Mathematics::operator*(const BinaryScientificRational<UInteger>& lhs, const BinaryScientificRational<UInteger>& rhs)
{
    return BinaryScientificRational<UInteger>{ lhs } *= rhs;
}

template <typename UInteger>
Mathematics::BinaryScientificRational<UInteger> Mathematics::operator/(const BinaryScientificRational<UInteger>& lhs, const BinaryScientificRational<UInteger>& rhs)
{
    return BinaryScientificRational<UInteger>{ lhs } /= rhs;
}

template <typename UInteger>
bool Mathematics::operator==(const BinaryScientificRational<UInteger>& lhs, const BinaryScientificRational<UInteger>& rhs)
{
    /// 首先进行廉价的符号测试以获得最佳性能。
    if (lhs.GetNumerator().GetSign() != rhs.GetNumerator().GetSign())
    {
        return false;
    }

    if (lhs.GetNumerator().GetSign() == 0)
    {
        /// 这两个数字都是零。
        return true;
    }

    return lhs.GetNumerator() * rhs.GetDenominator() == lhs.GetDenominator() * rhs.GetNumerator();
}

template <typename UInteger>
bool Mathematics::operator!=(const BinaryScientificRational<UInteger>& lhs, const BinaryScientificRational<UInteger>& rhs)
{
    return !(lhs == rhs);
}

template <typename UInteger>
bool Mathematics::operator<(const BinaryScientificRational<UInteger>& lhs, const BinaryScientificRational<UInteger>& rhs)
{
    /// 首先进行廉价的符号测试以获得最佳性能。
    if (lhs.GetNumerator().GetSign() > 0)
    {
        if (rhs.GetNumerator().GetSign() <= 0)
        {
            return false;
        }
    }
    else if (lhs.GetNumerator().GetSign() == 0)
    {
        return rhs.GetNumerator().GetSign() > 0;
    }
    else if (lhs.GetNumerator().GetSign() < 0)
    {
        if (rhs.GetNumerator().GetSign() >= 0)
        {
            return true;
        }
    }

    return lhs.GetNumerator() * rhs.GetDenominator() < lhs.GetDenominator() * rhs.GetNumerator();
}

template <typename UInteger>
bool Mathematics::operator<=(const BinaryScientificRational<UInteger>& lhs, const BinaryScientificRational<UInteger>& rhs)
{
    return !(rhs < lhs);
}

template <typename UInteger>
bool Mathematics::operator>(const BinaryScientificRational<UInteger>& lhs, const BinaryScientificRational<UInteger>& rhs)
{
    return rhs < lhs;
}

template <typename UInteger>
bool Mathematics::operator>=(const BinaryScientificRational<UInteger>& lhs, const BinaryScientificRational<UInteger>& rhs)
{
    return !(lhs < rhs);
}

template <typename UInteger>
Mathematics::BinaryScientificRational<UInteger> Mathematics::AtanDivPi(const BinaryScientificRational<UInteger>& x)
{
    return BinaryScientificRational<UInteger>{ AtanDivPi(static_cast<double>(x)) };
}

template <typename UInteger>
Mathematics::BinaryScientificRational<UInteger> Mathematics::Atan2DivPi(const BinaryScientificRational<UInteger>& y, const BinaryScientificRational<UInteger>& x)
{
    return BinaryScientificRational<UInteger>{ Atan2DivPi(static_cast<double>(y), static_cast<double>(x)) };
}

template <typename UInteger>
Mathematics::BinaryScientificRational<UInteger> Mathematics::Clamp(const BinaryScientificRational<UInteger>& x, const BinaryScientificRational<UInteger>& xMin, const BinaryScientificRational<UInteger>& xMax)
{
    return BinaryScientificRational<UInteger>{ Clamp(static_cast<double>(x), static_cast<double>(xMin), static_cast<double>(xMax)) };
}

template <typename UInteger>
Mathematics::BinaryScientificRational<UInteger> Mathematics::CosPi(const BinaryScientificRational<UInteger>& x)
{
    return BinaryScientificRational<UInteger>{ CosPi(static_cast<double>(x)) };
}

template <typename UInteger>
Mathematics::BinaryScientificRational<UInteger> Mathematics::Exp10(const BinaryScientificRational<UInteger>& x)
{
    return BinaryScientificRational<UInteger>{ Exp10(static_cast<double>(x)) };
}

template <typename UInteger>
Mathematics::BinaryScientificRational<UInteger> Mathematics::InvSqrt(const BinaryScientificRational<UInteger>& x)
{
    return BinaryScientificRational<UInteger>{ InvSqrt(static_cast<double>(x)) };
}

template <typename UInteger>
int Mathematics::SignToInt(const BinaryScientificRational<UInteger>& x)
{
    return SignToInt(static_cast<double>(x));
}

template <typename UInteger>
Mathematics::BinaryScientificRational<UInteger> Mathematics::Saturate(const BinaryScientificRational<UInteger>& x)
{
    return BinaryScientificRational<UInteger>{ Saturate(static_cast<double>(x)) };
}

template <typename UInteger>
Mathematics::BinaryScientificRational<UInteger> Mathematics::Sign(const BinaryScientificRational<UInteger>& x)
{
    return BinaryScientificRational<UInteger>{ Sign(static_cast<double>(x)) };
}

template <typename UInteger>
Mathematics::BinaryScientificRational<UInteger> Mathematics::SinPi(const BinaryScientificRational<UInteger>& x)
{
    return BinaryScientificRational<UInteger>{ SinPi(static_cast<double>(x)) };
}

template <typename UInteger>
Mathematics::BinaryScientificRational<UInteger> Mathematics::Sqr(const BinaryScientificRational<UInteger>& x)
{
    return BinaryScientificRational<UInteger>{ Sqr(static_cast<double>(x)) };
}

template <typename UInteger>
Mathematics::BinaryScientificRational<UInteger> Mathematics::Fma(const BinaryScientificRational<UInteger>& u, const BinaryScientificRational<UInteger>& v, const BinaryScientificRational<UInteger>& w)
{
    return u * v + w;
}

template <typename UInteger>
Mathematics::BinaryScientificRational<UInteger> Mathematics::RobustSop(const BinaryScientificRational<UInteger>& u, const BinaryScientificRational<UInteger>& v, const BinaryScientificRational<UInteger>& w, const BinaryScientificRational<UInteger>& z)
{
    return u * v + w * z;
}

template <typename UInteger>
Mathematics::BinaryScientificRational<UInteger> Mathematics::RobustDop(const BinaryScientificRational<UInteger>& u, const BinaryScientificRational<UInteger>& v, const BinaryScientificRational<UInteger>& w, const BinaryScientificRational<UInteger>& z)
{
    return u * v - w * z;
}

template <typename UInteger>
Mathematics::BinaryScientificRational<UInteger> Mathematics::Acos(const BinaryScientificRational<UInteger>& x)
{
    return BinaryScientificRational<UInteger>{ std::acos(static_cast<double>(x)) };
}

template <typename UInteger>
Mathematics::BinaryScientificRational<UInteger> Mathematics::Acosh(const BinaryScientificRational<UInteger>& x)
{
    return BinaryScientificRational<UInteger>{ std::acosh(static_cast<double>(x)) };
}

template <typename UInteger>
Mathematics::BinaryScientificRational<UInteger> Mathematics::Asin(const BinaryScientificRational<UInteger>& x)
{
    return BinaryScientificRational<UInteger>{ std::asin(static_cast<double>(x)) };
}

template <typename UInteger>
Mathematics::BinaryScientificRational<UInteger> Mathematics::Asinh(const BinaryScientificRational<UInteger>& x)
{
    return BinaryScientificRational<UInteger>{ std::asinh(static_cast<double>(x)) };
}

template <typename UInteger>
Mathematics::BinaryScientificRational<UInteger> Mathematics::Atan(const BinaryScientificRational<UInteger>& x)
{
    return BinaryScientificRational<UInteger>{ std::atan(static_cast<double>(x)) };
}

template <typename UInteger>
Mathematics::BinaryScientificRational<UInteger> Mathematics::Atanh(const BinaryScientificRational<UInteger>& x)
{
    return BinaryScientificRational<UInteger>{ std::atanh(static_cast<double>(x)) };
}

template <typename UInteger>
Mathematics::BinaryScientificRational<UInteger> Mathematics::Atan2(const BinaryScientificRational<UInteger>& y, const BinaryScientificRational<UInteger>& x)
{
    return BinaryScientificRational<UInteger>{ std::atan2(static_cast<double>(y), static_cast<double>(x)) };
}

template <typename UInteger>
Mathematics::BinaryScientificRational<UInteger> Mathematics::Ceil(const BinaryScientificRational<UInteger>& x)
{
    return BinaryScientificRational<UInteger>{ std::ceil(static_cast<double>(x)) };
}

template <typename UInteger>
Mathematics::BinaryScientificRational<UInteger> Mathematics::Cos(const BinaryScientificRational<UInteger>& x)
{
    return BinaryScientificRational<UInteger>{ std::cos(static_cast<double>(x)) };
}

template <typename UInteger>
Mathematics::BinaryScientificRational<UInteger> Mathematics::Cosh(const BinaryScientificRational<UInteger>& x)
{
    return BinaryScientificRational<UInteger>{ std::cosh(static_cast<double>(x)) };
}

template <typename UInteger>
Mathematics::BinaryScientificRational<UInteger> Mathematics::Exp(const BinaryScientificRational<UInteger>& x)
{
    return BinaryScientificRational<UInteger>{ std::exp(static_cast<double>(x)) };
}

template <typename UInteger>
Mathematics::BinaryScientificRational<UInteger> Mathematics::Exp2(const BinaryScientificRational<UInteger>& x)
{
    return BinaryScientificRational<UInteger>{ std::exp2(static_cast<double>(x)) };
}

template <typename UInteger>
Mathematics::BinaryScientificRational<UInteger> Mathematics::Fabs(const BinaryScientificRational<UInteger>& x)
{
    return (x.GetSign() >= 0 ? x : -x);
}

template <typename UInteger>
Mathematics::BinaryScientificRational<UInteger> Mathematics::Floor(const BinaryScientificRational<UInteger>& x)
{
    return BinaryScientificRational<UInteger>{ std::floor(static_cast<double>(x)) };
}

template <typename UInteger>
Mathematics::BinaryScientificRational<UInteger> Mathematics::Fmod(const BinaryScientificRational<UInteger>& x, const BinaryScientificRational<UInteger>& y)
{
    return BinaryScientificRational<UInteger>{ std::fmod(static_cast<double>(x), static_cast<double>(y)) };
}

template <typename UInteger>
Mathematics::BinaryScientificRational<UInteger> Mathematics::Frexp(const BinaryScientificRational<UInteger>& x, int32_t* exponent)
{
    auto result = x;
    auto& numerator = result.GetNumerator();
    auto& denominator = result.GetDenominator();
    auto e = numerator.GetExponent() - denominator.GetExponent();
    numerator.SetExponent(0);
    denominator.SetExponent(0);
    const auto saveSign = numerator.GetSign();
    numerator.SetSign(1);
    if (numerator >= denominator)
    {
        ++e;
        numerator.SetExponent(-1);
    }
    numerator.SetSign(saveSign);
    if (exponent != nullptr)
    {
        *exponent = e;
    }

#if defined(MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE)

    result.SetValue();

#endif  // MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE

    return result;
}

template <typename UInteger>
Mathematics::BinaryScientificRational<UInteger> Mathematics::Ldexp(const BinaryScientificRational<UInteger>& x, int32_t exponent) noexcept(!isBinaryScientificShowDouble)
{
    auto result = x;
    auto biasedExponent = result.GetNumerator().GetBiasedExponent();
    biasedExponent += exponent;
    result.GetNumerator().SetBiasedExponent(biasedExponent);

#if defined(MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE)

    result.SetValue();

#endif  // MATHEMATICS_BINARY_SCIENTIFIC_SHOW_DOUBLE

    return result;
}

template <typename UInteger>
Mathematics::BinaryScientificRational<UInteger> Mathematics::Log(const BinaryScientificRational<UInteger>& x)
{
    return BinaryScientificRational<UInteger>{ std::log(static_cast<double>(x)) };
}

template <typename UInteger>
Mathematics::BinaryScientificRational<UInteger> Mathematics::Log2(const BinaryScientificRational<UInteger>& x)
{
    return BinaryScientificRational<UInteger>{ std::log2(static_cast<double>(x)) };
}

template <typename UInteger>
Mathematics::BinaryScientificRational<UInteger> Mathematics::Log10(const BinaryScientificRational<UInteger>& x)
{
    return BinaryScientificRational<UInteger>{ std::log10(static_cast<double>(x)) };
}

template <typename UInteger>
Mathematics::BinaryScientificRational<UInteger> Mathematics::Pow(const BinaryScientificRational<UInteger>& x, const BinaryScientificRational<UInteger>& y)
{
    return BinaryScientificRational<UInteger>{ std::pow(static_cast<double>(x), static_cast<double>(y)) };
}

template <typename UInteger>
Mathematics::BinaryScientificRational<UInteger> Mathematics::Remainder(const BinaryScientificRational<UInteger>& x, const BinaryScientificRational<UInteger>& y)
{
    const auto dx = static_cast<double>(x);
    const auto dy = static_cast<double>(y);
    const auto result = std::remainder(dx, dy);

    return BinaryScientificRational<UInteger>{ result };
}

template <typename UInteger>
Mathematics::BinaryScientificRational<UInteger> Mathematics::Sin(const BinaryScientificRational<UInteger>& x)
{
    return BinaryScientificRational<UInteger>{ std::sin(static_cast<double>(x)) };
}

template <typename UInteger>
Mathematics::BinaryScientificRational<UInteger> Mathematics::Sinh(const BinaryScientificRational<UInteger>& x)
{
    return BinaryScientificRational<UInteger>{ std::sinh(static_cast<double>(x)) };
}

template <typename UInteger>
Mathematics::BinaryScientificRational<UInteger> Mathematics::Sqrt(const BinaryScientificRational<UInteger>& x)
{
    return BinaryScientificRational<UInteger>{ std::sqrt(static_cast<double>(x)) };
}

template <typename UInteger>
Mathematics::BinaryScientificRational<UInteger> Mathematics::Tan(const BinaryScientificRational<UInteger>& x)
{
    return BinaryScientificRational<UInteger>{ std::tan(static_cast<double>(x)) };
}

template <typename UInteger>
Mathematics::BinaryScientificRational<UInteger> Mathematics::Tanh(const BinaryScientificRational<UInteger>& x)
{
    return BinaryScientificRational<UInteger>{ std::tanh(static_cast<double>(x)) };
}

#endif  // MATHEMATICS_RATIONAL_BINARY_SCIENTIFIC_RATIONAL_DETAIL_H
