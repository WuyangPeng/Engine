// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.0.0.3 (2019/07/26 17:33)

#include "Rendering/RenderingExport.h" 

#include "PlatformTexture2DImpl.h"
#include "Rendering/Renderers/Renderer.h"
#include "Rendering/Dx9Renderer/Dx9Texture2D.h"
#include "Rendering/OpenGLRenderer/OpenGLTexture2D.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::make_shared;

Rendering::PlatformTexture2DImpl
	::PlatformTexture2DImpl()	
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::PlatformTexture2DImpl
	::~PlatformTexture2DImpl()
{
	RENDERING_SELF_CLASS_IS_VALID_9;	
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, PlatformTexture2DImpl)

// static 
Rendering::PlatformTexture2DImpl::PlatformTexture2DPtr Rendering::PlatformTexture2DImpl
	::Create(Renderer* renderer, const Texture2D* texture2D)
{
    switch(renderer->GetRendererType())
    {
    case RendererTypes::Default:
        return CreateDefault(renderer, texture2D);
    case RendererTypes::Window:
        return make_shared<Dx9Texture2D>(renderer, texture2D);
    case RendererTypes::Glut:
        return make_shared<OpenGLTexture2D>(renderer, texture2D);
    case RendererTypes::OpenGL:
        return make_shared<OpenGLTexture2D>(renderer, texture2D);
    case RendererTypes::Dx9:
        return make_shared<Dx9Texture2D>(renderer, texture2D);
    case RendererTypes::OpenGLES:
        return make_shared<OpenGLTexture2D>(renderer, texture2D);
    default:
        return CreateDefault(renderer, texture2D);
    }
}

// static 
Rendering::PlatformTexture2DImpl::PlatformTexture2DPtr Rendering::PlatformTexture2DImpl
	:: CreateDefault(Renderer* renderer, const Texture2D* texture2D)
{
    return make_shared <OpenGLTexture2D>(renderer, texture2D);
}