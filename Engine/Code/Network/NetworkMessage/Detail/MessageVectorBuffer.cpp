///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.7 (2023/05/08 11:39)

#include "Network/NetworkExport.h"

#include "MessageVectorBuffer.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/MemoryTools/MemoryHelper.h"
#include "CoreTools/Helper/Assertion/NetworkCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Network/NetworkMessage/Flags/MessageLengthFlags.h"

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
        THROW_EXCEPTION(SYSTEM_TEXT("扩容大小小于原容器大小"s))
    }

    auto messageVectorBuffer = make_shared<ClassType>(*this);

    messageVectorBuffer->Resize(count);

    return messageVectorBuffer;
}

void Network::MessageVectorBuffer::Resize(int count)
{
    buffer.resize(count);
}
