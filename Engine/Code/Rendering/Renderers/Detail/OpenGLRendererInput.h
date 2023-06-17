///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:34)

#ifndef RENDERING_RENDERERS_OPENGL_RENDERER_INPUT_H
#define RENDERING_RENDERERS_OPENGL_RENDERER_INPUT_H

#include "Rendering/RenderingDll.h"

#include "RendererInputImpl.h"

#include <windef.h>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE OpenGLRendererInput : public RendererInputImpl
    {
    public:
        using ClassType = OpenGLRendererInput;
        using ParentType = RendererInputImpl;

    public:
        OpenGLRendererInput() noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD RendererTypes GetRendererType() const noexcept override;
        void SetWindowID(int windowID) noexcept override;
        void SetWindowHandle(HWnd windowID) noexcept override;

    private:
        HWnd windowHandle;
        HDC rendererDC;
        int pixelFormat;
        bool disableVerticalSync;
    };
}

#endif  // RENDERING_RENDERERS_OPENGL_RENDERER_INPUT_H
