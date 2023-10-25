///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/20 14:53)

#ifndef CORE_TOOLS_STATE_MACHINE_DEFAULT_EVENT_DISPATCHER_DETAIL_H
#define CORE_TOOLS_STATE_MACHINE_DEFAULT_EVENT_DISPATCHER_DETAIL_H

#include "DefaultEventDispatcher.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename State>
template <typename FsmType, typename EventType>
typename CoreTools::DefaultEventDispatcher<State>::StateType CoreTools::DefaultEventDispatcher<State>::Dispatch(StateMachine<FsmType, StateType>& fsm, StateType state, const EventType& eventType)
{
    return fsm.CallNoTransition(state, eventType);
}

#endif  //  CORE_TOOLS_STATE_MACHINE_DEFAULT_EVENT_DISPATCHER_DETAIL_H
