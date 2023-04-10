///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	千年史策版本：0.9.0.5 (2023/04/03 09:57)

#include "DatabaseGenerateServer/DatabaseGenerateServerMiddleLayer/DatabaseGenerateServerMiddleLayerExport.h"

#include "CameraSystemsManager.h"
#include "DatabaseGenerateServer/DatabaseGenerateServerMiddleLayer/Helper/DatabaseGenerateServerMiddleLayerClassInvariantMacro.h"

DatabaseGenerateServerMiddleLayer::CameraSystemsManager::CameraSystemsManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ middleLayerPlatform, environmentDirectory }
{
    DATABASE_GENERATE_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseGenerateServerMiddleLayer, CameraSystemsManager)
