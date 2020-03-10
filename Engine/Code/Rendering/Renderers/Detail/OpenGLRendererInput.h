// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/26 14:12)

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
        OpenGLRendererInput();
        virtual ~ OpenGLRendererInput();
        
        CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

        virtual RendererTypes GetRendererType() const override;    
		virtual	void SetWindowID(int windowID) override;
		virtual	void SetWindowHandle(HWnd windowID) override;

    private:
    	HWnd m_WindowHandle; 
    	HDC m_RendererDC;
    	int m_PixelFormat;
    	bool m_DisableVerticalSync; 
    };
}

#endif // RENDERING_RENDERERS_OPENGL_RENDERER_INPUT_H
