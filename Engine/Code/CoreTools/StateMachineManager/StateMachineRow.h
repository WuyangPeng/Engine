///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/21 16:15)

#ifndef CORE_TOOLS_STATE_MACHINE_STATE_MACHINE_ROW_H
#define CORE_TOOLS_STATE_MACHINE_STATE_MACHINE_ROW_H

#include "CoreTools/CoreToolsDll.h"

namespace CoreTools
{
    template <typename Derived,
              typename State,
              State CurrentState,
              typename Event,
              State NextState,
              void (Derived::*Action)(const Event&)>
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
        static void Execute(Derived& fsm, const EventType& eventType) noexcept;
    };
}

#endif  //  CORE_TOOLS_STATE_MACHINE_STATE_MACHINE_ROW_H
