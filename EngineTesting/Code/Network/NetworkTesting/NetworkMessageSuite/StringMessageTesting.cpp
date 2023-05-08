///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/24 11:41)

#include "StringMessageTesting.h"
#include "Flags/StringMessageType.h"
#include "Detail/TestIntMessage.h"
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
#include "Network/NetworkMessage/StringMessageDetail.h"
using std::make_shared;
using std::string;

Network::StringMessageTesting::StringMessageTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, StringMessageTesting)

void Network::StringMessageTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

namespace Network
{
    using TestingType = StringMessage<StringMessageField>;
    using TestingTypeSharedPtr = std::shared_ptr<TestingType>;
}

void Network::StringMessageTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RttiTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FactoryTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamingTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MessageTest);
}

void Network::StringMessageTesting::RttiTest()
{
    TestingType::StringType stringType{ "UserName", "UserInfo", "GuildName" };

    TestingTypeSharedPtr testMessage{ make_shared<TestingType>(MessageHeadStrategy::Default, messageID, stringType) };
    TestIntMessageSharedPtr testIntMessage{ make_shared<TestIntMessage>(messageID) };

    ASSERT_TRUE(testMessage->IsExactly(TestingType::GetCurrentRttiType()));
    ASSERT_FALSE(testMessage->IsExactly(MessageInterface::GetCurrentRttiType()));
    ASSERT_TRUE(testMessage->IsDerived(MessageInterface::GetCurrentRttiType()));
    ASSERT_FALSE(testMessage->IsDerived(TestIntMessage::GetCurrentRttiType()));

    ASSERT_TRUE(testMessage->IsExactlyTypeOf(testMessage));
    ASSERT_TRUE(testMessage->IsDerivedTypeOf(testMessage));

    ASSERT_FALSE(testMessage->IsExactlyTypeOf(testIntMessage));
    ASSERT_FALSE(testMessage->IsDerivedTypeOf(testIntMessage));

    const auto& attiType = testMessage->GetRttiType();

    ASSERT_EQUAL(string{ attiType.GetName() }, string{ typeid(TestingType).name() });
}

void Network::StringMessageTesting::FactoryTest()
{
    TestingType::StringType stringType{ "UserName", "UserInfo", "GuildName" };

    TestingTypeSharedPtr testMessage{ make_shared<TestingType>(MessageHeadStrategy::Default, messageID, stringType) };
    ASSERT_TRUE(testMessage->IsExactlyTypeOf(testMessage));

    MESSAGE_MANAGER_SINGLETON.Insert(messageID, MessageTypeCondition::CreateNullCondition(), TestingType::Factory);
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

    auto factoryCreateMessage = TestingType::Factory(messageSource, MessageHeadStrategy::Default, messageID);
    auto polymorphicMessage = boost::dynamic_pointer_cast<TestingType>(factoryCreateMessage);

    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(polymorphicMessage, "��Ϣ���ʹ���");

    ASSERT_EQUAL(polymorphicMessage->GetSize(), System::EnumCastUnderlying(StringMessageField::Count));
    ASSERT_EQUAL_FAILURE_THROW(polymorphicMessage->GetSize(), boost::numeric_cast<int>(stringType.size()), "��Ϣ��С����");

    for (auto i = 0u; i < stringType.size(); ++i)
    {
        ASSERT_EQUAL(stringType.at(i), polymorphicMessage->GetValue(System::UnderlyingCastEnum<StringMessageField>(i)));
    }

    MESSAGE_MANAGER_SINGLETON.Remove(messageID);
}

void Network::StringMessageTesting::StreamingTest()
{
    TestingType::StringType stringType{ "UserName", "UserInfo", "GuildName" };

    TestingTypeSharedPtr testMessage{ make_shared<TestingType>(MessageHeadStrategy::Default, messageID, stringType) };
    ASSERT_TRUE(testMessage->IsExactlyTypeOf(testMessage));

    ASSERT_EQUAL(testMessage->GetStreamingSize(), CoreTools::GetStreamSize(messageID) + CoreTools::GetStreamSize(stringType));

    MESSAGE_MANAGER_SINGLETON.Insert(messageID, MessageTypeCondition::CreateNullCondition(), TestingType::Factory);
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

    auto sourceTestStringMessage{ make_shared<TestingType>(MessageHeadStrategy::Default, messageID, TestingType::StringType{}) };
    ASSERT_TRUE(sourceTestStringMessage->IsExactlyTypeOf(sourceTestStringMessage));

    sourceTestStringMessage->Load(messageSource);

    MESSAGE_MANAGER_SINGLETON.Remove(messageID);
}

void Network::StringMessageTesting::MessageTest()
{
    TestingType::StringType stringType{ "UserName", "UserInfo", "GuildName" };

    TestingTypeSharedPtr testMessage{ make_shared<TestingType>(MessageHeadStrategy::Default, messageID, stringType) };
    ASSERT_TRUE(testMessage->IsExactlyTypeOf(testMessage));

    ASSERT_EQUAL(testMessage->GetMessageId(), messageID);
    ASSERT_EQUAL(testMessage->GetSubMessageId(), 0);
    ASSERT_EQUAL(testMessage->GetFullMessageId(), messageID);
}
