// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.2.4 (2020/03/11 15:58)

#include "Network/NetworkExport.h" 

#include "BoostFixedSockStream.h"
#include "BoostSockStreamHelper.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Interface/Data/AddressData.h"
#include "Network/NetworkMessage/MessageBuffer.h"

using std::string;

Network::BoostFixedSockStream
	::BoostFixedSockStream()
	:ParentType{}
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::BoostFixedSockStream
	::~BoostFixedSockStream()
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, BoostFixedSockStream)

int Network::BoostFixedSockStream
	::Receive(const MessageBufferSharedPtr& messageBuffer)
{
	NETWORK_CLASS_IS_VALID_9;

	messageBuffer->ClearCurrentIndex();

	auto receiveSize = HandleReceive(messageBuffer);

	if (receiveSize != 0 && messageBuffer->GetMessageLength() != receiveSize)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("½ÓÊÕÏûÏ¢´íÎó£¡"s));
	}

	return receiveSize;
}

void Network::BoostFixedSockStream
	::AsyncReceive(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer)
{
	NETWORK_CLASS_IS_VALID_9;

	messageBuffer->ClearCurrentIndex();

	HandleAsyncReceive(eventInterface, messageBuffer, messageBuffer->GetCurrentWriteIndex());
}

void Network::BoostFixedSockStream
	::SubclassAsyncReceiveEvent(const ErrorCodeType& errorCode, const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer, int originalWriteIndex)
{
	BoostSockStreamHelper::EventReceiveFunction(errorCode, eventInterface, AddressData{ *this }, messageBuffer->GetCurrentWriteIndex() - originalWriteIndex);
}
