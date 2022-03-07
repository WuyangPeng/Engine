// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/12 11:55)

#ifndef NETWORK_TESTING_NETWORK_MESSAGE_SUITE_STRING_DOUBLE_MESSAGE_TESTING_H
#define NETWORK_TESTING_NETWORK_MESSAGE_SUITE_STRING_DOUBLE_MESSAGE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Network
{
	class StringDoubleMessageTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(StringDoubleMessageTesting);

	private:
		void MainTest();

		void RttiTest();
		void FactoryTest();
		void StreamingTest();
		void MessageTest();

		void DoRunUnitTest() override;

	private:
		static constexpr int64_t sm_MessageID{ 6 };
		static constexpr int64_t sm_SubMessageID{ 4 };
		static constexpr auto sm_FullMessageID = (sm_MessageID << 32ull) + sm_SubMessageID;
	};
}

#endif // NETWORK_TESTING_NETWORK_MESSAGE_SUITE_STRING_DOUBLE_MESSAGE_TESTING_H