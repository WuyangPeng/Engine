/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/05 13:47)

#ifndef MATHEMATICS_RATIONAL_IEEE_BINARY_16_H
#define MATHEMATICS_RATIONAL_IEEE_BINARY_16_H

#include "Mathematics/MathematicsDll.h"

#include "IeeeBinary.h"

namespace Mathematics
{
    class MATHEMATICS_DEFAULT_DECLARE IeeeBinary16 final : public IeeeBinary<int16_t, uint16_t, 16, 11>
    {
    public:
        using ClassType = IeeeBinary16;
        using ParentType = IeeeBinary<int16_t, uint16_t, 16, 11>;

    public:
        IeeeBinary16() noexcept;

        explicit IeeeBinary16(float number) noexcept;
        explicit IeeeBinary16(double number) noexcept;
        explicit IeeeBinary16(uint16_t encoding) noexcept;

        CLASS_INVARIANT_DECLARE;

        /// 隐式转换。
        NODISCARD explicit operator float() const;
        NODISCARD explicit operator double() const;

        /// 算术运算（高精度）。
        NODISCARD IeeeBinary16 operator-() const noexcept;

        /// 算术更新。
        IeeeBinary16& operator+=(const IeeeBinary16& rhs);
        IeeeBinary16& operator-=(const IeeeBinary16& rhs);
        IeeeBinary16& operator*=(const IeeeBinary16& rhs);
        IeeeBinary16& operator/=(const IeeeBinary16& rhs);
        IeeeBinary16& operator+=(float rhs);
        IeeeBinary16& operator-=(float rhs);
        IeeeBinary16& operator*=(float rhs);
        IeeeBinary16& operator/=(float rhs);

    private:
        using UnionType = union
        {
            float n;
            uint32_t e;
        };

        using ConversionsUnionType = union
        {
            uint32_t e;
            float n;
        };

    private:
        /// 基类IEEEBinary<int16_t, uint16_t, 16, 11>的成员。
        ///
        /// numEncodingBits = 16
        /// numExponentBits = 5
        /// numSignificandBits = 11
        /// numTrailingBits = 10
        /// exponentBias = 15
        /// maxBiasedExponent = 31
        /// minSubExponent = -14
        /// minExponent = -24
        /// signShift = 15
        /// signMask = 0x8000
        /// notSignMask = 0x7FFF
        /// trailingMask = 0x03FF
        /// exponentMask = 0x7C00
        /// nanQuietMask = 0x0200
        /// nanPayloadMask = 0x01ff
        /// maxTrailing = 0x03ff
        /// supTrailing = 0x0400
        /// posZero = 0x0000
        /// negZero = 0x8000
        /// minSubnormal = 0x0001
        /// maxSubnormal = 0x03ff
        /// minNormal = 0x0400
        /// maxNormal = 0x7bff
        /// posInfinity = 0x7c00
        /// negInfinity = 0xfc00

        /// 支持16位和32位数字之间的转换。
        using F16 = IeeeBinary16;
        using F32 = IeeeBinary32;

        /// 将“连续16位数字行”上的特殊数字编码为32位浮点数字。
        static constexpr auto f16AvrMinSubZer = 0x33000000;  // 2^{-25}
        static constexpr auto f16MinSub = 0x33800000;  // 2^{-24}
        static constexpr auto f16MinNor = 0x38800000;  // 2^{-14}
        static constexpr auto f16MaxNor = 0x477FE000;  // 2^{16)*(1-2^{-11})
        static constexpr auto f16AvrMaxNorInf = 0x477FF000;  // 2^{16)*(1-2^{-12})

        /// 在16位和32位数字的符号之间转换时要偏移的量。
        static constexpr auto conversionSignShift = F32::numEncodingBits - F16::numEncodingBits;

        /// 在16位和32位数字的尾随有效位之间转换时要移位的量。
        static constexpr auto conversionTrailingShift = F32::numSignificandBits - F16::numSignificandBits;

        /// 四舍五入的一半值与偶数相等。
        /// 舍入中的小数部分向左移动，使前导位为32位无符号整数的高阶位。
        static constexpr auto fractionHalf = F32::signMask;

