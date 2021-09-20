// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.1 (2019/10/11 14:04)

#include "LoginServer/LoginServerMiddleLayer/LoginServerMiddleLayerExport.h"

#include "EventManager.h" 
#include "LoginServer/LoginServerMiddleLayer/Macro/LoginServerMiddleLayerClassInvariantMacro.h"

LoginServerMiddleLayer::EventManager
	::EventManager(Framework::MiddleLayerPlatform middleLayerPlatform)
	:ParentType{ middleLayerPlatform }
{
	LOGIN_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

LoginServerMiddleLayer::EventManager
	::~EventManager()
{
	LOGIN_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(LoginServerMiddleLayer, EventManager)

 


