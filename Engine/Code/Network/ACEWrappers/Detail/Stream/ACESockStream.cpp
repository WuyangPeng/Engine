// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/01 20:22)

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

#include <boost/numeric/conversion/cast.hpp>
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"

using std::string;
using std::array;

Network::ACESockStream
	::ACESockStream()
	:ParentType{}, m_ACESockStream{}
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::ACESockStream
	::~ACESockStream()
{
	m_ACESockStream.close();

	NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, ACESockStream)

Network::ACESockStreamNativeType& Network::ACESockStream
	::GetACESockStream()
{
	NETWORK_CLASS_IS_VALID_9;

	return m_ACESockStream;
}

int Network::ACESockStream
	::Receive(const MessageBufferSharedPtr& messageBuffer)
{
	NETWORK_CLASS_IS_VALID_9;

	auto bytesTotal = messageBuffer->GetSize();

	static const int headSize = boost::numeric_cast<int>(MessageInterface::GetMessageHeadSize());

	if (bytesTotal <= headSize)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("接收消息头容量不足！"));
	}

	auto buffer = messageBuffer->GetCurrentWriteBufferedPtr();

	auto recvSize = m_ACESockStream.recv_n(buffer, headSize);

	if (recvSize == headSize)
	{
		messageBuffer->AddCurrentWriteIndex(headSize);

		auto totalLength = *reinterpret_cast<int*>(buffer);
		if (bytesTotal < totalLength)
		{
			THROW_EXCEPTION(SYSTEM_TEXT("接收数据长度不足！"));
		}

		auto remainLength = totalLength - headSize;
		if (m_ACESockStream.recv_n(buffer + headSize, remainLength) != remainLength)
		{
			THROW_EXCEPTION(SYSTEM_TEXT("接收数据长度错误！"));
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
		THROW_EXCEPTION(SYSTEM_TEXT("发送数据失败！"));
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
	::SetACEHandle( ACEHandle handle )
{
	NETWORK_CLASS_IS_VALID_9;

	m_ACESockStream.set_handle(handle);
}

bool Network::ACESockStream
	::CloseHandle()
{
	NETWORK_CLASS_IS_VALID_9;

	if(m_ACESockStream.close() == 0)
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
		THROW_EXCEPTION(SYSTEM_TEXT("发送数据失败！"));
	}

	CoreTools::CallbackParameters callbackParameters{};
	callbackParameters.SetValue(0, System::EnumCastUnderlying(SocketManagerEvent::AsyncSend));
	callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::WrappersStrategy), System::EnumCastUnderlying(WrappersStrategy::ACE));
	eventInterface->EventFunction(callbackParameters); 
}

void Network::ACESockStream
	::AsyncReceive(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer)
{
	NETWORK_CLASS_IS_VALID_9;

	auto bytesTotal = messageBuffer->GetSize();

	static const auto headSize = boost::numeric_cast<int>(MessageInterface::GetMessageHeadSize());

	if (bytesTotal <= headSize)
	{
		return;
	}

	auto buffer = messageBuffer->GetCurrentWriteBufferedPtr();

	auto recvSize = m_ACESockStream.recv_n(buffer, headSize);

	if (recvSize == headSize)
	{
		messageBuffer->AddCurrentWriteIndex(headSize);

		auto totalLength = *reinterpret_cast<int*>(buffer);
		if (bytesTotal < totalLength)
		{
			return;
		}

		auto remainLength = totalLength - headSize;
		if (m_ACESockStream.recv_n(buffer + headSize, remainLength) != remainLength)
		{
			return;
		}

		messageBuffer->AddCurrentWriteIndex(remainLength);

		CoreTools::CallbackParameters callbackParameters{};
		callbackParameters.SetValue(0, System::EnumCastUnderlying(SocketManagerEvent::AsyncReceive));
		callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::WrappersStrategy), System::EnumCastUnderlying(WrappersStrategy::ACE));
		eventInterface->EventFunction(callbackParameters);
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

#endif // NETWORK_USE_ACE