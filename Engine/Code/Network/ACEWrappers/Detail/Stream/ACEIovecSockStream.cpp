// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/01 20:21)

#include "Network/NetworkExport.h" 

#ifdef NETWORK_USE_ACE

#include "ACEIovecSockStream.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/MessageEvent/CallbackParameters.h"
#include "CoreTools/MessageEvent/EventInterface.h"
#include "Network/NetworkMessage/MessageBuffer.h"
#include "Network/NetworkMessage/BufferSendStream.h"
#include "Network/NetworkMessage/MessageInterface.h"
#include "Network/NetworkMessage/Flags/MessageEventFlags.h"

#include <boost/numeric/conversion/cast.hpp>
#include <array>
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"

using std::string;
using std::array;

Network::ACEIovecSockStream
	::ACEIovecSockStream()
	:ParentType{}
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::ACEIovecSockStream
	::~ACEIovecSockStream()
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, ACEIovecSockStream)

int Network::ACEIovecSockStream
	::Send(const MessageBufferSharedPtr& messageBuffer)
{
	NETWORK_CLASS_IS_VALID_9;

	static const auto headSize = boost::numeric_cast<int>(MessageInterface::GetMessageHeadSize());

	if(messageBuffer->GetCurrentWriteIndex() <= headSize)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("数据大小错误！"));
	}

	array<iovec,2> iov;
	iov[0].iov_base = const_cast<char*>(messageBuffer->GetInitialBufferedPtr());
	iov[0].iov_len  = headSize;
	iov[1].iov_base = const_cast<char*>(messageBuffer->GetInitialBufferedPtr()) + headSize;
	iov[1].iov_len  = messageBuffer->GetCurrentWriteIndex() - headSize;

	if (GetACESockStream().sendv_n(iov.data(), 2) != messageBuffer->GetCurrentWriteIndex())
	{
		THROW_EXCEPTION(SYSTEM_TEXT("发送数据失败！"));
	}	 

	return messageBuffer->GetCurrentWriteIndex();
}

void Network::ACEIovecSockStream
	::AsyncSend(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer)
{
	Send(messageBuffer);

	CoreTools::CallbackParameters callbackParameters{};
	callbackParameters.SetValue(0, System::EnumCastUnderlying(SocketManagerEvent::AsyncSend));
	callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::WrappersStrategy), System::EnumCastUnderlying(WrappersStrategy::ACE));
	eventInterface->EventFunction(callbackParameters);
}

#endif // NETWORK_USE_ACE