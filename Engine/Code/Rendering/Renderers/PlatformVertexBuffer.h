///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/21 18:59)

#ifndef RENDERING_RENDERERS_PLATFORM_VERTEX_BUFFER_H
#define RENDERING_RENDERERS_PLATFORM_VERTEX_BUFFER_H

#include "Rendering/RenderingDll.h"

#include "RenderersFwd.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/Resources/Flags/BufferFlags.h"
#include "Rendering/Resources/ResourcesFwd.h"

RENDERING_NON_COPY_EXPORT_IMPL(PlatformVertexBufferImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE PlatformVertexBuffer
    {
    public:
        NON_COPY_TYPE_DECLARE(PlatformVertexBuffer);
        using BufferType = VertexBuffer;

    public:
        PlatformVertexBuffer(Renderer* renderer, const VertexBuffer* vertexBuffer);

        CLASS_INVARIANT_DECLARE;

        // ���㻺����������
        void Enable(Renderer* renderer, unsigned int vertexSize, unsigned int streamIndex, unsigned int offset);
        void Disable(Renderer* renderer, unsigned int streamIndex);
        NODISCARD void* Lock(BufferLocking mode);
        void Unlock();

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_RENDERERS_PLATFORM_VERTEX_BUFFER_H
