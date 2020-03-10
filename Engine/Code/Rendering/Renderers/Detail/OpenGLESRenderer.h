// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/26 14:10)

#ifndef RENDERING_RENDERERS_OPENGL_ES_RENDERER_H
#define RENDERING_RENDERERS_OPENGL_ES_RENDERER_H

#include "Rendering/RenderingDll.h"

#include "RendererImpl.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE OpenGLESRenderer : public RendererImpl
    {
    public:
        using ClassType = OpenGLESRenderer;
        using ParentType = RendererImpl;
       
    public:
        explicit OpenGLESRenderer(const RendererBasis& basis);
        
        CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		virtual RendererTypes GetRendererType() const override;
    };
}

#endif // RENDERING_RENDERERS_OPENGL_ES_RENDERER_H
