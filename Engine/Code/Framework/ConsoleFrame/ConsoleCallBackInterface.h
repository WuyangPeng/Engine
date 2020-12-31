// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 16:44)

#ifndef FRAMEWORK_CONSOLE_CONSOLE_CALL_BACK_INTERFACE_H
#define FRAMEWORK_CONSOLE_CONSOLE_CALL_BACK_INTERFACE_H

#include "Framework/FrameworkDll.h" 

namespace Framework
{
	class FRAMEWORK_DEFAULT_DECLARE ConsoleCallBackInterface
	{
	public:
		using ClassType = ConsoleCallBackInterface;
	
	public:
		ConsoleCallBackInterface() noexcept = default;
		virtual ~ConsoleCallBackInterface() noexcept = default;
		ConsoleCallBackInterface(const ConsoleCallBackInterface&) noexcept = default;
		ConsoleCallBackInterface& operator=(const ConsoleCallBackInterface&) noexcept = default;
		ConsoleCallBackInterface(ConsoleCallBackInterface&&) noexcept = default;
		ConsoleCallBackInterface& operator=(ConsoleCallBackInterface&&) noexcept = default;

		CLASS_INVARIANT_VIRTUAL_DECLARE;  
	};
}

#endif // FRAMEWORK_CONSOLE_CONSOLE_CALL_BACK_INTERFACE_H
