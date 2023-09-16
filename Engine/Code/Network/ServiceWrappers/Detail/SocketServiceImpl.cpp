///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/11 17:03)

#include "Network/NetworkExport.h"

#include "SocketServiceImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

Network::SocketServiceImpl::SocketServiceImpl(ConfigurationStrategy configurationStrategy)
    : serviceSession{ configurationStrategy }, consumer{ configurationStrategy }, producer{ configurationStrategy }, configurationStrategy{ std::move(configurationStrategy) }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, SocketServiceImpl)
