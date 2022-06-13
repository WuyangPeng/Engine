///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 18:21)

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

        NODISCARD MessageBufferSharedPtr CreateAddMessageBuffer(ParserStrategy parserStrategy) const;
        NODISCARD MessageBufferSharedPtr CreateSendMessageBuffer(int testLoopCount, ParserStrategy parserStrategy) const;
        void AddBufferLength(MessageBuffer& messageBuffer);

        void DoRunUnitTest() override;

    private:
        static constexpr int64_t messageID{ 6 };
        static constexpr auto bufferSize = 1024;

        TestNullMessageSharedPtr testMessage;
        uint64_t socketID;
    };
}

#endif  // NETWORK_TESTING_NETWORK_MESSAGE_SUITE_BUFFER_RECEIVE_STREAM_TESTING_H