///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/30 10:25)

#ifndef RENDERING_RESOURCES_BUFFER_FLAGS_H
#define RENDERING_RESOURCES_BUFFER_FLAGS_H

#include "Rendering/RenderingDll.h"

namespace Rendering
{
    // Usage标记使用在顶点缓冲区,索引缓冲区,和纹理。
    enum class BufferUsage
    {
        Static,
        Dynamic,
        RenderTarget,
        DepthStencil,
        Texture,
        Quantity
    };

    // 锁定模式使用在访问视频内存对于缓冲区或纹理。
    enum class BufferLocking
    {
        ReadOnly,
        WriteOnly,
        ReadWrite,
        Quantity
    };
}

#endif  // RENDERING_RESOURCES_BUFFER_FLAGS_H
