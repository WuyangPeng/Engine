/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/06 11:29)

#ifndef RENDERING_OPENGL_RENDERER_OPENGL_RENDERER_OBJECT_H
#define RENDERING_OPENGL_RENDERER_OPENGL_RENDERER_OBJECT_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Using/OpenGLUsing.h"
#include "Rendering/Base/RendererObject.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE OpenGLRendererObject : public RendererObject
    {
    public:
        using ClassType = OpenGLRendererObject;
        using ParentType = RendererObject;

        using OpenGLUInt = System::OpenGLUnsignedInt;

    public:
        OpenGLRendererObject(const GraphicsObjectSharedPtr& graphicsObject, const std::string& name);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD OpenGLUInt GetGLHandle() const noexcept override;
        void SetGLHandle(OpenGLUInt handler) noexcept;

        void Enable() override;
        void Disable() override;
        NODISCARD bool Update() override;
        NODISCARD bool Update(int level) override;
        NODISCARD bool Update(int item, int level) override;

        NODISCARD bool CopyGpuToCpu() override;
        NODISCARD bool CopyGpuToCpu(int level) override;
        NODISCARD bool CopyGpuToCpu(int item, int level) override;

        NODISCARD bool CopyCpuToGpu() override;
        NODISCARD bool CopyCpuToGpu(int level) override;
        NODISCARD bool CopyCpuToGpu(int item, int level) override;

        NODISCARD bool GetNumActiveElements() override;

    private:
        OpenGLUInt glHandle;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_OPENGL_DEVICE_H
