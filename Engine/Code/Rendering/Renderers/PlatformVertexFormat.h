///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:37)

#ifndef RENDERING_RENDERERS_PLATFORM_VERTEX_FORMAT_H
#define RENDERING_RENDERERS_PLATFORM_VERTEX_FORMAT_H

#include "Rendering/RenderingDll.h"

#include "RenderersFwd.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/Resources/Flags/BufferFlags.h"
#include "Rendering/Resources/ResourcesFwd.h"

RENDERING_NON_COPY_EXPORT_IMPL(PlatformVertexFormatImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE PlatformVertexFormat
    {
    public:
        NON_COPY_TYPE_DECLARE(PlatformVertexFormat);

    public:
        PlatformVertexFormat(Renderer* renderer, const VertexFormat* vertexFormat);

        CLASS_INVARIANT_DECLARE;

        // 顶点格式操作。
        void Enable(Renderer* renderer);
        void Disable(Renderer* renderer);

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_RENDERERS_PLATFORM_VERTEX_FORMAT_H
