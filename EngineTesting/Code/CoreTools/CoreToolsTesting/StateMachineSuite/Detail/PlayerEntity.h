///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/18 11:03)

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