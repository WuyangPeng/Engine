///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/18 10:51)

#ifndef CORE_TOOLS_STATE_MACHINE_SUITE_GLOBAL_STATES_H
#define CORE_TOOLS_STATE_MACHINE_SUITE_GLOBAL_STATES_H

#include "PlayerEntity.h"
#include "CoreTools/StateMachineManager/StateDetail.h"

namespace CoreTools
{
    class GlobalStates : public State<PlayerEntity>
    {
    public:
        using ClassType = GlobalStates;
        using ParentType = State<PlayerEntity>;

    public:
        GlobalStates() noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD StateSharedPtr Execute(int64_t timeInterval) override;

        void Exit() noexcept override;

        NODISCARD MessageResult OnMessage(const Telegram& telegram) override;

        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;

    private:
        void DoEnter() noexcept override;
    };
}

#endif  // CORE_TOOLS_STATE_MACHINE_SUITE_GLOBAL_STATES_H