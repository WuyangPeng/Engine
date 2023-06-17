///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:36)

#ifndef RENDERING_RENDERERS_PLATFORM_INDEX_BUFFER_H
#define RENDERING_RENDERERS_PLATFORM_INDEX_BUFFER_H

#include "Rendering/RenderingDll.h"

#include "RenderersFwd.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/Resources/Flags/BufferFlags.h"
#include "Rendering/Resources/ResourcesFwd.h"

RENDERING_NON_COPY_EXPORT_IMPL(PlatformIndexBufferImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE PlatformIndexBuffer
    {
    public:
        NON_COPY_TYPE_DECLARE(PlatformIndexBuffer);
        using BufferType = IndexBuffer;

    public:
        PlatformIndexBuffer(Renderer* renderer, const IndexBuffer* indexBuffer);

        CLASS_INVARIANT_DECLARE;

        // 缓冲区操作
        void Enable(Renderer* renderer);
        void Disable(Renderer* renderer);
        NODISCARD void* Lock(BufferLocking mode);
        void Unlock();

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_RENDERERS_PLATFORM_INDEX_BUFFER_H
