// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/18 19:11)

#ifndef MATHEMATICS_BASE_SCALED_FLOAT_TO_INT_H
#define MATHEMATICS_BASE_SCALED_FLOAT_TO_INT_H

#include "Mathematics/MathematicsDll.h"

namespace Mathematics
{
	class MATHEMATICS_HIDDEN_DECLARE ScaledFloatToInt
	{
	public:
		using ClassType = ScaledFloatToInt;

	public:
		ScaledFloatToInt(float value, int power) noexcept;

		CLASS_INVARIANT_DECLARE;

		int GetScaledResult() const noexcept;

	private:
		void Scaled() noexcept;
		void ShiftIntegerValue() noexcept;
		void CorrectResult() noexcept;

	private:
		float m_FloatValue;
		int32_t m_IntegerValue;
		int m_Power;
		int m_Shift;
		int m_Result;
	};
}

#endif // MATHEMATICS_BASE_SCALED_FLOAT_TO_INT_H
