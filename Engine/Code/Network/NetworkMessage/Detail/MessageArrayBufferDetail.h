// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.4 (2020/03/10 15:42)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_ARRAY_BUFFER_DETAIL_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_ARRAY_BUFFER_DETAIL_H

#include "Network/NetworkExport.h"

#include "MessageArrayBuffer.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/NetworkCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h" 

template<Network::BuffBlockSize buffBlockSize>
Network::MessageArrayBuffer<buffBlockSize>
	::MessageArrayBuffer(ParserStrategy parserStrategy)
	:ParentType{ parserStrategy }, m_Buffer{}
{
	NETWORK_SELF_CLASS_IS_VALID_1;
}

template<Network::BuffBlockSize buffBlockSize>
Network::MessageArrayBuffer<buffBlockSize>
	::~MessageArrayBuffer()
{
	NETWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template<Network::BuffBlockSize buffBlockSize>
bool Network::MessageArrayBuffer<buffBlockSize>
	::IsValid() const noexcept
{
	if (ParentType::IsValid())
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT 

template<Network::BuffBlockSize buffBlockSize>
char* Network::MessageArrayBuffer<buffBlockSize>
	::GetInitialBufferedPtr()
{
	NETWORK_CLASS_IS_VALID_1;

	return NON_CONST_MEMBER_CALL_CONST_MEMBER(char*, GetInitialBufferedPtr);
}

template<Network::BuffBlockSize buffBlockSize>
const char* Network::MessageArrayBuffer<buffBlockSize>
	::GetInitialBufferedPtr() const
{
	NETWORK_CLASS_IS_VALID_CONST_1;

	return m_Buffer.data();
}

template<Network::BuffBlockSize buffBlockSize>
Network::BuffBlockSize Network::MessageArrayBuffer<buffBlockSize>
	::GetBuffBlockSize() const
{
	NETWORK_CLASS_IS_VALID_CONST_1;

	return buffBlockSize;
}

template<Network::BuffBlockSize buffBlockSize>
int Network::MessageArrayBuffer<buffBlockSize>
	::GetSize() const
{
	NETWORK_CLASS_IS_VALID_CONST_1;

	return System::EnumCastUnderlying(buffBlockSize);
}

template<Network::BuffBlockSize buffBlockSize>
typename Network::MessageArrayBuffer<buffBlockSize>::ImplPtr Network::MessageArrayBuffer<buffBlockSize>
	::Clone() const
{
	NETWORK_CLASS_IS_VALID_CONST_1;

	return std::make_shared<ClassType>(*this);
}

template<Network::BuffBlockSize buffBlockSize>
typename Network::MessageArrayBuffer<buffBlockSize>::ImplPtr Network::MessageArrayBuffer<buffBlockSize>
	::Expansion(int count) const
{
	if (count <= GetSize())
	{
		THROW_EXCEPTION(SYSTEM_TEXT("扩容大小小于原容器大小"));
	}

	auto messageVectorBuffer = std::make_shared<MessageVectorBuffer>(count, GetParserStrategy());

	messageVectorBuffer->PushBack(shared_from_this());
	messageVectorBuffer->AddCurrentReadIndex(GetCurrentReadIndex());
	messageVectorBuffer->SetReceiveCount(GetReceiveCount());

	return messageVectorBuffer;
}

#endif // NETWORK_NETWORK_MESSAGE_MESSAGE_ARRAY_BUFFER_DETAIL_H