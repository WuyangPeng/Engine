// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 19:14)

#ifndef CORE_TOOLS_STATE_MACHINE_SUITE_PLAYER_ENTITY_H
#define CORE_TOOLS_STATE_MACHINE_SUITE_PLAYER_ENTITY_H

#include "CoreTools/CoreToolsTesting/StateMachineSuite/Flags/States.h"
#include "CoreTools/StateMachineManager/StateEntityDetail.h"

namespace CoreTools
{
    class PlayerEntity : public StateEntity<PlayerEntity, States>
    {
    public:
        using ClassType = PlayerEntity;
        using ParentType = StateEntity<PlayerEntity, States>;

    public:
        explicit PlayerEntity(StateSharedPtr currentState);
        explicit PlayerEntity(StateSharedPtr currentState, StateSharedPtr globalState); 

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // CORE_TOOLS_STATE_MACHINE_SUITE_PLAYER_ENTITY_H