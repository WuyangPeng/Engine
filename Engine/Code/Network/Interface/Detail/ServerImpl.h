// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/01 16:55)

#ifndef NETWORK_NETWORK_INTERFACE_SERVER_IMPL_H
#define NETWORK_NETWORK_INTERFACE_SERVER_IMPL_H

#include "Network/NetworkDll.h"

#include "Network/Configuration/ConfigurationStrategy.h"
#include "Network/NetworkMessage/SocketManager.h"
#include "Network/NetworkMessage/MessageInterface.h"

namespace Network
{	
	class ConfigurationStrategy;

	class NETWORK_HIDDEN_DECLARE ServerImpl : public CoreTools::EventInterface
	{
	public:
		using ClassType = ServerImpl;
		using ParentType = EventInterface;

	public:
		ServerImpl (const SocketManagerSharedPtr& socketManager, const ConfigurationStrategy& configurationStrategy);
		virtual ~ServerImpl ();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		ConfigurationStrategy GetConfigurationStrategy() const;
		bool RunServer();

		virtual void Send(uint64_t socketID, const MessageInterfaceSharedPtr& message);
		virtual void AsyncSend(uint64_t socketID, const MessageInterfaceSharedPtr& message);

		virtual bool EventFunction(const CoreTools::CallbackParameters& callbackParameters) override;

	protected:
		SocketManagerSharedPtr GetSocketManagerSharedPtr();

	private:		
		virtual bool WaitForMultipleEvents();		 
		virtual bool HandleConnections(const SocketManagerSharedPtr& socketManager);
		virtual bool HandleData(const SocketManagerSharedPtr& socketManager);
		virtual bool ImmediatelySend(); 
		virtual bool ImmediatelySend(uint64_t socketID);
		virtual void ImmediatelyAsyncSend(uint64_t socketID);

	private:
		ConfigurationStrategy m_ConfigurationStrategy;
		SocketManagerWeakPtr m_SocketManagerWeakPtr;
	};
} 

#endif // NETWORK_NETWORK_INTERFACE_SERVER_IMPL_H
