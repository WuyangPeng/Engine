/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/14 00:04)

#include "Rendering/RenderingExport.h"

#include "HLSLProgramFactory.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Rendering/Shaders/Flags/ShaderAPIType.h"

Rendering::HLSLProgramFactory::HLSLProgramFactory(CoreTools::DisableNotThrow disableNotThrow)
    : ParentType{ disableNotThrow }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, HLSLProgramFactory)

Rendering::ShaderAPIType Rendering::HLSLProgramFactory::GetAPI() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return ShaderAPIType::HLSL;
}

Rendering::ProgramFactoryImpl::VisualProgramSharedPtr Rendering::HLSLProgramFactory::CreateFromNamedSources(const std::string& vertexShaderName, const std::string& vertexShaderSource, const std::string& pixelShaderName, const std::string& pixelShaderSource, const std::string& geometryShaderName, const std::string& geometryShaderSource)
{
    RENDERING_CLASS_IS_VALID_9;

    System::UnusedFunction(vertexShaderName, vertexShaderSource, pixelShaderName, pixelShaderSource, geometryShaderName, geometryShaderSource);

    THROW_EXCEPTION(SYSTEM_TEXT("无法获取VisualProgram"))
}

Rendering::ProgramFactoryImpl::ComputeProgramSharedPtr Rendering::HLSLProgramFactory::CreateFromNamedSource(const std::string& computeShaderName, const std::string& computeShaderSource)
{
    RENDERING_CLASS_IS_VALID_9;

    System::UnusedFunction(computeShaderName, computeShaderSource);

    THROW_EXCEPTION(SYSTEM_TEXT("无法获取ComputeProgram"))
}
