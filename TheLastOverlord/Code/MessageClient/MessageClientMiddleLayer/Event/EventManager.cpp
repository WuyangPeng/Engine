// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.0 (2019/10/10 16:47)

#include "MessageClient/MessageClientMiddleLayer/MessageClientMiddleLayerExport.h"

#include "EventManager.h" 
#include "MessageClient/MessageClientMiddleLayer/Macro/MessageClientMiddleLayerClassInvariantMacro.h"

MessageClientMiddleLayer::EventManager
	::EventManager(Framework::MiddleLayerPlatform middleLayerPlatform)
	:ParentType{ middleLayerPlatform }
{
	MESSAGE_CLIENT_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

MessageClientMiddleLayer::EventManager
	::~EventManager()
{
	MESSAGE_CLIENT_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(MessageClientMiddleLayer, EventManager)

 


