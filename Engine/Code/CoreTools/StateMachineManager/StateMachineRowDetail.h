///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/20 14:52)

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
