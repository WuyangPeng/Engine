///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/24 11:36)

#include "SendMessageLevelTesting.h"
#include "Detail/TestNullMessage.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Network/NetworkMessage/SendMessageLevel.h"

using std::make_shared;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE_USE_TESTING_TYPE(Network, SendMessageLevel)

void Network::SendMessageLevelTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SendMessageTest);
}

void Network::SendMessageLevelTesting::SendMessageTest()
{
    const auto bufferSize = 8 * GetTestLoopCount();
    TestingType sendMessageLevel{ bufferSize };

    ASSERT_EQUAL(sendMessageLevel.GetTopLevelSize(), 0);
    ASSERT_EQUAL(sendMessageLevel.GetCurrentSize(), 0);
    ASSERT_EQUAL(sendMessageLevel.GetRemainingSize(), bufferSize);

    constexpr int64_t messageID{ 6 };
    TestNullMessageSharedPtr testMessage{ make_shared<TestNullMessage>(messageID) };

    for (auto i = 0; i < GetTestLoopCount(); ++i)
    {
        sendMessageLevel.Insert(testMessage);

        ASSERT_EQUAL(sendMessageLevel.GetTopLevelSize(), i + 1);
        ASSERT_EQUAL(sendMessageLevel.GetCurrentSize(), testMessage->GetStreamingSize() * (i + 1));
        ASSERT_EQUAL(sendMessageLevel.GetRemainingSize(), bufferSize - testMessage->GetStreamingSize() * (i + 1));

        ASSERT_EQUAL(sendMessageLevel[i], testMessage);
    }

    sendMessageLevel.Clear();

    ASSERT_EQUAL(sendMessageLevel.GetTopLevelSize(), 0);
    ASSERT_EQUAL(sendMessageLevel.GetCurrentSize(), 0);
    ASSERT_EQUAL(sendMessageLevel.GetRemainingSize(), bufferSize);
}
