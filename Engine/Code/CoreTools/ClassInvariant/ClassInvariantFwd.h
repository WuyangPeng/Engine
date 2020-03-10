// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/18 18:05)

#ifndef CORE_TOOLS_CLASS_INVARIANT_FWD_H
#define CORE_TOOLS_CLASS_INVARIANT_FWD_H

#include <functional>

namespace CoreTools
{
	enum class TriggerAssertCheck;
	enum class CheckInvariantConditions;

    class FunctionDescribed;

	template<typename T>
	class ScopeExit;

	class TriggerAssert;
    
    template <typename T>
    class CheckInvariant;
}

#endif // CORE_TOOLS_CLASS_INVARIANT_FWD_H