///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/20 14:51)

#ifndef CORE_TOOLS_STATE_MACHINE_STATE_MACHINE_BASE_H
#define CORE_TOOLS_STATE_MACHINE_STATE_MACHINE_BASE_H

#include "CoreTools/CoreToolsDll.h"

#include "State.h"
#include "StateEntity.h"
#include "CoreTools/MessageEvent/Telegram.h"

namespace CoreTools
{
    template <typename EntityType, typename EventType>
    class StateMachineBase
    {
    public:
        using ClassType = StateMachineBase<EntityType, EventType>;

        using EntityTypePtr = std::shared_ptr<EntityType>;
        using EntityEventType = EventType;
        using Telegram = Telegram<EntityEventType>;
        using EntityTypeWeakPtr = std::weak_ptr<EntityType>;
        using State = State<EntityType>;
        using StateSharedPtr = std::shared_ptr<State>;
        using ConstStateSharedPtr = std::shared_ptr<const State>;

    public:
        explicit StateMachineBase(StateSharedPtr currentState) noexcept;
        StateMachineBase(StateSharedPtr currentState, StateSharedPtr globalState) noexcept;

        virtual ~StateMachineBase() noexcept = default;
        StateMachineBase(const StateMachineBase& rhs) noexcept = default;
        StateMachineBase& operator=(const StateMachineBase& rhs) noexcept = default;
        StateMachineBase(StateMachineBase&& rhs) noexcept = default;
        StateMachineBase& operator=(StateMachineBase&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        void Register(EntityTypePtr owner);

        void Update(int64_t timeInterval);

        NODISCARD bool HandleMessage(const Telegram& msg);

        NODISCARD bool IsInState(const State& state) const;

        NODISCARD ConstStateSharedPtr GetCurrentState() const noexcept;
        NODISCARD ConstStateSharedPtr GetGlobalState() const noexcept;
        NODISCARD ConstStateSharedPtr GetPreviousState() const noexcept;
        NODISCARD ConstStateSharedPtr GetPossiblePreviousState() const noexcept;

        NODISCARD StateSharedPtr GetPossiblePreviousState() noexcept;

    private:
        void ChangeState(const StateSharedPtr& newState);

    private:
        StateSharedPtr currentState;
        StateSharedPtr previousState;
        StateSharedPtr globalState;
    };
}

#endif  //  CORE_TOOLS_STATE_MACHINE_STATE_MACHINE_BASE_H
