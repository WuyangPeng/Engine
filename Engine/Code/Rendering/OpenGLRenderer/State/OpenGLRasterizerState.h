///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.3 (2022/10/14 23:24)

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

        void Enable() noexcept(g_Assert < 3 || g_MathematicsAssert < 3) override;

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_OPENGL_DEPTH_STENCIL_STATE_H
