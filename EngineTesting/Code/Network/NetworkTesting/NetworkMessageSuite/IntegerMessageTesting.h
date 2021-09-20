// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/12 11:45)

#ifndef NETWORK_TESTING_NETWORK_MESSAGE_SUITE_INTEGER_MESSAGE_TESTING_H
#define NETWORK_TESTING_NETWORK_MESSAGE_SUITE_INTEGER_MESSAGE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Network
{
	class IntegerMessageTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(IntegerMessageTesting);

	private:
		void MainTest();

		void RttiTest();
		void FactoryTest();
		void StreamingTest();
		void MessageTest();

		virtual void DoRunUnitTest() override;

	private:
		static constexpr int64_t sm_MessageID{ 6 };
	};
}

#endif // NETWORK_TESTING_NETWORK_MESSAGE_SUITE_INTEGER_MESSAGE_TESTING_H