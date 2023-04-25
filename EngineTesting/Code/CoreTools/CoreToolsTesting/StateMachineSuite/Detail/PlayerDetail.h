///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.6 (2023/04/25 10:50)

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