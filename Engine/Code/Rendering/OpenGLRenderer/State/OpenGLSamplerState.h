///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:18)

#ifndef RENDERING_OPENGL_RENDERER_OPENGL_SAMPLER_STATE_H
#define RENDERING_OPENGL_RENDERER_OPENGL_SAMPLER_STATE_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/OpenGLFwd.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/Base/RendererObject.h"
#include "Rendering/OpenGLRenderer/OpenGLRendererObject.h"
#include "Rendering/State/SamplerState.h"
#include "Rendering/State/StateFwd.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE OpenGLSamplerState : public OpenGLRendererObject
    {
    public:
        using ClassType = OpenGLSamplerState;
        using ParentType = OpenGLRendererObject;

    public:
        OpenGLSamplerState(const SamplerStateSharedPtr& samplerState, const std::string& name);
        ~OpenGLSamplerState() noexcept;
        OpenGLSamplerState(const OpenGLSamplerState& rhs) = default;
        OpenGLSamplerState& operator=(const OpenGLSamplerState& rhs) = default;
        OpenGLSamplerState(OpenGLSamplerState&& rhs) noexcept = default;
        OpenGLSamplerState& operator=(OpenGLSamplerState&& rhs) noexcept = default;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void Enable() noexcept override;
        NODISCARD bool Update() noexcept override;

        NODISCARD static System::TextureSamplerCoordinate GetSamplerStateMode(SamplerStateMode samplerStateMode);

    private:
        void Init(const SamplerState& samplerState);

    public:
        [[nodiscard]] bool Update(int level) override;
        [[nodiscard]] bool Update(int item, int level) override;
        [[nodiscard]] bool CopyGpuToCpu() override;
        [[nodiscard]] bool CopyGpuToCpu(int level) override;
        [[nodiscard]] bool CopyGpuToCpu(int item, int level) override;
        [[nodiscard]] bool CopyCpuToGpu() override;
        [[nodiscard]] bool CopyCpuToGpu(int level) override;
        [[nodiscard]] bool CopyCpuToGpu(int item, int level) override;
        [[nodiscard]] bool GetNumActiveElements() override;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_OPENGL_SAMPLER_STATE_H
