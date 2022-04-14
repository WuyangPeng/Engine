///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.5 (2022/04/01 11:01)

#ifndef RENDERING_SCENE_GRAPH_LIGHT_FLAGS_H
#define RENDERING_SCENE_GRAPH_LIGHT_FLAGS_H

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

#endif  // RENDERING_SCENE_GRAPH_LIGHT_FLAGS_H
