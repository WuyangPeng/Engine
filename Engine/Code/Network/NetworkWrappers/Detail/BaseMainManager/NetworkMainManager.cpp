///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/23 17:40)

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

Network::NetworkMainManager::NetworkMainManager(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow)
    : ParentType{}
{
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
    const auto startUp = System::WinSockStartUp(versionRequested, &wsaData);

    if (startUp != System::WinSockStartUpReturn::Successful)
    {
        THROW_WINDOWS_EXCEPTION;
    }
}

void Network::NetworkMainManager::Release() noexcept
{
    const auto cleanup = System::WinSockCleanup();

    if (cleanup != System::WinSockCleanupReturn::Successful)
    {
        LOG_SINGLETON_ENGINE_APPENDER(Error, Network, SYSTEM_TEXT("销毁WinSock失败！"), CoreTools::LogAppenderIOManageSign::TriggerAssert);
    }
}
