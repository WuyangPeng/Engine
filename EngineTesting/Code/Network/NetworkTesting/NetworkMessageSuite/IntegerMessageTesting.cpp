// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎测试版本：0.0.1.0 (2019/11/26 15:46)

#include "IntegerMessageTesting.h"
#include "Flags/IntegerMessageType.h"
#include "Detail/TestIntMessage.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/NetworkMessage/Flags/MessageLengthFlags.h"
#include "Network/NetworkMessage/IntegerMessageDetail.h"
#include "Network/NetworkMessage/MessageManager.h"
#include "Network/NetworkMessage/MessageSourceDetail.h"
#include "Network/NetworkMessage/MessageTargetDetail.h"
#include "Network/NetworkMessage/MessageTypeCondition.h"

using std::make_shared;
using std::string;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Network, IntegerMessageTesting)
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26414)
namespace Network
{
    using TestingType = IntegerMessage<IntegerMessageField>;
    using TestingTypeSharedPtr = std::shared_ptr<TestingType>;
}

void Network::IntegerMessageTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RttiTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FactoryTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamingTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MessageTest);
}

void Network::IntegerMessageTesting ::RttiTest()
{
    TestingType::IntegerType integerType{ 100, 10, 1000, 2, 100 };

    TestingTypeSharedPtr testMessage{ make_shared<TestingType>(sm_MessageID, integerType) };
    TestIntMessageSharedPtr testIntMessage{ make_shared<TestIntMessage>(sm_MessageID) };

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

void Network::IntegerMessageTesting ::FactoryTest()
{
    TestingType::IntegerType integerType{ 100, 10, 1000, 2, 100 };

    TestingTypeSharedPtr testMessage{ make_shared<TestingType>(sm_MessageID, integerType) };

    MESSAGE_MANAGER_SINGLETON.Insert(sm_MessageID, MessageTypeCondition::CreateNullCondition(), TestingType::Factory);

    MessageBufferSharedPtr buffer{ make_shared<MessageBuffer>(BuffBlockSize::Size256, ParserStrategy::LittleEndian) };
    MessageTargetSharedPtr messageTarget{ make_shared<MessageTarget>(buffer) };

    testMessage->Save(*messageTarget);

    MessageSourceSharedPtr messageSource{ make_shared<MessageSource>(buffer) };

    int64_t sourceMessageID{ 0 };
    messageSource->Read(sourceMessageID);

    ASSERT_EQUAL(sourceMessageID, sm_MessageID);

    auto factoryCreateMessage = TestingType::Factory(*messageSource, sm_MessageID);
    // 	auto polymorphicMessage = CoreTools::PolymorphicSharedPtrCast<TestingType>(factoryCreateMessage);
    //
    // 	ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(polymorphicMessage,"消息类型错误！");
    //
    // 	ASSERT_EQUAL(polymorphicMessage->GetSize(),System::EnumCastUnderlying(IntegerMessageField::Count));
    // 	ASSERT_EQUAL_FAILURE_THROW(polymorphicMessage->GetSize(),boost::numeric_cast<int>(integerType.size()),"消息大小错误！");
    //
    // 	for (auto i = 0u;i < integerType.size();++i)
    // 	{
    // 		ASSERT_EQUAL(integerType[i], polymorphicMessage->GetValue(System::UnderlyingCastEnum<IntegerMessageField>(i)));
    // 	}
    //
    // 	MESSAGE_MANAGER_SINGLETON.Remove(sm_MessageID);
}

void Network::IntegerMessageTesting ::StreamingTest()
{
    TestingType::IntegerType integerType{ 100, 10, 1000, 2, 100 };

    TestingTypeSharedPtr testMessage{ make_shared<TestingType>(sm_MessageID, integerType) };

    ASSERT_EQUAL(testMessage->GetStreamingSize(), CORE_TOOLS_STREAM_SIZE(sm_MessageID) + CORE_TOOLS_STREAM_SIZE(integerType));

    MESSAGE_MANAGER_SINGLETON.Insert(sm_MessageID, MessageTypeCondition::CreateNullCondition(), TestingType::Factory);

    MessageBufferSharedPtr buffer{ make_shared<MessageBuffer>(BuffBlockSize::Size256, ParserStrategy::LittleEndian) };
    MessageTargetSharedPtr messageTarget{ make_shared<MessageTarget>(buffer) };

    testMessage->Save(*messageTarget);

    MessageSourceSharedPtr messageSource{ make_shared<MessageSource>(buffer) };

    int64_t sourceMessageID{ 0 };
    messageSource->Read(sourceMessageID);

    ASSERT_EQUAL(sourceMessageID, sm_MessageID);

    auto sourceTestIntMessage{ make_shared<TestingType>(sm_MessageID, TestingType::IntegerType{}) };

    sourceTestIntMessage->Load(*messageSource);

    MESSAGE_MANAGER_SINGLETON.Remove(sm_MessageID);
}

void Network::IntegerMessageTesting ::MessageTest()
{
    TestingType::IntegerType integerType{ 100, 10, 1000, 2, 100 };

    TestingTypeSharedPtr testMessage{ make_shared<TestingType>(sm_MessageID, integerType) };

    ASSERT_EQUAL(testMessage->GetMessageID(), sm_MessageID);
    ASSERT_EQUAL(testMessage->GetSubMessageID(), 0);
    ASSERT_EQUAL(testMessage->GetFullMessageID(), sm_MessageID);
}