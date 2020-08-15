// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.0.0.3 (2019/07/26 17:32)

#include "Rendering/RenderingExport.h" 

#include "PlatformTexture1DImpl.h"
#include "Rendering/Renderers/Renderer.h"
#include "Rendering/Dx9Renderer/Dx9Texture1D.h"
#include "Rendering/OpenGLRenderer/OpenGLTexture1D.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/Renderers/Flags/RendererTypes.h"
using std::make_shared;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26429)
Rendering::PlatformTexture1DImpl
	::PlatformTexture1DImpl()	noexcept
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::PlatformTexture1DImpl
	::~PlatformTexture1DImpl()
{
	RENDERING_SELF_CLASS_IS_VALID_9;	
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, PlatformTexture1DImpl)

// static 
Rendering::PlatformTexture1DImpl::PlatformTexture1DPtr Rendering::PlatformTexture1DImpl
	::Create(Renderer* renderer, const Texture1D* texture1D)
{
    switch(renderer->GetRendererType())
    {
    case RendererTypes::Default:
        return CreateDefault(renderer, texture1D);
    case RendererTypes::Window:
        return make_shared<Dx9Texture1D>(renderer, texture1D);
    case RendererTypes::Glut:
        return make_shared<OpenGLTexture1D>(renderer, texture1D);
    case RendererTypes::OpenGL:
        return make_shared<OpenGLTexture1D>(renderer, texture1D);
    case RendererTypes::Dx9:
        return make_shared<Dx9Texture1D>(renderer, texture1D);
    case RendererTypes::OpenGLES:
        return  make_shared<OpenGLTexture1D>(renderer, texture1D);
    default:
        return CreateDefault(renderer, texture1D);
    }
}

// static 
Rendering::PlatformTexture1DImpl::PlatformTexture1DPtr Rendering::PlatformTexture1DImpl
	:: CreateDefault(Renderer* renderer, const Texture1D* texture1D)
{
    return make_shared<OpenGLTexture1D>(renderer, texture1D);
}
#include STSTEM_WARNING_POP