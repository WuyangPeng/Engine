///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/21 19:13)

#include "Rendering/RenderingExport.h"

#include "Renderer.h"
#include "RendererBasis.h"
#include "RendererFactory.h"
#include "RendererParameter.h"
#include "RenderingEnvironment.h"
#include "Detail/Dx9Renderer.h"
#include "Detail/Dx9RendererInput.h"
#include "Detail/GlutRenderer.h"
#include "Detail/GlutRendererInput.h"
#include "Detail/OpenGLESRenderer.h"
#include "Detail/OpenGLESRendererInput.h"
#include "Detail/OpenGLRenderer.h"
#include "Detail/OpenGLRendererInput.h"
#include "Detail/WindowRenderer.h"
#include "Detail/WindowRendererInput.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::make_shared;

Rendering::RendererFactory::RendererSharedPtr Rendering::RendererFactory::Create(const EnvironmentParameter& environmentParameter, const std::string& fileName)
{
    RendererParameter rendererParameter{ fileName };
    const RenderingEnvironment renderingEnvironment{ environmentParameter, rendererParameter };
    auto ptr = Create(environmentParameter, rendererParameter.GetRendererType(), rendererParameter, renderingEnvironment);
    ptr->SetClearColor(rendererParameter.GetClearColor());

    return ptr;
}

Rendering::RendererFactory::RendererSharedPtr Rendering::RendererFactory::Create(const EnvironmentParameter& environmentParameter, RendererTypes type, const RendererParameter& basis, const RenderingEnvironment& renderingEnvironment)
{
    switch (type)
    {
        case RendererTypes::Default:
            return CreateDefault(basis, renderingEnvironment);
        case RendererTypes::Windows:
            return make_shared<WindowRenderer>(environmentParameter, basis);
        case RendererTypes::Glut:
            return make_shared<GlutRenderer>(environmentParameter, basis);
        case RendererTypes::OpenGL:
            return make_shared<OpenGLRenderer>(renderingEnvironment, basis.GetRendererBasis());
        case RendererTypes::Dx11:
            return make_shared<Dx9Renderer>(environmentParameter, basis);
        case RendererTypes::OpenGLES:
            return make_shared<OpenGLESRenderer>(environmentParameter, basis);
        default:
            return CreateDefault(basis, renderingEnvironment);
    }
}

Rendering::RendererFactory::RendererSharedPtr Rendering::RendererFactory::CreateDefault(const RendererParameter& basis, const RenderingEnvironment& renderingEnvironment)
{
    return make_shared<OpenGLRenderer>(renderingEnvironment, basis.GetRendererBasis());
}

Rendering::RendererFactory::RendererInputSharedPtr Rendering::RendererFactory::CreateInput(RendererTypes type)
{
    switch (type)
    {
        case RendererTypes::Default:
            return CreateDefaultInput();
        case RendererTypes::Windows:
            return make_shared<WindowRendererInput>();
        case RendererTypes::Glut:
            return make_shared<GlutRendererInput>();
        case RendererTypes::OpenGL:
            return make_shared<OpenGLRendererInput>();
        case RendererTypes::Dx11:
            return make_shared<Dx9RendererInput>();
        case RendererTypes::OpenGLES:
            return make_shared<OpenGLESRendererInput>();
        default:
            return CreateDefaultInput();
    }
}

Rendering::RendererFactory::RendererInputSharedPtr Rendering::RendererFactory::CreateDefaultInput()
{
    return make_shared<OpenGLRendererInput>();
}
