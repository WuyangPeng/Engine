//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/28 12:45)

#include "Network/NetworkExport.h"

#include "IterativeServer.h"
#include "ReactiveServer.h"
#include "ServerFactory.h"
#include "ServerImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"

using std::make_shared;
using std::string;

Network::ServerFactory::ServerFactory() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, ServerFactory)

// static
const Network::ServerFactory::ImplTypePtr Network::ServerFactory::Create(const SocketManagerSharedPtr& socketManager, const ConfigurationStrategy& configurationStrategy)
{
    const auto patternStrategyFlag = configurationStrategy.GetPatternStrategy();

    switch (patternStrategyFlag)
    {
        case ServerStrategy::Iterative:
            return make_shared<IterativeServer>(socketManager, configurationStrategy);
        case ServerStrategy::Reactive:
            return make_shared<ReactiveServer>(socketManager, configurationStrategy);
        default:
            return make_shared<ImplType>(socketManager, configurationStrategy);
    }
}