// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/12 11:49)

#ifndef NETWORK_TESTING_NETWORK_MESSAGE_SUITE_MESSAGE_MANAGER_TESTING_H
#define NETWORK_TESTING_NETWORK_MESSAGE_SUITE_MESSAGE_MANAGER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Network
{
	class MessageManagerTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(MessageManagerTesting);

	private:
		void MainTest();

		void FullVersionTest();
		void ManagerTest();
		void ExceptionTest();

		virtual void DoRunUnitTest() override;
	};
}

#endif // NETWORK_TESTING_NETWORK_MESSAGE_SUITE_MESSAGE_MANAGER_TESTING_H