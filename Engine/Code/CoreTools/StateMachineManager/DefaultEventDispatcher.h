//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/26 15:53)

#ifndef CORE_TOOLS_STATE_MACHINE_DEFAULT_EVENT_DISPATCHER_H
#define CORE_TOOLS_STATE_MACHINE_DEFAULT_EVENT_DISPATCHER_H

#include "CoreTools/CoreToolsDll.h"

#include "StateMachineManagerFwd.h"

// 默认事件分派器
namespace CoreTools
{
    template <typename State = int>
    class DefaultEventDispatcher final
    {
    public:
        using StateType = State;
        using ClassType = DefaultEventDispatcher<StateType>;

    public:
        template <typename FsmType, typename EventType>
        [[nodiscard]] static StateType Dispatch(StateMachine<FsmType, StateType>& fsm, StateType state, const EventType& eventType) noexcept;
    };
}

#endif  //  CORE_TOOLS_STATE_MACHINE_DEFAULT_EVENT_DISPATCHER_H
