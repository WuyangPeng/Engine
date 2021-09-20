// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 最后的霸王版本：0.0.0.1 (2019/10/12 13:05)

#include "WorldServerMessage.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include "WorldServer/WorldServerMiddleLayer/Input/InputManagerDetail.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "Framework/MiddleLayer/EngineMiddleLayerContainerDetail.h"
#include "Framework/MiddleLayer/InputManagerDetail.h"
#include "Framework/MiddleLayer/MiddleLayerInterface.h"
#include "Framework/MiddleLayer/ObjectLogicManagerDetail.h"
#include "Framework/WindowProcess/WindowMessageDetail.h"

WorldServer::WorldServerMessage ::WorldServerMessage(int64_t delta)
    : ParentType{ delta }, m_Alloc{ CoreTools::DisableNotThrow::Disable }
{
    SELF_CLASS_IS_VALID_1;
}

WorldServer::WorldServerMessage ::~WorldServerMessage()
{
    SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(WorldServer, WorldServerMessage)
