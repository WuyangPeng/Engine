///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/05 16:10)

#ifndef FRAMEWORK_AUDIO_MANAGER_INTERFACE_FLAGS_H
#define FRAMEWORK_AUDIO_MANAGER_INTERFACE_FLAGS_H

#include "System/Helper/ConfigMacro.h"

namespace Framework
{
    enum class AudioMiddleLayer
    {
        System,
        Resource,

        Count,
    };
}

#endif  // FRAMEWORK_AUDIO_MANAGER_INTERFACE_FLAGS_H