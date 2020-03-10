// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/26 15:36)

#ifndef RENDERING_RENDERERS_RENDERER_FACTORY_H
#define RENDERING_RENDERERS_RENDERER_FACTORY_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "Flags/RendererTypes.h"

#include <string>

namespace Rendering
{
    class RendererImpl;
	class RendererBasis;
	class RendererInputImpl;

    class RENDERING_DEFAULT_DECLARE RendererFactory  
    {
    public: 
        using RendererPtr = std::shared_ptr<RendererImpl>;
        using RendererInputPtr = std::shared_ptr<RendererInputImpl>;
        
    public:
         static RendererPtr Create(RendererTypes type,const RendererBasis& basis);
		 static RendererPtr Create(const std::string& fileName);
         static RendererInputPtr CreateInput(RendererTypes type);

    private:
         static RendererPtr CreateDefault(const RendererBasis& basis);
         static RendererInputPtr CreateDefaultInput();
    };
}

#endif // RENDERING_RENDERERS_RENDERER_FACTORY_H
