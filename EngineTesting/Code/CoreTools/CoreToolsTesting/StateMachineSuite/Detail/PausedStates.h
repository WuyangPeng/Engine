/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/23 12:57)

#ifndef CORE_TOOLS_STATE_MACHINE_SUITE_PAUSED_STATES_H
#define CORE_TOOLS_STATE_MACHINE_SUITE_PAUSED_STATES_H

#include "PlayerEntity.h"
#include "CoreTools/StateMachineManager/State.h"

namespace CoreTools
{
    class PausedStates final : public State<PlayerEntity>
    {
    public:
        using ClassType = PausedStates;
        using ParentType = State<PlayerEntity>;

    public:
        PausedStates() noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD StateSharedPtr Execute(int64_t timeInterval) override;

        void Exit() noexcept override;

        NODISCARD MessageResult OnMessage(const TelegramType& telegram) override;

        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;

    private:
        void DoEnter() noexcept override;
    };
}

#endif  // CORE_TOOLS_STATE_MACHINE_SUITE_PAUSED_STATES_H