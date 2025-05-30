/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 15:18)

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
        using TelegramType = Telegram<EntityEventType>;
        using EntityTypeWeakPtr = std::weak_ptr<EntityType>;
        using StateType = State<EntityType>;
        using StateSharedPtr = std::shared_ptr<StateType>;
        using ConstStateSharedPtr = std::shared_ptr<const StateType>;

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

        NODISCARD bool HandleMessage(const TelegramType& msg);

        NODISCARD bool IsInState(const StateType& state) const;

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
