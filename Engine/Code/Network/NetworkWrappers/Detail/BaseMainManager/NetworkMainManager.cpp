// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/02 10:24)

#include "Network/NetworkExport.h"

#include "NetworkMainManager.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h" 
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/WindowsMacro.h"
#include "System/MemoryTools/MemoryHelperDetail.h"
#include "System/Network/WindowsExtensionPrototypes.h"
#include "System/Network/Flags/WindowsExtensionPrototypesFlags.h"

Network::NetworkMainManager
	::NetworkMainManager() 
	:ParentType{}
{
	Init();

	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::NetworkMainManager
	::~NetworkMainManager()
{
	NETWORK_SELF_CLASS_IS_VALID_9;

	Release();	
}

CLASS_INVARIANT_STUB_DEFINE(Network, NetworkMainManager)

void Network::NetworkMainManager
	::Run()
{
	NETWORK_CLASS_IS_VALID_9; 
}

void Network::NetworkMainManager
	::Init()
{
	System::WinSockData wsaData{};
	System::FillMemoryToZero(wsaData);

	constexpr auto versionRequested = System::MakeWord(2, 2);
	auto startUp = System::WinSockStartUp(versionRequested, &wsaData);

	if (startUp != System::WinSockStartUpReturn::Successful)
	{
		THROW_WINDOWS_EXCEPTION;
	}
}

void Network::NetworkMainManager	
	::Release()
{
	auto cleanup = System::WinSockCleanup();

	if (cleanup != System::WinSockCleanupReturn::Successful)
	{
		LOG_SINGLETON_ENGINE_APPENDER(Error, Network)
			<< SYSTEM_TEXT("œ˙ªŸWinSock ß∞‹£°")
			<< LOG_SINGLETON_TRIGGER_ASSERT;
	}
}



