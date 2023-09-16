///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/16 09:23)

#ifndef NETWORK_TESTING_NETWORK_MESSAGE_SUITE_BUFFER_SEND_STREAM_TESTING_H
#define NETWORK_TESTING_NETWORK_MESSAGE_SUITE_BUFFER_SEND_STREAM_TESTING_H

#include "Detail/TestNullMessage.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Network
{
    class BufferSendStreamTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = BufferSendStreamTesting;
        using ParentType = UnitTest;

    public:
        explicit BufferSendStreamTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void DoRunUnitTest() override;

        void SendTest(int aTestLoopCount);
        void FinishSendTest(int aTestLoopCount, ParserStrategy parserStrategy);

    private:
        static constexpr auto messageId = 6LL;
        static constexpr auto bufferSize = 1024;

        TestNullMessageSharedPtr testMessage;
    };
}

#endif  // NETWORK_TESTING_NETWORK_MESSAGE_SUITE_BUFFER_SEND_STREAM_TESTING_H