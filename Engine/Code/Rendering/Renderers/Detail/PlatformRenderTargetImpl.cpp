// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.0.0.3 (2019/07/26 17:30)

#include "Rendering/RenderingExport.h" 

#include "PlatformRenderTargetImpl.h"
#include "Rendering/Renderers/Renderer.h"
#include "Rendering/Dx9Renderer/Dx9RenderTarget.h"
#include "Rendering/OpenGLRenderer/OpenGLRenderTarget.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/Renderers/Flags/RendererTypes.h"

using std::make_shared;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26429)
Rendering::PlatformRenderTargetImpl
	::PlatformRenderTargetImpl() noexcept
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::PlatformRenderTargetImpl
	::~PlatformRenderTargetImpl()
{
	RENDERING_SELF_CLASS_IS_VALID_9;	
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, PlatformRenderTargetImpl)

// static 
Rendering::PlatformRenderTargetImpl::PlatformRenderTargetPtr Rendering::PlatformRenderTargetImpl
	::Create(Renderer* renderer, const RenderTarget* renderTarget)
{
    switch(renderer->GetRendererType())
    {
    case RendererTypes::Default:
        return CreateDefault(renderer, renderTarget);
    case RendererTypes::Window:
        return make_shared<Dx9RenderTarget>(renderer, renderTarget);
    case RendererTypes::Glut:
        return make_shared < OpenGLRenderTarget>(renderer, renderTarget);
    case RendererTypes::OpenGL:
        return make_shared < OpenGLRenderTarget>(renderer, renderTarget);
    case RendererTypes::Dx9:
        return make_shared < Dx9RenderTarget>(renderer, renderTarget);
    case RendererTypes::OpenGLES:
        return make_shared < OpenGLRenderTarget>(renderer, renderTarget);
    default:
        return CreateDefault(renderer, renderTarget);
    }
}

// static 
Rendering::PlatformRenderTargetImpl::PlatformRenderTargetPtr Rendering::PlatformRenderTargetImpl
	:: CreateDefault(Renderer* renderer,const RenderTarget* renderTarget)
{
    return make_shared < OpenGLRenderTarget>(renderer, renderTarget);
}
#include STSTEM_WARNING_POP