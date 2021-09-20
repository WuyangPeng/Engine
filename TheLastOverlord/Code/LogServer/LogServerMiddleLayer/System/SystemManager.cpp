// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���İ����汾��0.0.0.1 (2019/10/12 23:02)

#include "LogServer/LogServerMiddleLayer/LogServerMiddleLayerExport.h"

#include "SystemManager.h" 
#include "LogServer/LogServerMiddleLayer/Macro/LogServerMiddleLayerClassInvariantMacro.h"

LogServerMiddleLayer::SystemManager
	::SystemManager(Framework::MiddleLayerPlatform middleLayerPlatform)
	:ParentType{ middleLayerPlatform }
{
	LOG_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

LogServerMiddleLayer::SystemManager
	::~SystemManager()
{
	LOG_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(LogServerMiddleLayer, SystemManager)

 


