// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/11 11:11)

#include "Network/NetworkExport.h"

#include "HandleSetIteratorFactory.h"
#include "HandleSetIteratorImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/ACEWrappers/Detail/Acceptor/SockACEHandleSetIterator.h"
#include "Network/Configuration/ConfigurationStrategy.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/Interface/HandleSet.h"

using std::make_shared;

Network::HandleSetIteratorFactory ::HandleSetIteratorFactory() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, HandleSetIteratorFactory)

// static
const Network::HandleSetIteratorFactory::ImplTypePtr Network::HandleSetIteratorFactory ::Create(const ConfigurationStrategy& configurationStrategy, const HandleSet& handleSet)
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
