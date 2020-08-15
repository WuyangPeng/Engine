// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/11 16:31)

#include "Network/NetworkExport.h"

#include "NetworkMainManager.h"
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/WindowsMacro.h"
#include "System/MemoryTools/MemoryHelperDetail.h"
#include "System/Network/WindowsExtensionPrototypes.h"
#include "System/Network/Flags/WindowsExtensionPrototypesFlags.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h" 
#include "System/Helper/PragmaWarning/NumericCast.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455)
Network::NetworkMainManager
	::NetworkMainManager()  
	:ParentType{} 
{
	Init();

	NETWORK_SELF_CLASS_IS_VALID_9;
}
#include STSTEM_WARNING_POP
Network::NetworkMainManager
	::~NetworkMainManager() noexcept
{
	NETWORK_SELF_CLASS_IS_VALID_9;

	Release();
}

CLASS_INVARIANT_STUB_DEFINE(Network, NetworkMainManager)

void Network::NetworkMainManager
	::Run() noexcept
{
	NETWORK_CLASS_IS_VALID_9;
}

void Network::NetworkMainManager
	::Init()  
{
	System::WinSockData wsaData{};
	System::FillMemoryToZero(wsaData);

	constexpr auto versionRequested = System::MakeWord(2, 2);
	const auto startUp = System::WinSockStartUp(versionRequested, &wsaData);

	if (startUp != System::WinSockStartUpReturn::Successful)
	{
		THROW_WINDOWS_EXCEPTION;
	}
}

void Network::NetworkMainManager
	::Release() noexcept
{
	const auto cleanup = System::WinSockCleanup();

	if (cleanup != System::WinSockCleanupReturn::Successful)
	{
		LOG_SINGLETON_ENGINE_APPENDER(Error, Network)
			<< SYSTEM_TEXT("œ˙ªŸWinSock ß∞‹£°")
			<< LOG_SINGLETON_TRIGGER_ASSERT;
	}
}



