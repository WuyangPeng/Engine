/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:23)

#include "Network/NetworkExport.h"

#include "SendMessageLevel.h"
#include "Detail/SendMessageLevelImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Network, SendMessageLevel)

Network::SendMessageLevel::SendMessageLevel(int messageMaxSize)
    : impl{ messageMaxSize }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Network, SendMessageLevel)

int Network::SendMessageLevel::GetTopLevelSize() const
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return impl->GetTopLevelSize();
}

Network::ConstMessageInterfaceSharedPtr Network::SendMessageLevel::operator[](int index) const
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return (*impl)[index];
}

Network::MessageInterfaceSharedPtr Network::SendMessageLevel::operator[](int index)
{
    NETWORK_CLASS_IS_VALID_1;

    return (*impl)[index];
}

void Network::SendMessageLevel::Insert(const MessageInterfaceSharedPtr& messagePtr)
{
    NETWORK_CLASS_IS_VALID_1;

    return impl->Insert(messagePtr);
}

int Network::SendMessageLevel::GetRemainingSize() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return impl->GetRemainingSize();
}

int Network::SendMessageLevel::GetCurrentSize() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return impl->GetCurrentSize();
}

void Network::SendMessageLevel::Clear()
{
    NETWORK_CLASS_IS_VALID_1;

    return impl->Clear();
}
