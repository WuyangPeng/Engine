// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/26 14:04)

#ifndef RENDERING_RENDERERS_DX9_RENDERER_H
#define RENDERING_RENDERERS_DX9_RENDERER_H

#include "Rendering/RenderingDll.h"

#include "RendererImpl.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE Dx9Renderer : public RendererImpl
    {
    public:
        using ClassType = Dx9Renderer;
        using ParentType = RendererImpl;
       
    public:
		explicit Dx9Renderer(const RendererBasis& basis);
        
        CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		virtual RendererTypes GetRendererType() const override;
    };
}

#endif // RENDERING_RENDERERS_DX9_RENDERER_H
