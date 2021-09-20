// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.1 (2019/10/11 14:07)

#include "LoginServer/LoginServerMiddleLayer/LoginServerMiddleLayerExport.h"

#include "RenderingManager.h" 
#include "LoginServer/LoginServerMiddleLayer/Macro/LoginServerMiddleLayerClassInvariantMacro.h"

LoginServerMiddleLayer::RenderingManager
	::RenderingManager(Framework::MiddleLayerPlatform middleLayerPlatform)
	:ParentType{ middleLayerPlatform }
{
	LOGIN_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

LoginServerMiddleLayer::RenderingManager
	::~RenderingManager()
{
	LOGIN_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(LoginServerMiddleLayer, RenderingManager)

 


