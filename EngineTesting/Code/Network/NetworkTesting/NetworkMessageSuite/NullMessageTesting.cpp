///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/16 09:51)

#include "NullMessageTesting.h"
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
#include "Network/NetworkMessage/NullDoubleMessage.h"
#include "Network/NetworkMessage/NullMessage.h"

Network::NullMessageTesting::NullMessageTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, NullMessageTesting)

void Network::NullMessageTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::NullMessageTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RttiTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FactoryTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamingTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MessageTest);
}

void Network::NullMessageTesting::RttiTest()
{
    const auto testMessage = std::make_shared<NullMessage>(MessageHeadStrategy::Default, messageId);
    const auto nullDoubleMessage = std::make_shared<NullDoubleMessage>(MessageHeadStrategy::UseSubId, messageId);

    ASSERT_TRUE(testMessage->IsExactly(NullMessage::GetCurrentRttiType()));
    ASSERT_FALSE(testMessage->IsExactly(MessageInterface::GetCurrentRttiType()));
    ASSERT_TRUE(testMessage->IsDerived(NullMessage::GetCurrentRttiType()));
    ASSERT_FALSE(testMessage->IsDerived(NullDoubleMessage::GetCurrentRttiType()));

    ASSERT_TRUE(testMessage->IsExactlyTypeOf(testMessage));
    ASSERT_TRUE(testMessage->IsDerivedTypeOf(testMessage));

    ASSERT_FALSE(testMessage->IsExactlyTypeOf(nullDoubleMessage));
    ASSERT_FALSE(testMessage->IsDerivedTypeOf(nullDoubleMessage));

    const auto& attiType = testMessage->GetRttiType();

    ASSERT_EQUAL(attiType.GetName(), "Network.NullMessage");
}

void Network::NullMessageTesting::FactoryTest()
{
    const auto testMessage = std::make_shared<NullMessage>(MessageHeadStrategy::Default, messageId);
    ASSERT_TRUE(testMessage->IsExactlyTypeOf(testMessage));

    MESSAGE_MANAGER_SINGLETON.Insert(messageId, MessageTypeCondition::CreateNullCondition(), NullMessage::Factory);

    MessageBuffer buffer{ BuffBlockSize::Size256, ParserStrategy::LittleEndian };
    MessageTarget messageTarget{ buffer };

    testMessage->Save(messageTarget);

    MessageSource messageSource{ buffer };

    MessageHeadStrategy messageHeadStrategy{};
    messageSource.ReadEnum(messageHeadStrategy);

    int32_t sourceMessageId{ 0 };
    messageSource.Read(sourceMessageId);

    ASSERT_EQUAL(sourceMessageId, messageId);

    const auto factoryCreateMessage = NullMessage::Factory(messageSource, MessageHeadStrategy::Default, messageId);
    const auto polymorphicMessage = boost::dynamic_pointer_cast<NullMessage>(factoryCreateMessage);

    ASSERT_UNEQUAL_NULL_PTR(polymorphicMessage);

    MESSAGE_MANAGER_SINGLETON.Remove(messageId);
}

void Network::NullMessageTesting::StreamingTest()
{
    const auto testMessage = std::make_shared<NullMessage>(MessageHeadStrategy::Default, messageId);
    ASSERT_TRUE(testMessage->IsExactlyTypeOf(testMessage));

    ASSERT_EQUAL(testMessage->GetStreamingSize(), 8);

    MESSAGE_MANAGER_SINGLETON.Insert(messageId, MessageTypeCondition::CreateNullCondition(), NullMessage::Factory);

    MessageBuffer buffer{ BuffBlockSize::Size256, ParserStrategy::LittleEndian };
    MessageTarget messageTarget{ buffer };

    testMessage->Save(messageTarget);

    MessageSource messageSource{ buffer };

    MessageHeadStrategy messageHeadStrategy{};
    messageSource.ReadEnum(messageHeadStrategy);

    int32_t sourceMessageId{ 0 };
    messageSource.Read(sourceMessageId);

    ASSERT_EQUAL(sourceMessageId, messageId);

    const auto sourceTestIntMessage = std::make_shared<NullMessage>(MessageHeadStrategy::Default, messageId);
    ASSERT_TRUE(sourceTestIntMessage->IsExactlyTypeOf(sourceTestIntMessage));

    sourceTestIntMessage->Load(messageSource);

    MESSAGE_MANAGER_SINGLETON.Remove(messageId);
}

void Network::NullMessageTesting::MessageTest()
{
    const auto testMessage = std::make_shared<NullMessage>(MessageHeadStrategy::Default, messageId);
    ASSERT_TRUE(testMessage->IsExactlyTypeOf(testMessage));

    ASSERT_EQUAL(testMessage->GetMessageId(), messageId);
    ASSERT_EQUAL(testMessage->GetSubMessageId(), 0);
    ASSERT_EQUAL(testMessage->GetFullMessageId(), messageId);
}
