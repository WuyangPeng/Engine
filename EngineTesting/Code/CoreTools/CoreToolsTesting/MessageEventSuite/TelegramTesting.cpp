///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/18 15:31)

#include "TelegramTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/MessageEvent/TelegramDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::TelegramTesting::TelegramTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, TelegramTesting)

void CoreTools::TelegramTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

namespace CoreTools
{
    using TestingType = Telegram<int>;
}

void CoreTools::TelegramTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(TelegramTest);
}

void CoreTools::TelegramTesting::TelegramTest()
{
    TestingType telegram0{ 1, 5, 3, 2 };

    const auto sender0 = telegram0.GetSender();
    const auto receiverInfo0 = telegram0.GetReceiver();
    const auto eventType0 = telegram0.GetMessageType();
    const auto dispatchMillisecondTime0 = telegram0.GetDispatchMillisecondTime();
    const auto callbackParameters0 = telegram0.GetCallbackParameters();

    ASSERT_EQUAL(sender0, 1);
    ASSERT_EQUAL_FAILURE_THROW(receiverInfo0.size(), 1u, "接收者数量应该不为空。");
    ASSERT_EQUAL(receiverInfo0.at(0), 5);
    ASSERT_EQUAL(eventType0, 3);
    ASSERT_EQUAL(dispatchMillisecondTime0, 2);
    ASSERT_EQUAL(callbackParameters0.GetContainerSize(), 0);

    CallbackParameters callbackParameters{ 0 };
    callbackParameters.SetValue(0, 10);

    TestingType telegram1{ 1, 5, 3, 2, callbackParameters };

    callbackParameters.SetValue(1, 5);

    const auto sender1 = telegram1.GetSender();
    const auto receiverInfo1 = telegram1.GetReceiver();
    const auto eventType1 = telegram1.GetMessageType();
    const auto dispatchMillisecondTime1 = telegram1.GetDispatchMillisecondTime();
    const auto callbackParameters1 = telegram1.GetCallbackParameters();

    ASSERT_EQUAL(sender1, 1);
    ASSERT_EQUAL_FAILURE_THROW(receiverInfo1.size(), 1u, "接收者数量应该不为空。");
    ASSERT_EQUAL(receiverInfo1.at(0), 5);
    ASSERT_EQUAL(eventType1, 3);
    ASSERT_EQUAL(dispatchMillisecondTime1, 2);
    ASSERT_EQUAL(callbackParameters1.GetContainerSize(), 1);

    const auto value = callbackParameters1.GetInt32Value(0);
    ASSERT_EQUAL(value, 10);

    TestingType telegram2{ 1, 5, 3 };

    const auto sender2 = telegram2.GetSender();
    const auto receiverInfo2 = telegram2.GetReceiver();
    const auto eventType2 = telegram2.GetMessageType();
    const auto dispatchMillisecondTime2 = telegram2.GetDispatchMillisecondTime();
    const auto callbackParameters2 = telegram2.GetCallbackParameters();

    ASSERT_EQUAL(sender2, 1);
    ASSERT_TRUE(receiverInfo2.empty());
    ASSERT_EQUAL(eventType2, 5);
    ASSERT_EQUAL(dispatchMillisecondTime2, 3);
    ASSERT_EQUAL(callbackParameters2.GetContainerSize(), 0);

    TestingType telegram3{ 1, 5, 3, callbackParameters };

    const auto sender3 = telegram3.GetSender();
    const auto receiverInfo3 = telegram3.GetReceiver();
    const auto eventType3 = telegram3.GetMessageType();
    const auto dispatchMillisecondTime3 = telegram3.GetDispatchMillisecondTime();
    const auto callbackParameters3 = telegram3.GetCallbackParameters();

    ASSERT_EQUAL(sender3, 1);
    ASSERT_TRUE(receiverInfo3.empty());
    ASSERT_EQUAL(eventType3, 5);
    ASSERT_EQUAL(dispatchMillisecondTime3, 3);
    ASSERT_EQUAL(callbackParameters3.GetContainerSize(), 2);

    TestingType::ReceiverInfo receiverInfo{ 1, 2, 3, 4, 5 };

    TestingType telegram4{ 1, receiverInfo, 5, 3 };

    const auto sender4 = telegram4.GetSender();
    const auto receiverInfo4 = telegram4.GetReceiver();
    const auto eventType4 = telegram4.GetMessageType();
    const auto dispatchMillisecondTime4 = telegram4.GetDispatchMillisecondTime();
    const auto callbackParameters4 = telegram4.GetCallbackParameters();

    ASSERT_EQUAL(sender4, 1);
    ASSERT_EQUAL(receiverInfo4.size(), 5u);
    ASSERT_EQUAL(eventType4, 5);
    ASSERT_EQUAL(dispatchMillisecondTime4, 3);
    ASSERT_EQUAL(callbackParameters4.GetContainerSize(), 0);

    TestingType telegram5{ 1, receiverInfo, 5, 3, callbackParameters };

    const auto sender5 = telegram5.GetSender();
    const auto receiverInfo5 = telegram5.GetReceiver();
    const auto eventType5 = telegram5.GetMessageType();
    const auto dispatchMillisecondTime5 = telegram5.GetDispatchMillisecondTime();
    const auto callbackParameters5 = telegram5.GetCallbackParameters();

    ASSERT_EQUAL(sender5, 1);
    ASSERT_EQUAL(receiverInfo5.size(), 5u);
    ASSERT_EQUAL(eventType5, 5);
    ASSERT_EQUAL(dispatchMillisecondTime5, 3);
    ASSERT_EQUAL(callbackParameters5.GetContainerSize(), 2);
}
