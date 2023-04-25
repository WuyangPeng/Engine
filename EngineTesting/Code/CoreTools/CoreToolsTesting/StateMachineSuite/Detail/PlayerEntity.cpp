///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.6 (2023/04/25 10:55)

#include "PlayerEntity.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/MessageEvent/EventEntityDetail.h"
#include "CoreTools/StateMachineManager/StateDetail.h"
#include "CoreTools/StateMachineManager/StateMachineBaseDetail.h"

CoreTools::PlayerEntity::PlayerEntity(const StateSharedPtr& currentState)
    : ParentType{ currentState }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::PlayerEntity::PlayerEntity(const StateSharedPtr& currentState, const StateSharedPtr& globalState)
    : ParentType{ currentState, globalState }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, PlayerEntity)
