// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/20 15:57)

#ifndef CORE_TOOLS_DATA_TYPE_TUPLE_LESS_H
#define CORE_TOOLS_DATA_TYPE_TUPLE_LESS_H

#include "CoreTools/CoreToolsDll.h"

#include "Tuple.h"

namespace CoreTools
{
	template <int Dimension, typename Type>
	class TupleLess
	{
	public:
		using ClassType = TupleLess<Dimension, Type>;
		using Tuple = Tuple<Dimension, Type>;

	public:
		explicit TupleLess(int index);

		CLASS_INVARIANT_DECLARE;

		bool operator()(const Tuple& lhs, const Tuple& rhs) const noexcept;

	private:
		int m_Index;
	};
}

#endif // CORE_TOOLS_DATA_TYPE_TUPLE_LESS_H