/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/05 13:47)

#ifndef MATHEMATICS_RATIONAL_IEEE_BINARY_H
#define MATHEMATICS_RATIONAL_IEEE_BINARY_H

#include "Mathematics/MathematicsDll.h"

#include "RationalFwd.h"

namespace Mathematics
{
    template <typename Float, typename UInt, int NumBits, int Precision>
    requires(std::is_arithmetic_v<Float> && std::is_integral_v<UInt> && 0 < NumBits && 0 < Precision)
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE IeeeBinary
    {
    public:
        using ClassType = IeeeBinary<Float, UInt, NumBits, Precision>;

        /// 用于模板类型的通用访问。
        using FloatType = Float;
        using UIntType = UInt;

    public:
        IeeeBinary() noexcept;
        virtual ~IeeeBinary() noexcept = default;
        IeeeBinary(const IeeeBinary& rhs) noexcept = default;
        IeeeBinary& operator=(const IeeeBinary& rhs) noexcept = default;
        IeeeBinary(IeeeBinary&& rhs) noexcept = default;
        IeeeBinary& operator=(IeeeBinary&& rhs) noexcept = default;

        explicit IeeeBinary(UIntType encoding) noexcept;
        explicit IeeeBinary(UIntType sign, UIntType biased, UIntType trailing) noexcept;
        explicit IeeeBinary(FloatType number) noexcept;

        CLASS_INVARIANT_DECLARE;

        /// 隐式转换为整数类型或浮点类型。
        NODISCARD explicit operator UIntType() const noexcept;
        NODISCARD explicit operator FloatType() const noexcept;

        NODISCARD UIntType GetEncoding() const noexcept;
        NODISCARD FloatType GetNumber() const noexcept;

        void SetEncoding(UIntType aEncoding) noexcept;
        void SetNumber(FloatType aNumber) noexcept;

        /// 特殊常数。
        static constexpr auto numEncodingBits = NumBits;
        static constexpr auto numExponentBits = NumBits - Precision;
        static constexpr auto numSignificandBits = Precision;
        static constexpr auto numTrailingBits = Precision - 1;
        static constexpr auto exponentBias = (1 << (numExponentBits - 1)) - 1;
        static constexpr auto maxBiasedExponent = (1 << numExponentBits) - 1;
        static constexpr auto minSubExponent = 1 - exponentBias;
        static constexpr auto minExponent = minSubExponent - numTrailingBits;
        static constexpr auto signShift = NumBits - 1;

        static constexpr auto signMask = (UIntType{ 1 } << (NumBits - 1));
        static constexpr auto notSignMask = static_cast<UIntType>(~signMask);
        static constexpr auto trailingMask = (UIntType{ 1 } << numTrailingBits) - 1;
        static constexpr auto exponentMask = notSignMask & ~trailingMask;
        static constexpr auto nanQuietMask = (UIntType{ 1 } << (numTrailingBits - 1));
        static constexpr auto nanPayloadMask = (trailingMask >> 1);
        static constexpr auto maxTrailing = trailingMask;
        static constexpr auto supTrailing = (UIntType{ 1 } << numTrailingBits);
        static constexpr auto posZero = UIntType{ 0 };
        static constexpr auto negZero = signMask;
        static constexpr auto minSubnormal = UIntType{ 1 };
        static constexpr auto maxSubnormal = trailingMask;
        static constexpr auto minNormal = supTrailing;
        static constexpr auto maxNormal = static_cast<UIntType>(notSignMask & ~supTrailing);
        static constexpr auto posInfinity = exponentMask;
        static constexpr auto negInfinity = static_cast<UIntType>(signMask | exponentMask);

        NODISCARD Classification GetClassification() const noexcept;
        NODISCARD bool IsZero() const noexcept;
        NODISCARD bool IsSignMinus() const noexcept;
        NODISCARD bool IsSubnormal() const noexcept;
        NODISCARD bool IsNormal() const noexcept;
        NODISCARD bool IsFinite() const noexcept;
        NODISCARD bool IsInfinite() const noexcept;
        NODISCARD bool IsNaN() const noexcept;
        NODISCARD bool IsQuietNaN() const noexcept;
        NODISCARD bool IsSignalingNaN() const noexcept;

        /// 获取相邻号码。
        NODISCARD UIntType GetNextUp() const noexcept;
        NODISCARD UIntType GetNextDown() const noexcept;

        /// 对二进制表示进行编码和解码。
        /// 符号为0（数字为非负）或1（数字为负）。
        /// 带偏指数在[0，maxBiasedExponent]范围内。
        /// 尾部有效位在[0，maxTrailing]范围内。
        NODISCARD UIntType GetSign() const noexcept;
        NODISCARD UIntType GetBiased() const noexcept;
        NODISCARD UIntType GetTrailing() const noexcept;

        void SetEncoding(UIntType sign, UIntType biased, UIntType trailing) noexcept;
        void GetEncoding(UIntType& sign, UIntType& biased, UIntType& trailing) const noexcept;

    private:
        /// 用于直接操作对象的访问权限。
        union
        {
            UIntType encoding;
            FloatType number;
        };
    };

    using IeeeBinary32 = IeeeBinary<float, uint32_t, 32, 24>;
    /// numEncodingBits = 32
    /// numExponentBits = 8
    /// numSignificandBits = 24
    /// numTrailingBits = 23
    /// exponentBias = 127
    /// maxBiasedExponent = 255
    /// minSubExponent = -126
    /// minExponent = -149
    /// signShift = 31
    /// signMask = 0x80000000
    /// notSignMask = 0x7FFFFFFF
    /// trailingMask = 0x007FFFFF
    /// exponentMask = 0x7F800000
    /// nanQuietMask = 0x00400000
    /// nanPayloadMask = 0x003FFFFF
    /// maxTrailing = 0x007FFFFF
    /// supTrailing = 0x00800000
    /// PosZero = 0x00000000
    /// NegZero = 0x80000000
    /// minSubnormal = 0x00000001
    /// maxSubnormal = 0x007FFFFF
    /// minNormal = 0x00800000
    /// maxNormal = 0x7F7FFFFF
    /// PosInfinity = 0x7F800000
    /// NegInfinity = 0xFF800000

    using IeeeBinary64 = IeeeBinary<double, uint64_t, 64, 53>;
    /// numEncodingBits = 64
    /// numExponentBits = 11
    /// numSignificandBits = 53
    /// numTrailingBits = 52
    /// exponentBias = 1023
    /// maxBiasedExponent = 2047
    /// minSubExponent = -1022
    /// minExponent = -1074
    /// signShift = 63
    /// signMask = 0x8000000000000000
    /// notSignMask = 0x7FFFFFFFFFFFFFFF
    /// trailingMask = 0x000FFFFFFFFFFFFF
    /// exponentMask = 0x7FF0000000000000
    /// nanQuietMask = 0x0008000000000000
    /// nanPayloadMask = 0x0007FFFFFFFFFFFF
    /// maxTrailing = 0x000FFFFFFFFFFFFF
    /// supTrailing = 0x0010000000000000
    /// PosZero = 0x0000000000000000
    /// NegZero = 0x8000000000000000
    /// minSubnormal = 0x0000000000000001
    /// maxSubnormal = 0x000FFFFFFFFFFFFF
    /// minNormal = 0x0010000000000000
    /// maxNormal = 0x7FEFFFFFFFFFFFFF
    /// PosInfinity = 0x7FF0000000000000
    /// NegInfinity = 0xFFF0000000000000
}

#endif  // MATHEMATICS_RATIONAL_IEEE_BINARY_H
