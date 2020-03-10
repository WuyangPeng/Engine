// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/03 19:32)

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
		ScaledFloatToInt (float value, int power);	

		CLASS_INVARIANT_DECLARE;

		int GetScaledResult() const;

	private:
		void Scaled();
		void ShiftIntegerValue();
		void CorrectResult();

	private:
		float m_FloatValue;
		int m_IntegerValue;
		int m_Power;
		int m_Shift;
		int m_Result;
	};	
}

#endif // MATHEMATICS_BASE_SCALED_FLOAT_TO_INT_H
