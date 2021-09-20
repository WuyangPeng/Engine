//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/26 16:02)

#ifndef CORE_TOOLS_STATE_MACHINE_DEFAULT_EVENT_DISPATCHER_DETAIL_H
#define CORE_TOOLS_STATE_MACHINE_DEFAULT_EVENT_DISPATCHER_DETAIL_H

#include "DefaultEventDispatcher.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename State>
template <typename FsmType, typename EventType>
typename CoreTools::DefaultEventDispatcher<State>::StateType CoreTools::DefaultEventDispatcher<State>::Dispatch(StateMachine<FsmType, StateType>& fsm, StateType state, const EventType& eventType) noexcept
{
    return fsm.CallNoTransition(state, eventType);
}

#endif  //  CORE_TOOLS_STATE_MACHINE_DEFAULT_EVENT_DISPATCHER_DETAIL_H
