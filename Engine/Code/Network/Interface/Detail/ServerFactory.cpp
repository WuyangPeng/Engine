///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.8 (2023/05/09 11:32)

#include "Network/NetworkExport.h"

#include "IterativeServer.h"
#include "NullServer.h"
#include "ReactiveServer.h"
#include "ServerFactory.h"
#include "ServerImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"

Network::ServerFactory::ServerFactory() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, ServerFactory)

Network::ServerFactory::ImplTypeSharedPtr Network::ServerFactory::Create(const ConfigurationStrategy& configurationStrategy, const MessageEventManagerSharedPtr& messageEventManager)
{
    switch (const auto serverStrategy = configurationStrategy.GetServerStrategy();
            serverStrategy)
    {
        case ServerStrategy::Iterative:
            return std::make_shared<IterativeServer>(configurationStrategy, messageEventManager);
        case ServerStrategy::Reactive:
            return std::make_shared<ReactiveServer>(configurationStrategy, messageEventManager);
        default:
            return std::make_shared<NullServer>(configurationStrategy, messageEventManager);
    }
}