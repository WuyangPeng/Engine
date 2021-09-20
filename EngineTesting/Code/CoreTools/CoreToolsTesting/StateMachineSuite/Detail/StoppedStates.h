// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 19:14)

#ifndef CORE_TOOLS_STATE_MACHINE_SUITE_STOPPED_STATES_H
#define CORE_TOOLS_STATE_MACHINE_SUITE_STOPPED_STATES_H

#include "PlayerEntity.h"
#include "CoreTools/StateMachineManager/StateDetail.h"

namespace CoreTools
{
    class StoppedStates : public State<PlayerEntity>
    {
    public:
        using ClassType = StoppedStates;
        using ParentType = State<PlayerEntity>;

    public:
        StoppedStates() noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        StateSharedPtr Execute(int64_t timeInterval) override;

        void Exit() noexcept override;

        MessageResult OnMessage(const Telegram& telegram) override;

        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;

    private:
        void DoEnter() noexcept override;
    };
}

#endif  // CORE_TOOLS_STATE_MACHINE_SUITE_STOPPED_STATES_H