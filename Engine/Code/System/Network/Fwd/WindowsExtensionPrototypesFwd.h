// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:25)

#ifndef SYSTEM_NETWORK_WINDOWS_EXTENSION_PROTOTYPES_FWD_H 
#define SYSTEM_NETWORK_WINDOWS_EXTENSION_PROTOTYPES_FWD_H 

#include "NetworkFlagsFwd.h"
#include "System/Network/Using/WindowsExtensionPrototypesUsing.h"

namespace System
{	
	WinSockStartUpReturn WinSockStartUp(WindowWord versionRequired, WinSockDataPtr wSAData) noexcept;
	WinSockCleanupReturn WinSockCleanup() noexcept;
	void SetWinSockLastError(WinSockLastError error) noexcept;
	WinSockLastError GetWinSockLastError() noexcept;
}

#endif // SYSTEM_NETWORK_WINDOWS_EXTENSION_PROTOTYPES_FWD_H