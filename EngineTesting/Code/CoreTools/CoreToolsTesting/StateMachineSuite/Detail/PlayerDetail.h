// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 19:13)

#ifndef CORE_TOOLS_STATE_MACHINE_SUITE_PLAYER_DETAIL_H
#define CORE_TOOLS_STATE_MACHINE_SUITE_PLAYER_DETAIL_H

#include "Player.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename EventType>
CoreTools::Player::StateType CoreTools::Player::NoTransition(StateType state, const EventType& eventType) noexcept
{
	if (state == States::Empty)
	{
		SetStateType(state);
	}

	return ParentType::NoTransition(state, eventType);
}

#endif // CORE_TOOLS_STATE_MACHINE_SUITE_PLAYER_DETAIL_H