/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.9 (2024/04/23 12:57)

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