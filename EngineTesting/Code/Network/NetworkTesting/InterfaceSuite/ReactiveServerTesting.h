// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/13 11:38)

#ifndef NETWORK_TESTING_NETWORK_INTERFACE_SUITE_REACTIVE_SERVER_TESTING_H
#define NETWORK_TESTING_NETWORK_INTERFACE_SUITE_REACTIVE_SERVER_TESTING_H

#include "Network/Interface/Client.h"
#include "Network/Interface/NetworkInternalFwd.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTesting.h" 

namespace Network
{
	class ReactiveServerTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(ReactiveServerTesting);

	private:
		void MainTest();
		void CreateMessage();
		void ReactiveServerTest();
		void ClientThread(ClientSharedPtr client);
		void DestroyMessage();

		virtual void DoRunUnitTest() override;

	private:
		int m_Port;
		uint32_t m_ServerSendMessageID;
		uint32_t m_ClientSendMessageID;
		int m_Increase;
	};
}

#endif // NETWORK_TESTING_NETWORK_INTERFACE_SUITE_REACTIVE_SERVER_TESTING_H