//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.7.1.1 (2020/10/26 15:58)

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
        explicit StateEntity(StateSharedPtr currentState);
        explicit StateEntity(StateSharedPtr currentState, StateSharedPtr globalState);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] bool EventFunction(const Telegram& telegram) override;

        void Update(int64_t timeInterval);

        [[nodiscard]] ConstStateSharedPtr GetCurrentState() const noexcept;
        [[nodiscard]] ConstStateSharedPtr GetGlobalState() const noexcept;
        [[nodiscard]] StateSharedPtr GetPossiblePreviousState() noexcept;

    private:
        void DoRegister() override;

    private:
        StateMachineBase m_StateMachineBase;
    };
}

#endif  // CORE_TOOLS_STATE_MACHINE_MANAGER_STATE_ENTITY_H