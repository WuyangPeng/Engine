/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/05 14:15)

#include "Mathematics/MathematicsExport.h"

#include "IeeeBinary16.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/BitHacks.h"
#include "Mathematics/Base/Functions.h"

#include <gsl/util>
#include <cmath>

Mathematics::IeeeBinary16::IeeeBinary16() noexcept
    : ParentType{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

Mathematics::IeeeBinary16::IeeeBinary16(float number) noexcept
    : ParentType{ Convert32To16(UnionType{ number }.e) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

Mathematics::IeeeBinary16::IeeeBinary16(double number) noexcept
    : ParentType{ Convert32To16(UnionType{ static_cast<float>(number) }.e) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

Mathematics::IeeeBinary16::IeeeBinary16(uint16_t encoding) noexcept
    : ParentType{ encoding }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, IeeeBinary16)

Mathematics::IeeeBinary16::operator float() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return ConversionsUnionType{ Convert16To32(GetEncoding()) }.n;
}

Mathematics::IeeeBinary16::operator double() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return ConversionsUnionType{ Convert16To32(GetEncoding()) }.n;
}

Mathematics::IeeeBinary16 Mathematics::IeeeBinary16::operator-() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return IeeeBinary16{ gsl::narrow_cast<uint16_t>(GetEncoding() ^ signMask) };
}

Mathematics::IeeeBinary16& Mathematics::IeeeBinary16::operator+=(const IeeeBinary16& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    *this = IeeeBinary16{ static_cast<float>(*this) + static_cast<float>(rhs) };

    return *this;
}

Mathematics::IeeeBinary16& Mathematics::IeeeBinary16::operator-=(const IeeeBinary16& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    *this = IeeeBinary16{ static_cast<float>(*this) - static_cast<float>(rhs) };

    return *this;
}

Mathematics::IeeeBinary16& Mathematics::IeeeBinary16::operator*=(const IeeeBinary16& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    *this = IeeeBinary16{ static_cast<float>(*this) * static_cast<float>(rhs) };

    return *this;
}

Mathematics::IeeeBinary16& Mathematics::IeeeBinary16::operator/=(const IeeeBinary16& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    *this = IeeeBinary16{ static_cast<float>(*this) / static_cast<float>(rhs) };

    return *this;
}

Mathematics::IeeeBinary16& Mathematics::IeeeBinary16::operator+=(float rhs)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    *this = IeeeBinary16{ static_cast<float>(*this) + rhs };

    return *this;
}

Mathematics::IeeeBinary16& Mathematics::IeeeBinary16::operator-=(float rhs)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    *this = IeeeBinary16{ static_cast<float>(*this) - rhs };

    return *this;
}

Mathematics::IeeeBinary16& Mathematics::IeeeBinary16::operator*=(float rhs)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    *this = IeeeBinary16{ static_cast<float>(*this) * rhs };

    return *this;
}

Mathematics::IeeeBinary16& Mathematics::IeeeBinary16::operator/=(float rhs)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    *this = IeeeBinary16{ static_cast<float>(*this) / rhs };

    return *this;
}

