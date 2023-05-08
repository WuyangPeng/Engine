///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/20 17:20)

#include "Network/NetworkExport.h"

#include "ClientImpl.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Interface/BaseMainManager.h"
#include "Network/Interface/SockAddress.h"

Network::ClientImpl::ClientImpl(const ConfigurationStrategy& configurationStrategy, const MessageEventManagerSharedPtr& socketManager) noexcept
    : ParentType{}, configurationStrategy{ configurationStrategy }, socketManager{ socketManager }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, ClientImpl)

Network::ConfigurationStrategy Network::ClientImpl::GetConfigurationStrategy() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return configurationStrategy;
}

uint64_t Network::ClientImpl::GetSocketID() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return 0;
}

Network::MessageEventManagerSharedPtr Network::ClientImpl::GetSocketManagerSharedPtr()
{
    NETWORK_CLASS_IS_VALID_9;

    auto result = socketManager.lock();

    if (result != nullptr)
    {
        return result;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("Socket 管理器已失效。"s));
    }
}
