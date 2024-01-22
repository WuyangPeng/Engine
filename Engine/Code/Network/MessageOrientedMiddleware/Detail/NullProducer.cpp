/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 16:26)

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
