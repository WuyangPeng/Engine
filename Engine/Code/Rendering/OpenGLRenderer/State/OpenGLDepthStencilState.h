///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:18)

#ifndef RENDERING_OPENGL_RENDERER_OPENGL_DEPTH_STENCIL_STATE_H
#define RENDERING_OPENGL_RENDERER_OPENGL_DEPTH_STENCIL_STATE_H

#include "Rendering/RenderingDll.h"

#include "OpenGLDrawingState.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/State/DepthStencilState.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(OpenGLDepthStencilState, OpenGLDepthStencilStateImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE OpenGLDepthStencilState : public OpenGLDrawingState
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(OpenGLDepthStencilState);
        using ParentType = OpenGLDrawingState;

    public:
        OpenGLDepthStencilState(const DepthStencilStateSharedPtr& depthStencilState, const std::string& name);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void Enable() noexcept override;

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_OPENGL_DEPTH_STENCIL_STATE_H
