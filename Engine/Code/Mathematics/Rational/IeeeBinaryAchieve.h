/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/05 13:48)

#ifndef MATHEMATICS_RATIONAL_IEEE_BINARY_ACHIEVE_H
#define MATHEMATICS_RATIONAL_IEEE_BINARY_ACHIEVE_H

#include "IeeeBinary.h"
#include "Flags/FloatingPointAnalysisType.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include <gsl/util>

template <typename Float, typename UInt, int NumBits, int Precision>
requires(std::is_arithmetic_v<Float> && std::is_integral_v<UInt> && 0 < NumBits && 0 < Precision)
Mathematics::IeeeBinary<Float, UInt, NumBits, Precision>::IeeeBinary() noexcept
    : encoding{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Float, typename UInt, int NumBits, int Precision>
requires(std::is_arithmetic_v<Float> && std::is_integral_v<UInt> && 0 < NumBits && 0 < Precision)
Mathematics::IeeeBinary<Float, UInt, NumBits, Precision>::IeeeBinary(UIntType encoding) noexcept
    : encoding{ encoding }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Float, typename UInt, int NumBits, int Precision>
requires(std::is_arithmetic_v<Float> && std::is_integral_v<UInt> && 0 < NumBits && 0 < Precision)
Mathematics::IeeeBinary<Float, UInt, NumBits, Precision>::IeeeBinary(UIntType sign, UIntType biased, UIntType trailing) noexcept
    : encoding{ gsl::narrow_cast<UIntType>((sign << signShift) | (biased << numTrailingBits) | trailing) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Float, typename UInt, int NumBits, int Precision>
requires(std::is_arithmetic_v<Float> && std::is_integral_v<UInt> && 0 < NumBits && 0 < Precision)
Mathematics::IeeeBinary<Float, UInt, NumBits, Precision>::IeeeBinary(FloatType number) noexcept
    : number{ number }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Float, typename UInt, int NumBits, int Precision>
requires(std::is_arithmetic_v<Float> && std::is_integral_v<UInt> && 0 < NumBits && 0 < Precision)
bool Mathematics::IeeeBinary<Float, UInt, NumBits, Precision>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Float, typename UInt, int NumBits, int Precision>
requires(std::is_arithmetic_v<Float> && std::is_integral_v<UInt> && 0 < NumBits && 0 < Precision)
Mathematics::IeeeBinary<Float, UInt, NumBits, Precision>::operator UInt() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return encoding;
}

template <typename Float, typename UInt, int NumBits, int Precision>
requires(std::is_arithmetic_v<Float> && std::is_integral_v<UInt> && 0 < NumBits && 0 < Precision)
Mathematics::IeeeBinary<Float, UInt, NumBits, Precision>::operator Float() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return number;
}

template <typename Float, typename UInt, int NumBits, int Precision>
requires(std::is_arithmetic_v<Float> && std::is_integral_v<UInt> && 0 < NumBits && 0 < Precision)
typename Mathematics::IeeeBinary<Float, UInt, NumBits, Precision>::UIntType Mathematics::IeeeBinary<Float, UInt, NumBits, Precision>::GetEncoding() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return encoding;
}

template <typename Float, typename UInt, int NumBits, int Precision>
requires(std::is_arithmetic_v<Float> && std::is_integral_v<UInt> && 0 < NumBits && 0 < Precision)
typename Mathematics::IeeeBinary<Float, UInt, NumBits, Precision>::FloatType Mathematics::IeeeBinary<Float, UInt, NumBits, Precision>::GetNumber() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return number;
}

template <typename Float, typename UInt, int NumBits, int Precision>
requires(std::is_arithmetic_v<Float> && std::is_integral_v<UInt> && 0 < NumBits && 0 < Precision)
void Mathematics::IeeeBinary<Float, UInt, NumBits, Precision>::SetEncoding(UIntType aEncoding) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    encoding = aEncoding;
}

template <typename Float, typename UInt, int NumBits, int Precision>
requires(std::is_arithmetic_v<Float> && std::is_integral_v<UInt> && 0 < NumBits && 0 < Precision)
void Mathematics::IeeeBinary<Float, UInt, NumBits, Precision>::SetNumber(FloatType aNumber) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    number = aNumber;
}

template <typename Float, typename UInt, int NumBits, int Precision>
requires(std::is_arithmetic_v<Float> && std::is_integral_v<UInt> && 0 < NumBits && 0 < Precision)
Mathematics::Classification Mathematics::IeeeBinary<Float, UInt, NumBits, Precision>::GetClassification() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    UIntType sign{};
    UIntType biased{};
    UIntType trailing{};
    GetEncoding(sign, biased, trailing);

    if (biased == 0)
    {
        if (trailing == 0)
        {
            if (sign != 0)
            {
                return Classification::NegZero;
            }
            else
            {
                return Classification::PosZero;
            }
        }
        else
        {
            if (sign != 0)
            {
                return Classification::NegSubnormal;
            }
            else
            {
                return Classification::PosSubnormal;
            }
        }
    }
    else if (biased < maxBiasedExponent)
    {
        if (sign != 0)
        {
            return Classification::NegNormal;
        }
        else
        {
            return Classification::PosNormal;
        }
    }
    else if (trailing == 0)
    {
        if (sign != 0)
        {
            return Classification::NegInfinity;
        }
        else
        {
            return Classification::PosInfinity;
        }
    }
    else if (trailing & nanQuietMask)
    {
        return Classification::QuietNan;
    }
    else
    {
        return Classification::SignalingNan;
    }
}

