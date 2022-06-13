///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/18 11:15)

#include "StateEntityTesting.h"
#include "Detail/EmptyStates.h"
#include "Detail/GlobalStates.h"
#include "Detail/OpenStates.h"
#include "Detail/PausedStates.h"
#include "Detail/PlayerEntity.h"
#include "Detail/PlayingStates.h"
#include "Detail/StoppedStates.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/MessageEvent/EntityManagerDetail.h"
#include "CoreTools/StateMachineManager/StateDetail.h"
#include "CoreTools/StateMachineManager/StateMachineBaseDetail.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, StateEntityTesting)

void CoreTools::StateEntityTesting::MainTest()
{
    EntityManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(PlayerTest);

    EntityManager::Destroy();
}

void CoreTools::StateEntityTesting::PlayerTest()
{
    auto currentState = State<PlayerEntity>::MakeState<EmptyStates>();
    auto globalState = State<PlayerEntity>::MakeState<GlobalStates>();
    auto playerEntity = ENTITY_MANAGER_SINGLETON.MakeEntity<PlayerEntity>(currentState, globalState);

    auto secondCurrentState = playerEntity->GetCurrentState();
    auto secondGlobalState = playerEntity->GetGlobalState();

    ASSERT_TRUE(secondCurrentState->IsExactly(EmptyStates::GetCurrentRttiType()));
    ASSERT_TRUE(secondGlobalState->IsExactly(GlobalStates::GetCurrentRttiType()));

    Telegram<States> firstTelegram{ 1, States::Open, 0 };

    MAYBE_UNUSED const auto value0 = playerEntity->EventFunction(firstTelegram);

    ASSERT_TRUE(playerEntity->GetCurrentState()->IsExactly(OpenStates::GetCurrentRttiType()));

    Telegram<States> secondTelegram{ 1, States::Stopped, 0 };

    MAYBE_UNUSED const auto value1 = playerEntity->EventFunction(secondTelegram);

    ASSERT_TRUE(playerEntity->GetCurrentState()->IsExactly(StoppedStates::GetCurrentRttiType()));

    Telegram<States> thirdTelegram{ 1, States::Playing, 0 };

    MAYBE_UNUSED const auto value2 = playerEntity->EventFunction(thirdTelegram);

    ASSERT_TRUE(playerEntity->GetCurrentState()->IsExactly(PlayingStates::GetCurrentRttiType()));

    Telegram<States> fourthTelegram{ 1, States::Paused, 0 };

    MAYBE_UNUSED const auto value3 = playerEntity->EventFunction(fourthTelegram);

    ASSERT_TRUE(playerEntity->GetCurrentState()->IsExactly(PausedStates::GetCurrentRttiType()));

    Telegram<States> fifthTelegram{ 1, States::Stopped, 0 };

    MAYBE_UNUSED const auto value4 = playerEntity->EventFunction(fifthTelegram);

    ASSERT_TRUE(playerEntity->GetCurrentState()->IsExactly(StoppedStates::GetCurrentRttiType()));

    Telegram<States> sixthTelegram{ 1, States::Empty, 0 };

    MAYBE_UNUSED const auto value5 = playerEntity->EventFunction(sixthTelegram);

    ASSERT_TRUE(playerEntity->GetCurrentState()->IsExactly(EmptyStates::GetCurrentRttiType()));

    Telegram<States> seventhTelegram{ 1, States::Previous, 0 };

    MAYBE_UNUSED const auto value6 = playerEntity->EventFunction(seventhTelegram);

    ASSERT_TRUE(playerEntity->GetCurrentState()->IsExactly(StoppedStates::GetCurrentRttiType()));
}
