// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/26 14:06)

#ifndef RENDERING_RENDERERS_DX9_RENDERER_INPUT_H
#define RENDERING_RENDERERS_DX9_RENDERER_INPUT_H

#include "Rendering/RenderingDll.h"

#include "RendererInputImpl.h"

#include <d3d9.h>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE Dx9RendererInput : public RendererInputImpl
    {
    public:
        using ClassType = Dx9RendererInput;
        using ParentType = RendererInputImpl;
       
    public:
        Dx9RendererInput();
        virtual ~Dx9RendererInput();
        
        CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

        virtual RendererTypes GetRendererType() const override;
		
		virtual	void SetWindowID(int windowID) override;
		virtual	void SetWindowHandle(HWnd windowID) override;

    private:
    	HWnd m_WindowHandle;
		IDirect3D9* m_Driver;
    };
}

#endif // RENDERING_RENDERERS_DX9_RENDERER_INPUT_H