template <typename Float, typename UInt, int NumBits, int Precision>
requires(std::is_arithmetic_v<Float> && std::is_integral_v<UInt> && 0 < NumBits && 0 < Precision)
bool Mathematics::IeeeBinary<Float, UInt, NumBits, Precision>::IsZero() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return encoding == posZero || encoding == negZero;
}

template <typename Float, typename UInt, int NumBits, int Precision>
requires(std::is_arithmetic_v<Float> && std::is_integral_v<UInt> && 0 < NumBits && 0 < Precision)
bool Mathematics::IeeeBinary<Float, UInt, NumBits, Precision>::IsSignMinus() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return (encoding & signMask) != 0;
}

template <typename Float, typename UInt, int NumBits, int Precision>
requires(std::is_arithmetic_v<Float> && std::is_integral_v<UInt> && 0 < NumBits && 0 < Precision)
bool Mathematics::IeeeBinary<Float, UInt, NumBits, Precision>::IsSubnormal() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return GetBiased() == 0 && GetTrailing() > 0;
}

template <typename Float, typename UInt, int NumBits, int Precision>
requires(std::is_arithmetic_v<Float> && std::is_integral_v<UInt> && 0 < NumBits && 0 < Precision)
bool Mathematics::IeeeBinary<Float, UInt, NumBits, Precision>::IsNormal() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto biased = GetBiased();

    return 0 < biased && biased < maxBiasedExponent;
}

template <typename Float, typename UInt, int NumBits, int Precision>
requires(std::is_arithmetic_v<Float> && std::is_integral_v<UInt> && 0 < NumBits && 0 < Precision)
bool Mathematics::IeeeBinary<Float, UInt, NumBits, Precision>::IsFinite() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return GetBiased() < maxBiasedExponent;
}

template <typename Float, typename UInt, int NumBits, int Precision>
requires(std::is_arithmetic_v<Float> && std::is_integral_v<UInt> && 0 < NumBits && 0 < Precision)
bool Mathematics::IeeeBinary<Float, UInt, NumBits, Precision>::IsInfinite() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return GetBiased() == maxBiasedExponent && GetTrailing() == 0;
}

template <typename Float, typename UInt, int NumBits, int Precision>
requires(std::is_arithmetic_v<Float> && std::is_integral_v<UInt> && 0 < NumBits && 0 < Precision)
bool Mathematics::IeeeBinary<Float, UInt, NumBits, Precision>::IsNaN() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return GetBiased() == maxBiasedExponent && GetTrailing() != 0;
}

template <typename Float, typename UInt, int NumBits, int Precision>
requires(std::is_arithmetic_v<Float> && std::is_integral_v<UInt> && 0 < NumBits && 0 < Precision)
bool Mathematics::IeeeBinary<Float, UInt, NumBits, Precision>::IsQuietNaN() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto trailing = GetTrailing();

    return GetBiased() == maxBiasedExponent && (trailing & nanQuietMask) != 0 && (trailing & nanPayloadMask) != 0;
}

template <typename Float, typename UInt, int NumBits, int Precision>
requires(std::is_arithmetic_v<Float> && std::is_integral_v<UInt> && 0 < NumBits && 0 < Precision)
bool Mathematics::IeeeBinary<Float, UInt, NumBits, Precision>::IsSignalingNaN() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto trailing = GetTrailing();

    return GetBiased() == maxBiasedExponent && (trailing & nanQuietMask) == 0 && (trailing & nanPayloadMask) != 0;
}

template <typename Float, typename UInt, int NumBits, int Precision>
requires(std::is_arithmetic_v<Float> && std::is_integral_v<UInt> && 0 < NumBits && 0 < Precision)
typename Mathematics::IeeeBinary<Float, UInt, NumBits, Precision>::UIntType Mathematics::IeeeBinary<Float, UInt, NumBits, Precision>::GetNextUp() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    UIntType sign{};
    UIntType biased{};
    UIntType trailing{};
    GetEncoding(sign, biased, trailing);

    if (biased == 0)
    {
        if (trailing == 0)
        {
            /// -0和+0的下一个值是minSubnormal。
            return minSubnormal;
        }
        else
        {
            if (sign != 0)
            {
                /// 当尾随为1时，'this'为-minSubnormal，下一个向上为-0。
                --trailing;
                return signMask | trailing;
            }
            else
            {
                /// 当trailing是maxTrailing时，'this'是maxSubnormal，下一个是minNormal。
                ++trailing;
                return trailing;
            }
        }
    }
    else if (biased < maxBiasedExponent)
    {
        auto nonnegative = (encoding & notSignMask);
        if (sign != 0)
        {
            --nonnegative;
            return gsl::narrow_cast<UIntType>(signMask | nonnegative);
        }
        else
        {
            ++nonnegative;
            return gsl::narrow_cast<UIntType>(nonnegative);
        }
    }
    else if (trailing == 0)
    {
        if (sign != 0)
        {
            /// -INFINITY的下一个值是-maxNormal。
            return signMask | maxNormal;
        }
        else
        {
            /// +INFINITY的下一个值是+INFINITY。
            return posInfinity;
        }
    }
    else if (trailing & nanQuietMask)
    {
        /// 该数字是一个quiet NAN，可能带有有效载荷。
        /// 只需返回数字本身。
        return encoding;
    }
    else
    {
        /// 该数字是一个signaling NAN，可能带有有效载荷。
        /// 只需返回数字本身。
        return encoding;
    }
}

