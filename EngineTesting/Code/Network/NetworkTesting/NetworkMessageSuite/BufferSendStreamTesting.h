// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/12 11:43)

#ifndef NETWORK_TESTING_NETWORK_MESSAGE_SUITE_BUFFER_SEND_STREAM_TESTING_H
#define NETWORK_TESTING_NETWORK_MESSAGE_SUITE_BUFFER_SEND_STREAM_TESTING_H

#include "Detail/TestNullMessage.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "Network/NetworkMessage/NetworkMessageInternalFwd.h"

namespace Network
{
	class BufferSendStreamTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(BufferSendStreamTesting);

	private:
		void MainTest();

		void SendTest(int testLoopCount);
		void FinishSendTest(int testLoopCount, ParserStrategy parserStrategy);

		virtual void DoRunUnitTest() override;

	private:
		static constexpr int64_t sm_MessageID{ 6 };
		static constexpr auto sm_BufferSize = 1024;

		TestNullMessageSharedPtr m_TestMessage;
	};
}

#endif // NETWORK_TESTING_NETWORK_MESSAGE_SUITE_BUFFER_SEND_STREAM_TESTING_H