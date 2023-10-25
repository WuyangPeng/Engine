///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 14:49)

#include "PlayerEntity.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/MessageEvent/EventEntityDetail.h"
#include "CoreTools/StateMachineManager/StateDetail.h"
#include "CoreTools/StateMachineManager/StateEntityDetail.h"
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
