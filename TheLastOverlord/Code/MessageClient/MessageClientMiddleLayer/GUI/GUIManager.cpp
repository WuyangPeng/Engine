// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.0 (2019/10/10 16:47)

#include "MessageClient/MessageClientMiddleLayer/MessageClientMiddleLayerExport.h"

#include "GUIManager.h" 
#include "MessageClient/MessageClientMiddleLayer/Macro/MessageClientMiddleLayerClassInvariantMacro.h"

MessageClientMiddleLayer::GUIManager
	::GUIManager(Framework::MiddleLayerPlatform middleLayerPlatform)
	:ParentType{ middleLayerPlatform }
{
	MESSAGE_CLIENT_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

MessageClientMiddleLayer::GUIManager
	::~GUIManager()
{
	MESSAGE_CLIENT_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(MessageClientMiddleLayer, GUIManager)

 


