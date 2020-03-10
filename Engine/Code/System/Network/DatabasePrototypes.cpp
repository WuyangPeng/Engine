// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:27)

#include "System/SystemExport.h"

#include "DatabasePrototypes.h"
#include "Using/SocketPrototypesUsing.h"
#include "System/EnumOperator/EnumCastDetail.h"
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/PragmaWarning.h"

System::WinSockHostent* System
	::GetHostByAddr(const WinSockInAddr* addr,  ProtocolFamilies type) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	

	#include STSTEM_WARNING_PUSH
	#include SYSTEM_WARNING_DISABLE(4996)
	#include SYSTEM_WARNING_DISABLE(26490)

		return ::gethostbyaddr(reinterpret_cast<const char*>(addr), sizeof(WinSockInAddr), EnumCastUnderlying(type));
	
	#include STSTEM_WARNING_POP

#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(addr);
	SYSTEM_UNUSED_ARG(type);

	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32	
}

System::WinSockHostent* System
	::GetHostByName(const char* name) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	

	#include STSTEM_WARNING_PUSH
	#include SYSTEM_WARNING_DISABLE(4996)

		return ::gethostbyname(name);

	#include STSTEM_WARNING_POP

#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(name);

	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32	
}



bool System
	::GetHostName(char* name, int namelen) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	if (::gethostname(name, namelen) != g_SocketError)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(name);
	SYSTEM_UNUSED_ARG(namelen);

	return false;
#endif // SYSTEM_PLATFORM_WIN32	
}

System::WinSockServent* System
	::GetServentByPort(int port, const char* proto) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	return ::getservbyport(port, proto);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(port);
	SYSTEM_UNUSED_ARG(proto);

	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32	
}

System::WinSockServent* System
	::GetServentByName(const char* name, const char* proto) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	return ::getservbyname(name, proto);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(name);
	SYSTEM_UNUSED_ARG(proto);

	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32	
}

System::WinSockProtoent* System
	::GetProtoentByNumber(int proto) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	return ::getprotobynumber(proto);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(proto);

	return nullptr;  
#endif // SYSTEM_PLATFORM_WIN32	
}

System::WinSockProtoent* System
	::GetProtoentByName(const char* name) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	return ::getprotobyname(name);
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(name);

	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32	
}
