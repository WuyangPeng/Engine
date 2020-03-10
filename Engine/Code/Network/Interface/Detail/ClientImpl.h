// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/01 16:53)

#ifndef NETWORK_NETWORK_INTERFACE_CLIENT_IMPL_H
#define NETWORK_NETWORK_INTERFACE_CLIENT_IMPL_H

#include "Network/NetworkDll.h"

#include "Network/Configuration/ConfigurationStrategy.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/NetworkMessage/SocketManager.h"
#include "Network/NetworkMessage/MessageInterface.h"

namespace Network
{	
	class NETWORK_HIDDEN_DECLARE ClientImpl : public CoreTools::EventInterface
	{
	public:
		using ClassType = ClientImpl;
		using ParentType = EventInterface;
		using EventInterfaceSharedPtr = CoreTools::EventInterfaceSharedPtr;
		 
	public:
		ClientImpl (const ConfigurationStrategy& configurationStrategy,const SocketManagerSharedPtr& socketManager);
		virtual ~ClientImpl();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		virtual uint64_t Connect();
		virtual void AsyncConnect();

		virtual void Send(uint64_t socketID, const MessageInterfaceSharedPtr& message);
		virtual void AsyncSend(uint64_t socketID, const MessageInterfaceSharedPtr& message);

		virtual void Receive();
		virtual void AsyncReceive();
		virtual void ImmediatelySend(uint64_t socketID);
		virtual void ImmediatelyAsyncSend(uint64_t socketID);

		ConfigurationStrategy GetConfigurationStrategy() const;

		virtual uint64_t GetSocketID() const;

	protected:
		SocketManagerSharedPtr GetSocketManagerSharedPtr();

	private:
		virtual bool EventFunction(const CoreTools::CallbackParameters& callbackParameters) override;
		 	 
	private:
		ConfigurationStrategy m_ConfigurationStrategy; 
		SocketManagerWeakPtr m_SocketManager;
	};	
} 

#endif // NETWORK_NETWORK_INTERFACE_CLIENT_IMPL_H
