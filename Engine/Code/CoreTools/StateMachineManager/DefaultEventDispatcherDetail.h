/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/12 15:20)

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
