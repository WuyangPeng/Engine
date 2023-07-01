///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:17)

#ifndef RENDERING_OPENGL_RENDERER_OPENGL_SHADER_H
#define RENDERING_OPENGL_RENDERER_OPENGL_SHADER_H

#include "Rendering/RenderingDll.h"

#include "OpenGLRendererData.h"
#include "Rendering/RendererEngine/RendererEngineFwd.h"

namespace Rendering
{
    class OpenGLShader
    {
    public:
        using ClassType = OpenGLShader;

    public:
        OpenGLShader() noexcept = default;
        virtual ~OpenGLShader() noexcept = default;
        OpenGLShader(const OpenGLShader& rhs) noexcept = default;
        OpenGLShader& operator=(const OpenGLShader& rhs) noexcept = default;
        OpenGLShader(OpenGLShader&& rhs) noexcept = default;
        OpenGLShader& operator=(OpenGLShader&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

    protected:
        void SetSamplerState(BaseRenderer* renderer,
                             int profile,
                             int maxSamplers,
                             RendererData::SamplerState* currentSS) noexcept;

        void DisableTextures(BaseRenderer* renderer, int profile, int maxSamplers) noexcept;
    };

}

#endif  // RENDERING_OPENGL_RENDERER_OPENGL_SHADER_H
