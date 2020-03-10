// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/26 15:09)

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
        WindowRendererInput();
        virtual ~ WindowRendererInput();
        
        CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

        virtual RendererTypes GetRendererType() const override;    
		virtual	void SetWindowID(int windowID) override;
		virtual	void SetWindowHandle(HWnd windowID) override;

    private:
    	HWnd m_WindowHandle; 
    };
}

#endif // RENDERING_RENDERERS_WINDOW_RENDERER_INPUT_H
