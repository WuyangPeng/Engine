///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/24 11:12)

#include "MultipleMessageTesting.h"
#include "Flags/MultipleMessageType.h"
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
#include "Network/NetworkMessage/MultipleMessageDetail.h"
using std::make_shared;
using std::string;

Network::MultipleMessageTesting::MultipleMessageTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, MultipleMessageTesting)

void Network::MultipleMessageTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

namespace Network
{
    using TestingType = MultipleMessage<MultipleMessageField,
                                        MultipleMessageByteType::Int8,
                                        MultipleMessageByteType::Uint8,
                                        MultipleMessageByteType::Int16,
                                        MultipleMessageByteType::Uint16,
                                        MultipleMessageByteType::Int32,
                                        MultipleMessageByteType::Uint32,
                                        MultipleMessageByteType::Int64,
                                        MultipleMessageByteType::Uint64,
                                        MultipleMessageByteType::String>;
    using TestingTypeSharedPtr = std::shared_ptr<TestingType>;
}

void Network::MultipleMessageTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RttiTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FactoryTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamingTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MessageTest);
}

void Network::MultipleMessageTesting::RttiTest()
{
    constexpr int8_t int8Value{ -8 };
    constexpr int16_t int16Value{ 24 };
    constexpr int32_t int32Value{ -24 };
    constexpr int64_t int64Value{ 56 };

    constexpr uint8_t uint8Value{ 18 };
    constexpr uint16_t uint16Value{ 124 };
    constexpr uint32_t uint32Value{ 224 };
    constexpr uint64_t uint64Value{ 156 };

    const string stringValue{ "string" };

    TestingType::MessageType messageType{ int8Value, uint8Value, int16Value, uint16Value, int32Value, uint32Value, int64Value, uint64Value, stringValue };

    TestingTypeSharedPtr testMessage{ make_shared<TestingType>(MessageHeadStrategy::Default, messageID, messageType) };
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

void Network::MultipleMessageTesting::FactoryTest()
{
    constexpr int8_t int8Value{ -8 };
    constexpr int16_t int16Value{ 24 };
    constexpr int32_t int32Value{ -24 };
    constexpr int64_t int64Value{ 56 };

    constexpr uint8_t uint8Value{ 18 };
    constexpr uint16_t uint16Value{ 124 };
    constexpr uint32_t uint32Value{ 224 };
    constexpr uint64_t uint64Value{ 156 };

    const string stringValue{ "string" };

    TestingType::MessageType messageType{ int8Value, uint8Value, int16Value, uint16Value, int32Value, uint32Value, int64Value, uint64Value, stringValue };

    TestingTypeSharedPtr testMessage{ make_shared<TestingType>(MessageHeadStrategy::Default, messageID, messageType) };

    MESSAGE_MANAGER_SINGLETON.Insert(messageID, MessageTypeCondition::CreateNullCondition(), TestingType::Factory);

    MessageBufferSharedPtr buffer{ make_shared<MessageBuffer>(BuffBlockSize::Size256, ParserStrategy::LittleEndian) };
    MessageTarget messageTarget{ *buffer };

    testMessage->Save(messageTarget);

    MessageSource messageSource{ *buffer };

    MessageHeadStrategy messageHeadStrategy{};
    messageSource.ReadEnum(messageHeadStrategy);

    int32_t sourceMessageID{ 0 };
    messageSource.Read(sourceMessageID);

    ASSERT_EQUAL(sourceMessageID, messageID);

    auto factoryCreateMessage = TestingType::Factory(messageSource, MessageHeadStrategy::Default, messageID);
    auto polymorphicMessage = boost::dynamic_pointer_cast<TestingType>(factoryCreateMessage);

    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(polymorphicMessage, "消息类型错误！");

    ASSERT_EQUAL(polymorphicMessage->GetSize(), System::EnumCastUnderlying(MultipleMessageField::Count));
    ASSERT_EQUAL_FAILURE_THROW(polymorphicMessage->GetSize(), messageType.GetSize(), "消息大小错误！");

    ASSERT_EQUAL(polymorphicMessage->GetValue<MultipleMessageField::Int8>(), int8Value);
    ASSERT_EQUAL(polymorphicMessage->GetValue<MultipleMessageField::UInt8>(), uint8Value);
    ASSERT_EQUAL(polymorphicMessage->GetValue<MultipleMessageField::Int16>(), int16Value);
    ASSERT_EQUAL(polymorphicMessage->GetValue<MultipleMessageField::UInt16>(), uint16Value);
    ASSERT_EQUAL(polymorphicMessage->GetValue<MultipleMessageField::Int32>(), int32Value);
    ASSERT_EQUAL(polymorphicMessage->GetValue<MultipleMessageField::UInt32>(), uint32Value);
    ASSERT_EQUAL(polymorphicMessage->GetValue<MultipleMessageField::Int64>(), int64Value);
    ASSERT_EQUAL(polymorphicMessage->GetValue<MultipleMessageField::UInt64>(), uint64Value);
    ASSERT_EQUAL(polymorphicMessage->GetValue<MultipleMessageField::String>(), stringValue);

    MESSAGE_MANAGER_SINGLETON.Remove(messageID);
}

void Network::MultipleMessageTesting::StreamingTest()
{
    constexpr int8_t int8Value{ -8 };
    constexpr int16_t int16Value{ 24 };
    constexpr int32_t int32Value{ -24 };
    constexpr int64_t int64Value{ 56 };

    constexpr uint8_t uint8Value{ 18 };
    constexpr uint16_t uint16Value{ 124 };
    constexpr uint32_t uint32Value{ 224 };
    constexpr uint64_t uint64Value{ 156 };

    const string stringValue{ "string" };

    TestingTypeSharedPtr testMessage{ make_shared<TestingType>(MessageHeadStrategy::Default, messageID, int8Value, uint8Value, int16Value, uint16Value, int32Value, uint32Value, int64Value, uint64Value, stringValue) };
    ASSERT_TRUE(testMessage->IsExactlyTypeOf(testMessage));

    const auto streamSize = CoreTools::GetStreamSize(int8Value) +
                            CoreTools::GetStreamSize(int16Value) +
                            CoreTools::GetStreamSize(int32Value) +
                            CoreTools::GetStreamSize(int64Value) +
                            CoreTools::GetStreamSize(uint8Value) +
                            CoreTools::GetStreamSize(uint16Value) +
                            CoreTools::GetStreamSize(uint32Value) +
                            CoreTools::GetStreamSize(uint64Value) +
                            CoreTools::GetStreamSize(stringValue) +
                            CoreTools::GetStreamSize(messageID);

    ASSERT_EQUAL(testMessage->GetStreamingSize(), streamSize);

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

    auto sourceTestMessage{ make_shared<TestingType>(MessageHeadStrategy::Default, messageID, TestingType::MessageType{}) };

    ASSERT_TRUE(sourceTestMessage->IsExactlyTypeOf(sourceTestMessage));

    sourceTestMessage->Load(messageSource);

    ASSERT_EQUAL(sourceTestMessage->GetValue<MultipleMessageField::Int8>(), int8Value);
    ASSERT_EQUAL(sourceTestMessage->GetValue<MultipleMessageField::UInt8>(), uint8Value);
    ASSERT_EQUAL(sourceTestMessage->GetValue<MultipleMessageField::Int16>(), int16Value);
    ASSERT_EQUAL(sourceTestMessage->GetValue<MultipleMessageField::UInt16>(), uint16Value);
    ASSERT_EQUAL(sourceTestMessage->GetValue<MultipleMessageField::Int32>(), int32Value);
    ASSERT_EQUAL(sourceTestMessage->GetValue<MultipleMessageField::UInt32>(), uint32Value);
    ASSERT_EQUAL(sourceTestMessage->GetValue<MultipleMessageField::Int64>(), int64Value);
    ASSERT_EQUAL(sourceTestMessage->GetValue<MultipleMessageField::UInt64>(), uint64Value);
    ASSERT_EQUAL(sourceTestMessage->GetValue<MultipleMessageField::String>(), stringValue);

    MESSAGE_MANAGER_SINGLETON.Remove(messageID);
}

void Network::MultipleMessageTesting::MessageTest()
{
    constexpr int8_t int8Value{ -8 };
    constexpr int16_t int16Value{ 24 };
    constexpr int32_t int32Value{ -24 };
    constexpr int64_t int64Value{ 56 };

    constexpr uint8_t uint8Value{ 18 };
    constexpr uint16_t uint16Value{ 124 };
    constexpr uint32_t uint32Value{ 224 };
    constexpr uint64_t uint64Value{ 156 };

    const string stringValue{ "string" };

    TestingTypeSharedPtr testMessage{ make_shared<TestingType>(MessageHeadStrategy::Default, messageID, int8Value, uint8Value, int16Value, uint16Value, int32Value, uint32Value, int64Value, uint64Value, stringValue) };
    ASSERT_TRUE(testMessage->IsExactlyTypeOf(testMessage));

    ASSERT_EQUAL(testMessage->GetMessageId(), messageID);
    ASSERT_EQUAL(testMessage->GetSubMessageId(), 0);
    ASSERT_EQUAL(testMessage->GetFullMessageId(), messageID);
}