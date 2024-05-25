/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/23 12:57)

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

#endif  // CORE_TOOLS_STATE_MACHINE_SUITE_PLAYER_DETAIL_H