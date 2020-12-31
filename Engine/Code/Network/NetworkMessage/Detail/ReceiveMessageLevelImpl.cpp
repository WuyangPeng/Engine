//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/27 13:52)

#include "Network/NetworkExport.h"

#include "ReceiveMessageLevelImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

Network::ReceiveMessageLevelImpl::ReceiveMessageLevelImpl() noexcept
    : m_TopLevel{}
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, ReceiveMessageLevelImpl)

int Network::ReceiveMessageLevelImpl::GetTopLevelSize() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(m_TopLevel.size());
}

const Network::ConstMessageInterfaceSharedPtr Network::ReceiveMessageLevelImpl::operator[](int index) const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return m_TopLevel.at(index);
}

void Network::ReceiveMessageLevelImpl::Insert(const MessageInterfaceSharedPtr& message)
{
    NETWORK_CLASS_IS_VALID_9;

    m_TopLevel.emplace_back(message);
}

Network::ReceiveMessageLevelImpl::MessageContainerConstIter Network::ReceiveMessageLevelImpl::begin() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return m_TopLevel.begin();
}

Network::ReceiveMessageLevelImpl::MessageContainerConstIter Network::ReceiveMessageLevelImpl::end() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return m_TopLevel.end();
}
