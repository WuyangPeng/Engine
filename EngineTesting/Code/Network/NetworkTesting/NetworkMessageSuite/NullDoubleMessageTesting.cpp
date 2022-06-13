///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/24 11:27)

#include "NullDoubleMessageTesting.h"
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
#include "Network/NetworkMessage/NullDoubleMessage.h"
#include "Network/NetworkMessage/NullMessage.h"

using std::make_shared;
using std::shared_ptr;
using std::string;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE_USE_TESTING_TYPE(Network, NullDoubleMessage)

namespace Network
{
    using TestingTypeSharedPtr = shared_ptr<TestingType>;
}

void Network::NullDoubleMessageTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RttiTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FactoryTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamingTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MessageTest);
}

void Network::NullDoubleMessageTesting::RttiTest()
{
    TestingTypeSharedPtr testMessage{ make_shared<TestingType>(fullMessageID) };
    NullMessageSharedPtr nullDoubleMessage{ make_shared<NullMessage>(fullMessageID) };

    ASSERT_TRUE(testMessage->IsExactly(TestingType::GetCurrentRttiType()));
    ASSERT_FALSE(testMessage->IsExactly(MessageInterface::GetCurrentRttiType()));
    ASSERT_TRUE(testMessage->IsDerived(TestingType::GetCurrentRttiType()));
    ASSERT_FALSE(testMessage->IsDerived(NullMessage::GetCurrentRttiType()));

    ASSERT_TRUE(testMessage->IsExactlyTypeOf(testMessage));
    ASSERT_TRUE(testMessage->IsDerivedTypeOf(testMessage));

    ASSERT_FALSE(testMessage->IsExactlyTypeOf(nullDoubleMessage));
    ASSERT_FALSE(testMessage->IsDerivedTypeOf(nullDoubleMessage));

    const auto& attiType = testMessage->GetRttiType();

    ASSERT_EQUAL(string{ attiType.GetName() }, string{ "Network.NullDoubleMessage" });
}

void Network::NullDoubleMessageTesting::FactoryTest()
{
    constexpr auto intValue = 5;

    TestingTypeSharedPtr testMessage{ make_shared<TestingType>(fullMessageID) };
    ASSERT_TRUE(testMessage->IsExactlyTypeOf(testMessage));

    MESSAGE_MANAGER_SINGLETON.Insert(fullMessageID, MessageTypeCondition::CreateNullCondition(), TestingType::Factory);

    MessageBufferSharedPtr buffer{ make_shared<MessageBuffer>(BuffBlockSize::Size256, ParserStrategy::LittleEndian) };
    MessageTarget messageTarget{ buffer };

    testMessage->Save(messageTarget);

    MessageSource messageSource{ buffer };

    int64_t sourceMessageID{ 0 };
    messageSource.Read(sourceMessageID);

    ASSERT_EQUAL(sourceMessageID, fullMessageID);

    auto factoryCreateMessage = TestingType::Factory(messageSource, fullMessageID);
    auto polymorphicMessage = boost::dynamic_pointer_cast<TestingType>(factoryCreateMessage);

    ASSERT_UNEQUAL_NULL_PTR(polymorphicMessage);

    MESSAGE_MANAGER_SINGLETON.Remove(fullMessageID);
}

void Network::NullDoubleMessageTesting::StreamingTest()
{
    constexpr auto intValue = 5;

    TestingTypeSharedPtr testMessage{ make_shared<TestingType>(fullMessageID) };
    ASSERT_TRUE(testMessage->IsExactlyTypeOf(testMessage));

    ASSERT_EQUAL(testMessage->GetStreamingSize(), CORE_TOOLS_STREAM_SIZE(fullMessageID));

    MESSAGE_MANAGER_SINGLETON.Insert(fullMessageID, MessageTypeCondition::CreateNullCondition(), TestingType::Factory);

    MessageBufferSharedPtr buffer{ make_shared<MessageBuffer>(BuffBlockSize::Size256, ParserStrategy::LittleEndian) };
    MessageTarget messageTarget{ buffer };

    testMessage->Save(messageTarget);

    MessageSource messageSource{ buffer };

    int64_t sourceMessageID{ 0 };
    messageSource.Read(sourceMessageID);

    ASSERT_EQUAL(sourceMessageID, fullMessageID);

    auto sourceTestIntMessage{ make_shared<TestingType>(fullMessageID) };
    ASSERT_TRUE(sourceTestIntMessage->IsExactlyTypeOf(sourceTestIntMessage));

    sourceTestIntMessage->Load(messageSource);

    MESSAGE_MANAGER_SINGLETON.Remove(fullMessageID);
}

void Network::NullDoubleMessageTesting::MessageTest()
{
    TestingTypeSharedPtr testMessage{ make_shared<TestingType>(fullMessageID) };
    ASSERT_TRUE(testMessage->IsExactlyTypeOf(testMessage));

    ASSERT_EQUAL(testMessage->GetMessageID(), messageID);
    ASSERT_EQUAL(testMessage->GetSubMessageID(), subMessageID);
    ASSERT_EQUAL(testMessage->GetFullMessageID(), fullMessageID);
}
