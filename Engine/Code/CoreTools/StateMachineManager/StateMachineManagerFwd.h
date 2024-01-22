/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 10:20)

#ifndef CORE_TOOLS_STATE_MACHINE_FWD_H
#define CORE_TOOLS_STATE_MACHINE_FWD_H

// 状态机
namespace CoreTools
{
    template <typename Transition, typename Next, typename State>
    class EventDispatcher;

    template <typename State>
    class DefaultEventDispatcher;

    template <typename Derived, typename State, State CurrentState, typename Event, State NextState, void (Derived::*Action)(const Event&)>
    class StateMachineRow;

    template <typename Transition>
    struct TransitionEvent;

    template <typename Table, typename Event, typename State>
    struct GenerateDispatcher;

    template <typename Derived, typename State>
    class StateMachine;

    template <typename Subclass, typename EventType>
    class StateEntity;

    template <typename EntityType>
    class State;

    template <typename EntityType, typename EventType>
    class StateMachineBase;
}

#endif  // CORE_TOOLS_STATE_MACHINE_FWD_H