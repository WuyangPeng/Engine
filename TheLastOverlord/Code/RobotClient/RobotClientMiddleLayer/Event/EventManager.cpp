// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.0 (2019/10/10 10:19)

#include "RobotClient/RobotClientMiddleLayer/RobotClientMiddleLayerExport.h"

#include "EventManager.h" 
#include "RobotClient/RobotClientMiddleLayer/Macro/RobotClientMiddleLayerClassInvariantMacro.h"

RobotClientMiddleLayer::EventManager
	::EventManager(Framework::MiddleLayerPlatform middleLayerPlatform)
	:ParentType{ middleLayerPlatform }
{
	ROBOT_CLIENT_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

RobotClientMiddleLayer::EventManager
	::~EventManager()
{
	ROBOT_CLIENT_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(RobotClientMiddleLayer, EventManager)

 


