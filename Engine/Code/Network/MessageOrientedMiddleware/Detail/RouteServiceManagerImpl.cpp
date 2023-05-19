///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.8 (2023/05/10 09:43)

#include "Network/NetworkExport.h"

#include "RouteServiceManagerImpl.h"
#include "System/Helper/Tools.h"
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