uint16_t Mathematics::IeeeBinary16::Convert32To16(uint32_t inEncoding) noexcept
{
    /// 在该函数的注释中，
    /// x表示inEncoding对应的32位浮点数，
    /// y表示x转换为的16位浮点数。

    /// 提取x的通道。
    const auto sign32 = (inEncoding & F32::signMask);
    const auto biased32 = ((inEncoding & F32::exponentMask) >> F32::numTrailingBits);
    auto trailing32 = (inEncoding & F32::trailingMask);
    const auto nonNeg32 = (inEncoding & F32::notSignMask);

    /// 为y生成通道。
    const auto sign16 = gsl::narrow_cast<uint16_t>(sign32 >> conversionSignShift);

    if (biased32 == 0)
    {
        /// x为零或低于标准32，最接近的y为零。
        return sign16;
    }

    if (biased32 < F32::maxBiasedExponent)
    {
        /// x为32正常值。
        if (nonNeg32 <= f16AvrMinSubZer)
        {
            /// x <= 2^{-25}, 最接近的y为零。
            return sign16;
        }

        if (nonNeg32 <= f16MinSub)
        {
            /// 2^{-25} < x <= 2^{-24}, 最近的y比正常值低16分钟。
            return sign16 | F16::minSubnormal;
        }

        if (nonNeg32 < f16MinNor)
        {
            /// 2^{-24} < x < 2^{-14},
            /// 使用四舍五入到偶数的关系计算最近的16位次正规y。
            ///
            /// y = 0.s9 ... s0 * 2^{14}
            /// x = 1.t22 ... t0 * 2^e, where -24 <= e <= -15
            ///   = (0.1 t22 ... t0 * 2^{e+15}) * 2^{-14}
            ///   = (0.1 t22 ... t0 * 2^p) * 2^{-14}
            /// 这里 p = e+15 with -9 = p <= 0.
            /// 项(0.1 t22 ... t0 * 2^p)必须四舍五入到0.s9 ... s0 * 2^{-14}。
            const auto p = gsl::narrow_cast<int32_t>(biased32) - F32::exponentBias + F16::exponentBias;

            /// x是32个正常值，
            /// 因此有一个隐含的1位必须首先附加到32个尾随有效位，
            /// 再附加到16个次正常值y的16尾随有效位所需的位。
            /// 得到的数字是000000001 t22 ... t0。
            trailing32 |= F32::supTrailing;

            /// 获取整数部分。
            const auto rShift = gsl::narrow_cast<uint32_t>(-F16::minSubExponent - p);
            auto trailing16 = gsl::narrow_cast<uint16_t>(trailing32 >> rShift);

            /// 得到分数部分。
            const auto lShift = gsl::narrow_cast<uint32_t>(F32::numEncodingBits + F16::minSubExponent + p);

            /// 四舍五入，领带至偶数。
            if (const auto frcPart = (trailing32 << lShift);
                fractionHalf < frcPart || (frcPart == fractionHalf && (trailing16 & 1)))
            {
                /// 如果指数中有进位，最接近的实际上是16分钟正常1.0*2^{-14}，
                /// 因此trailing16的高阶位使biased16等于1，结果是正确的。
                ++trailing16;
            }
            return sign16 | trailing16;
        }

        if (nonNeg32 <= f16MaxNor)
        {
            /// 2^{-14} <= x <= 1.1111111111*2^{15},
            /// 使用四舍五入到偶数的关系计算最近的16位次正规y。

            /// x和y的指数是相同的，尽管由于指数偏置参数的不同，偏置指数不同。
            const auto e = gsl::narrow_cast<int32_t>(biased32) - F32::exponentBias;
            auto biased16 = gsl::narrow_cast<uint16_t>(e + F16::exponentBias);
            biased16 = (biased16 << F16::numTrailingBits);

            /// 设x = 1.t22...t0 * 2^e和y = 1.s9...s0 * 2^e。
            /// x和y都有一个隐含的前导1位（都是正常的），所以我们可以忽略它。
            /// 数字0.t22...t0 必须四舍五入到数字0.s9...s0。

            /// 获取整数部分。
            auto trailing16 = gsl::narrow_cast<uint16_t>(trailing32 >> conversionTrailingShift);

            /// 得到分数部分。
            constexpr auto lShift = gsl::narrow_cast<uint32_t>(F32::numEncodingBits + F16::minSubExponent + 1);

            /// 四舍五入，领带至偶数。
            if (const auto frcPart = (trailing32 << lShift);
                fractionHalf < frcPart || (frcPart == fractionHalf && (trailing16 & 1)))
            {
                /// 如果指数中有进位，则偏置16（而不是或ing）的加法会产生正确的结果。
                ++trailing16;
            }
            return sign16 | (biased16 + trailing16);
        }

        if (nonNeg32 < f16AvrMaxNorInf)
        {
            /// 1.1111111111*2^{15} < x < (MAX_NORMAL+INFINITY)/2,
            /// 因此该数字最接近16最大正常值。
            return sign16 | F16::maxNormal;
        }

        /// nonneg32 >= (MAX_NORMAL+INFINITY)/2, 因此转换为16无穷大。
        return sign16 | F16::posInfinity;
    }

    if (trailing32 == 0)
    {
        /// 这个数字是32，无穷大。
        /// 转换为16无穷大。
        return sign16 | F16::posInfinity;
    }

    /// 这个数字是32 NaN。
    /// 将32个有效载荷的高阶9位转换为16个NaN和16个有效载荷。
    /// 在转换中复制32个quiet NaN掩码位。
    const auto maskPayload = gsl::narrow_cast<uint16_t>(trailing32 >> conversionTrailingShift);

    return sign16 | F16::exponentMask | maskPayload;
}

