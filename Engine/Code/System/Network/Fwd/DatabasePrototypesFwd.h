// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:25)

#ifndef SYSTEM_NETWORK_DATABASE_PROTOTYPES_FWD_H 
#define SYSTEM_NETWORK_DATABASE_PROTOTYPES_FWD_H  

#include "NetworkFlagsFwd.h"
#include "System/Network/Using/DatabasePrototypesUsing.h"

namespace System
{
	WinSockHostent* GetHostByAddr(const WinSockInAddr* addr, ProtocolFamilies type) noexcept;
	WinSockHostent* GetHostByName(const char* name) noexcept;
	bool GetHostName(char* name, int namelen) noexcept;
	WinSockServent* GetServentByPort(int port, const char* proto) noexcept;
	WinSockServent* GetServentByName(const char* name, const char* proto) noexcept;
	WinSockProtoent* GetProtoentByNumber(int proto) noexcept;
	WinSockProtoent* GetProtoentByName(const char* name) noexcept;
}

#endif // SYSTEM_NETWORK_DATABASE_PROTOTYPES_FWD_H