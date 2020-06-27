// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/20 09:49)

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
		static constexpr uint32_t g_SymbolShifting{ 31 };
		static constexpr IntegerType g_Exponent{ 0x7F800000 };
		static constexpr uint32_t g_ExponentShifting{ 23 };
		static constexpr uint32_t g_RealExponentDifference{ 0x7F };
		static constexpr IntegerType g_Mantissa{ 0x007FFFFF };
		static constexpr IntegerType g_QuietNaN{ 0x00400000 };

		static_assert(g_Symbol + g_Exponent + g_Mantissa == 0xFFFFFFFF, "g_Symbol + g_Exponent + g_Mantissa != 0xFFFFFFFF");
	};

	struct DoubleType
	{
		using IntegerType = uint64_t;
		static constexpr IntegerType g_Symbol{ 0x8000000000000000ULL };
		static constexpr uint32_t g_SymbolShifting{ 63 };
		static constexpr IntegerType g_Exponent{ 0x7FF0000000000000ULL };
		static constexpr uint32_t g_ExponentShifting{ 52 };
		static constexpr uint32_t g_RealExponentDifference{ 0x3FF };
		static constexpr IntegerType g_Mantissa{ 0x000FFFFFFFFFFFFFULL };
		static constexpr IntegerType g_QuietNaN{ 0x0008000000000000ULL };

		static_assert(g_Symbol + g_Exponent + g_Mantissa == (0xFFFFFFFFFFFFFFFFULL), "g_Symbol + g_Exponent + g_Mantissa != (0xFFFFFFFFFFFFFFFFULL)");
	};

	template < typename T>
	struct IntegerTraits;

	template<>
	struct IntegerTraits<int8_t>
	{
		using TraitsType = SignedIntegerType;
	};

	template<>
	struct IntegerTraits<int16_t>
	{
		using TraitsType = SignedIntegerType;
	};

	template<>
	struct IntegerTraits<int>
	{
		using TraitsType = SignedIntegerType;
	};

	template<>
	struct IntegerTraits<int64_t>
	{
		using TraitsType = SignedIntegerType;
	};

	template<>
	struct IntegerTraits<uint8_t>
	{
		using TraitsType = UnsignedIntegerType;
	};

	template<>
	struct IntegerTraits<uint16_t>
	{
		using TraitsType = UnsignedIntegerType;
	};

	template<>
	struct IntegerTraits<uint32_t>
	{
		using TraitsType = UnsignedIntegerType;
	};

	template<>
	struct IntegerTraits<uint64_t>
	{
		using TraitsType = UnsignedIntegerType;
	};

	template<>
	struct IntegerTraits<float>
	{
		using TraitsType = FloatType;
	};

	template<>
	struct IntegerTraits<double>
	{
		using TraitsType = DoubleType;
	};
}

#endif // MATHEMATICS_RATIONAL_INTEGER_DATA_H
