/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:30)

#include "Network/NetworkExport.h"

#include "HandleSetFactory.h"
#include "HandleSetImpl.h"
#include "NullHandleSet.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/AceWrappers/Detail/Acceptor/SockAceHandleSet.h"
#include "Network/Configuration/ConfigurationStrategy.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"

Network::HandleSetFactory::HandleSetFactory() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, HandleSetFactory)

Network::HandleSetFactory::ImplTypeSharedPtr Network::HandleSetFactory::Create(const ConfigurationStrategy& configurationStrategy)
{
    switch (const auto wrappersStrategy = configurationStrategy.GetWrappersStrategy();
            wrappersStrategy)
    {
#ifdef NETWORK_USE_ACE

        case WrappersStrategy::Ace:
            return std::make_shared<SockAceHandleSet>();

#endif  // NETWORK_USE_ACE

        default:
            return std::make_shared<NullHandleSet>();
    }
}
