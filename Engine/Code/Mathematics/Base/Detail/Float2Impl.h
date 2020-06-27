// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/18 19:06)

#ifndef MATHEMATICS_BASE_FLOAT_2_IMPL_H
#define MATHEMATICS_BASE_FLOAT_2_IMPL_H

#include "Mathematics/MathematicsDll.h"

#include "CoreTools/DataTypes/TupleDetail.h"

namespace Mathematics
{
	class MATHEMATICS_HIDDEN_DECLARE Float2Impl
	{
	public:
		using ClassType = Float2Impl;

	public:
		Float2Impl();
		Float2Impl(float firstValue, float secondValue);

		CLASS_INVARIANT_DECLARE;

		float GetFirstValue() const;
		float GetSecondValue() const;

		void SetFirstValue(float value);
		void SetSecondValue(float value);

	private:
		using FloatTuple2 = CoreTools::Tuple<2, float>;

	private:
		FloatTuple2 m_Tuple;
	};
}

#endif // MATHEMATICS_BASE_FLOAT_2_IMPL_H
