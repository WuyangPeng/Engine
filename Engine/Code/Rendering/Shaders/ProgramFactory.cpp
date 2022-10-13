///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.1 (2022/08/20 16:17)

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

Rendering::ProgramFactory::VisualProgramSharedPtr Rendering::ProgramFactory::CreateFromFiles(const std::string& vsFile, const std::string& psFile, const std::string& gsFile)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->CreateFromFiles(vsFile, psFile, gsFile);
}

Rendering::ProgramFactory::VisualProgramSharedPtr Rendering::ProgramFactory::CreateFromSources(const std::string& vsSource, const std::string& psSource, const std::string& gsSource)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->CreateFromFiles(vsSource, psSource, gsSource);
}

Rendering::ProgramFactory::ComputeProgramSharedPtr Rendering::ProgramFactory::CreateFromFile(const std::string& csFile)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->CreateFromFile(csFile);
}

Rendering::ProgramFactory::ComputeProgramSharedPtr Rendering::ProgramFactory::CreateFromSource(const std::string& csSource)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->CreateFromSource(csSource);
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