        static uint16_t Convert32To16(uint32_t inEncoding) noexcept;
        static uint32_t Convert16To32(uint16_t inEncoding);
    };

    NODISCARD bool MATHEMATICS_DEFAULT_DECLARE operator==(const IeeeBinary16& lhs, const IeeeBinary16& rhs);
    NODISCARD bool MATHEMATICS_DEFAULT_DECLARE operator!=(const IeeeBinary16& lhs, const IeeeBinary16& rhs);
    NODISCARD bool MATHEMATICS_DEFAULT_DECLARE operator<(const IeeeBinary16& lhs, const IeeeBinary16& rhs);
    NODISCARD bool MATHEMATICS_DEFAULT_DECLARE operator<=(const IeeeBinary16& lhs, const IeeeBinary16& rhs);
    NODISCARD bool MATHEMATICS_DEFAULT_DECLARE operator>(const IeeeBinary16& lhs, const IeeeBinary16& rhs);
    NODISCARD bool MATHEMATICS_DEFAULT_DECLARE operator>=(const IeeeBinary16& lhs, const IeeeBinary16& rhs);

    NODISCARD float MATHEMATICS_DEFAULT_DECLARE operator+(const IeeeBinary16& lhs, const IeeeBinary16& rhs);
    NODISCARD float MATHEMATICS_DEFAULT_DECLARE operator-(const IeeeBinary16& lhs, const IeeeBinary16& rhs);
    NODISCARD float MATHEMATICS_DEFAULT_DECLARE operator*(const IeeeBinary16& lhs, const IeeeBinary16& rhs);
    NODISCARD float MATHEMATICS_DEFAULT_DECLARE operator/(const IeeeBinary16& lhs, const IeeeBinary16& rhs);

    NODISCARD float MATHEMATICS_DEFAULT_DECLARE operator+(const IeeeBinary16& lhs, float rhs);
    NODISCARD float MATHEMATICS_DEFAULT_DECLARE operator-(const IeeeBinary16& lhs, float rhs);
    NODISCARD float MATHEMATICS_DEFAULT_DECLARE operator*(const IeeeBinary16& lhs, float rhs);
    NODISCARD float MATHEMATICS_DEFAULT_DECLARE operator/(const IeeeBinary16& lhs, float rhs);

    NODISCARD float MATHEMATICS_DEFAULT_DECLARE operator+(float lhs, const IeeeBinary16& rhs);
    NODISCARD float MATHEMATICS_DEFAULT_DECLARE operator-(float lhs, const IeeeBinary16& rhs);
    NODISCARD float MATHEMATICS_DEFAULT_DECLARE operator*(float lhs, const IeeeBinary16& rhs);
    NODISCARD float MATHEMATICS_DEFAULT_DECLARE operator/(float lhs, const IeeeBinary16& rhs);

    NODISCARD IeeeBinary16 MATHEMATICS_DEFAULT_DECLARE AtanDivPi(const IeeeBinary16& x);
    NODISCARD IeeeBinary16 MATHEMATICS_DEFAULT_DECLARE Atan2DivPi(const IeeeBinary16& y, const IeeeBinary16& x);
    NODISCARD IeeeBinary16 MATHEMATICS_DEFAULT_DECLARE Clamp(const IeeeBinary16& x, const IeeeBinary16& xMin, const IeeeBinary16& xMax);
    NODISCARD IeeeBinary16 MATHEMATICS_DEFAULT_DECLARE CosPi(const IeeeBinary16& x);
    NODISCARD IeeeBinary16 MATHEMATICS_DEFAULT_DECLARE Exp10(const IeeeBinary16& x);
    NODISCARD IeeeBinary16 MATHEMATICS_DEFAULT_DECLARE InvSqrt(const IeeeBinary16& x);
    NODISCARD int MATHEMATICS_DEFAULT_DECLARE SignToInt(const IeeeBinary16& x);
    NODISCARD IeeeBinary16 MATHEMATICS_DEFAULT_DECLARE Saturate(const IeeeBinary16& x);
    NODISCARD IeeeBinary16 MATHEMATICS_DEFAULT_DECLARE Sign(const IeeeBinary16& x);
    NODISCARD IeeeBinary16 MATHEMATICS_DEFAULT_DECLARE SinPi(const IeeeBinary16& x);
    NODISCARD IeeeBinary16 MATHEMATICS_DEFAULT_DECLARE Sqr(const IeeeBinary16& x);

