///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/20 18:23)

#include "Network/NetworkExport.h"

#include "HandleSetIteratorFactory.h"
#include "HandleSetIteratorImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/ACEWrappers/Detail/Acceptor/SockACEHandleSetIterator.h"
#include "Network/Configuration/ConfigurationStrategy.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/Interface/HandleSet.h"

using std::make_shared;

Network::HandleSetIteratorFactory::HandleSetIteratorFactory() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, HandleSetIteratorFactory)

// static
Network::HandleSetIteratorFactory::ImplTypeSharedPtr Network::HandleSetIteratorFactory::Create(const ConfigurationStrategy& configurationStrategy, const HandleSet& handleSet)
{
    const auto wrappersStrategyFlag = configurationStrategy.GetWrappersStrategy();

    switch (wrappersStrategyFlag)
    {
#ifdef NETWORK_USE_ACE
        case WrappersStrategy::ACE:
            return make_shared<SockACEHandleSetIterator>(handleSet.GetACEHandleSet());
#endif  // NETWORK_USE_ACE
        default:
            return make_shared<ImplType>();
    }
}
