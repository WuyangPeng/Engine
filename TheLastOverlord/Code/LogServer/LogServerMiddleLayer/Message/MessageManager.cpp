// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 最后的霸王版本：0.0.0.1 (2019/10/12 23:00)

#include "LogServer/LogServerMiddleLayer/LogServerMiddleLayerExport.h"

#include "MessageManager.h" 
#include "LogServer/LogServerMiddleLayer/Macro/LogServerMiddleLayerClassInvariantMacro.h"

LogServerMiddleLayer::MessageManager
	::MessageManager(Framework::MiddleLayerPlatform middleLayerPlatform)
	:ParentType{ middleLayerPlatform }
{
	LOG_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

LogServerMiddleLayer::MessageManager
	::~MessageManager()
{
	LOG_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(LogServerMiddleLayer, MessageManager)

 


