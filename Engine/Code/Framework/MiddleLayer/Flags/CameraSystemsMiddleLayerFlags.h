///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.7 (2022/05/06 16:09)

#ifndef FRAMEWORK_CAMERA_SYSTEMS_MANAGER_INTERFACE_FLAGS_H
#define FRAMEWORK_CAMERA_SYSTEMS_MANAGER_INTERFACE_FLAGS_H

#include "System/Helper/ConfigMacro.h"

namespace Framework
{
    enum class CameraSystemsMiddleLayer
    {
        System,
        Rendering,
        GUI,

        Count,
    };
}

#endif  // FRAMEWORK_CAMERA_SYSTEMS_MANAGER_INTERFACE_FLAGS_H