///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/21 15:35)

#ifndef RENDERING_RENDERERS_WINDOW_RENDERER_INPUT_H
#define RENDERING_RENDERERS_WINDOW_RENDERER_INPUT_H

#include "Rendering/RenderingDll.h"

#include "RendererInputImpl.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE WindowRendererInput : public RendererInputImpl
    {
    public:
        using ClassType = WindowRendererInput;
        using ParentType = RendererInputImpl;

    public:
        WindowRendererInput() noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD RendererTypes GetRendererType() const noexcept override;
        void SetWindowID(int windowID) noexcept override;
        void SetWindowHandle(HWnd windowID) noexcept override;

    private:
        HWnd windowHandle;
    };
}

#endif  // RENDERING_RENDERERS_WINDOW_RENDERER_INPUT_H
