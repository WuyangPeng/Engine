///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 13:18)

#ifndef RENDERING_OPENGL_RENDERER_OPENGL_BLEND_STATE_H
#define RENDERING_OPENGL_RENDERER_OPENGL_BLEND_STATE_H

#include "Rendering/RenderingDll.h"

#include "OpenGLDrawingState.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/State/BlendState.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(OpenGLBlendState, OpenGLBlendStateImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE OpenGLBlendState : public OpenGLDrawingState
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(OpenGLBlendState);
        using ParentType = OpenGLDrawingState;

    public:
        OpenGLBlendState(const BlendStateSharedPtr& blendState, const std::string& name);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void Enable() override;

    private:
        void EnableAlphaToCoverage() noexcept;
        void EnableIndependentBlend();
        void SetGLBlendColor() noexcept;

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

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_OPENGL_BLEND_STATE_TARGET_IMPL_H
