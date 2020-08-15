// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/20 09:45)

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
		static_assert(std::is_floating_point<T>::value, "T must be floating point.");

		using ClassType = FloatingPointAnalysis<T>;
		using TraitsType = typename IntegerTraits<T>::TraitsType;
		using IntegerType = typename TraitsType::IntegerType;

	public:
		explicit FloatingPointAnalysis(T value) noexcept;

		CLASS_INVARIANT_DECLARE;

		// �ڴ��ʾ��
		// ����λ��1����ָ��λ��float8λ��double11λ����β��λ��float23λ��double52λ������ȡδ������Ĵ洢ֵ��
		IntegerType GetSymbolValue() const noexcept;
		IntegerType GetExponent() const noexcept;
		IntegerType GetMantissa() const noexcept;

		NumericalValueSymbol GetSymbol() const noexcept;
		FloatingPointAnalysisType GetType() const noexcept;
		int GetRealExponent() const;
		IntegerType GetRealMantissa() const noexcept;

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
