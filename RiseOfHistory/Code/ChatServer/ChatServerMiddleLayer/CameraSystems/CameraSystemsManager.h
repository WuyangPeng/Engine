/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/17 19:45)

#ifndef CHAT_SERVER_MIDDLE_LAYER_CAMERA_SYSTEMS_MIDDLE_LAYER_CAMERA_SYSTEMS_H
#define CHAT_SERVER_MIDDLE_LAYER_CAMERA_SYSTEMS_MIDDLE_LAYER_CAMERA_SYSTEMS_H

#include "ChatServer/ChatServerMiddleLayer/ChatServerMiddleLayerDll.h"

#include "ChatServer/ChatServerMiddleLayer/Helper/ExportMacro.h"
#include "Framework/MiddleLayer/CameraSystemsManagerInterface.h"

namespace ChatServerMiddleLayer
{
    class CHAT_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE CameraSystemsManager final : public Framework::CameraSystemsManagerInterface
    {
    public:
        using ClassType = CameraSystemsManager;
        using ParentType = CameraSystemsManagerInterface;

    public:
        CameraSystemsManager(MiddleLayerPlatform middleLayerPlatform, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // CHAT_SERVER_MIDDLE_LAYER_CAMERA_SYSTEMS_MIDDLE_LAYER_CAMERA_SYSTEMS_H
