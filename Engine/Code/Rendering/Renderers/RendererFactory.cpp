// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/29 10:27)

#include "Rendering/RenderingExport.h"

#include "Renderer.h"
#include "RendererBasis.h"
#include "RendererFactory.h"
#include "RendererParameter.h"

#include "Detail/WindowRenderer.h"
#include "Detail/GlutRenderer.h"
#include "Detail/OpenGLRenderer.h"
#include "Detail/Dx9Renderer.h"
#include "Detail/OpenGLESRenderer.h"
#include "Detail/WindowRendererInput.h"
#include "Detail/GlutRendererInput.h"
#include "Detail/OpenGLRendererInput.h"
#include "Detail/Dx9RendererInput.h"
#include "Detail/OpenGLESRendererInput.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::make_shared;

Rendering::RendererFactory::RendererPtr Rendering::RendererFactory
      ::Create(const std::string& fileName)
{
	RendererParameter rendererParameter{ fileName };
	auto ptr =  Create(rendererParameter.GetRendererType(),rendererParameter.GetRendererBasis());
	ptr->SetClearColor(rendererParameter.GetClearColor());

	return ptr;
}

Rendering::RendererFactory::RendererPtr Rendering::RendererFactory
      ::Create(RendererTypes type,const RendererBasis& basis)
{
    switch(type)
    {
    case RendererTypes::Default:
        return CreateDefault(basis);
	case RendererTypes::Window:
        return make_shared<WindowRenderer>(basis);
    case RendererTypes::Glut:
        return make_shared<GlutRenderer>(basis);  
    case RendererTypes::OpenGL:
        return make_shared<OpenGLRenderer>(basis); 
    case RendererTypes::Dx9:
        return make_shared<Dx9Renderer>(basis); 
    case RendererTypes::OpenGLES:
        return make_shared<OpenGLESRenderer>(basis); 
    default:
        return CreateDefault(basis);
	}
}

Rendering::RendererFactory::RendererPtr Rendering::RendererFactory
      ::CreateDefault(const RendererBasis& basis)
{
    return make_shared<OpenGLRenderer>(basis); 
}

Rendering::RendererFactory::RendererInputPtr Rendering::RendererFactory
      ::CreateInput(RendererTypes type)
{
    switch(type)
    {
    case RendererTypes::Default:
        return CreateDefaultInput();
    case RendererTypes::Window:
        return make_shared<WindowRendererInput>();
    case RendererTypes::Glut:
        return make_shared<GlutRendererInput>();
    case RendererTypes::OpenGL:
        return make_shared<OpenGLRendererInput>();
    case RendererTypes::Dx9:
        return make_shared<Dx9RendererInput>();
    case RendererTypes::OpenGLES:
        return make_shared<OpenGLESRendererInput>();
    default:
        return CreateDefaultInput();
	}
}

Rendering::RendererFactory::RendererInputPtr Rendering::RendererFactory
      ::CreateDefaultInput()
{
    return make_shared<OpenGLRendererInput>();
}
