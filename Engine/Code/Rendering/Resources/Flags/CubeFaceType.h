/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/29 13:53)

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
