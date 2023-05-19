///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.8 (2023/05/10 09:43)

#include "Network/NetworkExport.h"

#include "NullProducer.h"
#include "System/Helper/Tools.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

Network::NullProducer::NullProducer(const ConfigurationStrategy& configurationStrategy) noexcept
    : ParentType{ configurationStrategy }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, NullProducer)

void Network::NullProducer::SendServerMessage(const String& address, const MessageInterfaceSharedPtr& message) noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(address, message);
}
