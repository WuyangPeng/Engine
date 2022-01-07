///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/21 15:55)

#ifndef CORE_TOOLS_STATE_MACHINE_DEFAULT_EVENT_DISPATCHER_H
#define CORE_TOOLS_STATE_MACHINE_DEFAULT_EVENT_DISPATCHER_H

#include "CoreTools/CoreToolsDll.h"

#include "StateMachineManagerFwd.h"

// Ĭ���¼�������
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
        NODISCARD static StateType Dispatch(StateMachine<FsmType, StateType>& fsm, StateType state, const EventType& eventType);
    };
}

#endif  //  CORE_TOOLS_STATE_MACHINE_DEFAULT_EVENT_DISPATCHER_H
