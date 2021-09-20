// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.0 (2019/10/10 16:29)

#include "MessageClient/MessageClientMiddleLayer/MessageClientMiddleLayerExport.h"

#include "AudioManager.h" 
#include "MessageClient/MessageClientMiddleLayer/Macro/MessageClientMiddleLayerClassInvariantMacro.h"

MessageClientMiddleLayer::AudioManager
	::AudioManager(Framework::MiddleLayerPlatform middleLayerPlatform)
	:ParentType{ middleLayerPlatform }
{
	MESSAGE_CLIENT_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

MessageClientMiddleLayer::AudioManager
	::~AudioManager()
{
	MESSAGE_CLIENT_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(MessageClientMiddleLayer, AudioManager)

 


