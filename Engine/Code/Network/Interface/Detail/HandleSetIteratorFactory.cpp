///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.8 (2023/05/09 09:55)

#include "Network/NetworkExport.h"

#include "HandleSetIteratorFactory.h"
#include "HandleSetIteratorImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/ACEWrappers/Detail/Acceptor/SockACEHandleSetIterator.h"
#include "Network/Configuration/ConfigurationStrategy.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/Interface/HandleSet.h"

Network::HandleSetIteratorFactory::HandleSetIteratorFactory() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, HandleSetIteratorFactory)

Network::HandleSetIteratorFactory::ImplTypeSharedPtr Network::HandleSetIteratorFactory::Create(const ConfigurationStrategy& configurationStrategy, const HandleSet& handleSet)
{
    switch (const auto wrappersStrategy = configurationStrategy.GetWrappersStrategy();
            wrappersStrategy)
    {
#ifdef NETWORK_USE_ACE

        case WrappersStrategy::Ace:
            return std::make_shared<SockACEHandleSetIterator>(handleSet.GetACEHandleSet());

#endif  // NETWORK_USE_ACE

        default:
            return std::make_shared<ImplType>();
    }
}
