///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/16 09:24)

#ifndef NETWORK_TESTING_NETWORK_MESSAGE_SUITE_MESSAGE_BUFFER_TESTING_H
#define NETWORK_TESTING_NETWORK_MESSAGE_SUITE_MESSAGE_BUFFER_TESTING_H

#include "Detail/TestNullMessage.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "Network/NetworkMessage/NetworkMessageInternalFwd.h"

namespace Network
{
    class MessageBufferTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = MessageBufferTesting;
        using ParentType = UnitTest;

    public:
        explicit MessageBufferTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void DoRunUnitTest() override;

        void InitTest();
        void PushBackTest(int aTestLoopCount, ParserStrategy parserStrategy);
        void ExpansionTest(int aTestLoopCount, ParserStrategy parserStrategy);
        void CloneTest(int aTestLoopCount, ParserStrategy parserStrategy);
        void ReadTest(int aTestLoopCount, ParserStrategy parserStrategy);
        void WriteTest(ParserStrategy parserStrategy);
        void BufferedTest(int aTestLoopCount, ParserStrategy parserStrategy);
        void LengthTest(int aTestLoopCount, ParserStrategy parserStrategy);
        void ExpansionExceptionTest(ParserStrategy parserStrategy);
        void CheckingMessageHeadSizeExceptionTest(ParserStrategy parserStrategy);
        void CheckingMessageContentSizeExceptionTest(ParserStrategy parserStrategy);

        void LoopTest(int aTestLoopCount);

        NODISCARD MessageBufferSharedPtr CreateSendMessageBuffer(int aTestLoopCount, ParserStrategy parserStrategy);
        NODISCARD MessageBufferSharedPtr CreateAddMessageBuffer(int aTestLoopCount, ParserStrategy parserStrategy) const;
        void AddBufferLength(int aTestLoopCount, MessageBuffer& messageBuffer);

    private:
        static constexpr auto messageId = 6LL;
        static constexpr auto bufferSize = 1024;

        TestNullMessageSharedPtr testMessage;
    };
}

#endif  // NETWORK_TESTING_NETWORK_MESSAGE_SUITE_MESSAGE_BUFFER_TESTING_H