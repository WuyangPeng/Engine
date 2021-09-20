// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/12 11:54)

#ifndef NETWORK_TESTING_NETWORK_MESSAGE_SUITE_NULL_DOUBLE_MESSAGE_TESTING_H
#define NETWORK_TESTING_NETWORK_MESSAGE_SUITE_NULL_DOUBLE_MESSAGE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Network
{
	class NullDoubleMessageTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(NullDoubleMessageTesting);

	private:
		void MainTest();

		void RttiTest();
		void FactoryTest();
		void StreamingTest();
		void MessageTest();

		virtual void DoRunUnitTest() override;

	private:
		static constexpr int64_t sm_MessageID{ 6 };
		static constexpr int64_t sm_SubMessageID{ 4 };
		static constexpr auto sm_FullMessageID = (sm_MessageID << 32ull) + sm_SubMessageID;
	};
}

#endif // NETWORK_TESTING_NETWORK_MESSAGE_SUITE_NULL_DOUBLE_MESSAGE_TESTING_H