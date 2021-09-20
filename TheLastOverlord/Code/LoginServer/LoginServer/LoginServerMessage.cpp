// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.1 (2019/10/11 14:00)

#include "LoginServerMessage.h"
#include "CoreTools/Helper/ClassInvariantMacro.h" 

#include "Framework/MiddleLayer/InputManagerDetail.h"
#include "Framework/WindowProcess/WindowMessageDetail.h" 
#include "Framework/MiddleLayer/ObjectLogicManagerDetail.h"
#include "Framework/MiddleLayer/MiddleLayerInterface.h"
#include "Framework/MiddleLayer/EngineMiddleLayerContainerDetail.h"
#include "LoginServer/LoginServerMiddleLayer/Input/InputManagerDetail.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"

LoginServer::LoginServerMessage
	::LoginServerMessage(int64_t delta)
    : ParentType{ delta }, m_Alloc{ CoreTools::DisableNotThrow::Disable }
{ 
	SELF_CLASS_IS_VALID_1;
}

LoginServer::LoginServerMessage
	::~LoginServerMessage()
{
	SELF_CLASS_IS_VALID_1;
}
 
CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(LoginServer, LoginServerMessage)
 
 