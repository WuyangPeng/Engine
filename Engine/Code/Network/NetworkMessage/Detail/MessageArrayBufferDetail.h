///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/04 16:01)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_ARRAY_BUFFER_DETAIL_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_ARRAY_BUFFER_DETAIL_H

#include "Network/NetworkExport.h"

#include "MessageArrayBuffer.h"
#include "MessageVectorBuffer.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <Network::BuffBlockSize Size>
Network::MessageArrayBuffer<Size>::MessageArrayBuffer(ParserStrategy parserStrategy) noexcept
    : ParentType{ parserStrategy }, buffer{}
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <Network::BuffBlockSize Size>
bool Network::MessageArrayBuffer<Size>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <Network::BuffBlockSize Size>
char* Network::MessageArrayBuffer<Size>::GetInitialBufferedPtr() noexcept
{
    NETWORK_CLASS_IS_VALID_1;

    return NON_CONST_MEMBER_CALL_CONST_MEMBER(char*, GetInitialBufferedPtr);
}

template <Network::BuffBlockSize Size>
const char* Network::MessageArrayBuffer<Size>::GetInitialBufferedPtr() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return buffer.data();
}

template <Network::BuffBlockSize Size>
Network::BuffBlockSize Network::MessageArrayBuffer<Size>::GetBuffBlockSize() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return Size;
}

template <Network::BuffBlockSize Size>
int Network::MessageArrayBuffer<Size>::GetSize() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return System::EnumCastUnderlying(Size);
}

template <Network::BuffBlockSize Size>
typename Network::MessageArrayBuffer<Size>::ImplPtr Network::MessageArrayBuffer<Size>::Clone() const
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

template <Network::BuffBlockSize Size>
typename Network::MessageArrayBuffer<Size>::ImplPtr Network::MessageArrayBuffer<Size>::Expansion(int count) const
{
    if (count <= GetSize())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("扩容大小小于原容器大小"s))
    }

    auto messageVectorBuffer = std::make_shared<MessageVectorBuffer>(count, GetParserStrategy());

    messageVectorBuffer->PushBack(*this);
    messageVectorBuffer->AddCurrentReadIndex(GetCurrentReadIndex());
    messageVectorBuffer->SetReceiveCount(GetReceiveCount());

    return messageVectorBuffer;
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_ARRAY_BUFFER_DETAIL_H