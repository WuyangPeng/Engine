// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 10:39)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_SIMPLE_INCREMENTER_H
#define CORE_TOOLS_TEMPLATE_TOOLS_SIMPLE_INCREMENTER_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
	template <typename T>
	class SimpleIncrementer
	{
	public:
		using ClassType = SimpleIncrementer<T>;

		CLASS_INVARIANT_DECLARE;

	public:
		void operator ()(T& value);
	};
}

#endif //  CORE_TOOLS_TEMPLATE_TOOLS_SIMPLE_INCREMENTER_H

