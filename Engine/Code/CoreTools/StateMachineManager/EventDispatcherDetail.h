/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 15:20)

#ifndef CORE_TOOLS_STATE_MACHINE_EVENT_DISPATCHER_DETAIL_H
#define CORE_TOOLS_STATE_MACHINE_EVENT_DISPATCHER_DETAIL_H

#include "EventDispatcher.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename Transition, typename Next, typename State>
typename CoreTools::EventDispatcher<Transition, Next, State>::StateType CoreTools::EventDispatcher<Transition, Next, State>::Dispatch(FsmType& fsm, StateType state, const EventType& eventType)
{
    if (state == Transition::currentState)
    {
        Transition::Execute(fsm, eventType);

        return Transition::nextState;
    }
    else  /// 移动到链中的下一个节点。
    {
        return Next::Dispatch(fsm, state, eventType);
    }
}

#endif  //  CORE_TOOLS_TEMPLATE_TOOLS_EXPLICIT_CAST_DETAIL_H
