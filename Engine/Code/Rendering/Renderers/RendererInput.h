// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/26 15:37)

#ifndef RENDERING_RENDERERS_RENDERER_INPUT_H
#define RENDERING_RENDERERS_RENDERER_INPUT_H

#include "Rendering/RenderingDll.h"

#include "Flags/RendererTypes.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "System/Window/Flags/WindowFlags.h"
#include "System/Window/Using/WindowUsing.h"

#include <boost/noncopyable.hpp>
 
RENDERING_EXPORT_SHARED_PTR(RendererInputImpl);
EXPORT_NONCOPYABLE_CLASS(RENDERING);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE RendererInput : private boost::noncopyable
    {
    public:
		NON_COPY_CLASSES_TYPE_DECLARE(RendererInput);
		using HWnd = System::WindowHWnd;
        
    public:
        explicit RendererInput(RendererTypes type);
        
        CLASS_INVARIANT_DECLARE;

		void SetWindowID(int windowID);
		void SetWindowHandle(HWnd windowID);

	private:	
		IMPL_TYPE_DECLARE(RendererInput);
    };
}

#endif // RENDERING_RENDERERS_RENDERER_INPUT_H
