// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 16:43)

#ifndef FRAMEWORK_LINUX_LINUX_CALL_BACK_INTERFACE_H
#define FRAMEWORK_LINUX_LINUX_CALL_BACK_INTERFACE_H

#include "Framework/FrameworkDll.h" 

namespace Framework
{
	class FRAMEWORK_DEFAULT_DECLARE LinuxCallBackInterface
	{
	public:
		using ClassType = LinuxCallBackInterface;
	
	public:
		LinuxCallBackInterface() noexcept = default;
		virtual ~LinuxCallBackInterface() noexcept = default;
		LinuxCallBackInterface(const LinuxCallBackInterface&) noexcept = default;
		LinuxCallBackInterface& operator=(const LinuxCallBackInterface&) noexcept = default;
		LinuxCallBackInterface(LinuxCallBackInterface&&) noexcept = default;
		LinuxCallBackInterface& operator=(LinuxCallBackInterface&&) noexcept = default;

		CLASS_INVARIANT_VIRTUAL_DECLARE;  
	};
}

#endif // FRAMEWORK_LINUX_LINUX_CALL_BACK_INTERFACE_H
