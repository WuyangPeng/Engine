///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.0 (2023/06/19 15:20)

#ifndef GAME_CLIENT_MIDDLE_LAYER_CAMERA_SYSTEMS_CAMERA_SYSTEMS_MANAGER_H
#define GAME_CLIENT_MIDDLE_LAYER_CAMERA_SYSTEMS_CAMERA_SYSTEMS_MANAGER_H

#include "GameClient/GameClientMiddleLayer/GameClientMiddleLayerDll.h"

#include "GameClient/GameClientMiddleLayer/Helper/ExportMacro.h"
#include "Framework/MiddleLayer/CameraSystemsManagerInterface.h"

namespace GameClientMiddleLayer
{
    class GAME_CLIENT_MIDDLE_LAYER_DEFAULT_DECLARE CameraSystemsManager final : public Framework::CameraSystemsManagerInterface
    {
    public:
        using ClassType = CameraSystemsManager;
        using ParentType = CameraSystemsManagerInterface;

        using MiddleLayerPlatform = Framework::MiddleLayerPlatform;
        using EnvironmentDirectory = Framework::EnvironmentDirectory;

    public:
        CameraSystemsManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // GAME_CLIENT_MIDDLE_LAYER_CAMERA_SYSTEMS_CAMERA_SYSTEMS_MANAGER_H
