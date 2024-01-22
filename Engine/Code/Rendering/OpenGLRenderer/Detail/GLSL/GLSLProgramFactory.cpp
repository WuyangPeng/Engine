/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/14 18:52)

#include "Rendering/RenderingExport.h"

#include "GLSLProgramFactory.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/OpenGL/OpenGLProgram.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Rendering/RendererEngine/Flags/RendererTypes.h"
#include "Rendering/Shaders/ComputeProgram.h"
#include "Rendering/Shaders/Flags/ShaderAPIType.h"
#include "Rendering/Shaders/Reflection.h"
#include "Rendering/Shaders/Shader.h"
#include "Rendering/Shaders/VisualProgram.h"

Rendering::ProgramFactoryImpl::ProgramFactorySharedPtr Rendering::GLSLProgramFactory::Create()
{
    return std::make_shared<ClassType>(CoreTools::DisableNotThrow::Disable);
}

Rendering::GLSLProgramFactory::GLSLProgramFactory(CoreTools::DisableNotThrow disableNotThrow)
    : ParentType{ "#version 460",
                  "main",
                  "main",
                  "main",
                  "main",
                  0 }
{
    System::UnusedFunction(disableNotThrow);

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, GLSLProgramFactory)

Rendering::ShaderAPIType Rendering::GLSLProgramFactory::GetAPI() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return ShaderAPIType::GLSL;
}

Rendering::GLSLProgramFactory::VisualProgramSharedPtr Rendering::GLSLProgramFactory::CreateFromNamedSources(const std::string& vertexShaderName, const std::string& vertexShaderSource, const std::string& pixelShaderName, const std::string& pixelShaderSource, const std::string& geometryShaderName, const std::string& geometryShaderSource)
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(vertexShaderName, pixelShaderName, geometryShaderName);

    return VisualProgram::Create(vertexShaderSource, pixelShaderSource, geometryShaderSource, GetVersion(), GetProgramDefines());
}

Rendering::GLSLProgramFactory::ComputeProgramSharedPtr Rendering::GLSLProgramFactory::CreateFromNamedSource(const std::string& computeShaderName, const std::string& computeShaderSource)
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(computeShaderName);

    return ComputeProgram::Create(computeShaderSource, GetVersion(), GetProgramDefines());
}
