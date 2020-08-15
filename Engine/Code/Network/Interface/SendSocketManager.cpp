// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/11 10:55)

#include "Network/NetworkExport.h" 

#include "SendSocketManager.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/ClassInvariant/Noexcept.h"

#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26418)

Network::SendSocketManager
	::SendSocketManager(const std::string& fileName)
{
	fileName;

	CoreTools::DoNothing();

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
        CoreTools::DoNothing();
}



Network::SocketManagerSharedPtr Network::SendSocketManager::GetSocketManager(SocketType socketType, int serverID)
{
	NETWORK_CLASS_IS_VALID_9;

	socketType;
        CoreTools::DoNothing();
	serverID;

	return nullptr;
}

void Network::SendSocketManager::Insert(SocketType socketType, int serverID, int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent)
{
    CoreTools::DoNothing();
	socketType; serverID; messageID; messageEvent;
}

void Network::SendSocketManager::Insert(SocketType socketType, int serverID, int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent, MessageEventPriority priority)
{
    CoreTools::DoNothing();
	socketType; serverID; messageID; messageEvent; priority;
}

void Network::SendSocketManager::Remove(SocketType socketType, int serverID, int64_t messageID)
{
    CoreTools::DoNothing();
	socketType; serverID; messageID;
}

void Network::SendSocketManager::HandlingMessages()
{
    CoreTools::DoNothing();
}

void Network::SendSocketManager::Destroy()
{
    CoreTools::DoNothing();
}

void Network::SendSocketManager::Remove(SocketType socketType, int serverID, int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent)
{
    CoreTools::DoNothing();
	socketType; serverID; messageID; messageEvent;
}

std::vector<std::pair<Network::SocketType, int>>::const_iterator Network::SendSocketManager::begin()
{
    CoreTools::DoNothing();
	return std::vector<std::pair<SocketType, int>>::const_iterator();
}

std::vector<std::pair<Network::SocketType, int>>::const_iterator Network::SendSocketManager::end()
{
    CoreTools::DoNothing();
	return std::vector<std::pair<SocketType, int>>::const_iterator();
}
#include STSTEM_WARNING_POP