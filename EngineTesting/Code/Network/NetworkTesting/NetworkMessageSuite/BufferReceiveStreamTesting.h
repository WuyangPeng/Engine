// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/12 11:43)

#ifndef NETWORK_TESTING_NETWORK_MESSAGE_SUITE_BUFFER_RECEIVE_STREAM_TESTING_H
#define NETWORK_TESTING_NETWORK_MESSAGE_SUITE_BUFFER_RECEIVE_STREAM_TESTING_H

#include "Detail/TestNullMessage.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "Network/NetworkMessage/NetworkMessageInternalFwd.h"

namespace Network
{
	class BufferReceiveStreamTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(BufferReceiveStreamTesting);

	private:
		void MainTest();

		void ReceiveTest(int testLoopCount);
		void FinishReceiveTest(int testLoopCount, ParserStrategy parserStrategy);
		void UnFinishReceiveTest(int testLoopCount, ParserStrategy parserStrategy);
		void CopyFinishReceiveTest(int testLoopCount, ParserStrategy parserStrategy);
		void CopyUnFinishReceiveTest(int testLoopCount, ParserStrategy parserStrategy);

		MessageBufferSharedPtr CreateAddMessageBuffer(ParserStrategy parserStrategy) const;
		MessageBufferSharedPtr CreateSendMessageBuffer(int testLoopCount, ParserStrategy parserStrategy) const;
		void AddBufferLength(MessageBuffer& messageBuffer);

		void DoRunUnitTest() override;

	private:
		static constexpr int64_t sm_MessageID{ 6 };
		static constexpr auto sm_BufferSize = 1024;

		TestNullMessageSharedPtr m_TestMessage;
		uint64_t m_SocketID;
	};
}

#endif // NETWORK_TESTING_NETWORK_MESSAGE_SUITE_BUFFER_RECEIVE_STREAM_TESTING_H