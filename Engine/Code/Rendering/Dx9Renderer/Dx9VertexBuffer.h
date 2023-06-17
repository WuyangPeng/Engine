///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 13:49)

#ifndef RENDERING_RENDERERS_DX9_VERTEX_BUFFER_H
#define RENDERING_RENDERERS_DX9_VERTEX_BUFFER_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Using/OpenGLUsing.h"
#include "Rendering/Renderers/Detail/PlatformVertexBufferImpl.h"
#include "Rendering/Renderers/RenderersFwd.h"
#include "Rendering/Resources/ResourcesFwd.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE Dx9VertexBuffer : public PlatformVertexBufferImpl
    {
    public:
        using ClassType = Dx9VertexBuffer;
        using ParentType = PlatformVertexBufferImpl;
        using UInt = System::OpenGLUInt;

    public:
        Dx9VertexBuffer(Renderer* renderer, const VertexBuffer* vertexBuffer) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        // ���㻺����������
        void Enable(Renderer* renderer, int vertexSize, int streamIndex, int offset) noexcept override;
        void Disable(Renderer* renderer, int streamIndex) noexcept override;
        NODISCARD void* Lock(BufferLocking mode) noexcept override;
        void Unlock() noexcept override;
    };
}

#endif  // RENDERING_RENDERERS_DX9_VERTEX_BUFFER_H
