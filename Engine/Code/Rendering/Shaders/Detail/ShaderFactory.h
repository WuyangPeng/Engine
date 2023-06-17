///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 10:30)

#ifndef RENDERING_SHADERS_SHADER_FACTORY_H
#define RENDERING_SHADERS_SHADER_FACTORY_H

#include "Rendering/RenderingDll.h"

#include "Rendering/OpenGLRenderer/Flags/ReferenceType.h"
#include "Rendering/OpenGLRenderer/GLSL/GLSLReflection.h"
#include "Rendering/Renderers/RenderersFwd.h"
#include "Rendering/Shaders/ShadersInternalFwd.h"

#include <string>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE ShaderFactory
    {
    public:
        using ClassType = ShaderFactory;
        using ShaderSharedPtr = std::shared_ptr<ShaderImpl>;

    public:
        NODISCARD static ShaderSharedPtr Create(RendererTypes type, const GLSLReflection& reflector, ReferenceType referenceType);
    };
}

#endif  // RENDERING_SHADERS_SHADER_DATA_IMPL_H
