///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/23 14:38)

#ifndef RENDERING_RENDERERS_OPENGL_VERTEX_BUFFER_H
#define RENDERING_RENDERERS_OPENGL_VERTEX_BUFFER_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/OpenGLAPI.h"
#include "Rendering/Renderers/Detail/PlatformVertexBufferImpl.h"
#include "Rendering/Renderers/RenderersFwd.h"
#include "Rendering/Resources/ResourcesFwd.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE OpenGLVertexBuffer : public PlatformVertexBufferImpl
    {
    public:
        using ClassType = OpenGLVertexBuffer;
        using ParentType = PlatformVertexBufferImpl;
        using UInt = System::OpenGLUInt;

    public:
        OpenGLVertexBuffer(Renderer* renderer, const VertexBuffer* vertexBuffer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        // 顶点缓冲区操作。
        void Enable(Renderer* renderer, int vertexSize, int streamIndex, int offset) noexcept override;
        void Disable(Renderer* renderer, int streamIndex) noexcept override;
        NODISCARD void* Lock(BufferLocking mode) noexcept override;
        void Unlock() noexcept override;

    private:
        void Init(const VertexBuffer* vertexBuffer);

    private:
        UInt buffer;
    };
}

#endif  // RENDERING_RENDERERS_OPENGL_VERTEX_BUFFER_H
