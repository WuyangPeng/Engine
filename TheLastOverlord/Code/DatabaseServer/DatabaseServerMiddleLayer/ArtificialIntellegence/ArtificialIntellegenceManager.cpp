///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/29 21:23)

#include "DatabaseServer/DatabaseServerMiddleLayer/DatabaseServerMiddleLayerExport.h"

#include "ArtificialIntellegenceManager.h"
#include "DatabaseServer/DatabaseServerMiddleLayer/Macro/DatabaseServerMiddleLayerClassInvariantMacro.h"

DatabaseServerMiddleLayer::ArtificialIntellegenceManager::ArtificialIntellegenceManager(Framework::MiddleLayerPlatform middleLayerPlatform)
    : ParentType{ middleLayerPlatform }
{
    DATABASE_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(DatabaseServerMiddleLayer, ArtificialIntellegenceManager)