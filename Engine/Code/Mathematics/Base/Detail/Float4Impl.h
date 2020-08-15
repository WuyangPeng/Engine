// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/18 19:06)

#ifndef MATHEMATICS_BASE_FLOAT_4_IMPL_H
#define MATHEMATICS_BASE_FLOAT_4_IMPL_H

#include "Mathematics/MathematicsDll.h"

#include "CoreTools/DataTypes/TupleDetail.h"

namespace Mathematics
{
	class MATHEMATICS_HIDDEN_DECLARE Float4Impl
	{
	public:
		using ClassType = Float4Impl;

	public:
		Float4Impl() noexcept;
		Float4Impl(float firstValue, float secondValue, float thirdValue, float fourValue) noexcept;

		CLASS_INVARIANT_DECLARE;

		float GetFirstValue() const;
		float GetSecondValue() const;
		float GetThirdValue() const;
		float GetFourthValue() const;

		void SetFirstValue(float value);
		void SetSecondValue(float value);
		void SetThirdValue(float value);
		void SetFourthValue(float value);

	private:
		using FloatTuple4 = CoreTools::Tuple<4, float>;

	private:
		FloatTuple4 m_Tuple;
	};
}

#endif // MATHEMATICS_BASE_FLOAT_4_IMPL_H
