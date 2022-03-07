///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/18 22:34)

#include "Network/NetworkExport.h"

#include "MessageVectorBuffer.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/MemoryTools/MemoryHelper.h"
#include "CoreTools/Helper/Assertion/NetworkCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Network/NetworkMessage/Flags/MessageLengthFlags.h"

using std::make_shared;

Network::MessageVectorBuffer::MessageVectorBuffer(int count, ParserStrategy parserStrategy)
    : ParentType{ parserStrategy }, buffer(count)
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, MessageVectorBuffer)

Network::MessageVectorBuffer::ImplPtr Network::MessageVectorBuffer::Clone() const
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return make_shared<ClassType>(*this);
}

Network::BuffBlockSize Network::MessageVectorBuffer::GetBuffBlockSize() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return BuffBlockSize::Automatic;
}

int Network::MessageVectorBuffer::GetSize() const
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return boost::numeric_cast<int>(buffer.size());
}

const char* Network::MessageVectorBuffer::GetInitialBufferedPtr() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return buffer.data();
}

char* Network::MessageVectorBuffer::GetInitialBufferedPtr() noexcept
{
    NETWORK_CLASS_IS_VALID_1;

    return NON_CONST_MEMBER_CALL_CONST_MEMBER(char*, GetInitialBufferedPtr);
}

Network::MessageVectorBuffer::ImplPtr Network::MessageVectorBuffer::Expansion(int count) const
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    if (count <= GetSize())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("���ݴ�СС��ԭ������С"s));
    }

    auto messageVectorBuffer = make_shared<ClassType>(*this);

    messageVectorBuffer->Resize(count);

    return messageVectorBuffer;
}

// private
void Network::MessageVectorBuffer::Resize(int count)
{
    buffer.resize(count);
}
