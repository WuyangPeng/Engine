/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2024/01/09 19:07)

#ifndef RENDERING_LOCAL_EFFECTS_LIGHT_FLAGS_H
#define RENDERING_LOCAL_EFFECTS_LIGHT_FLAGS_H

#include "Rendering/RenderingDll.h"

namespace Rendering
{
    enum class LightType
    {
        Ambient,
        Directional,
        Point,
        Spot,
        Quantity
    };
}

#endif  // RENDERING_LOCAL_EFFECTS_LIGHT_FLAGS_H
