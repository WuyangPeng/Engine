// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 10:35)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_IF_THEN_ELSE_H
#define CORE_TOOLS_TEMPLATE_TOOLS_IF_THEN_ELSE_H 

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
	template<bool Constant, typename Lhs, typename Rhs>
	class IfThenElse;

	template<typename Lhs, typename Rhs>
	class IfThenElse<true, Lhs, Rhs>
	{
	public:
		using ResultType = Lhs;
	};

	template<typename Lhs, typename Rhs>
	class IfThenElse<false, Lhs, Rhs>
	{
	public:
		using ResultType = Rhs;
	};
}

#endif // CORE_TOOLS_TEMPLATE_TOOLS_IF_THEN_ELSE_H

