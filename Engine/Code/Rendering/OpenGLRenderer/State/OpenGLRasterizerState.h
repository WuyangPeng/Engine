/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/06 16:09)

#ifndef RENDERING_OPENGL_RENDERER_OPENGL_RASTERIZER_STATE_H
#define RENDERING_OPENGL_RENDERER_OPENGL_RASTERIZER_STATE_H

#include "Rendering/RenderingDll.h"

#include "OpenGLDrawingState.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/State/RasterizerState.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(OpenGLRasterizerState, OpenGLRasterizerStateImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE OpenGLRasterizerState : public OpenGLDrawingState
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(OpenGLRasterizerState);
        using ParentType = OpenGLDrawingState;

    public:
        OpenGLRasterizerState(const RasterizerStateSharedPtr& rasterizerState, const std::string& name);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void Enable() noexcept(gAssert < 3 || gMathematicsAssert < 3) override;

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_OPENGL_DEPTH_STENCIL_STATE_H
