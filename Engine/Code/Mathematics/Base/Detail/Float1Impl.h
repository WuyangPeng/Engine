// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/18 19:05)

#ifndef MATHEMATICS_BASE_FLOAT_1_IMPL_H
#define MATHEMATICS_BASE_FLOAT_1_IMPL_H

#include "Mathematics/MathematicsDll.h"

#include "CoreTools/DataTypes/TupleDetail.h"

namespace Mathematics
{
	class MATHEMATICS_HIDDEN_DECLARE Float1Impl
	{
	public:
		using ClassType = Float1Impl;

	public:
		Float1Impl();
		explicit Float1Impl(float value);

		CLASS_INVARIANT_DECLARE;

		float GetValue() const;
		void SetValue(float value);

	private:
		using FloatTuple1 = CoreTools::Tuple<1, float>;

	private:
		FloatTuple1 m_Tuple;
	};
}

#endif // MATHEMATICS_BASE_FLOAT_1_IMPL_H
