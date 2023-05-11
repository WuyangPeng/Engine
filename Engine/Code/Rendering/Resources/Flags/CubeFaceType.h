///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.0 (2022/08/16 11:25)

#ifndef RENDERING_RESOURCES_CUBE_FACE_TYPE_H
#define RENDERING_RESOURCES_CUBE_FACE_TYPE_H

#include "Rendering/RenderingDll.h"

namespace Rendering
{
    enum class CubeFaceType
    {
        PositiveX = 0,
        NegativeX = 1,
        PositiveY = 2,
        NegativeY = 3,
        PositiveZ = 4,
        NegativeZ = 5,
        Count = 6
    };
}

#endif  // RENDERING_RESOURCES_CUBE_FACE_TYPE_H