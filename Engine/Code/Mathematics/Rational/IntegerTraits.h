///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/08 16:07)

#ifndef MATHEMATICS_RATIONAL_INTEGER_TRAITS_H
#define MATHEMATICS_RATIONAL_INTEGER_TRAITS_H

#include "Mathematics/MathematicsDll.h"

namespace Mathematics
{
    struct SignedIntegerType
    {
    };

    struct UnsignedIntegerType
    {
    };

    struct FloatType
    {
        using IntegerType = uint32_t;
        static constexpr IntegerType symbol{ 0x80000000 };
        static constexpr auto symbolShifting = 31u;
        static constexpr IntegerType exponent{ 0x7F800000 };
        static constexpr auto exponentShifting = 23u;
        static constexpr auto realExponentDifference = 0x7Fu;
        static constexpr IntegerType mantissa{ 0x007FFFFF };
        static constexpr IntegerType quietNaN{ 0x00400000 };
        static constexpr auto exponentDigits = symbolShifting - exponentShifting;

        static_assert(symbol + exponent + mantissa == 0xFFFFFFFF, "symbol + exponent + mantissa != 0xFFFFFFFF");
    };

    struct DoubleType
    {
        using IntegerType = uint64_t;
        static constexpr IntegerType symbol{ 0x8000000000000000ULL };
        static constexpr auto symbolShifting = 63u;
        static constexpr IntegerType exponent{ 0x7FF0000000000000ULL };
        static constexpr auto exponentShifting = 52u;
        static constexpr auto realExponentDifference = 0x3FFu;
        static constexpr IntegerType mantissa{ 0x000FFFFFFFFFFFFFULL };
        static constexpr IntegerType quietNaN{ 0x0008000000000000ULL };
        static constexpr auto exponentDigits = symbolShifting - exponentShifting;

        static_assert(symbol + exponent + mantissa == (0xFFFFFFFFFFFFFFFFULL), "symbol + exponent + mantissa != (0xFFFFFFFFFFFFFFFFULL)");
    };

    template <typename T>
    struct IntegerTraits;

    template <>
    struct IntegerTraits<int8_t>
    {
        using TraitsType = SignedIntegerType;
    };

    template <>
    struct IntegerTraits<int16_t>
    {
        using TraitsType = SignedIntegerType;
    };

    template <>
    struct IntegerTraits<int32_t>
    {
        using TraitsType = SignedIntegerType;
    };

    template <>
    struct IntegerTraits<int64_t>
    {
        using TraitsType = SignedIntegerType;
    };

    template <>
    struct IntegerTraits<uint8_t>
    {
        using TraitsType = UnsignedIntegerType;
    };

    template <>
    struct IntegerTraits<uint16_t>
    {
        using TraitsType = UnsignedIntegerType;
    };

    template <>
    struct IntegerTraits<uint32_t>
    {
        using TraitsType = UnsignedIntegerType;
    };

    template <>
    struct IntegerTraits<uint64_t>
    {
        using TraitsType = UnsignedIntegerType;
    };

    template <>
    struct IntegerTraits<float>
    {
        using TraitsType = FloatType;
    };

    template <>
    struct IntegerTraits<double>
    {
        using TraitsType = DoubleType;
    };
}

#endif  // MATHEMATICS_RATIONAL_INTEGER_DATA_H
