// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/11 10:55)

#include "Network/NetworkExport.h" 

#include "SendSocketManager.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

Network::SendSocketManager
	::SendSocketManager(const std::string& fileName)
{
	fileName;

	NETWORK_SELF_CLASS_IS_VALID_9;
} 

CLASS_INVARIANT_STUB_DEFINE(Network, SendSocketManager)

void Network::SendSocketManager
	::Send(SocketType socketType, int serverID, uint64_t socketID, const MessageInterfaceSharedPtr& message)
{
	NETWORK_CLASS_IS_VALID_9;

	socketID;

	message;

	socketType;
	 
	serverID;
}



Network::SocketManagerSharedPtr Network::SendSocketManager::GetSocketManager(SocketType socketType, int serverID)
{
	NETWORK_CLASS_IS_VALID_9;

	socketType;

	serverID;

	return nullptr;
}

void Network::SendSocketManager::Insert(SocketType socketType, int serverID, int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent)
{
	socketType; serverID; messageID; messageEvent;
}

void Network::SendSocketManager::Insert(SocketType socketType, int serverID, int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent, MessageEventPriority priority)
{
	socketType; serverID; messageID; messageEvent; priority;
}

void Network::SendSocketManager::Remove(SocketType socketType, int serverID, int64_t messageID)
{
	socketType; serverID; messageID;
}

void Network::SendSocketManager::HandlingMessages()
{

}

void Network::SendSocketManager::Destroy()
{

}

void Network::SendSocketManager::Remove(SocketType socketType, int serverID, int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent)
{
	socketType; serverID; messageID; messageEvent;
}

std::vector<std::pair<Network::SocketType, int>>::const_iterator Network::SendSocketManager::begin()
{
	return std::vector<std::pair<SocketType, int>>::const_iterator();
}

std::vector<std::pair<Network::SocketType, int>>::const_iterator Network::SendSocketManager::end()
{
	return std::vector<std::pair<SocketType, int>>::const_iterator();
}
