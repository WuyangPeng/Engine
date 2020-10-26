// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.4 (2020/03/11 13:48)

#include "Network/NetworkExport.h" 

#ifdef NETWORK_USE_ACE

#include "ACESockStream.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/MessageEvent/EventInterface.h"
#include "CoreTools/MessageEvent/CallbackParameters.h"
#include "Network/NetworkMessage/MessageBuffer.h"
#include "Network/NetworkMessage/BufferSendStream.h"
#include "Network/NetworkMessage/MessageInterface.h"
#include "Network/NetworkMessage/Flags/MessageEventFlags.h" 
#include "Network/ACEWrappers/Detail/Address/ACESockInetAddress.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "System/Helper/PragmaWarning/NumericCast.h"

using std::string;
using std::array;
#include "System/Helper/PragmaWarning.h" 
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26455) 
#include SYSTEM_WARNING_DISABLE(26415) 
#include SYSTEM_WARNING_DISABLE(26418) 
#include SYSTEM_WARNING_DISABLE(26481) 
#include SYSTEM_WARNING_DISABLE(26490) 
#include SYSTEM_WARNING_DISABLE(26429) 
Network::ACESockStream
	::ACESockStream()
	:ParentType{}, m_ACESockStream{}
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::ACESockStream
	::~ACESockStream()
{
	#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26447)

	EXCEPTION_TRY
	{
		m_ACESockStream.close();
	}
	EXCEPTION_ALL_CATCH(Network)

#include STSTEM_WARNING_POP		

	NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, ACESockStream)

Network::ACESockStreamNativeType& Network::ACESockStream
	::GetACESockStream() noexcept
{
	NETWORK_CLASS_IS_VALID_9;

	return m_ACESockStream;
}

int Network::ACESockStream
	::Receive(const MessageBufferSharedPtr& messageBuffer)
{
	NETWORK_CLASS_IS_VALID_9;

	const auto bytesTotal = messageBuffer->GetSize();

	static constexpr auto headSize = MessageInterface::GetMessageHeadSize();

	if (bytesTotal <= headSize)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("接收消息头容量不足！"s));
	}

	auto buffer = messageBuffer->GetCurrentWriteBufferedPtr();

	const auto recvSize = m_ACESockStream.recv_n(buffer, headSize);

	if (recvSize == headSize)
	{
		messageBuffer->AddCurrentWriteIndex(headSize);

		const auto totalLength = *reinterpret_cast<int*>(buffer);
		if (bytesTotal < totalLength)
		{
			THROW_EXCEPTION(SYSTEM_TEXT("接收数据长度不足！"s));
		}

		const auto remainLength = totalLength - headSize;
		if (m_ACESockStream.recv_n(buffer + headSize, remainLength) != remainLength)
		{
			THROW_EXCEPTION(SYSTEM_TEXT("接收数据长度错误！"s));
		}

		messageBuffer->AddCurrentWriteIndex(remainLength);

		return totalLength;
	}
	else
	{
		return 0;
	}
}

int Network::ACESockStream
	::Send(const MessageBufferSharedPtr& messageBuffer)
{
	NETWORK_CLASS_IS_VALID_9;

	if (m_ACESockStream.send_n(messageBuffer->GetInitialBufferedPtr(), messageBuffer->GetCurrentWriteIndex()) != messageBuffer->GetCurrentWriteIndex())
	{
		THROW_EXCEPTION(SYSTEM_TEXT("发送数据失败！"s));
	}

	return  messageBuffer->GetSize();
}

Network::ACEHandle Network::ACESockStream
	::GetACEHandle() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return m_ACESockStream.get_handle();
}

void Network::ACESockStream
	::SetACEHandle(ACEHandle handle)
{
	NETWORK_CLASS_IS_VALID_9;

	m_ACESockStream.set_handle(handle);
}

bool Network::ACESockStream
	::CloseHandle()
{
	NETWORK_CLASS_IS_VALID_9;

	if (m_ACESockStream.close() == 0)
	{
		m_ACESockStream.set_handle(reinterpret_cast<ACEHandle>(System::g_InvalidSocket));

		return true;
	}
	else
	{
		return false;
	}
}

void Network::ACESockStream
	::AsyncSend(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer)
{
	NETWORK_CLASS_IS_VALID_9;

	if (m_ACESockStream.send_n(messageBuffer->GetInitialBufferedPtr(), messageBuffer->GetCurrentWriteIndex()) != messageBuffer->GetCurrentWriteIndex())
	{
		THROW_EXCEPTION(SYSTEM_TEXT("发送数据失败！"s));
	}

	CoreTools::CallbackParameters callbackParameters{};
	callbackParameters.SetValue(0, System::EnumCastUnderlying(SocketManagerEvent::AsyncSend));
	callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::WrappersStrategy), System::EnumCastUnderlying(WrappersStrategy::ACE));
        if (!eventInterface->EventFunction(callbackParameters))
        {
        }
}

void Network::ACESockStream
	::AsyncReceive(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer)
{
	NETWORK_CLASS_IS_VALID_9;

	const auto bytesTotal = messageBuffer->GetSize();

	static constexpr auto headSize = MessageInterface::GetMessageHeadSize();

	if (bytesTotal <= headSize)
	{
		return;
	}

	auto buffer = messageBuffer->GetCurrentWriteBufferedPtr();

	const auto recvSize = m_ACESockStream.recv_n(buffer, headSize);

	if (recvSize == headSize)
	{
		messageBuffer->AddCurrentWriteIndex(headSize);

		const auto totalLength = *reinterpret_cast<int*>(buffer);
		if (bytesTotal < totalLength)
		{
			return;
		}

		const auto remainLength = totalLength - headSize;
		if (m_ACESockStream.recv_n(buffer + headSize, remainLength) != remainLength)
		{
			return;
		}

		messageBuffer->AddCurrentWriteIndex(remainLength);

		CoreTools::CallbackParameters callbackParameters{};
		callbackParameters.SetValue(0, System::EnumCastUnderlying(SocketManagerEvent::AsyncReceive));
		callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::WrappersStrategy), System::EnumCastUnderlying(WrappersStrategy::ACE));
                if (!eventInterface->EventFunction(callbackParameters))
                {
                }
	}
	else
	{
		return;
	}
}

const std::string Network::ACESockStream
	::GetRemoteAddress() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	ACESockInetAddress address;

	if (m_ACESockStream.get_remote_addr(address.GetACEInetAddress()) == 0)
	{
		return address.GetAddress();
	}
	else
	{
		return "";
	}
}

int Network::ACESockStream
	::GetRemotePort() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	ACESockInetAddress address;

	if (m_ACESockStream.get_remote_addr(address.GetACEInetAddress()) == 0)
	{
		return address.GetPort();
	}
	else
	{
		return 0;
	}
}

bool Network::ACESockStream
	::EnableNonBlock()
{
	NETWORK_CLASS_IS_VALID_9;

	if (m_ACESockStream.enable(g_NonBlock) == 0)
		return true;
	else
		return false;
}
#include STSTEM_WARNING_POP
#endif // NETWORK_USE_ACE