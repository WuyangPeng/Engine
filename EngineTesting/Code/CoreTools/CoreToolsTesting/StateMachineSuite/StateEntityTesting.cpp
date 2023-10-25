///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 14:49)

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
#include "CoreTools/StateMachineManager/StateEntityDetail.h"
#include "CoreTools/StateMachineManager/StateMachineBaseDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::StateEntityTesting::StateEntityTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, StateEntityTesting)

void CoreTools::StateEntityTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::StateEntityTesting::MainTest()
{
    EntityManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(PlayerTest);

    EntityManager::Destroy();
}

void CoreTools::StateEntityTesting::PlayerTest()
{
    auto currentState0 = State<PlayerEntity>::MakeState<EmptyStates>();
    auto globalState0 = State<PlayerEntity>::MakeState<GlobalStates>();
    auto playerEntity = ENTITY_MANAGER_SINGLETON.MakeEntity<PlayerEntity>(currentState0, globalState0);

    auto currentState1 = playerEntity->GetCurrentState();
    auto globalState1 = playerEntity->GetGlobalState();

    ASSERT_TRUE(currentState1->IsExactly(EmptyStates::GetCurrentRttiType()));
    ASSERT_TRUE(globalState1->IsExactly(GlobalStates::GetCurrentRttiType()));

    Telegram telegram0{ 1, States::Open, 0 };

    MAYBE_UNUSED const auto value0 = playerEntity->EventFunction(telegram0);

    ASSERT_TRUE(playerEntity->GetCurrentState()->IsExactly(OpenStates::GetCurrentRttiType()));

    Telegram telegram1{ 1, States::Stopped, 0 };

    MAYBE_UNUSED const auto value1 = playerEntity->EventFunction(telegram1);

    ASSERT_TRUE(playerEntity->GetCurrentState()->IsExactly(StoppedStates::GetCurrentRttiType()));

    Telegram telegram2{ 1, States::Playing, 0 };

    MAYBE_UNUSED const auto value2 = playerEntity->EventFunction(telegram2);

    ASSERT_TRUE(playerEntity->GetCurrentState()->IsExactly(PlayingStates::GetCurrentRttiType()));

    Telegram telegram3{ 1, States::Paused, 0 };

    MAYBE_UNUSED const auto value3 = playerEntity->EventFunction(telegram3);

    ASSERT_TRUE(playerEntity->GetCurrentState()->IsExactly(PausedStates::GetCurrentRttiType()));

    Telegram telegram4{ 1, States::Stopped, 0 };

    MAYBE_UNUSED const auto value4 = playerEntity->EventFunction(telegram4);

    ASSERT_TRUE(playerEntity->GetCurrentState()->IsExactly(StoppedStates::GetCurrentRttiType()));

    Telegram telegram5{ 1, States::Empty, 0 };

    MAYBE_UNUSED const auto value5 = playerEntity->EventFunction(telegram5);

    ASSERT_TRUE(playerEntity->GetCurrentState()->IsExactly(EmptyStates::GetCurrentRttiType()));

    Telegram telegram6{ 1, States::Previous, 0 };

    MAYBE_UNUSED const auto value6 = playerEntity->EventFunction(telegram6);

    ASSERT_TRUE(playerEntity->GetCurrentState()->IsExactly(StoppedStates::GetCurrentRttiType()));
}
