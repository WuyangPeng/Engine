// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/03 19:17)

#ifndef MATHEMATICS_BASE_FLOAT_3_IMPL_H
#define MATHEMATICS_BASE_FLOAT_3_IMPL_H

#include "Mathematics/MathematicsDll.h"

#include "CoreTools/DataTypes/TupleDetail.h"

namespace Mathematics
{
	class MATHEMATICS_HIDDEN_DECLARE Float3Impl 
	{
	public:
		using ClassType = Float3Impl;

	public:				
		Float3Impl();	
		Float3Impl (float firstValue,float secondValue,float thirdValue);

		CLASS_INVARIANT_DECLARE;

		float GetFirstValue() const;
		float GetSecondValue() const;
		float GetThirdValue() const;

		void SetFirstValue(float value);
		void SetSecondValue(float value);
		void SetThirdValue(float value);

	private:
		using FloatTuple3 = CoreTools::Tuple<3,float>;

	private:
		FloatTuple3 m_Tuple;
	};	
}

#endif // MATHEMATICS_BASE_FLOAT_3_IMPL_H
