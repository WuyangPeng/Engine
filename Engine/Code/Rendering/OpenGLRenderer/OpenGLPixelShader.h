///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:18)

#ifndef RENDERING_OPENGL_RENDERER_OPENGL_PIXEL_SHADER_H
#define RENDERING_OPENGL_RENDERER_OPENGL_PIXEL_SHADER_H

#include "Rendering/RenderingDll.h"

#include "OpenGLShader.h"
#include "Rendering/RendererEngine/RendererEngineFwd.h"

namespace Rendering
{
    class PdrPixelShader : public OpenGLShader
    {
    public:
        using ClassType = PdrPixelShader;
        using ParentType = OpenGLShader;

    public:
        PdrPixelShader(BaseRenderer* renderer) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void Enable(BaseRenderer* renderer) noexcept;
        void Disable(BaseRenderer* renderer) noexcept;

    private:
        GLuint shader = 0;
    };

}

#endif  // RENDERING_OPENGL_RENDERER_OPENGL_PIXEL_SHADER_H
