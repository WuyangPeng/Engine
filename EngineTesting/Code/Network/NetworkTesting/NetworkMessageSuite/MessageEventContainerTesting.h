// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/12 11:47)

#ifndef NETWORK_TESTING_NETWORK_MESSAGE_SUITE_MESSAGE_EVENT_CONTAINER_TESTING_H
#define NETWORK_TESTING_NETWORK_MESSAGE_SUITE_MESSAGE_EVENT_CONTAINER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Network
{
	class MessageEventContainerTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(MessageEventContainerTesting);

	private:
		void MainTest();

		void SingleContainerTest();
		void PriorityContainerTest();
		void MultiContainerTest();

		virtual void DoRunUnitTest() override;
	};
}

#endif // NETWORK_TESTING_NETWORK_MESSAGE_SUITE_MESSAGE_EVENT_CONTAINER_TESTING_H