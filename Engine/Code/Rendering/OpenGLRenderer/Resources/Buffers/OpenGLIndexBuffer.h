/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2024/01/08 14:53)

#ifndef RENDERING_OPENGL_RENDERER_OPENGL_VERTEX_BUFFER_H
#define RENDERING_OPENGL_RENDERER_OPENGL_VERTEX_BUFFER_H

#include "Rendering/RenderingDll.h"

#include "OpenGLBuffer.h"
#include "Rendering/Resources/Buffers/IndexBuffer.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE OpenGLIndexBuffer : public OpenGLBuffer
    {
    public:
        using ClassType = OpenGLIndexBuffer;
        using ParentType = OpenGLBuffer;
        using OpenGLInt = System::OpenGLInt;

    public:
        OpenGLIndexBuffer(const IndexBufferSharedPtr& buffer, const std::string& name);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD ConstIndexBufferSharedPtr GetIndexBuffer() const;

        void Enable() noexcept override;
        void Disable() noexcept override;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_OPENGL_VERTEX_BUFFER_H
