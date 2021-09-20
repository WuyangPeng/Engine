// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.0 (2019/10/10 17:58)

#include "BackgroundClient/BackgroundClientMiddleLayer/BackgroundClientMiddleLayerExport.h"

#include "NetworkManager.h" 
#include "BackgroundClient/BackgroundClientMiddleLayer/Macro/BackgroundClientMiddleLayerClassInvariantMacro.h"

BackgroundClientMiddleLayer::NetworkManager
	::NetworkManager(Framework::MiddleLayerPlatform middleLayerPlatform)
	:ParentType{ middleLayerPlatform }
{
	BACKGROUND_CLIENT_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

BackgroundClientMiddleLayer::NetworkManager
	::~NetworkManager()
{
	BACKGROUND_CLIENT_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BackgroundClientMiddleLayer, NetworkManager)

 