uint32_t Mathematics::IeeeBinary16::Convert16To32(uint16_t inEncoding)
{
    /// 提取IEEEBinary16编号的通道。
    const auto sign16 = (inEncoding & F16::signMask);
    const auto biased16 = ((inEncoding & F16::exponentMask) >> F16::numTrailingBits);
    const auto trailing16 = (inEncoding & F16::trailingMask);

    /// 生成二进制32编号的通道。
    const auto sign32 = gsl::narrow_cast<uint32_t>(sign16 << conversionSignShift);

    if (biased16 == 0)
    {
        if (trailing16 == 0)
        {
            /// 这个数字是16零。转换为32零。
            return sign32;
        }
        else
        {
            /// 这个数字比正常值低16。转换为32法线。
            auto trailing32 = gsl::narrow_cast<uint32_t>(trailing16);
            const auto leading = BitHacks::GetLeadingBit(trailing32);
            const auto shift = 23 - leading;
            const auto biased32 = gsl::narrow_cast<uint32_t>(F32::exponentBias - 1 - shift);
            trailing32 = (trailing32 << shift) & F32::trailingMask;
            return sign32 | (biased32 << F32::numTrailingBits) | trailing32;
        }
    }

    if (biased16 < F16::maxBiasedExponent)
    {
        /// 正常情况下，数字是16。转换为32法线。
        const auto biased32 = gsl::narrow_cast<uint32_t>(biased16 - F16::exponentBias + F32::exponentBias);
        const auto trailing32 = (gsl::narrow_cast<uint32_t>(trailing16) << conversionTrailingShift);
        return sign32 | (biased32 << F32::numTrailingBits) | trailing32;
    }

    if (trailing16 == 0)
    {
        /// 这个数字是16无穷大。转换为32无穷大。
        return sign32 | F32::exponentMask;
    }

    /// 这个数字是16 NaN。
    /// 转换为具有32个有效载荷的32个NaN，其高阶9位来自16个有效载荷。
    /// 在转换中复制16个安静的NaN掩码位。
    const auto maskPayload = (gsl::narrow_cast<uint32_t>(trailing16) << conversionTrailingShift);

    return sign32 | F32::exponentMask | maskPayload;
}

bool Mathematics::operator==(const IeeeBinary16& lhs, const IeeeBinary16& rhs)
{
    return static_cast<float>(lhs) == static_cast<float>(rhs);
}

bool Mathematics::operator!=(const IeeeBinary16& lhs, const IeeeBinary16& rhs)
{
    return !(lhs == rhs);
}

bool Mathematics::operator<(const IeeeBinary16& lhs, const IeeeBinary16& rhs)
{
    return static_cast<float>(lhs) < static_cast<float>(rhs);
}

bool Mathematics::operator<=(const IeeeBinary16& lhs, const IeeeBinary16& rhs)
{
    return !(rhs < lhs);
}

bool Mathematics::operator>(const IeeeBinary16& lhs, const IeeeBinary16& rhs)
{
    return rhs < lhs;
}

bool Mathematics::operator>=(const IeeeBinary16& lhs, const IeeeBinary16& rhs)
{
    return !(lhs < rhs);
}

float Mathematics::operator+(const IeeeBinary16& lhs, const IeeeBinary16& rhs)
{
    return static_cast<float>(lhs) + static_cast<float>(rhs);
}

float Mathematics::operator-(const IeeeBinary16& lhs, const IeeeBinary16& rhs)
{
    return static_cast<float>(lhs) - static_cast<float>(rhs);
}

float Mathematics::operator*(const IeeeBinary16& lhs, const IeeeBinary16& rhs)
{
    return static_cast<float>(lhs) * static_cast<float>(rhs);
}

