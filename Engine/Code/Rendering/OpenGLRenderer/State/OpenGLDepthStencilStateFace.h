///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.3 (2022/10/13 18:39)

#ifndef RENDERING_OPENGL_RENDERER_OPENGL_DEPTH_STENCIL_STATE_FACE_H
#define RENDERING_OPENGL_RENDERER_OPENGL_DEPTH_STENCIL_STATE_FACE_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE OpenGLDepthStencilStateFace
    {
    public:
        using ClassType = OpenGLDepthStencilStateFace;
        using DepthStencilStateMode = System::DepthStencilStateMode;
        using DepthStencilStateOperation = System::DepthStencilStateOperation;

    public:
        OpenGLDepthStencilStateFace() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD DepthStencilStateOperation GetOnFail() const noexcept;
        void SetOnFail(DepthStencilStateOperation aOnFail) noexcept;

        NODISCARD DepthStencilStateOperation GetOnZFail() const noexcept;
        void SetOnZFail(DepthStencilStateOperation aOnZFail) noexcept;

        NODISCARD DepthStencilStateOperation GetOnZPass() const noexcept;
        void SetOnZPass(DepthStencilStateOperation aOnZPass) noexcept;

        NODISCARD DepthStencilStateMode GetComparison() const noexcept;
        void SetComparison(DepthStencilStateMode aComparison) noexcept;

    private:
        DepthStencilStateOperation onFail;
        DepthStencilStateOperation onZFail;
        DepthStencilStateOperation onZPass;
        DepthStencilStateMode comparison;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_OPENGL_DEPTH_STENCIL_STATE_FACE_H
