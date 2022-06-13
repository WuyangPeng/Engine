///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/23 16:51)

#include "MessageInterfaceTesting.h"
#include "Detail/TestIntMessage.h"
#include "Detail/TestNullMessage.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/NetworkMessage/Flags/MessageLengthFlags.h"
#include "Network/NetworkMessage/MessageManager.h"
#include "Network/NetworkMessage/MessageSourceDetail.h"
#include "Network/NetworkMessage/MessageTargetDetail.h"
#include "Network/NetworkMessage/MessageTypeCondition.h"

using std::make_shared;
using std::string;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Network, MessageInterfaceTesting)

void Network::MessageInterfaceTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RttiTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FactoryTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamingTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MessageTest);
}

void Network::MessageInterfaceTesting::RttiTest()
{
    TestNullMessageSharedPtr testMessage{ make_shared<TestNullMessage>(messageID) };
    TestIntMessageSharedPtr testIntMessage{ make_shared<TestIntMessage>(messageID) };

    ASSERT_TRUE(testMessage->IsExactly(TestNullMessage::GetCurrentRttiType()));
    ASSERT_FALSE(testMessage->IsExactly(MessageInterface::GetCurrentRttiType()));
    ASSERT_TRUE(testMessage->IsDerived(MessageInterface::GetCurrentRttiType()));
    ASSERT_FALSE(testMessage->IsDerived(TestIntMessage::GetCurrentRttiType()));

    ASSERT_TRUE(testMessage->IsExactlyTypeOf(testMessage));
    ASSERT_TRUE(testMessage->IsDerivedTypeOf(testMessage));

    ASSERT_FALSE(testMessage->IsExactlyTypeOf(testIntMessage));
    ASSERT_FALSE(testMessage->IsDerivedTypeOf(testIntMessage));

    const auto& attiType = testMessage->GetRttiType();

    ASSERT_EQUAL(string{ attiType.GetName() }, string{ "Network.TestNullMessage" });

    constexpr auto messsageHeadSize = 16;

    ASSERT_EQUAL(MessageInterface::GetMessageHeadSize(), messsageHeadSize);
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26414)

void Network::MessageInterfaceTesting::FactoryTest()
{
    constexpr auto intValue = 5;

    TestIntMessageSharedPtr testIntMessage{ make_shared<TestIntMessage>(messageID) };

    testIntMessage->SetIntValue(intValue);

    MESSAGE_MANAGER_SINGLETON.Insert(messageID, MessageTypeCondition::CreateNullCondition(), TestIntMessage::Factory);

    MessageBufferSharedPtr buffer{ make_shared<MessageBuffer>(BuffBlockSize::Size256, ParserStrategy::LittleEndian) };
    MessageTargetSharedPtr messageTarget{ make_shared<MessageTarget>(buffer) };

    testIntMessage->Save(*messageTarget);

    MessageSourceSharedPtr messageSource{ make_shared<MessageSource>(buffer) };

    int64_t sourceMessageID{ 0 };
    messageSource->Read(sourceMessageID);

    ASSERT_EQUAL(sourceMessageID, messageID);

    auto factoryCreateMessage = TestIntMessage::Factory(*messageSource, messageID);
    auto polymorphicMessage = boost::dynamic_pointer_cast<TestIntMessage>(factoryCreateMessage);

    ASSERT_EQUAL(polymorphicMessage->GetIntValue(), intValue);

    MESSAGE_MANAGER_SINGLETON.Remove(messageID);
}

void Network::MessageInterfaceTesting::StreamingTest()
{
    constexpr auto intValue = 5;

    TestIntMessageSharedPtr testIntMessage{ make_shared<TestIntMessage>(messageID) };

    ASSERT_EQUAL(testIntMessage->GetStreamingSize(), CORE_TOOLS_STREAM_SIZE(messageID) + CORE_TOOLS_STREAM_SIZE(intValue));

    testIntMessage->SetIntValue(intValue);

    MESSAGE_MANAGER_SINGLETON.Insert(messageID, MessageTypeCondition::CreateNullCondition(), TestIntMessage::Factory);

    MessageBufferSharedPtr buffer{ make_shared<MessageBuffer>(BuffBlockSize::Size256, ParserStrategy::LittleEndian) };
    MessageTargetSharedPtr messageTarget{ make_shared<MessageTarget>(buffer) };

    testIntMessage->Save(*messageTarget);

    MessageSourceSharedPtr messageSource{ make_shared<MessageSource>(buffer) };

    int64_t sourceMessageID{ 0 };
    messageSource->Read(sourceMessageID);

    ASSERT_EQUAL(sourceMessageID, messageID);

    auto sourceTestIntMessage{ make_shared<TestIntMessage>(messageID) };

    sourceTestIntMessage->Load(*messageSource);

    ASSERT_EQUAL(sourceTestIntMessage->GetIntValue(), intValue);

    MESSAGE_MANAGER_SINGLETON.Remove(messageID);
}

#include STSTEM_WARNING_POP

void Network::MessageInterfaceTesting::MessageTest()
{
    TestNullMessageSharedPtr testMessage{ make_shared<TestNullMessage>(messageID) };

    ASSERT_EQUAL(testMessage->GetMessageID(), messageID);
    ASSERT_EQUAL(testMessage->GetSubMessageID(), 0);
    ASSERT_EQUAL(testMessage->GetFullMessageID(), messageID);

    ASSERT_TRUE(testMessage->IsExactlyTypeOf(testMessage));
}