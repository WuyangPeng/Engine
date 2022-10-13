///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.1 (2022/08/19 18:18)

#include "Rendering/RenderingExport.h"

#include "ShaderFactory.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "Rendering/OpenGLRenderer/Detail/GLSLShader.h"
#include "Rendering/Renderers/Flags/RendererTypes.h"

using std::make_shared;

Rendering::ShaderFactory::ShaderSharedPtr Rendering::ShaderFactory::Create(RendererTypes type)
{
    switch (type)
    {
        case RendererTypes::Glut:
            return make_shared<GLSLShader>();
        case RendererTypes::OpenGL:
            return make_shared<GLSLShader>();
        case RendererTypes::OpenGLES:
            return make_shared<GLSLShader>();

        case RendererTypes::Dx11:
        case RendererTypes::Default:
        case RendererTypes::Windows:
        default:
        {
            THROW_EXCEPTION(SYSTEM_TEXT("未定义的着色器类型。"s));
        }
    }
}
