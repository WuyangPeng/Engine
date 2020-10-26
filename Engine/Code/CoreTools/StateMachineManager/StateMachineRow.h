//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/26 16:01)

#ifndef CORE_TOOLS_STATE_MACHINE_STATE_MACHINE_ROW_H
#define CORE_TOOLS_STATE_MACHINE_STATE_MACHINE_ROW_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    template <typename Derived, typename State, State CurrentState, typename Event,
              State NextState, void (Derived::*Action)(const Event&)>
    class StateMachineRow final
    {
    public:
        using StateType = State;
        using EventType = Event;
        constexpr static auto sm_CurrentState = CurrentState;
        constexpr static auto sm_NextState = NextState;
        using ClassType = StateMachineRow<Derived, StateType, CurrentState, EventType, NextState, Action>;
        using FsmType = Derived;

    public:
        static void Execute(Derived& fsm, const EventType& eventType);
    };
}

#endif  //  CORE_TOOLS_STATE_MACHINE_STATE_MACHINE_ROW_H
