///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/04 16:34)

#include "Network/NetworkExport.h"

#include "ReceiveMessageLevelImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

Network::ReceiveMessageLevelImpl::ReceiveMessageLevelImpl() noexcept
    : topLevel{}
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, ReceiveMessageLevelImpl)

int Network::ReceiveMessageLevelImpl::GetTopLevelSize() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(topLevel.size());
}

Network::ConstMessageInterfaceSharedPtr Network::ReceiveMessageLevelImpl::operator[](int index) const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return topLevel.at(index);
}

void Network::ReceiveMessageLevelImpl::Insert(const MessageInterfaceSharedPtr& message)
{
    NETWORK_CLASS_IS_VALID_9;

    topLevel.emplace_back(message);
}

Network::ReceiveMessageLevelImpl::MessageContainerConstIter Network::ReceiveMessageLevelImpl::begin() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return topLevel.begin();
}

Network::ReceiveMessageLevelImpl::MessageContainerConstIter Network::ReceiveMessageLevelImpl::end() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return topLevel.end();
}
