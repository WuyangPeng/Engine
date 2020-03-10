// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/18 18:05)

#ifndef CORE_TOOLS_CLASS_INVARIANT_SCOPE_EXIT_H
#define CORE_TOOLS_CLASS_INVARIANT_SCOPE_EXIT_H

#include "CoreTools/CoreToolsDll.h" 

#include <boost/noncopyable.hpp>
#include <functional>

EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
	template<typename T = std::function<void(void)>>
	class ScopeExit : private boost::noncopyable
	{
	public:
		using ClassType = ScopeExit;

	public:
		explicit ScopeExit(T function) noexcept;
		~ScopeExit() noexcept;

	private:
		T m_Function;
	};
}

#endif // CORE_TOOLS_CLASS_INVARIANT_SCOPE_EXIT_H
