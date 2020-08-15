// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/26 14:10)

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

        CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

        RendererTypes GetRendererType() const noexcept override;
        void SetWindowID(int windowID) noexcept override;
        void SetWindowHandle(HWnd windowID) noexcept override;

    private:
        int m_WindowID;
        bool m_DisableVerticalSync;
    };
}

#endif  // RENDERING_RENDERERS_GLUT_RENDERER_INPUT_H
