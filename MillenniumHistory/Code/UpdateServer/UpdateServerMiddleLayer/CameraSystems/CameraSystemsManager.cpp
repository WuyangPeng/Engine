/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.1 (2023/11/25 20:42)

#include "UpdateServer/UpdateServerMiddleLayer/UpdateServerMiddleLayerExport.h"

#include "UpdateServer/UpdateServerMiddleLayer/Helper/UpdateServerMiddleLayerClassInvariantMacro.h"
#include "CameraSystemsManager.h"

UpdateServerMiddleLayer::CameraSystemsManager::CameraSystemsManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory }
{
    UPDATE_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(UpdateServerMiddleLayer, CameraSystemsManager)
