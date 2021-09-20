// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 最后的霸王版本：0.0.0.1 (2019/10/13 18:58)

#include "UpdateServer/UpdateServerMiddleLayer/UpdateServerMiddleLayerExport.h"

#include "AudioManager.h" 
#include "UpdateServer/UpdateServerMiddleLayer/Macro/UpdateServerMiddleLayerClassInvariantMacro.h"

UpdateServerMiddleLayer::AudioManager
 ::AudioManager(Framework::MiddleLayerPlatform middleLayerPlatform)
	:ParentType{ middleLayerPlatform }
{
	UPDATE_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

UpdateServerMiddleLayer::AudioManager
	::~AudioManager()
{
	UPDATE_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(UpdateServerMiddleLayer, AudioManager)

 


