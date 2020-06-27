// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 16:44)

#ifndef FRAMEWORK_MACINTOSH_MACINTOSH_CALL_BACK_INTERFACE_H
#define FRAMEWORK_MACINTOSH_MACINTOSH_CALL_BACK_INTERFACE_H

#include "Framework/FrameworkDll.h" 

namespace Framework
{
	class FRAMEWORK_DEFAULT_DECLARE MacintoshCallBackInterface
	{
	public:
		using ClassType = MacintoshCallBackInterface; 
	
	public:
		MacintoshCallBackInterface() noexcept = default;
		virtual ~MacintoshCallBackInterface() noexcept = default;
		MacintoshCallBackInterface(const MacintoshCallBackInterface&) noexcept = default;
		MacintoshCallBackInterface& operator=(const MacintoshCallBackInterface&) noexcept = default;
		MacintoshCallBackInterface(MacintoshCallBackInterface&&) noexcept = default;
		MacintoshCallBackInterface& operator=(MacintoshCallBackInterface&&) noexcept = default;

		CLASS_INVARIANT_VIRTUAL_DECLARE;  
	};
}

#endif // FRAMEWORK_MACINTOSH_MACINTOSH_CALL_BACK_INTERFACE_H
