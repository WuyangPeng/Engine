///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/21 16:16)

#ifndef CORE_TOOLS_STATE_MACHINE_EVENT_DISPATCHER_DETAIL_H
#define CORE_TOOLS_STATE_MACHINE_EVENT_DISPATCHER_DETAIL_H

#include "EventDispatcher.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename Transition, typename Next, typename State>
typename CoreTools::EventDispatcher<Transition, Next, State>::StateType CoreTools::EventDispatcher<Transition, Next, State>::Dispatch(FsmType& fsm, StateType state, const EventType& eventType)  
{
    if (state == Transition::sm_CurrentState)
    {
        Transition::Execute(fsm, eventType);

        return Transition::sm_NextState;
    }
    else  // 移动到链中的下一个节点。
    {
        return Next::Dispatch(fsm, state, eventType);
    }
}

#endif  //  CORE_TOOLS_TEMPLATE_TOOLS_EXPLICIT_CAST_DETAIL_H
