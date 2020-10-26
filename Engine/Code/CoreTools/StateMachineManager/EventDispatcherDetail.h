//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/26 16:02)

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
    else  // �ƶ������е���һ���ڵ㡣
    {
        return Next::Dispatch(fsm, state, eventType);
    }
}

#endif  //  CORE_TOOLS_TEMPLATE_TOOLS_EXPLICIT_CAST_DETAIL_H
