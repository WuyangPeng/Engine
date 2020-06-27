// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.4 (2020/03/11 12:34)

#ifndef NETWORK_NETWORK_INTERFACE_ACE_USING_H
#define NETWORK_NETWORK_INTERFACE_ACE_USING_H

#include "System/Helper/PragmaWarning.h"
#include "System/Network/Using/SocketPrototypesUsing.h"
#include "Network/Helper/UserMacro.h"

#include <string>

#ifdef NETWORK_USE_ACE	

	#if defined(NDEBUG)	
		#include STSTEM_WARNING_PUSH
		#include SYSTEM_WARNING_DISABLE(4996)
		#include SYSTEM_WARNING_DISABLE(6387)
		#include SYSTEM_WARNING_DISABLE(26451)	
		#include SYSTEM_WARNING_DISABLE(26495)	
	#endif // defined(NDEBUG)  

	#include "System/Helper/PragmaWarning/ACE.h"

	#if defined(NDEBUG)	
		#include STSTEM_WARNING_POP
	#endif // defined(NDEBUG) 

#else // !NETWORK_USE_ACE

	#include "System/Network/Using/WindowsExtensionPrototypesUsing.h"

#endif // NETWORK_USE_ACE

namespace Network
{
	using SockFdSet = System::WinSockFdSet;

#ifdef NETWORK_USE_ACE

	using ACEInetAddress = ACE_INET_Addr;
	using ACESockStreamNativeType = ACE_SOCK_Stream;
	using ACEHandle = ACE_HANDLE;
	using ACEHandleSet = ACE_Handle_Set;
	constexpr auto g_NonBlock = ACE_NONBLOCK;

	#ifdef NETWORK_USES_ACE_WCHAR
		#ifndef ACE_USES_WCHAR
			#error "NETWORK_USES_ACE_WCHAR要与编译好的ACE库中是否定义ACE_USES_WCHAR相对应"
		#endif // ACE_USES_WCHAR
	#else // !NETWORK_USES_ACE_WCHAR
		#ifdef ACE_USES_WCHAR
			#error "NETWORK_USES_ACE_WCHAR要与编译好的ACE库中是否定义ACE_USES_WCHAR相对应"
		#endif // ACE_USES_WCHAR
	#endif // NETWORK_USES_ACE_WCHAR

	#ifdef NETWORK_USES_ACE_WCHAR

		using ACEString = std::wstring;

	#else // !NETWORK_USES_ACE_WCHAR

		using ACEString = std::string;

	#endif // NETWORK_USES_ACE_WCHAR

	using ACEChar = ACE_TCHAR;

#else // !NETWORK_USE_ACE

	class ACEInetAddress 
	{
	};

	class ACESockStreamNativeType
	{
	};

	using ACEHandle = System::WinSockHandle;

	class ACEHandleSet
	{

	};
	constexpr auto g_NonBlock = 1;

#endif // NETWORK_USE_ACE
} 

#endif // NETWORK_NETWORK_INTERFACE_ACE_USING_H
