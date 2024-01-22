/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 10:20)

#ifndef CORE_TOOLS_STATE_MACHINE_MANAGER_STATE_ENTITY_H
#define CORE_TOOLS_STATE_MACHINE_MANAGER_STATE_ENTITY_H

#include "CoreTools/CoreToolsDll.h"

#include "StateMachineBase.h"
#include "CoreTools/MessageEvent/EventEntity.h"

namespace CoreTools
{
    template <typename Subclass, typename EventType = int>
    class StateEntity : public EventEntity<EventType>
    {
    public:
        using ClassType = StateEntity<Subclass, EventType>;
        using ParentType = EventEntity<EventType>;

        using StateMachineBase = StateMachineBase<Subclass, EventType>;
        using State = State<Subclass>;
        using StateSharedPtr = std::shared_ptr<State>;
        using ConstStateSharedPtr = std::shared_ptr<const State>;
        using Telegram = Telegram<EventType>;

    public:
        explicit StateEntity(const StateSharedPtr& currentState);
        explicit StateEntity(const StateSharedPtr& currentState, const StateSharedPtr& globalState);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD bool EventFunction(const Telegram& telegram) override;

        void Update(int64_t timeInterval);

        NODISCARD ConstStateSharedPtr GetCurrentState() const noexcept;
        NODISCARD ConstStateSharedPtr GetGlobalState() const noexcept;
        NODISCARD StateSharedPtr GetPossiblePreviousState() noexcept;

    private:
        void DoRegister() override;

    private:
        StateMachineBase stateMachineBase;
    };
}

#endif  // CORE_TOOLS_STATE_MACHINE_MANAGER_STATE_ENTITY_H