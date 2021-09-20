// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.1 (2019/10/12 14:08)

#include "OfflineServer/OfflineServerMiddleLayer/OfflineServerMiddleLayerExport.h"

#include "SystemManager.h" 
#include "OfflineServer/OfflineServerMiddleLayer/Macro/OfflineServerMiddleLayerClassInvariantMacro.h"

OfflineServerMiddleLayer::SystemManager
	::SystemManager(Framework::MiddleLayerPlatform middleLayerPlatform)
	:ParentType{ middleLayerPlatform }
{
	OFFLINE_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

OfflineServerMiddleLayer::SystemManager
	::~SystemManager()
{
	OFFLINE_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(OfflineServerMiddleLayer, SystemManager)

 


