///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.6 (2023/04/25 10:50)

#ifndef CORE_TOOLS_STATE_MACHINE_SUITE_PLAYER_ENTITY_H
#define CORE_TOOLS_STATE_MACHINE_SUITE_PLAYER_ENTITY_H

#include "CoreTools/CoreToolsTesting/StateMachineSuite/Flags/States.h"
#include "CoreTools/StateMachineManager/StateEntityDetail.h"

namespace CoreTools
{
    class PlayerEntity final : public StateEntity<PlayerEntity, States>
    {
    public:
        using ClassType = PlayerEntity;
        using ParentType = StateEntity<PlayerEntity, States>;

    public:
        explicit PlayerEntity(const StateSharedPtr& currentState);
        explicit PlayerEntity(const StateSharedPtr& currentState, const StateSharedPtr& globalState);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // CORE_TOOLS_STATE_MACHINE_SUITE_PLAYER_ENTITY_H