// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/13 11:32)

#ifndef NETWORK_TESTING_NETWORK_INTERFACE_SUITE_ITERATIVE_SERVER_TESTING_H
#define NETWORK_TESTING_NETWORK_INTERFACE_SUITE_ITERATIVE_SERVER_TESTING_H

#include "Network/Interface/NetworkInternalFwd.h" 
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "Network/Interface/Client.h"
#include "Detail/TestSocketManager.h"

namespace Network
{
	class IterativeServerTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(IterativeServerTesting);

	private:
		void MainTest();
		void CreateMessage();
		void IterativeServerTest();
		void ClientThread(ClientSharedPtr client, TestSocketManagerSharedPtr testSocketManagerSharedPtr);
		void DestroyMessage();

		void DoRunUnitTest() override;

	private:
		int m_Port;
		uint32_t m_MessageID;
		int m_Increase;
	};
}

#endif // NETWORK_TESTING_NETWORK_INTERFACE_SUITE_ITERATIVE_SERVER_TESTING_H