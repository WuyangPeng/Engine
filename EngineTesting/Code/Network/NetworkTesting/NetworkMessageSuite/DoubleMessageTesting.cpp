///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/23 15:57)

#include "DoubleMessageTesting.h"
#include "Detail/TestDoubleIntMessage.h"
#include "Detail/TestDoubleNullMessage.h"
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
using std::make_shared;
using std::string;

Network::DoubleMessageTesting::DoubleMessageTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, DoubleMessageTesting)

void Network::DoubleMessageTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::DoubleMessageTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RttiTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FactoryTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamingTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MessageTest);
}

void Network::DoubleMessageTesting::RttiTest()
{
    auto testMessage = make_shared<TestDoubleNullMessage>(fullMessageID);
    auto testIntMessage = make_shared<TestDoubleIntMessage>(fullMessageID);

    ASSERT_TRUE(testMessage->IsExactly(TestDoubleNullMessage::GetCurrentRttiType()));
    ASSERT_FALSE(testMessage->IsExactly(MessageInterface::GetCurrentRttiType()));
    ASSERT_TRUE(testMessage->IsDerived(MessageInterface::GetCurrentRttiType()));
    ASSERT_FALSE(testMessage->IsDerived(TestDoubleIntMessage::GetCurrentRttiType()));

    ASSERT_TRUE(testMessage->IsExactlyTypeOf(testMessage));
    ASSERT_TRUE(testMessage->IsDerivedTypeOf(testMessage));

    ASSERT_FALSE(testMessage->IsExactlyTypeOf(testIntMessage));
    ASSERT_FALSE(testMessage->IsDerivedTypeOf(testIntMessage));

    const auto& attiType = testMessage->GetRttiType();

    ASSERT_EQUAL(string{ attiType.GetName() }, string{ "Network.TestDoubleNullMessage" });
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26414)

void Network::DoubleMessageTesting::FactoryTest()
{
    constexpr auto intValue = 5;

    auto testIntMessage = make_shared<TestDoubleIntMessage>(fullMessageID);

    testIntMessage->SetIntValue(intValue);

    MESSAGE_MANAGER_SINGLETON.Insert(fullMessageID, MessageTypeCondition::CreateNullCondition(), TestDoubleIntMessage::Factory);

    auto buffer = make_shared<MessageBuffer>(BuffBlockSize::Size256, ParserStrategy::LittleEndian);
    auto messageTarget = make_shared<MessageTarget>(*buffer);

    testIntMessage->Save(*messageTarget);

    auto messageSource = make_shared<MessageSource>(*buffer);

    MessageHeadStrategy messageHeadStrategy{};
    messageSource->ReadEnum(messageHeadStrategy);

    int64_t sourceMessageID{ 0 };
    messageSource->Read(sourceMessageID);

    ASSERT_EQUAL(sourceMessageID, fullMessageID);

    auto factoryCreateMessage = TestDoubleIntMessage::Factory(*messageSource, MessageHeadStrategy::UseSubId, fullMessageID);
    auto polymorphicMessage = boost::dynamic_pointer_cast<TestDoubleIntMessage>(factoryCreateMessage);

    ASSERT_EQUAL(polymorphicMessage->GetIntValue(), intValue);

    MESSAGE_MANAGER_SINGLETON.Remove(fullMessageID);
}

void Network::DoubleMessageTesting::StreamingTest()
{
    constexpr auto intValue = 5;

    auto testIntMessage = make_shared<TestDoubleIntMessage>(fullMessageID);

    ASSERT_EQUAL(testIntMessage->GetStreamingSize(), CoreTools::GetStreamSize(fullMessageID) + 4 + CoreTools::GetStreamSize(intValue));

    testIntMessage->SetIntValue(intValue);

    MESSAGE_MANAGER_SINGLETON.Insert(fullMessageID, MessageTypeCondition::CreateNullCondition(), TestDoubleIntMessage::Factory);

    MessageBufferSharedPtr buffer{ make_shared<MessageBuffer>(BuffBlockSize::Size256, ParserStrategy::LittleEndian) };
    auto messageTarget = make_shared<MessageTarget>(*buffer);

    testIntMessage->Save(*messageTarget);

    auto messageSource = make_shared<MessageSource>(*buffer);

    MessageHeadStrategy messageHeadStrategy{};
    messageSource->ReadEnum(messageHeadStrategy);

    int64_t sourceMessageID{ 0 };
    messageSource->Read(sourceMessageID);

    ASSERT_EQUAL(sourceMessageID, fullMessageID);

    auto sourceTestIntMessage = make_shared<TestDoubleIntMessage>(fullMessageID);

    sourceTestIntMessage->Load(*messageSource);

    ASSERT_EQUAL(sourceTestIntMessage->GetIntValue(), intValue);

    MESSAGE_MANAGER_SINGLETON.Remove(fullMessageID);
}

#include STSTEM_WARNING_POP

void Network::DoubleMessageTesting::MessageTest()
{
    auto testMessage = make_shared<TestDoubleNullMessage>(fullMessageID);

    ASSERT_EQUAL(testMessage->GetMessageId(), messageID);
    ASSERT_EQUAL(testMessage->GetSubMessageId(), subMessageID);
    ASSERT_EQUAL(testMessage->GetFullMessageId(), fullMessageID);

    ASSERT_TRUE(testMessage->IsExactlyTypeOf(testMessage));
}