/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.0 (2023/11/19 00:20)

#include "LogServer/LogServerMiddleLayer/LogServerMiddleLayerExport.h"

#include "LogServer/LogServerMiddleLayer/Helper/LogServerMiddleLayerClassInvariantMacro.h"
#include "ObjectLogicManager.h"

LogServerMiddleLayer::ObjectLogicManager::ObjectLogicManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory }
{
    LOG_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(LogServerMiddleLayer, ObjectLogicManager)