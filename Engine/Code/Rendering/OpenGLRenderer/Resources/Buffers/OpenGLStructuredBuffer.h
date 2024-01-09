/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/08 14:53)

#ifndef RENDERING_OPENGL_RENDERER_OPENGL_STRUCTURED_BUFFER_H
#define RENDERING_OPENGL_RENDERER_OPENGL_STRUCTURED_BUFFER_H

#include "Rendering/RenderingDll.h"

#include "OpenGLBuffer.h"
#include "Rendering/Resources/Buffers/StructuredBuffer.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE OpenGLStructuredBuffer : public OpenGLBuffer
    {
    public:
        using ClassType = OpenGLStructuredBuffer;
        using ParentType = OpenGLBuffer;
        using OpenGLInt = System::OpenGLInt;

    public:
        OpenGLStructuredBuffer(const StructuredBufferSharedPtr& buffer, const std::string& name);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD ConstStructuredBufferSharedPtr GetStructuredBuffer() const;

        void AttachToUnit(OpenGLInt shaderStorageBufferUnit);

        NODISCARD bool CopyCounterValueToBuffer(const OpenGLBuffer* targetBuffer, OpenGLInt offset);
        NODISCARD bool CopyCounterValueFromBuffer(const OpenGLBuffer* sourceBuffer, OpenGLInt offset);

        NODISCARD bool GetNumActiveElements() override;
        NODISCARD bool SetNumActiveElements();

        NODISCARD bool CopyGpuToCpu() override;

    protected:
        void Initialize() override;

    private:
        OpenGLInt counterOffset;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_OPENGL_STRUCTURED_BUFFER_H