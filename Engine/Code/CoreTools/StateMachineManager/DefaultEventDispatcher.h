///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/09/20 14:52)

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
