///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 13:19)

#ifndef RENDERING_OPENGL_RENDERER_OPENGL_BUFFER_H
#define RENDERING_OPENGL_RENDERER_OPENGL_BUFFER_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/OpenGLFwd.h"
#include "Rendering/OpenGLRenderer/Resources/OpenGLResource.h"
#include "Rendering/Resources/Buffers/Buffer.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE OpenGLBuffer : public OpenGLResource
    {
    public:
        using ClassType = OpenGLBuffer;
        using ParentType = OpenGLResource;
        using BufferUsage = System::BufferUsage;
        using BindBuffer = System::BindBuffer;

    public:
        OpenGLBuffer(const BufferSharedPtr& buffer, const std::string& name, BindBuffer type);
        ~OpenGLBuffer() noexcept;
        OpenGLBuffer(const OpenGLBuffer& rhs) = default;
        OpenGLBuffer& operator=(const OpenGLBuffer& rhs) = default;
        OpenGLBuffer(OpenGLBuffer&& rhs) noexcept = default;
        OpenGLBuffer& operator=(OpenGLBuffer&& rhs) noexcept = default;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD ConstBufferSharedPtr GetBuffer() const;

        NODISCARD BindBuffer GetType() const noexcept;
        NODISCARD BufferUsage GetUsage() const noexcept;

        NODISCARD bool Update() override;
        NODISCARD bool CopyCpuToGpu() override;
        NODISCARD bool CopyGpuToCpu() override;

    protected:
        virtual void Initialize();

    private:
        BindBuffer type;
        BufferUsage usage;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_OPENGL_BUFFER_H
