///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.8 (2023/05/09 10:50)

#include "Network/NetworkExport.h"

#include "ClientImpl.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Interface/BaseMainManager.h"
#include "Network/Interface/SockAddress.h"

Network::ClientImpl::ClientImpl(ConfigurationStrategy configurationStrategy, const MessageEventManagerSharedPtr& messageEventManager) noexcept
    : ParentType{}, configurationStrategy{ std::move(configurationStrategy) }, messageEventManager{ messageEventManager }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, ClientImpl)

Network::ConfigurationStrategy Network::ClientImpl::GetConfigurationStrategy() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return configurationStrategy;
}

int64_t Network::ClientImpl::GetSocketId() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return 0;
}

Network::MessageEventManagerSharedPtr Network::ClientImpl::GetMessageEventManagerSharedPtr()
{
    NETWORK_CLASS_IS_VALID_9;

    if (auto result = messageEventManager.lock();
        result != nullptr)
    {
        return result;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("Socket ��������ʧЧ��"s))
    }
}
