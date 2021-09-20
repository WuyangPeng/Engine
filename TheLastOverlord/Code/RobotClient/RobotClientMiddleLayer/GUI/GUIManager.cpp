// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.0 (2019/10/10 14:21)

#include "RobotClient/RobotClientMiddleLayer/RobotClientMiddleLayerExport.h"

#include "GUIManager.h" 
#include "RobotClient/RobotClientMiddleLayer/Macro/RobotClientMiddleLayerClassInvariantMacro.h"

RobotClientMiddleLayer::GUIManager
	::GUIManager(Framework::MiddleLayerPlatform middleLayerPlatform)
	:ParentType{ middleLayerPlatform }
{
	ROBOT_CLIENT_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

RobotClientMiddleLayer::GUIManager
	::~GUIManager()
{
	ROBOT_CLIENT_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(RobotClientMiddleLayer, GUIManager)

 


