/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 15:56)

#include "Network/NetworkExport.h"

#include "SocketServiceImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

Network::SocketServiceImpl::SocketServiceImpl(ConfigurationStrategy configurationStrategy)
    : serviceSession{ configurationStrategy }, consumer{ configurationStrategy }, producer{ configurationStrategy }, configurationStrategy{ std::move(configurationStrategy) }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, SocketServiceImpl)

void Network::SocketServiceImpl::SendTextMessage(const String& message)
{
    NETWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(message);

    CoreTools::DisableNoexcept();
}
