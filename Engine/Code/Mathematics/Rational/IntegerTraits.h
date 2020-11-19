///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/19 10:27)

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
        static constexpr IntegerType g_Symbol{ 0x80000000 };
        static constexpr auto g_SymbolShifting = 31u;
        static constexpr IntegerType g_Exponent{ 0x7F800000 };
        static constexpr auto g_ExponentShifting = 23u;
        static constexpr auto g_RealExponentDifference = 0x7Fu;
        static constexpr IntegerType g_Mantissa{ 0x007FFFFF };
        static constexpr IntegerType g_QuietNaN{ 0x00400000 };
        static constexpr auto g_ExponentDigits = g_SymbolShifting - g_ExponentShifting;

        static_assert(g_Symbol + g_Exponent + g_Mantissa == 0xFFFFFFFF, "g_Symbol + g_Exponent + g_Mantissa != 0xFFFFFFFF");
    };

    struct DoubleType
    {
        using IntegerType = uint64_t;
        static constexpr IntegerType g_Symbol{ 0x8000000000000000ULL };
        static constexpr auto g_SymbolShifting = 63u;
        static constexpr IntegerType g_Exponent{ 0x7FF0000000000000ULL };
        static constexpr auto g_ExponentShifting = 52u;
        static constexpr auto g_RealExponentDifference = 0x3FFu;
        static constexpr IntegerType g_Mantissa{ 0x000FFFFFFFFFFFFFULL };
        static constexpr IntegerType g_QuietNaN{ 0x0008000000000000ULL };
        static constexpr auto g_ExponentDigits = g_SymbolShifting - g_ExponentShifting;

        static_assert(g_Symbol + g_Exponent + g_Mantissa == (0xFFFFFFFFFFFFFFFFULL), "g_Symbol + g_Exponent + g_Mantissa != (0xFFFFFFFFFFFFFFFFULL)");
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
    struct IntegerTraits<int>
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
