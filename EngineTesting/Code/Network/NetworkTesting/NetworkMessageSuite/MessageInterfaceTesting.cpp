///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.8 (2023/05/11 14:14)

#include "MessageInterfaceTesting.h"
#include "TestDoubleIntMessage.h"
#include "Detail/TestIntMessage.h"
#include "Detail/TestNullMessage.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/NetworkMessage/Flags/MessageLengthFlags.h"
#include "Network/NetworkMessage/MessageManager.h"
#include "Network/NetworkMessage/MessageSourceDetail.h"
#include "Network/NetworkMessage/MessageTargetDetail.h"
#include "Network/NetworkMessage/MessageTypeCondition.h"

Network::MessageInterfaceTesting::MessageInterfaceTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, MessageInterfaceTesting)

void Network::MessageInterfaceTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::MessageInterfaceTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RttiTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FactoryTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamingTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MessageTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UseSubIdTest);
}

void Network::MessageInterfaceTesting::RttiTest()
{
    const auto testMessage = std::make_shared<TestNullMessage>(messageId);
    const auto testIntMessage = std::make_shared<TestIntMessage>(messageId);

    ASSERT_TRUE(testMessage->IsExactly(TestNullMessage::GetCurrentRttiType()));
    ASSERT_FALSE(testMessage->IsExactly(MessageInterface::GetCurrentRttiType()));
    ASSERT_TRUE(testMessage->IsDerived(MessageInterface::GetCurrentRttiType()));
    ASSERT_FALSE(testMessage->IsDerived(TestIntMessage::GetCurrentRttiType()));

    ASSERT_TRUE(testMessage->IsExactlyTypeOf(testMessage));
    ASSERT_TRUE(testMessage->IsDerivedTypeOf(testMessage));

    ASSERT_FALSE(testMessage->IsExactlyTypeOf(testIntMessage));
    ASSERT_FALSE(testMessage->IsDerivedTypeOf(testIntMessage));

    const auto& attiType = testMessage->GetRttiType();

    ASSERT_EQUAL(attiType.GetName(), "Network.TestNullMessage");

    constexpr auto messageHeadSize = 16;

    ASSERT_EQUAL(MessageInterface::GetMessageHeadSize(), messageHeadSize);
}

void Network::MessageInterfaceTesting::FactoryTest()
{
    constexpr auto intValue = 5;

    TestIntMessage testIntMessage{ messageId };

    testIntMessage.SetIntValue(intValue);

    MESSAGE_MANAGER_SINGLETON.Insert(messageId, MessageTypeCondition::CreateNullCondition(), TestIntMessage::Factory);

    MessageBuffer buffer{ BuffBlockSize::Size256, ParserStrategy::LittleEndian };
    MessageTarget messageTarget{ buffer };

    testIntMessage.Save(messageTarget);

    MessageSource messageSource{ buffer };

    MessageHeadStrategy messageHeadStrategy{};
    messageSource.ReadEnum(messageHeadStrategy);

    int32_t sourceMessageId{ 0 };
    messageSource.Read(sourceMessageId);

    ASSERT_EQUAL(sourceMessageId, messageId);

    const auto factoryCreateMessage = TestIntMessage::Factory(messageSource, MessageHeadStrategy::Default, messageId);
    const auto polymorphicMessage = boost::dynamic_pointer_cast<TestIntMessage>(factoryCreateMessage);

    ASSERT_EQUAL(polymorphicMessage->GetIntValue(), intValue);

    MESSAGE_MANAGER_SINGLETON.Remove(messageId);
}

void Network::MessageInterfaceTesting::StreamingTest()
{
    constexpr auto intValue = 5;

    TestIntMessage testIntMessage{ messageId };

    ASSERT_EQUAL(testIntMessage.GetStreamingSize(), 8 + CoreTools::GetStreamSize(intValue));

    testIntMessage.SetIntValue(intValue);

    MESSAGE_MANAGER_SINGLETON.Insert(messageId, MessageTypeCondition::CreateNullCondition(), TestIntMessage::Factory);

    MessageBuffer buffer{ BuffBlockSize::Size256, ParserStrategy::LittleEndian };
    MessageTarget messageTarget{ buffer };

    testIntMessage.Save(messageTarget);

    MessageSource messageSource{ buffer };

    MessageHeadStrategy messageHeadStrategy{};
    messageSource.ReadEnum(messageHeadStrategy);

    int32_t sourceMessageId{ 0 };
    messageSource.Read(sourceMessageId);

    ASSERT_EQUAL(sourceMessageId, messageId);

    TestIntMessage sourceTestIntMessage{ messageId };

    sourceTestIntMessage.Load(messageSource);

    ASSERT_EQUAL(sourceTestIntMessage.GetIntValue(), intValue);

    MESSAGE_MANAGER_SINGLETON.Remove(messageId);
}

void Network::MessageInterfaceTesting::MessageTest()
{
    const auto testMessage = std::make_shared<TestNullMessage>(messageId);

    ASSERT_EQUAL(testMessage->GetMessageId(), messageId);
    ASSERT_EQUAL(testMessage->GetSubMessageId(), 0);
    ASSERT_EQUAL(testMessage->GetFullMessageId(), messageId);

    ASSERT_TRUE(testMessage->IsExactlyTypeOf(testMessage));

    ASSERT_EQUAL(testMessage->GetMessageHeadStrategy(), MessageHeadStrategy::Default);
}

void Network::MessageInterfaceTesting::UseSubIdTest()
{
    constexpr auto fullMessageId = (messageId << 32) + (messageId + 1);
    const auto testMessage = std::make_shared<TestDoubleIntMessage>(fullMessageId);

    ASSERT_EQUAL(testMessage->GetMessageId(), messageId);
    ASSERT_EQUAL(testMessage->GetSubMessageId(), messageId + 1);
    ASSERT_EQUAL(testMessage->GetFullMessageId(), fullMessageId);

    ASSERT_TRUE(testMessage->IsExactlyTypeOf(testMessage));

    ASSERT_ENUM_EQUAL(testMessage->GetMessageHeadStrategy(), MessageHeadStrategy::UseSubId);
}
