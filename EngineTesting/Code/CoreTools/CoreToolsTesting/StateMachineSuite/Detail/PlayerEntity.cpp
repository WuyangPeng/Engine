// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 19:16)

#include "PlayerEntity.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include "CoreTools/MessageEvent/EventEntityDetail.h"
#include "CoreTools/StateMachineManager/StateDetail.h"
#include "CoreTools/StateMachineManager/StateMachineBaseDetail.h"

CoreTools::PlayerEntity::PlayerEntity(StateSharedPtr currentState)
    : ParentType{ currentState }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::PlayerEntity::PlayerEntity(StateSharedPtr currentState, StateSharedPtr globalState)
    : ParentType{ currentState, globalState }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}
 
CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, PlayerEntity)
