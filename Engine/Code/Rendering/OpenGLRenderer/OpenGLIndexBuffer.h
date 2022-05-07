///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/22 18:10)

#ifndef RENDERING_RENDERERS_OPENGL_INDEX_BUFFER_H
#define RENDERING_RENDERERS_OPENGL_INDEX_BUFFER_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Using/OpenGLUsing.h"
#include "System/Windows/Using/WindowsUsing.h"
#include "Rendering/Renderers/Detail/PlatformIndexBufferImpl.h"
#include "Rendering/Renderers/RenderersFwd.h"
#include "Rendering/Resources/ResourcesFwd.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE OpenGLIndexBuffer : public PlatformIndexBufferImpl
    {
    public:
        using ClassType = OpenGLIndexBuffer;
        using ParentType = PlatformIndexBufferImpl;
        using UInt = System::OpenGLUInt;

    public:
        OpenGLIndexBuffer(Renderer* renderer, const IndexBuffer* indexBuffer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        // ����������
        void Enable(Renderer* renderer) noexcept override;
        void Disable(Renderer* renderer) noexcept override;
        NODISCARD void* Lock(BufferLocking mode) noexcept override;
        void Unlock() noexcept override;

    private:
        void Init(const IndexBuffer* indexBuffer);

    private:
        UInt buffer;
    };
}

#endif  // RENDERING_RENDERERS_OPENGL_INDEX_BUFFER_H
