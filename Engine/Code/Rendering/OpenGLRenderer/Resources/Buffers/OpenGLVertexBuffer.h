///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 13:19)

#ifndef RENDERING_OPENGL_RENDERER_OPENGL_VERTEX_BUFFER_H
#define RENDERING_OPENGL_RENDERER_OPENGL_VERTEX_BUFFER_H

#include "Rendering/RenderingDll.h"

#include "OpenGLBuffer.h"
#include "Rendering/Resources/Buffers/VertexBuffer.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE OpenGLVertexBuffer : public OpenGLBuffer
    {
    public:
        using ClassType = OpenGLVertexBuffer;
        using ParentType = OpenGLBuffer;
        using OpenGLInt = System::OpenGLInt;

    public:
        OpenGLVertexBuffer(const VertexBufferSharedPtr& buffer, const std::string& name);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD ConstVertexBufferSharedPtr GetVertexBuffer() const;

        void Enable() noexcept override;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_OPENGL_VERTEX_BUFFER_H
