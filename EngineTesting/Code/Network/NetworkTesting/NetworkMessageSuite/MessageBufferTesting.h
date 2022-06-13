///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 18:54)

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

        NODISCARD MessageBufferSharedPtr CreateSendMessageBuffer(int testLoopCount, ParserStrategy parserStrategy) const;
        NODISCARD MessageBufferSharedPtr CreateAddMessageBuffer(int testLoopCount, ParserStrategy parserStrategy) const;
        void AddBufferLength(int testLoopCount, MessageBuffer& messageBuffer);

        void DoRunUnitTest() override;

    private:
        static constexpr int64_t messageID{ 6 };
        static constexpr auto bufferSize = 1024;

        TestNullMessageSharedPtr testMessage;
    };
}

#endif  // NETWORK_TESTING_NETWORK_MESSAGE_SUITE_MESSAGE_BUFFER_TESTING_H