///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/20 11:19)

#ifndef RENDERING_RENDERERS_GLUT_RENDERER_INPUT_H
#define RENDERING_RENDERERS_GLUT_RENDERER_INPUT_H

#include "Rendering/RenderingDll.h"

#include "RendererInputImpl.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE GlutRendererInput : public RendererInputImpl
    {
    public:
        using ClassType = GlutRendererInput;
        using ParentType = RendererInputImpl;

    public:
        GlutRendererInput() noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD RendererTypes GetRendererType() const noexcept override;
        void SetWindowID(int aWindowID) noexcept override;
        void SetWindowHandle(HWnd aWindowID) noexcept override;

    private:
        int windowID;
        bool disableVerticalSync;
    };
}

#endif  // RENDERING_RENDERERS_GLUT_RENDERER_INPUT_H
