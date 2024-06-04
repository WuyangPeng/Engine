/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/23 12:59)

#include "StateMachineTesting.h"
#include "Detail/PlayerDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/StateMachineManager/StateMachineDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::StateMachineTesting::StateMachineTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, StateMachineTesting)

void CoreTools::StateMachineTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::StateMachineTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(PlayerTest);
}

void CoreTools::StateMachineTesting::PlayerTest()
{
    Player player{};

    ASSERT_EQUAL(player.GetStateType(), States::Empty);

    ASSERT_NOT_THROW_EXCEPTION_1(OpenCloseTest, player);
    ASSERT_NOT_THROW_EXCEPTION_1(PlayTest, player);
    ASSERT_NOT_THROW_EXCEPTION_1(StopTest, player);
}

void CoreTools::StateMachineTesting::OpenCloseTest(Player& player)
{
    std::ignore = player.ProcessEvent(OpenClose{});
    ASSERT_EQUAL(player.GetStateType(), States::Open);

    std::ignore = player.ProcessEvent(OpenClose{});
    ASSERT_EQUAL(player.GetStateType(), States::Empty);

    std::ignore = player.ProcessEvent(CdDetected{ "louie, louie", CdDetected::ClockContainer() });
    ASSERT_EQUAL(player.GetStateType(), States::Stopped);
}

void CoreTools::StateMachineTesting::PlayTest(Player& player)
{
    std::ignore = player.ProcessEvent(Play{});
    ASSERT_EQUAL(player.GetStateType(), States::Playing);

    std::ignore = player.ProcessEvent(Pause{});
    ASSERT_EQUAL(player.GetStateType(), States::Paused);

    std::ignore = player.ProcessEvent(Play{});
    ASSERT_EQUAL(player.GetStateType(), States::Playing);
}

void CoreTools::StateMachineTesting::StopTest(Player& player)
{
    std::ignore = player.ProcessEvent(Stop{});
    ASSERT_EQUAL(player.GetStateType(), States::Stopped);

    std::ignore = player.ProcessEvent(Stop{});
    ASSERT_EQUAL(player.GetStateType(), States::Stopped);

    std::ignore = player.ProcessEvent(CdDetected{ "louie, louie", CdDetected::ClockContainer() });
    ASSERT_EQUAL(player.GetStateType(), States::Stopped);
}