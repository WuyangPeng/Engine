/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2024/01/06 16:10)

#ifndef RENDERING_OPENGL_RENDERER_OPENGL_SAMPLER_STATE_H
#define RENDERING_OPENGL_RENDERER_OPENGL_SAMPLER_STATE_H

#include "OpenGLDrawingState.h"
#include "Rendering/RenderingDll.h"

#include "System/OpenGL/OpenGLFwd.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/OpenGLRenderer/OpenGLRendererObject.h"
#include "Rendering/State/SamplerState.h"
#include "Rendering/State/StateFwd.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE OpenGLSamplerState : public OpenGLDrawingState
    {
    public:
        using ClassType = OpenGLSamplerState;
        using ParentType = OpenGLDrawingState;

        using TextureSamplerCoordinate = System::TextureSamplerCoordinate;

    public:
        OpenGLSamplerState(const SamplerStateSharedPtr& samplerState, const std::string& name);
        ~OpenGLSamplerState() noexcept;
        OpenGLSamplerState(const OpenGLSamplerState& rhs) = default;
        OpenGLSamplerState& operator=(const OpenGLSamplerState& rhs) = default;
        OpenGLSamplerState(OpenGLSamplerState&& rhs) noexcept = default;
        OpenGLSamplerState& operator=(OpenGLSamplerState&& rhs) noexcept = default;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD static TextureSamplerCoordinate GetSamplerStateMode(SamplerStateMode samplerStateMode);

    private:
        void Init(const SamplerState& samplerState);
    };
}

#endif  // RENDERING_OPENGL_RENDERER_OPENGL_SAMPLER_STATE_H
