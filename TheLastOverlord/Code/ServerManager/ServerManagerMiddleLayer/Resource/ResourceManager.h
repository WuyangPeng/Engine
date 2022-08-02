///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	最后的霸王版本：0.8.0.12 (2022/07/28 23:12)

#ifndef SERVER_MANAGER_MIDDLE_LAYER_RESOURCE_MIDDLE_LAYER_RESOURCE_H
#define SERVER_MANAGER_MIDDLE_LAYER_RESOURCE_MIDDLE_LAYER_RESOURCE_H

#include "ServerManager/ServerManagerMiddleLayer/ServerManagerMiddleLayerDll.h"

#include "ServerManager/ServerManagerMiddleLayer/Macro/ExportMacro.h"
#include "Framework/MiddleLayer/ResourceManagerInterface.h"

namespace ServerManagerMiddleLayer
{
    class SERVER_MANAGER_MIDDLE_LAYER_DEFAULT_DECLARE ResourceManager : public Framework::ResourceManagerInterface
    {
    public:
        using ClassType = ResourceManager;
        using ParentType = Framework::ResourceManagerInterface;

    public:
        explicit ResourceManager(Framework::MiddleLayerPlatform middleLayerPlatform);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // SERVER_MANAGER_MIDDLE_LAYER_RESOURCE_MIDDLE_LAYER_RESOURCE_H
