// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:26)

#ifndef SYSTEM_NETWORK_WINDOWS_EXTENSION_PROTOTYPES_USING_H
#define SYSTEM_NETWORK_WINDOWS_EXTENSION_PROTOTYPES_USING_H

#include "System/Helper/Platform.h"
#include "System/Window/Using/WindowUsing.h"

#ifdef SYSTEM_PLATFORM_WIN32
	#include <WinSock2.h>  
#endif // SYSTEM_PLATFORM_WIN32 

namespace System
{	
#ifdef SYSTEM_PLATFORM_WIN32
 
	using WinSockData = WSADATA;
	using WinSockDataPtr = LPWSADATA;	
	using WinSockHandle = HANDLE;
	
	constexpr WindowWord g_WinSockDescriptionLen{ WSADESCRIPTION_LEN };
	constexpr WindowWord g_WinSockSystemStatusLen{ WSASYS_STATUS_LEN };
	 
#else // !SYSTEM_PLATFORM_WIN32
	
	constexpr WindowWord g_WinSockDescriptionLen{ 256 };
	constexpr WindowWord g_WinSockSystemStatusLen{ 128 };
 
	struct WinSockData 
	{
		uint16_t wVersion;
		uint16_t wHighVersion; 
		char szDescription[g_WinSockDescriptionLen + 1];
		char szSystemStatus[g_WinSockSystemStatusLen + 1];
		uint16_t iMaxSockets;
		uint16_t iMaxUdpDg;
		char* lpVendorInfo; 
	}; 
	
	using WinSockDataPtr = WinSockData*;
	using WinSockHandle = void*; 
	 
#endif // SYSTEM_PLATFORM_WIN32    		 
}

#endif // SYSTEM_NETWORK_WINDOWS_EXTENSION_PROTOTYPES_USING_H