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
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/NetworkMessage/ReceiveMessageLevel.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
using std::make_shared;

Network::ReceiveMessageLevelTesting::ReceiveMessageLevelTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, ReceiveMessageLevelTesting)

void Network::ReceiveMessageLevelTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::ReceiveMessageLevelTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ReceiveMessageTest);
}

void Network::ReceiveMessageLevelTesting::ReceiveMessageTest()
{
    ReceiveMessageLevel receiveMessageLevel = ReceiveMessageLevel::Create();

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
