// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.0 (2019/10/10 14:39)

#include "RobotClient/RobotClientMiddleLayer/RobotClientMiddleLayerExport.h"

#include "ResourceManager.h" 
#include "RobotClient/RobotClientMiddleLayer/Macro/RobotClientMiddleLayerClassInvariantMacro.h"

RobotClientMiddleLayer::ResourceManager
	::ResourceManager(Framework::MiddleLayerPlatform middleLayerPlatform)
	:ParentType{ middleLayerPlatform }
{
	ROBOT_CLIENT_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

RobotClientMiddleLayer::ResourceManager
	::~ResourceManager()
{
	ROBOT_CLIENT_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(RobotClientMiddleLayer, ResourceManager)

 


