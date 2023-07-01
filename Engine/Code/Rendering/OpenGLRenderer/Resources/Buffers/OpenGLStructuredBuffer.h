///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:19)

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

        void Enable() noexcept override;

    protected:
        void Initialize() override;

    public:
        [[nodiscard]] bool CopyGpuToCpu(int level) override;
        [[nodiscard]] bool CopyGpuToCpu(int item, int level) override;
        [[nodiscard]] bool CopyCpuToGpu(int level) override;
        [[nodiscard]] bool CopyCpuToGpu(int item, int level) override;

    private:
        OpenGLInt counterOffset;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_OPENGL_STRUCTURED_BUFFER_H