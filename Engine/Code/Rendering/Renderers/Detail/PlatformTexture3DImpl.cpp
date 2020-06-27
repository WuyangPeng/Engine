// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.0.0.3 (2019/07/26 17:35)

#include "Rendering/RenderingExport.h" 

#include "PlatformTexture3DImpl.h"
#include "Rendering/Renderers/Renderer.h"
#include "Rendering/Dx9Renderer/Dx9Texture3D.h"
#include "Rendering/OpenGLRenderer/OpenGLTexture3D.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/Renderers/Flags/RendererTypes.h"
using std::make_shared;

Rendering::PlatformTexture3DImpl
	::PlatformTexture3DImpl()	
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::PlatformTexture3DImpl
	::~PlatformTexture3DImpl()
{
	RENDERING_SELF_CLASS_IS_VALID_9;	
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, PlatformTexture3DImpl)

// static 
Rendering::PlatformTexture3DImpl::PlatformTexture3DPtr Rendering::PlatformTexture3DImpl
	::Create(Renderer* renderer, const Texture3D* texture3D)
{
    switch(renderer->GetRendererType())
    {
    case RendererTypes::Default:
        return CreateDefault(renderer, texture3D);
    case RendererTypes::Window:
        return make_shared <Dx9Texture3D>(renderer, texture3D);
    case RendererTypes::Glut:
        return make_shared <OpenGLTexture3D>(renderer, texture3D);
    case RendererTypes::OpenGL:
        return make_shared <OpenGLTexture3D>(renderer, texture3D);
    case RendererTypes::Dx9:
        return make_shared <Dx9Texture3D>(renderer, texture3D);
    case RendererTypes::OpenGLES:
        return make_shared <OpenGLTexture3D>(renderer, texture3D);
    default:
        return CreateDefault(renderer, texture3D);
    }
}

// static 
Rendering::PlatformTexture3DImpl::PlatformTexture3DPtr Rendering::PlatformTexture3DImpl
	:: CreateDefault(Renderer* renderer, const Texture3D* texture3D)
{
    return make_shared <OpenGLTexture3D>(renderer, texture3D);
}