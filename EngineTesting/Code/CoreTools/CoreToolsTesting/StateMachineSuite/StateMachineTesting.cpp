// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 19:17)

#include "StateMachineTesting.h" 
#include "Detail/PlayerDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, StateMachineTesting)

void CoreTools::StateMachineTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(PlayerTest);
}

void CoreTools::StateMachineTesting
	::PlayerTest()
{
	Player player;

	ASSERT_ENUM_EQUAL(player.GetStateType(), States::Empty);

	[[maybe_unused]] auto value0 = player.ProcessEvent(OpenClose{});
	ASSERT_ENUM_EQUAL(player.GetStateType(), States::Open);

[[maybe_unused]] auto value1 = player.ProcessEvent(OpenClose{});
	ASSERT_ENUM_EQUAL(player.GetStateType(), States::Empty);

	[[maybe_unused]] auto value2 = player.ProcessEvent(CdDetected{ "louie, louie", vector<clock_t>() });
	ASSERT_ENUM_EQUAL(player.GetStateType(), States::Stopped);

[[maybe_unused]] auto value3 = player.ProcessEvent(Play{});
	ASSERT_ENUM_EQUAL(player.GetStateType(), States::Playing);

[[maybe_unused]] auto value4 = player.ProcessEvent(Pause{});
	ASSERT_ENUM_EQUAL(player.GetStateType(), States::Paused);

	[[maybe_unused]] auto value5 = player.ProcessEvent(Play{});
	ASSERT_ENUM_EQUAL(player.GetStateType(), States::Playing);

	[[maybe_unused]] auto value6 = player.ProcessEvent(Stop{});
	ASSERT_ENUM_EQUAL(player.GetStateType(), States::Stopped);

	[[maybe_unused]] auto value7 = player.ProcessEvent(Stop{});
	ASSERT_ENUM_EQUAL(player.GetStateType(), States::Stopped);

	[[maybe_unused]] auto value8 = player.ProcessEvent(CdDetected{ "louie, louie", vector<clock_t>() });
	ASSERT_ENUM_EQUAL(player.GetStateType(), States::Stopped);
}

