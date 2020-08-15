// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/26 15:02)

#ifndef RENDERING_RENDERERS_RENDERER_INPUT_IMPL_H
#define RENDERING_RENDERERS_RENDERER_INPUT_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Renderers/Flags/RendererTypes.h"
#include "System/Window/Using/WindowUsing.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE RendererInputImpl
    {
    public:
        using ClassType = RendererInputImpl;
		using HWnd = System::WindowHWnd;
        
    public:
        RendererInputImpl() noexcept;
        virtual ~RendererInputImpl();
		RendererInputImpl(const RendererInputImpl&) = default;
		RendererInputImpl& operator=(const RendererInputImpl&) = default;
		RendererInputImpl( RendererInputImpl&&) = default;
		RendererInputImpl& operator=( RendererInputImpl&&) = default;
        
        CLASS_INVARIANT_VIRTUAL_DECLARE;

        virtual RendererTypes GetRendererType() const = 0;
		virtual	void SetWindowID(int windowID) = 0; 
		virtual	void SetWindowHandle(HWnd windowID) = 0;    
    };
}

#endif // RENDERING_RENDERERS_RENDERER_INPUT_IMPL_H
