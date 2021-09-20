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
#include "System/Windows/Flags/WindowsFlags.h"
#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include <boost/noncopyable.hpp>
 
RENDERING_NON_COPY_EXPORT_IMPL(RendererInputImpl);


namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE RendererInput  
    {
    public:
        NON_COPY_TYPE_DECLARE(RendererInput);
		using HWnd = System::WindowsHWnd;
        
    public:
        explicit RendererInput(RendererTypes type);
        ~RendererInput() noexcept = default;
        RendererInput(const RendererInput& rhs) noexcept = delete;
        RendererInput& operator=(const RendererInput& rhs) noexcept = delete;
        RendererInput(RendererInput&& rhs) noexcept = delete;
        RendererInput& operator=(RendererInput&& rhs) noexcept = delete;
        CLASS_INVARIANT_DECLARE;

		void SetWindowID(int windowID);
		void SetWindowHandle(HWnd windowID);

	private:	
		 PackageType impl;
    };
}

#endif // RENDERING_RENDERERS_RENDERER_INPUT_H
