// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.1.0.0 (2020/04/02 15:11)

#ifndef CORE_TOOLS_HELPER_NOEXCEPT_H
#define CORE_TOOLS_HELPER_NOEXCEPT_H 

#include "System/Helper/UnusedMacro.h"
#include "System/Helper/UnicodeUsing.h"

namespace CoreTools
{
	inline void DoNothing()
	{
		using namespace std::literals;

		const System::String doNothing(SYSTEM_TEXT(""));

		SYSTEM_UNUSED_ARG(doNothing);
	}

	template <typename T, typename Function>
	void NoexceptNoReturn(const T& master, Function function) noexcept;

	template <typename T, typename Function, typename T1>
	void NoexceptNoReturn(const T& master, Function function, const T1& parameter1) noexcept;

	template <typename T, typename Result, typename Function>
	Result Noexcept(const T& master, Function function, const Result& defaultResult) noexcept;

	template <typename T, typename Result, typename Function, typename T1>
	Result Noexcept(const T& master, Function function, const T1& parameter1, const Result& defaultResult) noexcept;

	template <typename T, typename Function>
	void NoexceptNoReturn(T& master, Function function) noexcept;

	template <typename T, typename Function, typename T1>
	void NoexceptNoReturn(T& master, Function function, const T1& parameter1) noexcept;

	template <typename T, typename Result, typename Function>
	Result Noexcept(T& master, Function function, const Result& defaultResult) noexcept;

	template <typename T, typename Result, typename Function, typename T1>
	Result Noexcept(T& master, Function function, const T1& parameter1, const Result& defaultResult) noexcept;
}

#endif // CORE_TOOLS_HELPER_NOEXCEPT_H
