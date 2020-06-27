// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.2.4 (2020/03/11 16:33)

#include "Network/NetworkExport.h" 

#include "NetworkSockStream.h"
#include "System/Helper/UnusedMacro.h"
#include "System/Network/SocketPrototypes.h"
#include "System/Network/Flags/SocketPrototypesFlags.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/NetworkMessage/MessageBuffer.h"

using std::string;

Network::NetworkSockStream
	::NetworkSockStream()
	:ParentType{}, m_WinSocket{ 0 }
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::NetworkSockStream
	::~NetworkSockStream()
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, NetworkSockStream)

int Network::NetworkSockStream
	::Receive(const MessageBufferSharedPtr& messageBuffer)
{
	NETWORK_CLASS_IS_VALID_9;

	return System::Recv(m_WinSocket, messageBuffer->GetCurrentWriteBufferedPtr(), messageBuffer->GetSize(), System::SocketRecv::Default);
}

int Network::NetworkSockStream
	::Send(const MessageBufferSharedPtr& messageBuffer)
{
	NETWORK_CLASS_IS_VALID_9;

	return System::Send(m_WinSocket, messageBuffer->GetInitialBufferedPtr(), messageBuffer->GetSize(), System::SocketSend::Default);
}

void Network::NetworkSockStream
	::AsyncReceive(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer)
{
	NETWORK_CLASS_IS_VALID_9;

	System::Recv(m_WinSocket, messageBuffer->GetCurrentWriteBufferedPtr(), messageBuffer->GetSize(), System::SocketRecv::Default);

	SYSTEM_UNUSED_ARG(eventInterface);
}

void Network::NetworkSockStream
	::AsyncSend(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer)
{
	NETWORK_CLASS_IS_VALID_9;

	System::Send(m_WinSocket, messageBuffer->GetInitialBufferedPtr(), messageBuffer->GetSize(), System::SocketSend::Default);

	SYSTEM_UNUSED_ARG(eventInterface);
}

Network::WinSocketStreamType& Network::NetworkSockStream
	::GetNetworkSockStream()
{
	NETWORK_CLASS_IS_VALID_9;

	return m_WinSocket;
}

bool Network::NetworkSockStream
	::CloseHandle()
{
	NETWORK_CLASS_IS_VALID_9;

	System::CloseSocket(m_WinSocket);

	return true;
}

void Network::NetworkSockStream
	::SetNetworkHandle(WinSocketStreamType winSocket)
{
	NETWORK_CLASS_IS_VALID_9;

	m_WinSocket = winSocket;
}

bool Network::NetworkSockStream
	::EnableNonBlock()
{
	NETWORK_CLASS_IS_VALID_9;

	unsigned long nonblock{ 1 };
	return System::IoctlSocket(m_WinSocket, System::IoctlSocketCmd::FionBio, &nonblock);
}

const std::string Network::NetworkSockStream
	::GetRemoteAddress() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return "";
}

int Network::NetworkSockStream
	::GetRemotePort() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return 0;
}

