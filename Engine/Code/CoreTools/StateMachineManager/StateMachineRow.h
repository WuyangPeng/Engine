/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 10:20)

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
        constexpr static auto currentState = CurrentState;
        constexpr static auto nextState = NextState;

        using ClassType = StateMachineRow<Derived, StateType, CurrentState, EventType, NextState, Action>;
        using FsmType = Derived;

    public:
        static void Execute(Derived& fsm, const EventType& eventType) noexcept;
    };
}

#endif  //  CORE_TOOLS_STATE_MACHINE_STATE_MACHINE_ROW_H
