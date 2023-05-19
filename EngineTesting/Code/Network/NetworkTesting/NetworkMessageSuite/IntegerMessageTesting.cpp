///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.8 (2023/05/12 08:55)

#include "IntegerMessageTesting.h"
#include "Flags/IntegerMessageType.h"
#include "Detail/TestIntMessage.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/NetworkMessage/Flags/MessageLengthFlags.h"
#include "Network/NetworkMessage/IntegerMessageDetail.h"
#include "Network/NetworkMessage/MessageManager.h"
#include "Network/NetworkMessage/MessageSourceDetail.h"
#include "Network/NetworkMessage/MessageTargetDetail.h"
#include "Network/NetworkMessage/MessageTypeCondition.h"

Network::IntegerMessageTesting::IntegerMessageTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, IntegerMessageTesting)

void Network::IntegerMessageTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

namespace Network
{
    using TestingType = IntegerMessage<IntegerMessageField>;
    using TestingTypeSharedPtr = std::shared_ptr<TestingType>;
}

void Network::IntegerMessageTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RttiTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FactoryTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamingTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MessageTest);
}

void Network::IntegerMessageTesting::RttiTest()
{
    const TestingType::IntegerType integerType{ 100, 10, 1000, 2, 100 };

    const auto testMessage = make_shared<TestingType>(MessageHeadStrategy::Default, messageId, integerType);
    const auto testIntMessage = std::make_shared<TestIntMessage>(messageId);

    ASSERT_TRUE(testMessage->IsExactly(TestingType::GetCurrentRttiType()));
    ASSERT_FALSE(testMessage->IsExactly(MessageInterface::GetCurrentRttiType()));
    ASSERT_TRUE(testMessage->IsDerived(MessageInterface::GetCurrentRttiType()));
    ASSERT_FALSE(testMessage->IsDerived(TestIntMessage::GetCurrentRttiType()));

    ASSERT_TRUE(testMessage->IsExactlyTypeOf(testMessage));
    ASSERT_TRUE(testMessage->IsDerivedTypeOf(testMessage));

    ASSERT_FALSE(testMessage->IsExactlyTypeOf(testIntMessage));
    ASSERT_FALSE(testMessage->IsDerivedTypeOf(testIntMessage));

    const auto& attiType = testMessage->GetRttiType();

    ASSERT_EQUAL(attiType.GetName(), typeid(TestingType).name());
}

void Network::IntegerMessageTesting::FactoryTest()
{
    const TestingType::IntegerType integerType{ 100, 10, 1000, 2, 100 };

    const TestingType testMessage{ MessageHeadStrategy::Default, messageId, integerType };

    MESSAGE_MANAGER_SINGLETON.Insert(messageId, MessageTypeCondition::CreateNullCondition(), TestingType::Factory);

    MessageBuffer buffer{ BuffBlockSize::Size256, ParserStrategy::LittleEndian };
    MessageTarget messageTarget{ buffer };

    testMessage.Save(messageTarget);

    MessageSource messageSource{ buffer };

    MessageHeadStrategy messageHeadStrategy{};
    messageSource.ReadEnum(messageHeadStrategy);

    int32_t sourceMessageId{ 0 };
    messageSource.Read(sourceMessageId);

    ASSERT_EQUAL(sourceMessageId, messageId);

    const auto factoryCreateMessage = TestingType::Factory(messageSource, MessageHeadStrategy::Default, messageId);
    const auto polymorphicMessage = boost::dynamic_pointer_cast<TestingType>(factoryCreateMessage);

    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(polymorphicMessage, "消息类型错误！");

    ASSERT_EQUAL(polymorphicMessage->GetSize(), System::EnumCastUnderlying(IntegerMessageField::Count));
    ASSERT_EQUAL_FAILURE_THROW(polymorphicMessage->GetSize(), boost::numeric_cast<int>(integerType.size()), "消息大小错误！");

    for (auto i = 0u; i < integerType.size(); ++i)
    {
        ASSERT_EQUAL(integerType.at(i), polymorphicMessage->GetValue(System::UnderlyingCastEnum<IntegerMessageField>(i)));
    }

    MESSAGE_MANAGER_SINGLETON.Remove(messageId);
}

void Network::IntegerMessageTesting::StreamingTest()
{
    const TestingType::IntegerType integerType{ 100, 10, 1000, 2, 100 };

    const TestingType testMessage{ MessageHeadStrategy::Default, messageId, integerType };

    ASSERT_EQUAL(testMessage.GetStreamingSize(), CoreTools::GetStreamSize(messageId) + CoreTools::GetStreamSize(integerType));

    MESSAGE_MANAGER_SINGLETON.Insert(messageId, MessageTypeCondition::CreateNullCondition(), TestingType::Factory);

    MessageBuffer buffer{ BuffBlockSize::Size256, ParserStrategy::LittleEndian };
    MessageTarget messageTarget{ buffer };

    testMessage.Save(messageTarget);

    MessageSource messageSource{ buffer };

    MessageHeadStrategy messageHeadStrategy{};
    messageSource.ReadEnum(messageHeadStrategy);

    int32_t sourceMessageId{ 0 };
    messageSource.Read(sourceMessageId);

    ASSERT_EQUAL(sourceMessageId, messageId);

    TestingType sourceTestIntMessage{ MessageHeadStrategy::Default, messageId, TestingType::IntegerType{} };

    sourceTestIntMessage.Load(messageSource);

    MESSAGE_MANAGER_SINGLETON.Remove(messageId);
}

void Network::IntegerMessageTesting::MessageTest()
{
    TestingType::IntegerType integerType{ 100, 10, 1000, 2, 100 };

    const auto testMessage = make_shared<TestingType>(MessageHeadStrategy::Default, messageId, integerType);

    ASSERT_EQUAL(testMessage->GetMessageId(), messageId);
    ASSERT_EQUAL(testMessage->GetSubMessageId(), 0);
    ASSERT_EQUAL(testMessage->GetFullMessageId(), messageId);

    ASSERT_TRUE(testMessage->IsExactlyTypeOf(testMessage));
}