/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.10 (2024/05/28 11:22)

#include "StateEntityTesting.h"
#include "Detail/EmptyStates.h"
#include "Detail/GlobalStates.h"
#include "Detail/OpenStates.h"
#include "Detail/PausedStates.h"
#include "Detail/PlayerEntity.h"
#include "Detail/PlayingStates.h"
#include "Detail/StoppedStates.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
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
    EntityManager::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    EntityManager::Destroy();
}

void CoreTools::StateEntityTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(PlayerTest);
}

void CoreTools::StateEntityTesting::PlayerTest()
{
    const auto playerEntity = MakeEntity();

    ASSERT_NOT_THROW_EXCEPTION_1(StateTest, *playerEntity);

    ASSERT_NOT_THROW_EXCEPTION_1(EventFunction0Test, *playerEntity);
    ASSERT_NOT_THROW_EXCEPTION_1(EventFunction1Test, *playerEntity);
    ASSERT_NOT_THROW_EXCEPTION_1(EventFunction2Test, *playerEntity);
    ASSERT_NOT_THROW_EXCEPTION_1(EventFunction3Test, *playerEntity);
    ASSERT_NOT_THROW_EXCEPTION_1(EventFunction4Test, *playerEntity);
    ASSERT_NOT_THROW_EXCEPTION_1(EventFunction5Test, *playerEntity);
    ASSERT_NOT_THROW_EXCEPTION_1(EventFunction6Test, *playerEntity);
}

CoreTools::StateEntityTesting::PlayerEntitySharedPtr CoreTools::StateEntityTesting::MakeEntity()
{
    auto currentState = State<PlayerEntity>::MakeState<EmptyStates>();
    auto globalState = State<PlayerEntity>::MakeState<GlobalStates>();

    return ENTITY_MANAGER_SINGLETON.MakeEntity<PlayerEntity>(currentState, globalState);
}

void CoreTools::StateEntityTesting::StateTest(const PlayerEntity& playerEntity)
{
    const auto currentState = playerEntity.GetCurrentState();
    const auto globalState = playerEntity.GetGlobalState();

    ASSERT_TRUE(currentState->IsExactly(EmptyStates::GetCurrentRttiType()));
    ASSERT_TRUE(globalState->IsExactly(GlobalStates::GetCurrentRttiType()));
}

void CoreTools::StateEntityTesting::EventFunction0Test(PlayerEntity& playerEntity)
{
    const Telegram telegram{ 1, States::Open, 0 };

    std::ignore = playerEntity.EventFunction(telegram);

    ASSERT_TRUE(playerEntity.GetCurrentState()->IsExactly(OpenStates::GetCurrentRttiType()));
}

void CoreTools::StateEntityTesting::EventFunction1Test(PlayerEntity& playerEntity)
{
    const Telegram telegram{ 1, States::Stopped, 0 };

    std::ignore = playerEntity.EventFunction(telegram);

    ASSERT_TRUE(playerEntity.GetCurrentState()->IsExactly(StoppedStates::GetCurrentRttiType()));
}

void CoreTools::StateEntityTesting::EventFunction2Test(PlayerEntity& playerEntity)
{
    const Telegram telegram{ 1, States::Playing, 0 };

    std::ignore = playerEntity.EventFunction(telegram);

    ASSERT_TRUE(playerEntity.GetCurrentState()->IsExactly(PlayingStates::GetCurrentRttiType()));
}

void CoreTools::StateEntityTesting::EventFunction3Test(PlayerEntity& playerEntity)
{
    const Telegram telegram{ 1, States::Paused, 0 };

    std::ignore = playerEntity.EventFunction(telegram);

    ASSERT_TRUE(playerEntity.GetCurrentState()->IsExactly(PausedStates::GetCurrentRttiType()));
}

void CoreTools::StateEntityTesting::EventFunction4Test(PlayerEntity& playerEntity)
{
    const Telegram telegram{ 1, States::Stopped, 0 };

    std::ignore = playerEntity.EventFunction(telegram);

    ASSERT_TRUE(playerEntity.GetCurrentState()->IsExactly(StoppedStates::GetCurrentRttiType()));
}

void CoreTools::StateEntityTesting::EventFunction5Test(PlayerEntity& playerEntity)
{
    const Telegram telegram{ 1, States::Empty, 0 };

    std::ignore = playerEntity.EventFunction(telegram);

    ASSERT_TRUE(playerEntity.GetCurrentState()->IsExactly(EmptyStates::GetCurrentRttiType()));
}

void CoreTools::StateEntityTesting::EventFunction6Test(PlayerEntity& playerEntity)
{
    const Telegram telegram{ 1, States::Previous, 0 };

    std::ignore = playerEntity.EventFunction(telegram);

    ASSERT_TRUE(playerEntity.GetCurrentState()->IsExactly(StoppedStates::GetCurrentRttiType()));
}
