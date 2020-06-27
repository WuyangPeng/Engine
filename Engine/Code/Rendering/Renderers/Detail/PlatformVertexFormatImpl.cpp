// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/26 17:42)

#include "Rendering/RenderingExport.h" 

#include "PlatformVertexFormatImpl.h"
#include "Rendering/Renderers/Renderer.h"
#include "Rendering/Dx9Renderer/Dx9VertexFormat.h"
#include "Rendering/OpenGLRenderer/OpenGLVertexFormat.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/Renderers/Flags/RendererTypes.h"
using std::make_shared;

Rendering::PlatformVertexFormatImpl
	::PlatformVertexFormatImpl()	
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::PlatformVertexFormatImpl
	::~PlatformVertexFormatImpl()
{
	RENDERING_SELF_CLASS_IS_VALID_9;	
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, PlatformVertexFormatImpl)

// static 
Rendering::PlatformVertexFormatImpl::PlatformVertexFormatPtr Rendering::PlatformVertexFormatImpl
	::Create(Renderer* renderer, const VertexFormat* vertexFormat)
{
    switch(renderer->GetRendererType())
    {
    case RendererTypes::Default:
        return CreateDefault(renderer, vertexFormat);
    case RendererTypes::Window:
        return make_shared <Dx9VertexFormat>(renderer, vertexFormat);
    case RendererTypes::Glut:
        return make_shared <OpenGLVertexFormat>(renderer, vertexFormat);
    case RendererTypes::OpenGL:
        return make_shared <OpenGLVertexFormat>(renderer, vertexFormat);
    case RendererTypes::Dx9:
        return make_shared <Dx9VertexFormat>(renderer, vertexFormat);
    case RendererTypes::OpenGLES:
        return make_shared <OpenGLVertexFormat>(renderer, vertexFormat);
    default:
        return CreateDefault(renderer, vertexFormat);
    }
}

// static 
Rendering::PlatformVertexFormatImpl::PlatformVertexFormatPtr Rendering::PlatformVertexFormatImpl
	:: CreateDefault(Renderer* renderer, const VertexFormat* vertexFormat)
{
    return make_shared <OpenGLVertexFormat>(renderer, vertexFormat);
}