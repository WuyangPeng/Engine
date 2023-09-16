///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/15 17:42)

#include "Network/NetworkExport.h"

#include "NetworkMainManager.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/WindowsMacro.h"
#include "System/MemoryTools/MemoryHelperDetail.h"
#include "System/Network/Flags/WindowsExtensionPrototypesFlags.h"
#include "System/Network/WindowsExtensionPrototypes.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/LogMacro.h"

Network::NetworkMainManager::NetworkMainManager(CoreTools::DisableNotThrow disableNotThrow)
    : ParentType{}
{
    System::UnusedFunction(disableNotThrow);

    Init();

    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::NetworkMainManager::~NetworkMainManager() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;

    Release();
}

CLASS_INVARIANT_STUB_DEFINE(Network, NetworkMainManager)

void Network::NetworkMainManager::Run() noexcept
{
    NETWORK_CLASS_IS_VALID_9;
}

void Network::NetworkMainManager::Init()
{
    System::WinSockData wsaData{};

    constexpr auto versionRequested = System::MakeWord(2, 2);

    if (const auto startUp = System::WinSockStartUp(versionRequested, &wsaData);
        startUp != System::WinSockStartUpReturn::Successful)
    {
        THROW_WINDOWS_EXCEPTION;
    }
}

void Network::NetworkMainManager::Release() noexcept
{
    if (const auto cleanup = System::WinSockCleanup();
        cleanup != System::WinSockCleanupReturn::Successful)
    {
        LOG_SINGLETON_ENGINE_APPENDER(Error, Network, SYSTEM_TEXT("销毁WinSock失败！"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
    }
}
