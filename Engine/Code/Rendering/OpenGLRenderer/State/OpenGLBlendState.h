///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.3 (2022/10/11 22:46)

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

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_OPENGL_BLEND_STATE_TARGET_IMPL_H