    NODISCARD IeeeBinary16 MATHEMATICS_DEFAULT_DECLARE Acos(const IeeeBinary16& x);
    NODISCARD IeeeBinary16 MATHEMATICS_DEFAULT_DECLARE Acosh(const IeeeBinary16& x);
    NODISCARD IeeeBinary16 MATHEMATICS_DEFAULT_DECLARE Asin(const IeeeBinary16& x);
    NODISCARD IeeeBinary16 MATHEMATICS_DEFAULT_DECLARE Asinh(const IeeeBinary16& x);
    NODISCARD IeeeBinary16 MATHEMATICS_DEFAULT_DECLARE Atan(const IeeeBinary16& x);
    NODISCARD IeeeBinary16 MATHEMATICS_DEFAULT_DECLARE Atanh(const IeeeBinary16& x);
    NODISCARD IeeeBinary16 MATHEMATICS_DEFAULT_DECLARE Atan2(const IeeeBinary16& y, const IeeeBinary16& x);
    NODISCARD IeeeBinary16 MATHEMATICS_DEFAULT_DECLARE Ceil(const IeeeBinary16& x);
    NODISCARD IeeeBinary16 MATHEMATICS_DEFAULT_DECLARE Cos(const IeeeBinary16& x);
    NODISCARD IeeeBinary16 MATHEMATICS_DEFAULT_DECLARE Cosh(const IeeeBinary16& x);
    NODISCARD IeeeBinary16 MATHEMATICS_DEFAULT_DECLARE Exp(const IeeeBinary16& x);
    NODISCARD IeeeBinary16 MATHEMATICS_DEFAULT_DECLARE Exp2(const IeeeBinary16& x);
    NODISCARD IeeeBinary16 MATHEMATICS_DEFAULT_DECLARE Fabs(const IeeeBinary16& x);
    NODISCARD IeeeBinary16 MATHEMATICS_DEFAULT_DECLARE Floor(const IeeeBinary16& x);
    NODISCARD IeeeBinary16 MATHEMATICS_DEFAULT_DECLARE Fmod(const IeeeBinary16& x, const IeeeBinary16& y);
    NODISCARD IeeeBinary16 MATHEMATICS_DEFAULT_DECLARE Frexp(const IeeeBinary16& x, int32_t* exponent);
    NODISCARD IeeeBinary16 MATHEMATICS_DEFAULT_DECLARE Ldexp(const IeeeBinary16& x, int32_t exponent);
    NODISCARD IeeeBinary16 MATHEMATICS_DEFAULT_DECLARE Log(const IeeeBinary16& x);
    NODISCARD IeeeBinary16 MATHEMATICS_DEFAULT_DECLARE Log2(const IeeeBinary16& x);
    NODISCARD IeeeBinary16 MATHEMATICS_DEFAULT_DECLARE Log10(const IeeeBinary16& x);
    NODISCARD IeeeBinary16 MATHEMATICS_DEFAULT_DECLARE Pow(const IeeeBinary16& x, const IeeeBinary16& y);
    NODISCARD IeeeBinary16 MATHEMATICS_DEFAULT_DECLARE Sin(const IeeeBinary16& x);
    NODISCARD IeeeBinary16 MATHEMATICS_DEFAULT_DECLARE Sinh(const IeeeBinary16& x);
    NODISCARD IeeeBinary16 MATHEMATICS_DEFAULT_DECLARE Sqrt(const IeeeBinary16& x);
    NODISCARD IeeeBinary16 MATHEMATICS_DEFAULT_DECLARE Tan(const IeeeBinary16& x);
    NODISCARD IeeeBinary16 MATHEMATICS_DEFAULT_DECLARE Tanh(const IeeeBinary16& x);
}

#endif  // MATHEMATICS_RATIONAL_IEEE_BINARY_16_H
