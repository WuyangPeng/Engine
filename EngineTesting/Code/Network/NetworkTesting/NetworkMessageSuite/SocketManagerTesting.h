// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/12 11:55)

#ifndef NETWORK_TESTING_NETWORK_MESSAGE_SUITE_SOCKET_MANAGER_TESTING_H
#define NETWORK_TESTING_NETWORK_MESSAGE_SUITE_SOCKET_MANAGER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Network
{
	class SocketManagerTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(SocketManagerTesting);

	private:
		void MainTest();
		void ManagerTest();

		virtual void DoRunUnitTest() override;
	};
}

#endif // NETWORK_TESTING_NETWORK_MESSAGE_SUITE_SOCKET_MANAGER_TESTING_H