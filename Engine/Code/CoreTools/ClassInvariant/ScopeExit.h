// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/18 18:05)

#ifndef CORE_TOOLS_CLASS_INVARIANT_SCOPE_EXIT_H
#define CORE_TOOLS_CLASS_INVARIANT_SCOPE_EXIT_H

#include "CoreTools/CoreToolsDll.h" 

#include <functional>

namespace CoreTools
{
	template<typename T = std::function<void(void)> >
	class ScopeExit 
	{
	public:
		using ClassType = ScopeExit;

	public:
		explicit ScopeExit(T function) noexcept;
		~ScopeExit() noexcept;

		ScopeExit(const ScopeExit&) = delete;
		ScopeExit& operator=(const ScopeExit&) = delete;
		ScopeExit(ScopeExit&&) noexcept = delete;
		ScopeExit& operator=(ScopeExit&&) noexcept = delete;

	private:
		T m_Function;
	};
}

#endif // CORE_TOOLS_CLASS_INVARIANT_SCOPE_EXIT_H
