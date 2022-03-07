///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/21 14:51)

#include "Network/NetworkExport.h"

#include "ServerImpl.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Interface/BaseMainManager.h"

Network::ServerImpl::ServerImpl(const SocketManagerSharedPtr& socketManager, const ConfigurationStrategy& configurationStrategy) noexcept
    : ParentType{}, configurationStrategy{ configurationStrategy }, m_SocketManager{ socketManager }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, ServerImpl)

Network::ConfigurationStrategy Network::ServerImpl::GetConfigurationStrategy() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return configurationStrategy;
}

bool Network::ServerImpl::RunServer()
{
    NETWORK_CLASS_IS_VALID_9;

    return WaitForMultipleEvents() &&
           HandleConnections(*m_SocketManager.lock()) &&
           HandleData(m_SocketManager.lock()) &&
           ImmediatelySend();
}

Network::SocketManagerSharedPtr Network::ServerImpl::GetSocketManagerSharedPtr()
{
    NETWORK_CLASS_IS_VALID_9;

    auto result = m_SocketManager.lock();

    if (result)
    {
        return result;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("Socket 管理器已失效。"s));
    }
}
