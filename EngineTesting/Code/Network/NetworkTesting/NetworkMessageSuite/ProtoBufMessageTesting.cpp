///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/16 09:52)

#include "ProtoBufMessageTesting.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/NetworkMessage/Flags/MessageLengthFlags.h"
#include "Network/NetworkMessage/MessageManager.h"
#include "Network/NetworkMessage/MessageSourceDetail.h"
#include "Network/NetworkMessage/MessageTargetDetail.h"
#include "Network/NetworkMessage/MessageTypeCondition.h"
#include "Network/NetworkMessage/ProtoBufMessageDetail.h"
#include "Network/NetworkTesting/NetworkMessageSuite/Detail/Resource/Protobuf/Proto/Player.pb.h"

using System::operator|;

namespace Network
{
    using PlayerRequest = ProtoBufMessage<Player::PlayerRequest>;
    using PlayerResponse = ProtoBufMessage<Player::PlayerResponse>;
}

Network::ProtoBufMessageTesting::ProtoBufMessageTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, ProtoBufMessageTesting)

void Network::ProtoBufMessageTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::ProtoBufMessageTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RttiTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FactoryTest);
    ASSERT_NOT_THROW_EXCEPTION_0(StreamingTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MessageTest);
}

void Network::ProtoBufMessageTesting::RttiTest()
{
    const auto playerRequestMessage = std::make_shared<PlayerRequest>(MessageHeadStrategy::UseProtoBuf, messageId, Player::PlayerRequest{});
    const auto playerResponseMessage = std::make_shared<PlayerResponse>(MessageHeadStrategy::UseSubId | MessageHeadStrategy::UseProtoBuf, messageId, Player::PlayerResponse{});

    ASSERT_TRUE(playerRequestMessage->IsExactly(PlayerRequest::GetCurrentRttiType()));
    ASSERT_FALSE(playerRequestMessage->IsExactly(MessageInterface::GetCurrentRttiType()));
    ASSERT_TRUE(playerRequestMessage->IsDerived(PlayerRequest::GetCurrentRttiType()));
    ASSERT_FALSE(playerRequestMessage->IsDerived(PlayerResponse::GetCurrentRttiType()));

    ASSERT_TRUE(playerRequestMessage->IsExactlyTypeOf(playerRequestMessage));
    ASSERT_TRUE(playerRequestMessage->IsDerivedTypeOf(playerRequestMessage));

    ASSERT_FALSE(playerRequestMessage->IsExactlyTypeOf(playerResponseMessage));
    ASSERT_FALSE(playerRequestMessage->IsDerivedTypeOf(playerResponseMessage));

    const auto& attiType = playerRequestMessage->GetRttiType();

    ASSERT_EQUAL(attiType.GetName(), "class Player::PlayerRequest");
}

void Network::ProtoBufMessageTesting::FactoryTest()
{
    constexpr auto userId = 5;

    Player::PlayerRequest request{};
    request.set_user_id(userId);

    const PlayerRequest playerRequest{ MessageHeadStrategy::UseProtoBuf, messageId, request };

    MESSAGE_MANAGER_SINGLETON.Insert(messageId, MessageTypeCondition::CreateNullCondition(), PlayerRequest::Factory);

    MessageBuffer buffer{ BuffBlockSize::Size256, ParserStrategy::LittleEndian };
    MessageTarget messageTarget{ buffer };

    playerRequest.Save(messageTarget);

    MessageSource messageSource{ buffer };

    MessageHeadStrategy messageHeadStrategy{};
    messageSource.ReadEnum(messageHeadStrategy);

    int32_t sourceMessageId{ 0 };
    messageSource.Read(sourceMessageId);

    ASSERT_EQUAL(sourceMessageId, messageId);

    const auto factoryCreateMessage = PlayerRequest::Factory(messageSource, MessageHeadStrategy::UseProtoBuf, messageId);
    const auto polymorphicMessage = boost::dynamic_pointer_cast<PlayerRequest>(factoryCreateMessage);

    ASSERT_EQUAL(polymorphicMessage->GetProtoBufMessage().user_id(), userId);

    MESSAGE_MANAGER_SINGLETON.Remove(messageId);
}

void Network::ProtoBufMessageTesting::StreamingTest()
{
    constexpr auto userId = 5;

    Player::PlayerResponse response{};
    response.set_user_id(userId);

    const auto playerResponse = std::make_shared<PlayerResponse>(MessageHeadStrategy::UseProtoBuf | MessageHeadStrategy::UseSubId, fullMessageId, response);
    ASSERT_TRUE(playerResponse->IsExactlyTypeOf(playerResponse));

    ASSERT_EQUAL(playerResponse->GetStreamingSize(), 16 + boost::numeric_cast<int>(response.ByteSizeLong()));

    MESSAGE_MANAGER_SINGLETON.Insert(messageId, MessageTypeCondition::CreateNullCondition(), PlayerResponse::Factory);

    MessageBuffer buffer{ BuffBlockSize::Size256, ParserStrategy::LittleEndian };
    MessageTarget messageTarget{ buffer };

    playerResponse->Save(messageTarget);

    MessageSource messageSource{ buffer };

    MessageHeadStrategy messageHeadStrategy{};
    messageSource.ReadEnum(messageHeadStrategy);

    int64_t sourceMessageId{ 0 };
    messageSource.Read(sourceMessageId);

    ASSERT_EQUAL(sourceMessageId, fullMessageId);

    const auto sourcePlayerResponse = std::make_shared<PlayerResponse>(MessageHeadStrategy::UseProtoBuf | MessageHeadStrategy::UseSubId, messageId, Player::PlayerResponse{});
    ASSERT_TRUE(sourcePlayerResponse->IsExactlyTypeOf(sourcePlayerResponse));

    sourcePlayerResponse->Load(messageSource);

    ASSERT_EQUAL(sourcePlayerResponse->GetProtoBufMessage().user_id(), userId);

    MESSAGE_MANAGER_SINGLETON.Remove(messageId);
}

void Network::ProtoBufMessageTesting::MessageTest()
{
    constexpr auto userId = 5;

    Player::PlayerResponse response{};
    response.set_user_id(userId);

    const auto playerResponse = std::make_shared<PlayerResponse>(MessageHeadStrategy::UseProtoBuf | MessageHeadStrategy::UseSubId, fullMessageId, response);

    ASSERT_EQUAL(playerResponse->GetMessageId(), messageId);
    ASSERT_EQUAL(playerResponse->GetSubMessageId(), subMessageId);
    ASSERT_EQUAL(playerResponse->GetFullMessageId(), fullMessageId);

    ASSERT_TRUE(playerResponse->IsExactlyTypeOf(playerResponse));

    ASSERT_ENUM_EQUAL(playerResponse->GetMessageHeadStrategy(), MessageHeadStrategy::UseProtoBuf | MessageHeadStrategy::UseSubId);
}
