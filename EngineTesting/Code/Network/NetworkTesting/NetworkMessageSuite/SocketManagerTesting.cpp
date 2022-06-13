///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/24 11:36)

#include "SocketManagerTesting.h"
#include "Detail/NullSocketManager.h"
#include "Detail/TestNullMessage.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/MessageEvent/CallbackParameters.h"

using std::make_shared;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Network, SocketManagerTesting)

void Network::SocketManagerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ManagerTest);
}

void Network::SocketManagerTesting::ManagerTest()
{
    constexpr int64_t messageID{ 6 };
    NullSocketManager nullSocketManager{ messageID };
    ASSERT_EQUAL(nullSocketManager.GetSocketSize(), 0);

    constexpr uint64_t socketID{ 1 };
    nullSocketManager.InsertSocket(socketID);
    ASSERT_EQUAL(nullSocketManager.GetSocketSize(), 1);

    TestNullMessageSharedPtr testMessage{ make_shared<TestNullMessage>(messageID) };

    nullSocketManager.OnEvent(socketID, messageID, testMessage);
    ASSERT_EQUAL(nullSocketManager.GetValue(), messageID);

    nullSocketManager.OnEvent(socketID, messageID, testMessage);
    ASSERT_EQUAL(nullSocketManager.GetValue(), messageID * 2);

    ASSERT_TRUE(nullSocketManager.EventFunction(CoreTools::CallbackParameters{ 0 }));

    nullSocketManager.RemoveSocket(socketID);

    ASSERT_EQUAL(nullSocketManager.GetSocketSize(), 0);

    nullSocketManager.OnEvent(socketID, messageID, testMessage);
    ASSERT_EQUAL(nullSocketManager.GetValue(), messageID * 2);
}
