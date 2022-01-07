// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎测试版本：0.0.2.3 (2020/03/06 19:04)

#include "TelegramTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/MessageEvent/TelegramDetail.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, TelegramTesting)

namespace CoreTools
{
    using TestingType = Telegram<int>;
}

void CoreTools::TelegramTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(TelegramTest);
}

void CoreTools::TelegramTesting ::TelegramTest()
{
    TestingType telegram2{ 1, 5, 3, 2 };

    const auto sender2 = telegram2.GetSender();
    auto receiverInfo2 = telegram2.GetReceiver();
    auto eventType2 = telegram2.GetMessageType();
    const auto dispatchMillisecondTime2 = telegram2.GetDispatchMillisecondTime();
    auto callbackParameters2 = telegram2.GetCallbackParameters();

    ASSERT_EQUAL(sender2, 1);
    ASSERT_EQUAL_FAILURE_THROW(receiverInfo2.size(), 1u, "接收者数量应该不为空。");
    ASSERT_EQUAL(receiverInfo2.at(0), 5);
    ASSERT_EQUAL(eventType2, 3);
    ASSERT_EQUAL(dispatchMillisecondTime2, 2);
    ASSERT_EQUAL(callbackParameters2.GetContainerSize(), 0);

    CallbackParameters callbackParameters{ 0 };
    callbackParameters.SetValue(0, 10);

    TestingType telegram3{ 1, 5, 3, 2, callbackParameters };

    callbackParameters.SetValue(1, 5);

    const auto sender3 = telegram3.GetSender();
    auto receiverInfo3 = telegram3.GetReceiver();
    auto eventType3 = telegram3.GetMessageType();
    const auto dispatchMillisecondTime3 = telegram3.GetDispatchMillisecondTime();
    auto callbackParameters3 = telegram3.GetCallbackParameters();

    ASSERT_EQUAL(sender3, 1);
    ASSERT_EQUAL_FAILURE_THROW(receiverInfo3.size(), 1u, "接收者数量应该不为空。");
    ASSERT_EQUAL(receiverInfo3.at(0), 5);
    ASSERT_EQUAL(eventType3, 3);
    ASSERT_EQUAL(dispatchMillisecondTime3, 2);
    ASSERT_EQUAL(callbackParameters3.GetContainerSize(), 1);

    const auto value = callbackParameters3.GetInt32Value(0);
    ASSERT_EQUAL(value, 10);

    TestingType telegram4{ 1, 5, 3 };

    const auto sender4 = telegram4.GetSender();
    auto receiverInfo4 = telegram4.GetReceiver();
    auto eventType4 = telegram4.GetMessageType();
    const auto dispatchMillisecondTime4 = telegram4.GetDispatchMillisecondTime();
    auto callbackParameters4 = telegram4.GetCallbackParameters();

    ASSERT_EQUAL(sender4, 1);
    ASSERT_TRUE(receiverInfo4.empty());
    ASSERT_EQUAL(eventType4, 5);
    ASSERT_EQUAL(dispatchMillisecondTime4, 3);
    ASSERT_EQUAL(callbackParameters4.GetContainerSize(), 0);

    TestingType telegram5{ 1, 5, 3, callbackParameters };

    const auto sender5 = telegram5.GetSender();
    auto receiverInfo5 = telegram5.GetReceiver();
    auto eventType5 = telegram5.GetMessageType();
    const auto dispatchMillisecondTime5 = telegram5.GetDispatchMillisecondTime();
    auto callbackParameters5 = telegram5.GetCallbackParameters();

    ASSERT_EQUAL(sender5, 1);
    ASSERT_TRUE(receiverInfo5.empty());
    ASSERT_EQUAL(eventType5, 5);
    ASSERT_EQUAL(dispatchMillisecondTime5, 3);
    ASSERT_EQUAL(callbackParameters5.GetContainerSize(), 2);

    TestingType::ReceiverInfo receiverInfo{ 1, 2, 3, 4, 5 };

    TestingType telegram6{ 1, receiverInfo, 5, 3 };

    const auto sender6 = telegram6.GetSender();
    auto receiverInfo6 = telegram6.GetReceiver();
    auto eventType6 = telegram6.GetMessageType();
    const auto dispatchMillisecondTime6 = telegram6.GetDispatchMillisecondTime();
    auto callbackParameters6 = telegram6.GetCallbackParameters();

    ASSERT_EQUAL(sender6, 1);
    ASSERT_EQUAL(receiverInfo6.size(), 5u);
    ASSERT_EQUAL(eventType6, 5);
    ASSERT_EQUAL(dispatchMillisecondTime6, 3);
    ASSERT_EQUAL(callbackParameters6.GetContainerSize(), 0);

    TestingType telegram7{ 1, receiverInfo, 5, 3, callbackParameters };

    const auto sender7 = telegram7.GetSender();
    auto receiverInfo7 = telegram7.GetReceiver();
    auto eventType7 = telegram7.GetMessageType();
    const auto dispatchMillisecondTime7 = telegram7.GetDispatchMillisecondTime();
    auto callbackParameters7 = telegram7.GetCallbackParameters();

    ASSERT_EQUAL(sender7, 1);
    ASSERT_EQUAL(receiverInfo7.size(), 5u);
    ASSERT_EQUAL(eventType7, 5);
    ASSERT_EQUAL(dispatchMillisecondTime7, 3);
    ASSERT_EQUAL(callbackParameters7.GetContainerSize(), 2);
}
