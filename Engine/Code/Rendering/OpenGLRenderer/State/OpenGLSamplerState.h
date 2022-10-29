///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.3 (2022/10/15 23:41)

#ifndef RENDERING_OPENGL_RENDERER_OPENGL_SAMPLER_STATE_H
#define RENDERING_OPENGL_RENDERER_OPENGL_SAMPLER_STATE_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/OpenGLFwd.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/Base/RendererObject.h"
#include "Rendering/State/SamplerState.h"
#include "Rendering/State/StateFwd.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE OpenGLSamplerState : public RendererObject
    {
    public:
        using ClassType = OpenGLSamplerState;
        using ParentType = RendererObject;

    public:
        OpenGLSamplerState(const SamplerStateSharedPtr& samplerState, const std::string& name);
        ~OpenGLSamplerState() noexcept;
        OpenGLSamplerState(const OpenGLSamplerState& rhs) = default;
        OpenGLSamplerState& operator=(const OpenGLSamplerState& rhs) = default;
        OpenGLSamplerState(OpenGLSamplerState&& rhs) noexcept = default;
        OpenGLSamplerState& operator=(OpenGLSamplerState&& rhs) noexcept = default;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void Enable() noexcept override;

        NODISCARD static System::TextureSamplerCoordinate GetSamplerStateMode(SamplerStateMode samplerStateMode);

    private:
        void Init(const SamplerState& samplerState);
    };
}

#endif  // RENDERING_OPENGL_RENDERER_OPENGL_SAMPLER_STATE_H
