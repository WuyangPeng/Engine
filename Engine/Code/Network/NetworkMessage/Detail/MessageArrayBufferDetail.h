//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 11:31)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_ARRAY_BUFFER_DETAIL_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_ARRAY_BUFFER_DETAIL_H

#include "Network/NetworkExport.h"

#include "MessageArrayBuffer.h"
#include "MessageVectorBuffer.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <Network::BuffBlockSize buffBlockSize>
Network::MessageArrayBuffer<buffBlockSize>::MessageArrayBuffer(ParserStrategy parserStrategy) noexcept
    : ParentType{ parserStrategy }, m_Buffer{}
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <Network::BuffBlockSize buffBlockSize>
bool Network::MessageArrayBuffer<buffBlockSize>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <Network::BuffBlockSize buffBlockSize>
char* Network::MessageArrayBuffer<buffBlockSize>::GetInitialBufferedPtr() noexcept
{
    NETWORK_CLASS_IS_VALID_1;

    return NON_CONST_MEMBER_CALL_CONST_MEMBER(char*, GetInitialBufferedPtr);
}

template <Network::BuffBlockSize buffBlockSize>
const char* Network::MessageArrayBuffer<buffBlockSize>::GetInitialBufferedPtr() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return m_Buffer.data();
}

template <Network::BuffBlockSize buffBlockSize>
Network::BuffBlockSize Network::MessageArrayBuffer<buffBlockSize>::GetBuffBlockSize() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return buffBlockSize;
}

template <Network::BuffBlockSize buffBlockSize>
int Network::MessageArrayBuffer<buffBlockSize>::GetSize() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return System::EnumCastUnderlying(buffBlockSize);
}

template <Network::BuffBlockSize buffBlockSize>
typename Network::MessageArrayBuffer<buffBlockSize>::ImplPtr Network::MessageArrayBuffer<buffBlockSize>::Clone() const
{
    NETWORK_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

template <Network::BuffBlockSize buffBlockSize>
typename Network::MessageArrayBuffer<buffBlockSize>::ImplPtr Network::MessageArrayBuffer<buffBlockSize>::Expansion(int count) const
{
    if (count <= GetSize())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("扩容大小小于原容器大小"s));
    }

    auto messageVectorBuffer = std::make_shared<MessageVectorBuffer>(count, GetParserStrategy());

    messageVectorBuffer->PushBack(shared_from_this());
    messageVectorBuffer->AddCurrentReadIndex(GetCurrentReadIndex());
    messageVectorBuffer->SetReceiveCount(GetReceiveCount());

    return messageVectorBuffer;
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_ARRAY_BUFFER_DETAIL_H