///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/03/31 16:02)

#ifndef CORE_TOOLS_STATE_MACHINE_DEFAULT_STATE_MACHINE_ROW_DETAIL_H
#define CORE_TOOLS_STATE_MACHINE_DEFAULT_STATE_MACHINE_ROW_DETAIL_H

#include "StateMachineRow.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename Derived, typename State, State CurrentState, typename Event, State NextState, void (Derived::*Action)(const Event&)>
void CoreTools::StateMachineRow<Derived, State, CurrentState, Event, NextState, Action>::Execute(Derived& fsm, const EventType& eventType) noexcept
{
    (fsm.*Action)(eventType);
}

#endif  //  CORE_TOOLS_STATE_MACHINE_DEFAULT_STATE_MACHINE_ROW_DETAIL_H
