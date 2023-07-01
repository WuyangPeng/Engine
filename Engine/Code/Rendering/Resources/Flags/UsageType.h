///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.0 (2023/06/29 11:28)

#ifndef RENDERING_RESOURCES_USAGE_TYPE_H
#define RENDERING_RESOURCES_USAGE_TYPE_H

#include "Rendering/RenderingDll.h"

namespace Rendering
{
    enum class UsageType
    {
        Immutable,
        DynamicUpdate,
        ShaderOutput
    };
}

#endif  // RENDERING_RESOURCES_USAGE_TYPE_H
