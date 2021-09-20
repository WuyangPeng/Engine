// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 最后的霸王版本：0.0.2.0 (2020/01/09 22:55)

#include "GameClientMessage.h"
#include "CoreTools/Helper/ClassInvariantMacro.h" 
#include "Framework/MiddleLayer/InputManagerDetail.h"
#include "Framework/WindowProcess/WindowMessageDetail.h" 
#include "Framework/MiddleLayer/ObjectLogicManagerDetail.h"
#include "Framework/MiddleLayer/MiddleLayerInterface.h"
#include "Framework/MiddleLayer/EngineMiddleLayerContainerDetail.h"
#include "GameClient/GameClientMiddleLayer/Input/InputManagerDetail.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"

GameClient::GameClientMessage
	::GameClientMessage(int64_t delta)
    : ParentType{ delta }, m_Alloc{ CoreTools::DisableNotThrow::Disable }
{ 
	SELF_CLASS_IS_VALID_1;
}

GameClient::GameClientMessage
	::~GameClientMessage()
{
	SELF_CLASS_IS_VALID_1;
}
 
CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(GameClient, GameClientMessage)
 
 