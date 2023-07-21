///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/05 14:34)

#include "Rendering/RenderingExport.h"

#include "ProgramFactory.h"
#include "Detail/ProgramFactoryImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::ProgramFactory::ProgramFactory(RendererTypes rendererTypes)
    : impl{ CoreTools::ImplCreateUseFactory::Default, rendererTypes }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, ProgramFactory)

Rendering::ShaderAPIType Rendering::ProgramFactory::GetAPI() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetAPI();
}

Rendering::ProgramFactory::VisualProgramSharedPtr Rendering::ProgramFactory::CreateFromFiles(const std::string& vertexShaderFile, const std::string& pixelShaderFile, const std::string& geometryShaderFile)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->CreateFromFiles(vertexShaderFile, pixelShaderFile, geometryShaderFile);
}

Rendering::ProgramFactory::VisualProgramSharedPtr Rendering::ProgramFactory::CreateFromSources(const std::string& vertexShaderSource, const std::string& pixelShaderSource, const std::string& geometryShaderSource)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->CreateFromSources(vertexShaderSource, pixelShaderSource, geometryShaderSource);
}

Rendering::ProgramFactory::ComputeProgramSharedPtr Rendering::ProgramFactory::CreateFromFile(const std::string& computeShaderFile)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->CreateFromFile(computeShaderFile);
}

Rendering::ProgramFactory::ComputeProgramSharedPtr Rendering::ProgramFactory::CreateFromSource(const std::string& computeShaderSource)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->CreateFromSource(computeShaderSource);
}

void Rendering::ProgramFactory::PushDefines()
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->PushDefines();
}

void Rendering::ProgramFactory::PopDefines()
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->PopDefines();
}

void Rendering::ProgramFactory::PushFlags()
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->PushFlags();
}

void Rendering::ProgramFactory::PopFlags() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->PopFlags();
}
