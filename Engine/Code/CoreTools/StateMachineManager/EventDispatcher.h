///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/20 14:52)

#ifndef CORE_TOOLS_STATE_MACHINE_EVENT_DISPATCHER_H
#define CORE_TOOLS_STATE_MACHINE_EVENT_DISPATCHER_H

#include "CoreTools/CoreToolsDll.h"

// 事件分派器
namespace CoreTools
{
    template <typename Transition, typename Next, typename State = int>
    class EventDispatcher final
    {
    public:
        using StateType = State;
        using ClassType = EventDispatcher<Transition, Next, StateType>;
        using FsmType = typename Transition::FsmType;
        using EventType = typename Transition::EventType;

    public:
        NODISCARD static StateType Dispatch(FsmType& fsm, StateType state, const EventType& eventType);
    };
}

#endif  //  CORE_TOOLS_STATE_MACHINE_EVENT_DISPATCHER_H
