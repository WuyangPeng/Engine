// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 11:03)

#ifndef CORE_TOOLS_CONSOLE_CONSOLE_INSTANCE_H
#define CORE_TOOLS_CONSOLE_CONSOLE_INSTANCE_H

#include "Flags/ConsoleColorsFlags.h"
#include "System/Window/Using/WindowUsing.h"

namespace CoreTools
{
	template <StandardHandle Handle>
	class ConsoleInstance
	{
	public:
		using ClassType = ConsoleInstance;
		using ConsoleHandle = System::WindowHandle;

	public:
		ConsoleInstance();

		CLASS_INVARIANT_DECLARE;

		ConsoleHandle GetHandle() noexcept;

	private:
		ConsoleHandle m_Handle;
	};
}

#endif // CORE_TOOLS_CONSOLE_CONSOLE_INSTANCE_H