float Mathematics::operator/(const IeeeBinary16& lhs, const IeeeBinary16& rhs)
{
    return static_cast<float>(lhs) / static_cast<float>(rhs);
}

float Mathematics::operator+(const IeeeBinary16& lhs, float rhs)
{
    return static_cast<float>(lhs) + rhs;
}

float Mathematics::operator-(const IeeeBinary16& lhs, float rhs)
{
    return static_cast<float>(lhs) - rhs;
}

float Mathematics::operator*(const IeeeBinary16& lhs, float rhs)
{
    return static_cast<float>(lhs) * rhs;
}

float Mathematics::operator/(const IeeeBinary16& lhs, float rhs)
{
    return static_cast<float>(lhs) / rhs;
}

float Mathematics::operator+(float lhs, const IeeeBinary16& rhs)
{
    return lhs + static_cast<float>(rhs);
}

float Mathematics::operator-(float lhs, const IeeeBinary16& rhs)
{
    return lhs - static_cast<float>(rhs);
}

float Mathematics::operator*(float lhs, const IeeeBinary16& rhs)
{
    return lhs * static_cast<float>(rhs);
}

float Mathematics::operator/(float lhs, const IeeeBinary16& rhs)
{
    return lhs / static_cast<float>(rhs);
}

Mathematics::IeeeBinary16 Mathematics::AtanDivPi(const IeeeBinary16& x)
{
    return IeeeBinary16{ AtanDivPi(static_cast<float>(x)) };
}

Mathematics::IeeeBinary16 Mathematics::Atan2DivPi(const IeeeBinary16& y, const IeeeBinary16& x)
{
    return IeeeBinary16{ Atan2DivPi(static_cast<float>(y), static_cast<float>(x)) };
}

Mathematics::IeeeBinary16 Mathematics::Clamp(const IeeeBinary16& x, const IeeeBinary16& xMin, const IeeeBinary16& xMax)
{
    return IeeeBinary16{ Clamp(static_cast<float>(x), static_cast<float>(xMin), static_cast<float>(xMax)) };
}

Mathematics::IeeeBinary16 Mathematics::CosPi(const IeeeBinary16& x)
{
    return IeeeBinary16{ CosPi(static_cast<float>(x)) };
}

Mathematics::IeeeBinary16 Mathematics::Exp10(const IeeeBinary16& x)
{
    return IeeeBinary16{ Exp10(static_cast<float>(x)) };
}

Mathematics::IeeeBinary16 Mathematics::InvSqrt(const IeeeBinary16& x)
{
    return IeeeBinary16{ InvSqrt(static_cast<float>(x)) };
}

int Mathematics::SignToInt(const IeeeBinary16& x)
{
    return SignToInt(static_cast<float>(x));
}

Mathematics::IeeeBinary16 Mathematics::Saturate(const IeeeBinary16& x)
{
    return IeeeBinary16{ Saturate(static_cast<float>(x)) };
}

Mathematics::IeeeBinary16 Mathematics::Sign(const IeeeBinary16& x)
{
    return IeeeBinary16{ Sign(static_cast<float>(x)) };
}

Mathematics::IeeeBinary16 Mathematics::SinPi(const IeeeBinary16& x)
{
    return IeeeBinary16{ SinPi(static_cast<float>(x)) };
}

Mathematics::IeeeBinary16 Mathematics::Sqr(const IeeeBinary16& x)
{
    return IeeeBinary16{ Sqr(static_cast<float>(x)) };
}

Mathematics::IeeeBinary16 Mathematics::Acos(const IeeeBinary16& x)
{
    return IeeeBinary16{ std::acos(static_cast<float>(x)) };
}

Mathematics::IeeeBinary16 Mathematics::Acosh(const IeeeBinary16& x)
{
    return IeeeBinary16{ std::acosh(static_cast<float>(x)) };
}

Mathematics::IeeeBinary16 Mathematics::Asin(const IeeeBinary16& x)
{
    return IeeeBinary16{ std::asin(static_cast<float>(x)) };
}

Mathematics::IeeeBinary16 Mathematics::Asinh(const IeeeBinary16& x)
{
    return IeeeBinary16{ std::asinh(static_cast<float>(x)) };
}

