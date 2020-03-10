// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.0.0.3 (2019/07/26 17:36)

#include "Rendering/RenderingExport.h" 

#include "PlatformTextureCubeImpl.h"
#include "Rendering/Renderers/Renderer.h"
#include "Rendering/Dx9Renderer/Dx9TextureCube.h"
#include "Rendering/OpenGLRenderer/OpenGLTextureCube.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::make_shared;

Rendering::PlatformTextureCubeImpl
	::PlatformTextureCubeImpl()	
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::PlatformTextureCubeImpl
	::~PlatformTextureCubeImpl()
{
	RENDERING_SELF_CLASS_IS_VALID_9;	
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, PlatformTextureCubeImpl)

// static 
Rendering::PlatformTextureCubeImpl::PlatformTextureCubePtr Rendering::PlatformTextureCubeImpl
	::Create(Renderer* renderer, const TextureCube* textureCube)
{
    switch(renderer->GetRendererType())
    {
    case RendererTypes::Default:
        return CreateDefault(renderer, textureCube);
    case RendererTypes::Window:
        return make_shared<Dx9TextureCube>(renderer, textureCube);
    case RendererTypes::Glut:
        return make_shared<OpenGLTextureCube>(renderer, textureCube);
    case RendererTypes::OpenGL:
        return make_shared<OpenGLTextureCube>(renderer, textureCube);
    case RendererTypes::Dx9:
        return make_shared<Dx9TextureCube>(renderer, textureCube);
    case RendererTypes::OpenGLES:
        return make_shared<OpenGLTextureCube>(renderer, textureCube);
    default:
        return CreateDefault(renderer, textureCube);
    }
}

// static 
Rendering::PlatformTextureCubeImpl::PlatformTextureCubePtr Rendering::PlatformTextureCubeImpl
	:: CreateDefault(Renderer* renderer, const TextureCube* textureCube)
{
    return make_shared <OpenGLTextureCube>(renderer, textureCube);
}