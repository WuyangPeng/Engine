//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/28 11:22)

#include "Network/NetworkExport.h"

#include "HandleSetFactory.h"
#include "HandleSetImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/ACEWrappers/Detail/Acceptor/SockACEHandleSet.h"
#include "Network/Configuration/ConfigurationStrategy.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"

using std::make_shared;

Network::HandleSetFactory::HandleSetFactory() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, HandleSetFactory)

// static
const Network::HandleSetFactory::ImplTypePtr Network::HandleSetFactory::Create(const ConfigurationStrategy& configurationStrategy)
{
    const auto wrappersStrategyFlag = configurationStrategy.GetWrappersStrategy();

    switch (wrappersStrategyFlag)
    {
#ifdef NETWORK_USE_ACE
        case WrappersStrategy::ACE:
            return make_shared<SockACEHandleSet>();
#endif  // NETWORK_USE_ACE
        default:
            return make_shared<ImplType>();
    }
}
