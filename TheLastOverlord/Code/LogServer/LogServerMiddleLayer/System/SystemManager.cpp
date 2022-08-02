///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/28 21:33)

#include "LogServer/LogServerMiddleLayer/LogServerMiddleLayerExport.h"

#include "LogServer/LogServerMiddleLayer/Macro/LogServerMiddleLayerClassInvariantMacro.h"
#include "SystemManager.h"

LogServerMiddleLayer::SystemManager::SystemManager(Framework::MiddleLayerPlatform middleLayerPlatform)
    : ParentType{ middleLayerPlatform }
{
    LOG_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(LogServerMiddleLayer, SystemManager)
