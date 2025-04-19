/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.9 (2024/04/23 12:57)

#ifndef CORE_TOOLS_STATE_MACHINE_SUITE_GLOBAL_STATES_H
#define CORE_TOOLS_STATE_MACHINE_SUITE_GLOBAL_STATES_H

#include "PlayerEntity.h"
#include "CoreTools/StateMachineManager/State.h"

namespace CoreTools
{
    class GlobalStates final : public State<PlayerEntity>
    {
    public:
        using ClassType = GlobalStates;
        using ParentType = State<PlayerEntity>;

    public:
        GlobalStates() noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD StateSharedPtr Execute(int64_t timeInterval) override;

        void Exit() noexcept override;

        NODISCARD MessageResult OnMessage(const TelegramType& telegram) override;

        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;

    private:
        void DoEnter() noexcept override;
    };
}

#endif  // CORE_TOOLS_STATE_MACHINE_SUITE_GLOBAL_STATES_H