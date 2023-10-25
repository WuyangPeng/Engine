///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/09/20 14:52)

#ifndef CORE_TOOLS_STATE_MACHINE_EVENT_DISPATCHER_H
#define CORE_TOOLS_STATE_MACHINE_EVENT_DISPATCHER_H

#include "CoreTools/CoreToolsDll.h"

// �¼�������
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
