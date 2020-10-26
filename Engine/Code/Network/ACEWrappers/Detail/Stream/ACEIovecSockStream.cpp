// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.4 (2020/03/11 13:48)

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
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"

#include "System/Helper/PragmaWarning/NumericCast.h"
#include <array>

using std::string;
using std::array;
#include "System/Helper/PragmaWarning.h" 
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455) 
#include SYSTEM_WARNING_DISABLE(26415) 
#include SYSTEM_WARNING_DISABLE(26418) 
#include SYSTEM_WARNING_DISABLE(26465) 
#include SYSTEM_WARNING_DISABLE(26446) 
#include SYSTEM_WARNING_DISABLE(26481) 
Network::ACEIovecSockStream
	::ACEIovecSockStream()
	:ParentType{}
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

 

CLASS_INVARIANT_STUB_DEFINE(Network, ACEIovecSockStream)

int Network::ACEIovecSockStream
	::Send(const MessageBufferSharedPtr& messageBuffer)
{
	NETWORK_CLASS_IS_VALID_9;

	static constexpr auto headSize = MessageInterface::GetMessageHeadSize();

	if (messageBuffer->GetCurrentWriteIndex() <= headSize)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("数据大小错误！"s));
	}

	array<iovec, 2> iov;
	iov[0].iov_base = const_cast<char*>(messageBuffer->GetInitialBufferedPtr());
	iov[0].iov_len = headSize;
	iov[1].iov_base = const_cast<char*>(messageBuffer->GetInitialBufferedPtr()) + headSize;
	iov[1].iov_len = messageBuffer->GetCurrentWriteIndex() - headSize;

	if (GetACESockStream().sendv_n(iov.data(), 2) != messageBuffer->GetCurrentWriteIndex())
	{
		THROW_EXCEPTION(SYSTEM_TEXT("发送数据失败！"s));
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
        if (!eventInterface->EventFunction(callbackParameters))
        {
        }
}
#include STSTEM_WARNING_POP
#endif // NETWORK_USE_ACE