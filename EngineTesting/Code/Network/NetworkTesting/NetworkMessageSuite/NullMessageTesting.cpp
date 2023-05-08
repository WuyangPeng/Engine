///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/24 11:32)

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
using std::make_shared;
using std::shared_ptr;
using std::string;

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

namespace Network
{
    using TestingTypeSharedPtr = shared_ptr<NullMessage>;
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
    TestingTypeSharedPtr testMessage{ make_shared<NullMessage>(MessageHeadStrategy::Default, messageID) };
    NullDoubleMessageSharedPtr nullDoubleMessage{ make_shared<NullDoubleMessage>(MessageHeadStrategy::UseSubId, messageID) };

    ASSERT_TRUE(testMessage->IsExactly(NullMessage::GetCurrentRttiType()));
    ASSERT_FALSE(testMessage->IsExactly(MessageInterface::GetCurrentRttiType()));
    ASSERT_TRUE(testMessage->IsDerived(NullMessage::GetCurrentRttiType()));
    ASSERT_FALSE(testMessage->IsDerived(NullDoubleMessage::GetCurrentRttiType()));

    ASSERT_TRUE(testMessage->IsExactlyTypeOf(testMessage));
    ASSERT_TRUE(testMessage->IsDerivedTypeOf(testMessage));

    ASSERT_FALSE(testMessage->IsExactlyTypeOf(nullDoubleMessage));
    ASSERT_FALSE(testMessage->IsDerivedTypeOf(nullDoubleMessage));

    const auto& attiType = testMessage->GetRttiType();

    ASSERT_EQUAL(string{ attiType.GetName() }, string{ "Network.NullMessage" });
}

void Network::NullMessageTesting::FactoryTest()
{
    constexpr auto intValue = 5;

    TestingTypeSharedPtr testMessage{ make_shared<NullMessage>(MessageHeadStrategy::Default, messageID) };
    ASSERT_TRUE(testMessage->IsExactlyTypeOf(testMessage));

    MESSAGE_MANAGER_SINGLETON.Insert(messageID, MessageTypeCondition::CreateNullCondition(), NullMessage::Factory);
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26414)
    MessageBufferSharedPtr buffer{ make_shared<MessageBuffer>(BuffBlockSize::Size256, ParserStrategy::LittleEndian) };
    MessageTarget messageTarget{ *buffer };
#include STSTEM_WARNING_POP
    testMessage->Save(messageTarget);

    MessageSource messageSource{ *buffer };

    MessageHeadStrategy messageHeadStrategy{};
    messageSource.ReadEnum(messageHeadStrategy);

    int32_t sourceMessageID{ 0 };
    messageSource.Read(sourceMessageID);

    ASSERT_EQUAL(sourceMessageID, messageID);

    auto factoryCreateMessage = NullMessage::Factory(messageSource, MessageHeadStrategy::Default, messageID);
    auto polymorphicMessage = boost::dynamic_pointer_cast<NullMessage>(factoryCreateMessage);

    ASSERT_UNEQUAL_NULL_PTR(polymorphicMessage);

    MESSAGE_MANAGER_SINGLETON.Remove(messageID);
}

void Network::NullMessageTesting::StreamingTest()
{
    constexpr auto intValue = 5;

    TestingTypeSharedPtr testMessage{ make_shared<NullMessage>(MessageHeadStrategy::Default, messageID) };
    ASSERT_TRUE(testMessage->IsExactlyTypeOf(testMessage));

    ASSERT_EQUAL(testMessage->GetStreamingSize(), CoreTools::GetStreamSize(messageID));

    MESSAGE_MANAGER_SINGLETON.Insert(messageID, MessageTypeCondition::CreateNullCondition(), NullMessage::Factory);
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26414)
    MessageBufferSharedPtr buffer{ make_shared<MessageBuffer>(BuffBlockSize::Size256, ParserStrategy::LittleEndian) };
    MessageTarget messageTarget{ *buffer };
#include STSTEM_WARNING_POP
    testMessage->Save(messageTarget);

    MessageSource messageSource{ *buffer };

    MessageHeadStrategy messageHeadStrategy{};
    messageSource.ReadEnum(messageHeadStrategy);

    int32_t sourceMessageID{ 0 };
    messageSource.Read(sourceMessageID);

    ASSERT_EQUAL(sourceMessageID, messageID);

    auto sourceTestIntMessage = make_shared<NullMessage>(MessageHeadStrategy::Default, messageID);
    ASSERT_TRUE(sourceTestIntMessage->IsExactlyTypeOf(sourceTestIntMessage));

    sourceTestIntMessage->Load(messageSource);

    MESSAGE_MANAGER_SINGLETON.Remove(messageID);
}

void Network::NullMessageTesting::MessageTest()
{
    TestingTypeSharedPtr testMessage{ make_shared<NullMessage>(MessageHeadStrategy::Default, messageID) };
    ASSERT_TRUE(testMessage->IsExactlyTypeOf(testMessage));

    ASSERT_EQUAL(testMessage->GetMessageId(), messageID);
    ASSERT_EQUAL(testMessage->GetSubMessageId(), 0);
    ASSERT_EQUAL(testMessage->GetFullMessageId(), messageID);
}
