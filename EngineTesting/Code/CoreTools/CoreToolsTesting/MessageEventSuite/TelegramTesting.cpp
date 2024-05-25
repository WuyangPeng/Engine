/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/05/19 19:54)

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

void CoreTools::TelegramTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(Telegram0Test);
    ASSERT_NOT_THROW_EXCEPTION_0(Telegram1Test);
    ASSERT_NOT_THROW_EXCEPTION_0(Telegram2Test);
    ASSERT_NOT_THROW_EXCEPTION_0(Telegram3Test);
    ASSERT_NOT_THROW_EXCEPTION_0(Telegram4Test);
    ASSERT_NOT_THROW_EXCEPTION_0(Telegram5Test);
}

void CoreTools::TelegramTesting::Telegram0Test()
{
    const TestingType telegram{ 1, 5, 3, 2 };

    const auto sender = telegram.GetSender();
    const auto receiverInfo = telegram.GetReceiver();
    const auto eventType = telegram.GetMessageType();
    const auto dispatchMillisecondTime = telegram.GetDispatchMillisecondTime();
    const auto callbackParameters = telegram.GetCallbackParameters();

    ASSERT_EQUAL(sender, 1);
    ASSERT_EQUAL_FAILURE_THROW(receiverInfo.size(), 1u, "接收者数量应该不为空。");
    ASSERT_EQUAL(receiverInfo.at(0), 5);
    ASSERT_EQUAL(eventType, 3);
    ASSERT_EQUAL(dispatchMillisecondTime, 2);
    ASSERT_EQUAL(callbackParameters.GetContainerSize(), 0);
}

void CoreTools::TelegramTesting::Telegram1Test()
{
    CallbackParameters callbackParameters0{ 0 };
    callbackParameters0.SetValue(0, 10);

    const TestingType telegram{ 1, 5, 3, 2, callbackParameters0 };

    callbackParameters0.SetValue(1, 5);

    const auto sender = telegram.GetSender();
    const auto receiverInfo = telegram.GetReceiver();
    const auto eventType = telegram.GetMessageType();
    const auto dispatchMillisecondTime = telegram.GetDispatchMillisecondTime();
    const auto callbackParameters1 = telegram.GetCallbackParameters();

    ASSERT_EQUAL(sender, 1);
    ASSERT_EQUAL_FAILURE_THROW(receiverInfo.size(), 1u, "接收者数量应该不为空。");
    ASSERT_EQUAL(receiverInfo.at(0), 5);
    ASSERT_EQUAL(eventType, 3);
    ASSERT_EQUAL(dispatchMillisecondTime, 2);
    ASSERT_EQUAL(callbackParameters1.GetContainerSize(), 1);

    const auto value = callbackParameters1.GetInt32Value(0);
    ASSERT_EQUAL(value, 10);
}

void CoreTools::TelegramTesting::Telegram2Test()
{
    const TestingType telegram{ 1, 5, 3 };

    const auto sender = telegram.GetSender();
    const auto receiverInfo = telegram.GetReceiver();
    const auto eventType = telegram.GetMessageType();
    const auto dispatchMillisecondTime = telegram.GetDispatchMillisecondTime();
    const auto callbackParameters = telegram.GetCallbackParameters();

    ASSERT_EQUAL(sender, 1);
    ASSERT_TRUE(receiverInfo.empty());
    ASSERT_EQUAL(eventType, 5);
    ASSERT_EQUAL(dispatchMillisecondTime, 3);
    ASSERT_EQUAL(callbackParameters.GetContainerSize(), 0);
}

void CoreTools::TelegramTesting::Telegram3Test()
{
    CallbackParameters callbackParameters0{ 0 };
    callbackParameters0.SetValue(0, 10);

    const TestingType telegram{ 1, 5, 3, callbackParameters0 };

    const auto sender = telegram.GetSender();
    const auto receiverInfo = telegram.GetReceiver();
    const auto eventType = telegram.GetMessageType();
    const auto dispatchMillisecondTime = telegram.GetDispatchMillisecondTime();
    const auto callbackParameters1 = telegram.GetCallbackParameters();

    ASSERT_EQUAL(sender, 1);
    ASSERT_TRUE(receiverInfo.empty());
    ASSERT_EQUAL(eventType, 5);
    ASSERT_EQUAL(dispatchMillisecondTime, 3);
    ASSERT_EQUAL(callbackParameters1.GetContainerSize(), 1);
}

void CoreTools::TelegramTesting::Telegram4Test()
{
    const TestingType::ReceiverInfo receiverInfo0{ 1, 2, 3, 4, 5 };

    const TestingType telegram{ 1, receiverInfo0, 5, 3 };

    const auto sender = telegram.GetSender();
    const auto receiverInfo1 = telegram.GetReceiver();
    const auto eventType = telegram.GetMessageType();
    const auto dispatchMillisecondTime = telegram.GetDispatchMillisecondTime();
    const auto callbackParameters = telegram.GetCallbackParameters();

    ASSERT_EQUAL(sender, 1);
    ASSERT_EQUAL(receiverInfo1.size(), 5u);
    ASSERT_EQUAL(eventType, 5);
    ASSERT_EQUAL(dispatchMillisecondTime, 3);
    ASSERT_EQUAL(callbackParameters.GetContainerSize(), 0);
}

void CoreTools::TelegramTesting::Telegram5Test()
{
    const TestingType::ReceiverInfo receiverInfo0{ 1, 2, 3, 4, 5 };

    CallbackParameters callbackParameters0{ 0 };
    callbackParameters0.SetValue(0, 10);

    const TestingType telegram{ 1, receiverInfo0, 5, 3, callbackParameters0 };

    const auto sender = telegram.GetSender();
    const auto receiverInfo1 = telegram.GetReceiver();
    const auto eventType = telegram.GetMessageType();
    const auto dispatchMillisecondTime = telegram.GetDispatchMillisecondTime();
    const auto callbackParameters1 = telegram.GetCallbackParameters();

    ASSERT_EQUAL(sender, 1);
    ASSERT_EQUAL(receiverInfo1.size(), 5u);
    ASSERT_EQUAL(eventType, 5);
    ASSERT_EQUAL(dispatchMillisecondTime, 3);
    ASSERT_EQUAL(callbackParameters1.GetContainerSize(), 1);
}
