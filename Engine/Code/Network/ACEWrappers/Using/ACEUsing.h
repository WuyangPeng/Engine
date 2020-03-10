// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.1.0 (2019/10/18 13:27)


#ifndef NETWORK_NETWORK_INTERFACE_ACE_USING_H
#define NETWORK_NETWORK_INTERFACE_ACE_USING_H

#include "System/Helper/ConfigMacro.h"
#include "System/Network/Using/SocketPrototypesUsing.h"
#include "Network/Helper/UserMacro.h"

#ifdef NETWORK_USE_ACE	

	#if defined(TCRE_USE_MSVC) && (1400 <= TCRE_USE_MSVC)  && defined(NDEBUG)	
		#include "System/Helper/PragmaWarning/Push.h"
		#include "System/Helper/PragmaWarning/Disable4996.h"
		#include "System/Helper/PragmaWarning/Disable6387.h"
		#include "System/Helper/PragmaWarning/Disable26451.h"	
		#include "System/Helper/PragmaWarning/Disable26495.h"		
	#endif // defined(TCRE_USE_MSVC) && (1400 <= TCRE_USE_MSVC)  

	#include <ace/INET_Addr.h>	
	#include <ace/Handle_Set.h>
	#include <ace/SOCK_Stream.h>

	#if defined(TCRE_USE_MSVC) && (1400 <= TCRE_USE_MSVC)  && defined(NDEBUG)	
		#include "System/Helper/PragmaWarning/Pop.h" 
	#endif // defined(TCRE_USE_MSVC) && (1400 <= TCRE_USE_MSVC)  

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
	constexpr int g_NonBlock{ ACE_NONBLOCK };

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
	constexpr int g_NonBlock{ 1 };

#endif // NETWORK_USE_ACE
} 

#endif // NETWORK_NETWORK_INTERFACE_ACE_USING_H
