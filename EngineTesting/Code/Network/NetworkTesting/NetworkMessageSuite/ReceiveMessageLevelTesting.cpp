///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/24 11:36)

#include "ReceiveMessageLevelTesting.h"
#include "Detail/TestNullMessage.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Network/NetworkMessage/ReceiveMessageLevel.h"

using std::make_shared;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE_USE_TESTING_TYPE(Network, ReceiveMessageLevel)

void Network::ReceiveMessageLevelTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ReceiveMessageTest);
}

void Network::ReceiveMessageLevelTesting::ReceiveMessageTest()
{
    TestingType receiveMessageLevel = TestingType::Create();

    ASSERT_EQUAL(receiveMessageLevel.GetTopLevelSize(), 0);

    constexpr int64_t messageID{ 6 };
    TestNullMessageSharedPtr testMessage{ make_shared<TestNullMessage>(messageID) };

    for (auto i = 0; i < GetTestLoopCount(); ++i)
    {
        receiveMessageLevel.Insert(testMessage);

        ASSERT_EQUAL(receiveMessageLevel.GetTopLevelSize(), i + 1);

        ASSERT_EQUAL(receiveMessageLevel[i], testMessage);
    }
}
