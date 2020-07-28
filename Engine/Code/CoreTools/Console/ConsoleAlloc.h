// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 11:02)

#ifndef CORE_TOOLS_CONSOLE_CONSOLE_ALLOC_H
#define CORE_TOOLS_CONSOLE_CONSOLE_ALLOC_H

#include "CoreTools/CoreToolsDll.h"

#include <cstdio>

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE ConsoleAlloc
	{
	public:
		using ClassType = ConsoleAlloc;

	public:
		ConsoleAlloc() noexcept;
		~ConsoleAlloc();

		ConsoleAlloc(const ConsoleAlloc&) = delete;
		ConsoleAlloc& operator=(const ConsoleAlloc&) = delete;

		ConsoleAlloc(ConsoleAlloc&&) noexcept = delete;
		ConsoleAlloc& operator=(ConsoleAlloc&&) noexcept = delete;

		CLASS_INVARIANT_DECLARE;

	private:
		void OpenConsole();
		void CloseConsole() noexcept;

	private:
		FILE* m_OutPtr;
		FILE* m_InPtr;
		FILE* m_ErrPtr;
	};
}

#endif // CORE_TOOLS_CONSOLE_CONSOLE_ALLOC_H
