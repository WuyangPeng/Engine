//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/26 16:00)

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
        explicit StateMachineBase(StateSharedPtr currentState);
        StateMachineBase(StateSharedPtr currentState, StateSharedPtr globalState);

        virtual ~StateMachineBase() noexcept = default;
        StateMachineBase(const StateMachineBase& rhs) noexcept = default;
        StateMachineBase& operator=(const StateMachineBase& rhs) noexcept = default;
        StateMachineBase(StateMachineBase&& rhs) noexcept = default;
        StateMachineBase& operator=(StateMachineBase&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        void Register(EntityTypePtr owner);

        void Update(int64_t timeInterval);

        [[nodiscard]] bool HandleMessage(const Telegram& msg);

        [[nodiscard]] bool IsInState(const State& state) const;

        [[nodiscard]] ConstStateSharedPtr GetCurrentState() const;
        [[nodiscard]] ConstStateSharedPtr GetGlobalState() const;
        [[nodiscard]] ConstStateSharedPtr GetPreviousState() const;
        [[nodiscard]] ConstStateSharedPtr GetPossiblePreviousState() const;

        [[nodiscard]] StateSharedPtr GetPossiblePreviousState();

    private:
        void ChangeState(StateSharedPtr newState);

    private:
        StateSharedPtr m_CurrentState;
        StateSharedPtr m_PreviousState;
        StateSharedPtr m_GlobalState;
    };
}

#endif  //  CORE_TOOLS_STATE_MACHINE_STATE_MACHINE_BASE_H
