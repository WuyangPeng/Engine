///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/18 11:15)

#include "StateMachineTesting.h"
#include "Detail/PlayerDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
using std::vector;

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
    Player player;

    ASSERT_ENUM_EQUAL(player.GetStateType(), States::Empty);

    MAYBE_UNUSED auto value0 = player.ProcessEvent(OpenClose{});
    ASSERT_ENUM_EQUAL(player.GetStateType(), States::Open);

    MAYBE_UNUSED auto value1 = player.ProcessEvent(OpenClose{});
    ASSERT_ENUM_EQUAL(player.GetStateType(), States::Empty);

    MAYBE_UNUSED auto value2 = player.ProcessEvent(CdDetected{ "louie, louie", vector<clock_t>() });
    ASSERT_ENUM_EQUAL(player.GetStateType(), States::Stopped);

    MAYBE_UNUSED auto value3 = player.ProcessEvent(Play{});
    ASSERT_ENUM_EQUAL(player.GetStateType(), States::Playing);

    MAYBE_UNUSED auto value4 = player.ProcessEvent(Pause{});
    ASSERT_ENUM_EQUAL(player.GetStateType(), States::Paused);

    MAYBE_UNUSED auto value5 = player.ProcessEvent(Play{});
    ASSERT_ENUM_EQUAL(player.GetStateType(), States::Playing);

    MAYBE_UNUSED auto value6 = player.ProcessEvent(Stop{});
    ASSERT_ENUM_EQUAL(player.GetStateType(), States::Stopped);

    MAYBE_UNUSED auto value7 = player.ProcessEvent(Stop{});
    ASSERT_ENUM_EQUAL(player.GetStateType(), States::Stopped);

    MAYBE_UNUSED auto value8 = player.ProcessEvent(CdDetected{ "louie, louie", vector<clock_t>() });
    ASSERT_ENUM_EQUAL(player.GetStateType(), States::Stopped);
}
