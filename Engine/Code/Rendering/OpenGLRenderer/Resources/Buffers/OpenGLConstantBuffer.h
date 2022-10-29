///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.3 (2022/10/20 21:54)

#ifndef RENDERING_OPENGL_RENDERER_OPENGL_CONSTANT_BUFFER_H
#define RENDERING_OPENGL_RENDERER_OPENGL_CONSTANT_BUFFER_H

#include "Rendering/RenderingDll.h"

#include "OpenGLBuffer.h"
#include "Rendering/Resources/Buffers/ConstantBuffer.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE OpenGLConstantBuffer : public OpenGLBuffer
    {
    public:
        using ClassType = OpenGLConstantBuffer;
        using ParentType = OpenGLBuffer;
        using OpenGLInt = System::OpenGLInt;

    public:
        OpenGLConstantBuffer(const ConstantBufferSharedPtr& buffer, const std::string& name);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void AttachToUnit(OpenGLInt uniformBufferUnit) noexcept;

        NODISCARD ConstConstantBufferSharedPtr GetConstantBuffer() const;

        void Enable() noexcept override;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_OPENGL_CONSTANT_BUFFER_H
