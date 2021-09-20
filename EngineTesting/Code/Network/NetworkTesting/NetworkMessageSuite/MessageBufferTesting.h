// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/12 11:45)

#ifndef NETWORK_TESTING_NETWORK_MESSAGE_SUITE_MESSAGE_BUFFER_TESTING_H
#define NETWORK_TESTING_NETWORK_MESSAGE_SUITE_MESSAGE_BUFFER_TESTING_H

#include "Detail/TestNullMessage.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "Network/NetworkMessage/NetworkMessageInternalFwd.h"

namespace Network
{
	class MessageBufferTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(MessageBufferTesting);

	private:
		void MainTest();

		void InitTest();
		void PushBackTest(int testLoopCount, ParserStrategy parserStrateg);
		void ExpansionTest(int testLoopCount, ParserStrategy parserStrategy);
		void CloneTest(int testLoopCount, ParserStrategy parserStrategy);
		void ReadTest(int testLoopCount, ParserStrategy parserStrategy);
		void WriteTest(ParserStrategy parserStrategy);
		void BufferedTest(int testLoopCount, ParserStrategy parserStrategy);
		void LengthTest(int testLoopCount, ParserStrategy parserStrategy);
		void ExpansionExceptionTest(ParserStrategy parserStrategy);
		void CheckingMessageHeadSizeExceptionTest(ParserStrategy parserStrategy);
		void CheckingMessageContentSizeExceptionTest(ParserStrategy parserStrategy);

		void LoopTest(int testLoopCount);

		MessageBufferSharedPtr CreateSendMessageBuffer(int testLoopCount, ParserStrategy parserStrategy) const;
		MessageBufferSharedPtr CreateAddMessageBuffer(int testLoopCount, ParserStrategy parserStrategy) const;
		void AddBufferLength(int testLoopCount, MessageBufferSharedPtr& messageBuffer);

		virtual void DoRunUnitTest() override;

	private:
		static constexpr int64_t sm_MessageID{ 6 };
		static constexpr auto sm_BufferSize = 1024;

		TestNullMessageSharedPtr m_TestMessage;
	};
}

#endif // NETWORK_TESTING_NETWORK_MESSAGE_SUITE_MESSAGE_BUFFER_TESTING_H