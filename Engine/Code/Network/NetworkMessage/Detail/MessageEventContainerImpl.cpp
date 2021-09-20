//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/27 13:35)

#include "Network/NetworkExport.h"

#include "MessageEventContainerImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "SingleMessageEventContainer.h"

Network::MessageEventContainerImpl::MessageEventContainerImpl() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, MessageEventContainerImpl)

Network::MessageEventContainerImpl::ImplPtr Network::MessageEventContainerImpl::Create()
{
    return std::make_shared<SingleMessageEventContainer>();
}
