// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.1 (2019/10/12 14:01)

#include "OfflineServerMessage.h"
#include "CoreTools/Helper/ClassInvariantMacro.h" 

#include "Framework/MiddleLayer/InputManagerDetail.h"
#include "Framework/WindowProcess/WindowMessageDetail.h" 
#include "Framework/MiddleLayer/ObjectLogicManagerDetail.h"
#include "Framework/MiddleLayer/MiddleLayerInterface.h"
#include "Framework/MiddleLayer/EngineMiddleLayerContainerDetail.h"
#include "OfflineServer/OfflineServerMiddleLayer/Input/InputManagerDetail.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"

OfflineServer::OfflineServerMessage
	::OfflineServerMessage(int64_t delta)
    : ParentType{ delta }, m_Alloc{ CoreTools::DisableNotThrow::Disable }
{ 
	SELF_CLASS_IS_VALID_1;
}

OfflineServer::OfflineServerMessage
	::~OfflineServerMessage()
{
	SELF_CLASS_IS_VALID_1;
}
 
CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(OfflineServer, OfflineServerMessage)
 
 