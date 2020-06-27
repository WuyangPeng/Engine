// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.0.0.3 (2019/07/26 17:37)

#include "Rendering/RenderingExport.h" 

#include "PlatformVertexBufferImpl.h"
#include "Rendering/Renderers/Renderer.h"
#include "Rendering/Dx9Renderer/Dx9VertexBuffer.h"
#include "Rendering/OpenGLRenderer/OpenGLVertexBuffer.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/Renderers/Flags/RendererTypes.h"
using std::make_shared;

Rendering::PlatformVertexBufferImpl
	::PlatformVertexBufferImpl()	
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::PlatformVertexBufferImpl
	::~PlatformVertexBufferImpl()
{
	RENDERING_SELF_CLASS_IS_VALID_9;	
}

CLASS_INVARIANT_STUB_DEFINE(Rendering,PlatformVertexBufferImpl)

// static 
Rendering::PlatformVertexBufferImpl::PlatformVertexBufferPtr Rendering::PlatformVertexBufferImpl
	::Create(Renderer* renderer, const VertexBuffer* vertexBuffer)
{
    switch(renderer->GetRendererType())
    {
    case RendererTypes::Default:
        return CreateDefault(renderer, vertexBuffer);
    case RendererTypes::Window:
        return make_shared <Dx9VertexBuffer>(renderer, vertexBuffer);
    case RendererTypes::Glut:
        return make_shared <OpenGLVertexBuffer>(renderer, vertexBuffer);
    case RendererTypes::OpenGL:
        return make_shared <OpenGLVertexBuffer>(renderer, vertexBuffer);
    case RendererTypes::Dx9:
        return make_shared <Dx9VertexBuffer>(renderer, vertexBuffer);
    case RendererTypes::OpenGLES:
        return make_shared <OpenGLVertexBuffer>(renderer, vertexBuffer);
    default:
        return CreateDefault(renderer, vertexBuffer);
    }
}

// static 
Rendering::PlatformVertexBufferImpl::PlatformVertexBufferPtr Rendering::PlatformVertexBufferImpl
	:: CreateDefault(Renderer* renderer, const VertexBuffer* vertexBuffer)
{
    return make_shared<OpenGLVertexBuffer>(renderer, vertexBuffer);
}