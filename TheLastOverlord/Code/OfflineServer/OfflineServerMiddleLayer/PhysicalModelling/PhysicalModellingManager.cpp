// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.1 (2019/10/12 14:07)

#include "OfflineServer/OfflineServerMiddleLayer/OfflineServerMiddleLayerExport.h"

#include "PhysicalModellingManager.h" 
#include "OfflineServer/OfflineServerMiddleLayer/Macro/OfflineServerMiddleLayerClassInvariantMacro.h"

OfflineServerMiddleLayer::PhysicalModellingManager
	::PhysicalModellingManager(Framework::MiddleLayerPlatform middleLayerPlatform)
	:ParentType{ middleLayerPlatform }
{
	OFFLINE_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

OfflineServerMiddleLayer::PhysicalModellingManager
	::~PhysicalModellingManager()
{
	OFFLINE_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(OfflineServerMiddleLayer, PhysicalModellingManager)

 

