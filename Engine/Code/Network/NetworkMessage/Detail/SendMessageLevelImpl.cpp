///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/18 22:38)

#include "Network/NetworkExport.h"

#include "SendMessageLevelImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/NetworkCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::const_pointer_cast;

Network::SendMessageLevelImpl::SendMessageLevelImpl(int messageMaxSize)
    : topLevel{}, messageMaxSize{ messageMaxSize }, currentSize{ 0 }
{
    if (messageMaxSize <= 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("���û�������СС���㣡"s));
    }

    NETWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Network::SendMessageLevelImpl::IsValid() const noexcept
{
    if (currentSize <= messageMaxSize)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

int Network::SendMessageLevelImpl::GetTopLevelSize() const
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return boost::numeric_cast<int>(topLevel.size());
}

Network::ConstMessageInterfaceSharedPtr Network::SendMessageLevelImpl::operator[](int index) const
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return topLevel.at(index);
}

Network::MessageInterfaceSharedPtr Network::SendMessageLevelImpl::operator[](int index)
{
    NETWORK_CLASS_IS_VALID_1;

    return std::const_pointer_cast<MessageInterface>(static_cast<const ClassType&>(*this)[index]);
}

void Network::SendMessageLevelImpl::Insert(const MessageInterfaceSharedPtr& message)
{
    NETWORK_CLASS_IS_VALID_1;

    if (messageMaxSize < currentSize + message->GetStreamingSize())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("��Ϣ�������㣡"s));
    }
    else
    {
        topLevel.emplace_back(message);
        currentSize += message->GetStreamingSize();
    }
}

int Network::SendMessageLevelImpl::GetRemainingSize() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return messageMaxSize - currentSize;
}

int Network::SendMessageLevelImpl::GetCurrentSize() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return currentSize;
}

void Network::SendMessageLevelImpl::Clear() noexcept
{
    NETWORK_CLASS_IS_VALID_1;

    topLevel.clear();
    currentSize = 0;
}
