// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.0 (2019/10/10 17:56)

#include "BackgroundClient/BackgroundClientMiddleLayer/BackgroundClientMiddleLayerExport.h"

#include "AudioManager.h" 
#include "BackgroundClient/BackgroundClientMiddleLayer/Macro/BackgroundClientMiddleLayerClassInvariantMacro.h"

BackgroundClientMiddleLayer::AudioManager
	::AudioManager(Framework::MiddleLayerPlatform middleLayerPlatform)
	:ParentType{ middleLayerPlatform }
{
	BACKGROUND_CLIENT_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

BackgroundClientMiddleLayer::AudioManager
	::~AudioManager()
{
	BACKGROUND_CLIENT_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BackgroundClientMiddleLayer, AudioManager)

 


