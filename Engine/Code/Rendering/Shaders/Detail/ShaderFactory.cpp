///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.1 (2023/07/05 14:32)

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
            THROW_EXCEPTION(SYSTEM_TEXT("δ�������ɫ�����͡�"s))
        }
    }
}
