///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/22 22:19)

#ifndef RENDERING_OPENGL_RENDERER_OPENGL_SHADER_H
#define RENDERING_OPENGL_RENDERER_OPENGL_SHADER_H

#include "Rendering/RenderingDll.h"

#include "OpenGLRendererData.h"
#include "Rendering/Renderers/RenderersFwd.h"
#include "Rendering/Shaders/ShaderBase.h"
#include "Rendering/Shaders/ShaderParameters.h"

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
        void SetSamplerState(Renderer* renderer,
                             const ShaderBase* shader,
                             int profile,
                             const ShaderParameters* parameters,
                             int maxSamplers,
                             RendererData::SamplerState* currentSS) noexcept;

        void DisableTextures(Renderer* renderer, const ShaderBase* shader, int profile, const ShaderParameters* parameters, int maxSamplers) noexcept;
    };

}

#endif  // RENDERING_OPENGL_RENDERER_OPENGL_SHADER_H
