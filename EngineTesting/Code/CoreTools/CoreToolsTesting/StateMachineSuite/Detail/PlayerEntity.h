/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.9 (2024/04/23 12:58)

#ifndef CORE_TOOLS_STATE_MACHINE_SUITE_PLAYER_ENTITY_H
#define CORE_TOOLS_STATE_MACHINE_SUITE_PLAYER_ENTITY_H

#include "CoreTools/CoreToolsTesting/StateMachineSuite/Flags/States.h"
#include "CoreTools/StateMachineManager/StateEntity.h"

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