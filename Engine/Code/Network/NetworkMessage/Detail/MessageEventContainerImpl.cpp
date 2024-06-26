/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:20)

#include "Network/NetworkExport.h"

#include "MessageEventContainerImpl.h"
#include "SingleMessageEventContainer.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

Network::MessageEventContainerImpl::MessageEventContainerImpl() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, MessageEventContainerImpl)

Network::MessageEventContainerImpl::ImplPtr Network::MessageEventContainerImpl::Create()
{
    return std::make_shared<SingleMessageEventContainer>();
}
