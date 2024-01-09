/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/26 15:07)

#include "Rendering/RenderingExport.h"

#include "ShaderFactory.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "Rendering/OpenGLRenderer/Detail/GLSL/GLSLShader.h"
#include "Rendering/RendererEngine/Flags/RendererTypes.h"

Rendering::ShaderFactory::ShaderSharedPtr Rendering::ShaderFactory::Create(RendererTypes rendererTypes, const Reflection& reflector, ReferenceType referenceType)
{
    switch (rendererTypes)
    {
        case RendererTypes::Glut:
        case RendererTypes::OpenGL:
        case RendererTypes::OpenGLES:
        case RendererTypes::Glfw:
        case RendererTypes::Vulkan:
        {
            return std::make_shared<GLSLShader>(reflector, referenceType);
        }

        case RendererTypes::Dx11:
        case RendererTypes::Default:
        case RendererTypes::Windows:
        default:
        {
            THROW_EXCEPTION(SYSTEM_TEXT("未定义的着色器类型。"s))
        }
    }
}
