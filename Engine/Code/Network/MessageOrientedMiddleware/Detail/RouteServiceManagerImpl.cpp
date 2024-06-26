/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:26)

#include "Network/NetworkExport.h"

#include "RouteServiceManagerImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

Network::RouteServiceManagerImpl::RouteServiceManagerImpl(bool useActiveMQ)
    : activeMQInit{ useActiveMQ ? std::make_shared<ActiveMQInit>(CoreTools::DisableNotThrow::Disable) : nullptr }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::RouteServiceManagerImpl::~RouteServiceManagerImpl() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, RouteServiceManagerImpl)