Mathematics::IeeeBinary16 Mathematics::Atan(const IeeeBinary16& x)
{
    return IeeeBinary16{ std::atan(static_cast<float>(x)) };
}

Mathematics::IeeeBinary16 Mathematics::Atanh(const IeeeBinary16& x)
{
    return IeeeBinary16{ std::atanh(static_cast<float>(x)) };
}

Mathematics::IeeeBinary16 Mathematics::Atan2(const IeeeBinary16& y, const IeeeBinary16& x)
{
    return IeeeBinary16{ std::atan2(static_cast<float>(y), static_cast<float>(x)) };
}

Mathematics::IeeeBinary16 Mathematics::Ceil(const IeeeBinary16& x)
{
    return IeeeBinary16{ std::ceil(static_cast<float>(x)) };
}

Mathematics::IeeeBinary16 Mathematics::Cos(const IeeeBinary16& x)
{
    return IeeeBinary16{ std::cos(static_cast<float>(x)) };
}

Mathematics::IeeeBinary16 Mathematics::Cosh(const IeeeBinary16& x)
{
    return IeeeBinary16{ std::cosh(static_cast<float>(x)) };
}

Mathematics::IeeeBinary16 Mathematics::Exp(const IeeeBinary16& x)
{
    return IeeeBinary16{ std::exp(static_cast<float>(x)) };
}

Mathematics::IeeeBinary16 Mathematics::Exp2(const IeeeBinary16& x)
{
    return IeeeBinary16{ std::exp2(static_cast<float>(x)) };
}

Mathematics::IeeeBinary16 Mathematics::Fabs(const IeeeBinary16& x)
{
    return IeeeBinary16{ std::fabs(static_cast<float>(x)) };
}

Mathematics::IeeeBinary16 Mathematics::Floor(const IeeeBinary16& x)
{
    return IeeeBinary16{ std::floor(static_cast<float>(x)) };
}

Mathematics::IeeeBinary16 Mathematics::Fmod(const IeeeBinary16& x, const IeeeBinary16& y)
{
    return IeeeBinary16{ std::fmod(static_cast<float>(x), static_cast<float>(y)) };
}

Mathematics::IeeeBinary16 Mathematics::Frexp(const IeeeBinary16& x, int32_t* exponent)
{
    return IeeeBinary16{ std::frexp(static_cast<float>(x), exponent) };
}

Mathematics::IeeeBinary16 Mathematics::Ldexp(const IeeeBinary16& x, int32_t exponent)
{
    return IeeeBinary16{ std::ldexp(static_cast<float>(x), exponent) };
}

Mathematics::IeeeBinary16 Mathematics::Log(const IeeeBinary16& x)
{
    return IeeeBinary16{ std::log(static_cast<float>(x)) };
}

Mathematics::IeeeBinary16 Mathematics::Log2(const IeeeBinary16& x)
{
    return IeeeBinary16{ std::log2(static_cast<float>(x)) };
}

Mathematics::IeeeBinary16 Mathematics::Log10(const IeeeBinary16& x)
{
    return IeeeBinary16{ std::log10(static_cast<float>(x)) };
}

Mathematics::IeeeBinary16 Mathematics::Pow(const IeeeBinary16& x, const IeeeBinary16& y)
{
    return IeeeBinary16{ std::pow(static_cast<float>(x), static_cast<float>(y)) };
}

Mathematics::IeeeBinary16 Mathematics::Sin(const IeeeBinary16& x)
{
    return IeeeBinary16{ std::sin(static_cast<float>(x)) };
}

Mathematics::IeeeBinary16 Mathematics::Sinh(const IeeeBinary16& x)
{
    return IeeeBinary16{ std::sinh(static_cast<float>(x)) };
}

Mathematics::IeeeBinary16 Mathematics::Sqrt(const IeeeBinary16& x)
{
    return IeeeBinary16{ std::sqrt(static_cast<float>(x)) };
}

Mathematics::IeeeBinary16 Mathematics::Tan(const IeeeBinary16& x)
{
    return IeeeBinary16{ std::tan(static_cast<float>(x)) };
}

Mathematics::IeeeBinary16 Mathematics::Tanh(const IeeeBinary16& x)
{
    return IeeeBinary16{ std::tanh(static_cast<float>(x)) };
}
