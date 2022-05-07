// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������԰汾��0.0.2.3 (2020/03/06 19:13)

#ifndef CORE_TOOLS_STATE_MACHINE_SUITE_PAUSED_STATES_H
#define CORE_TOOLS_STATE_MACHINE_SUITE_PAUSED_STATES_H

#include "PlayerEntity.h"
#include "CoreTools/StateMachineManager/StateDetail.h"

namespace CoreTools
{
    class PausedStates : public State<PlayerEntity>
    {
    public:
        using ClassType = PausedStates;
        using ParentType = State<PlayerEntity>;

    public:
        PausedStates() noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        StateSharedPtr Execute(int64_t timeInterval) override;

        void Exit() noexcept override;

        MessageResult OnMessage(const Telegram& telegram) override;

        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;

    private:
        void DoEnter() noexcept override;
    };
}

#endif  // CORE_TOOLS_STATE_MACHINE_SUITE_PAUSED_STATES_H