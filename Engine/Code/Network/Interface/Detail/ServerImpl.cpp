///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.8 (2023/05/09 11:34)

#include "Network/NetworkExport.h"

#include "ServerImpl.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Interface/BaseMainManager.h"

Network::ServerImpl::ServerImpl(const ConfigurationStrategy& configurationStrategy, const MessageEventManagerSharedPtr& messageEventManager) noexcept
    : ParentType{}, configurationStrategy{ configurationStrategy }, messageEventManager{ messageEventManager }
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
           HandleConnections() &&
           HandleData(messageEventManager.lock()) &&
           ImmediatelySend();
}

Network::MessageEventManagerSharedPtr Network::ServerImpl::GetMessageEventManagerSharedPtr()
{
    NETWORK_CLASS_IS_VALID_9;

    if (auto result = messageEventManager.lock();
        result != nullptr)
    {
        return result;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("Socket ��������ʧЧ��"s));
    }
}
