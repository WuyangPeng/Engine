///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/26 15:49)

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
        using OpenGLUInt = System::OpenGLUInt;

    public:
        OpenGLRendererObject(const GraphicsObjectSharedPtr& graphicsObject, const std::string& name);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD OpenGLUInt GetGLHandle() const noexcept override;
        void SetGLHandle(OpenGLUInt handler) noexcept;

    private:
        OpenGLUInt glHandle;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_OPENGL_DEVICE_H
