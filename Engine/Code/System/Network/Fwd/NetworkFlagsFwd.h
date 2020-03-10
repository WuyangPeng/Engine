// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:25)

#ifndef SYSTEM_NETWORK_NETWORK_FLAGS_FWD_H 
#define SYSTEM_NETWORK_NETWORK_FLAGS_FWD_H  

#include "System/Helper/ConfigMacro.h"

namespace System
{
	// SocketPrototypes
	enum class AddressFamilies;
	enum class ProtocolFamilies;
	enum class SocketTypes;
	enum class SocketProtocols;
	enum class SocketRecv;
	enum class SocketSend;
	enum class IoctlSocketCmd : uint32_t;
	enum class SocketLevelOption;
	enum class SocketRetrievedOption;
	enum class ShutdownHow;

	// WindowsExtensionPrototypes
	enum class WinSockStartUpReturn;
	enum class WinSockCleanupReturn;
	enum class WinSockLastError;
	enum class WinSockSelectEvent;

	// WindowsInternet
	enum class InternetOpenType;
	enum class InternetType : uint32_t;
	enum class QueryInfo;

	// WindowsSockEx
	enum class WaitForMultipleEventsReturn : uint32_t;
	enum class ProtocolInfoService;
	enum class ProtocolInfoProvider;
}

#endif // SYSTEM_NETWORK_NETWORK_FLAGS_FWD_H