template <typename Float, typename UInt, int NumBits, int Precision>
requires(std::is_arithmetic_v<Float> && std::is_integral_v<UInt> && 0 < NumBits && 0 < Precision)
typename Mathematics::IeeeBinary<Float, UInt, NumBits, Precision>::UIntType Mathematics::IeeeBinary<Float, UInt, NumBits, Precision>::GetNextDown() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    UIntType sign{};
    UIntType biased{};
    UIntType trailing{};
    GetEncoding(sign, biased, trailing);

    if (biased == 0)
    {
        if (trailing == 0)
        {
            /// -0和+0的下一个向下值是-minSubnormal。
            return signMask | minSubnormal;
        }
        else
        {
            if (sign == 0)
            {
                /// 当拖尾为1时，'this'为minSubnormal，下一个为+0。
                --trailing;
                return trailing;
            }
            else
            {
                /// 当trailing为maxTrailing时， 'this'为-maxSubnormal，下一个为-minNormal。
                ++trailing;
                return signMask | trailing;
            }
        }
    }
    else if (biased < maxBiasedExponent)
    {
        UInt nonnegative = (encoding & notSignMask);
        if (sign == 0)
        {
            --nonnegative;
            return nonnegative;
        }
        else
        {
            ++nonnegative;
            return signMask | nonnegative;
        }
    }
    else if (trailing == 0)
    {
        if (sign == 0)
        {
            /// +INFINITY的下一个向下值是+maxNormal。
            return maxNormal;
        }
        else
        {
            /// -INFINITY的下一个向下值是-INFINITY。
            return negInfinity;
        }
    }
    else if (trailing & nanQuietMask)
    {
        /// 该数字是一个quiet NAN，可能带有有效载荷。
        /// 只需返回数字本身。
        return encoding;
    }
    else
    {
        /// 该数字是一个signaling NAN，可能带有有效载荷。
        /// 只需返回数字本身。
        return encoding;
    }
}

template <typename Float, typename UInt, int NumBits, int Precision>
requires(std::is_arithmetic_v<Float> && std::is_integral_v<UInt> && 0 < NumBits && 0 < Precision)
typename Mathematics::IeeeBinary<Float, UInt, NumBits, Precision>::UIntType Mathematics::IeeeBinary<Float, UInt, NumBits, Precision>::GetSign() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return (encoding & signMask) >> signShift;
}

template <typename Float, typename UInt, int NumBits, int Precision>
requires(std::is_arithmetic_v<Float> && std::is_integral_v<UInt> && 0 < NumBits && 0 < Precision)
typename Mathematics::IeeeBinary<Float, UInt, NumBits, Precision>::UIntType Mathematics::IeeeBinary<Float, UInt, NumBits, Precision>::GetBiased() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return (encoding & exponentMask) >> numTrailingBits;
}

template <typename Float, typename UInt, int NumBits, int Precision>
requires(std::is_arithmetic_v<Float> && std::is_integral_v<UInt> && 0 < NumBits && 0 < Precision)
typename Mathematics::IeeeBinary<Float, UInt, NumBits, Precision>::UIntType Mathematics::IeeeBinary<Float, UInt, NumBits, Precision>::GetTrailing() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return encoding & trailingMask;
}

template <typename Float, typename UInt, int NumBits, int Precision>
requires(std::is_arithmetic_v<Float> && std::is_integral_v<UInt> && 0 < NumBits && 0 < Precision)
void Mathematics::IeeeBinary<Float, UInt, NumBits, Precision>::SetEncoding(UInt sign, UInt biased, UInt trailing) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    encoding = (sign << signShift) | (biased << numTrailingBits) | trailing;
}

template <typename Float, typename UInt, int NumBits, int Precision>
requires(std::is_arithmetic_v<Float> && std::is_integral_v<UInt> && 0 < NumBits && 0 < Precision)
void Mathematics::IeeeBinary<Float, UInt, NumBits, Precision>::GetEncoding(UInt& sign, UInt& biased, UInt& trailing) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    sign = GetSign();
    biased = GetBiased();
    trailing = GetTrailing();
}

#endif  // MATHEMATICS_RATIONAL_IEEE_BINARY_ACHIEVE_H
