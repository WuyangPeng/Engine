// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/26 17:28)

#include "Rendering/RenderingExport.h" 

#include "PlatformIndexBufferImpl.h"
#include "Rendering/Renderers/Renderer.h"
#include "Rendering/Dx9Renderer/Dx9IndexBuffer.h"
#include "Rendering/OpenGLRenderer/OpenGLIndexBuffer.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::make_shared;

Rendering::PlatformIndexBufferImpl
	::PlatformIndexBufferImpl()	
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::PlatformIndexBufferImpl
	::~PlatformIndexBufferImpl()
{
	RENDERING_SELF_CLASS_IS_VALID_9;	
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, PlatformIndexBufferImpl)

// static 
Rendering::PlatformIndexBufferImpl:: PlatformIndexBufferPtr Rendering::PlatformIndexBufferImpl
	::Create(Renderer* renderer, const IndexBuffer* indexBuffer)
{
    switch(renderer->GetRendererType())
    {
    case RendererTypes::Default:
        return CreateDefault(renderer, indexBuffer);
    case RendererTypes::Window:
        return make_shared<Dx9IndexBuffer>(renderer, indexBuffer);
    case RendererTypes::Glut:
        return make_shared<OpenGLIndexBuffer>(renderer, indexBuffer);
    case RendererTypes::OpenGL:
        return make_shared<OpenGLIndexBuffer>(renderer, indexBuffer);
    case RendererTypes::Dx9:
        return make_shared<Dx9IndexBuffer>(renderer, indexBuffer);
    case RendererTypes::OpenGLES:
        return make_shared<OpenGLIndexBuffer>(renderer, indexBuffer);
    default:
        return CreateDefault(renderer, indexBuffer);
    }
}

// static 
Rendering::PlatformIndexBufferImpl:: PlatformIndexBufferPtr Rendering::PlatformIndexBufferImpl
	:: CreateDefault(Renderer* renderer, const IndexBuffer* indexBuffer)
{
    return make_shared <OpenGLIndexBuffer>(renderer, indexBuffer);
}