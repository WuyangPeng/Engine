///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 10:46)

#include "Rendering/RenderingExport.h"

#include "ShaderFactory.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "Rendering/OpenGLRenderer/Detail/GLSL/GLSLShader.h"
#include "Rendering/Renderers/Flags/RendererTypes.h"

Rendering::ShaderFactory::ShaderSharedPtr Rendering::ShaderFactory::Create(RendererTypes type, const GLSLReflection& reflector, ReferenceType referenceType)
{
    switch (type)
    {
        case RendererTypes::Glut:
            return std::make_shared<GLSLShader>(reflector, referenceType);
        case RendererTypes::OpenGL:
            return std::make_shared<GLSLShader>(reflector, referenceType);
        case RendererTypes::OpenGLES:
            return std::make_shared<GLSLShader>(reflector, referenceType);

        case RendererTypes::Dx11:
        case RendererTypes::Default:
        case RendererTypes::Windows:
        default:
        {
            THROW_EXCEPTION(SYSTEM_TEXT("δ�������ɫ�����͡�"s));
        }
    }
}
