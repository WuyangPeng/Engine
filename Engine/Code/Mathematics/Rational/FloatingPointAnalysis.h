// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/08 10:43)

#ifndef MATHEMATICS_RATIONAL_FLOATING_POINT_ANALYSIS_H
#define MATHEMATICS_RATIONAL_FLOATING_POINT_ANALYSIS_H

#include "Mathematics/MathematicsDll.h"

#include "IntegerTraits.h"
#include "Flags/FloatingPointAnalysisType.h" 
#include "Mathematics/Base/Flags/NumericalValueSymbol.h"

#include <type_traits>

namespace Mathematics
{
	template <typename T>
	class FloatingPointAnalysis
	{
	public:
		BOOST_STATIC_ASSERT((boost::is_floating_point<T>::value));

		using ClassType = FloatingPointAnalysis<T>;
		using TraitsType = typename IntegerTraits<T>::TraitsType;
		using IntegerType = typename TraitsType::IntegerType;
		
	public:
		explicit FloatingPointAnalysis(T value);

		CLASS_INVARIANT_DECLARE;

		// 内存表示：
		// 符号位（1）、指数位（float8位、double11位）、尾数位（float23位、double52位），获取未经处理的存储值。
		IntegerType GetSymbolValue() const;
		IntegerType GetExponent() const;
		IntegerType GetMantissa() const;

		NumericalValueSymbol GetSymbol() const;
		FloatingPointAnalysisType GetType() const;
		int GetRealExponent() const;
		IntegerType GetRealMantissa() const;

	private:
		static constexpr IntegerType sm_Symbol{ TraitsType::g_Symbol };
		static constexpr uint32_t sm_SymbolShifting{ TraitsType::g_SymbolShifting };
		static constexpr IntegerType sm_Exponent{ TraitsType::g_Exponent };
		static constexpr uint32_t sm_ExponentShifting{ TraitsType::g_ExponentShifting };
		static constexpr IntegerType sm_MaxExponent{ sm_Exponent >> sm_ExponentShifting };
		static constexpr uint32_t sm_RealExponentDifference{ TraitsType::g_RealExponentDifference };
		static constexpr IntegerType sm_Mantissa{ TraitsType::g_Mantissa };
		static constexpr IntegerType sm_QuietNaN{ TraitsType::g_QuietNaN };

	private:
		T m_Value;
	};
}

#endif // MATHEMATICS_RATIONAL_FLOATING_POINT_ANALYSIS_H
