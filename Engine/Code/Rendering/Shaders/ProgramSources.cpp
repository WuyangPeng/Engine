///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/06 09:52)

#include "Rendering/RenderingExport.h"

#include "ProgramSources.h"
#include "Detail/ProgramSourcesImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, ProgramSources)

Rendering::ProgramSources::ProgramSources(const std::string& glsl, const std::string& hlsl)
    : impl{ glsl, hlsl }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, ProgramSources)

std::string Rendering::ProgramSources::GetProgramSources(ShaderAPIType shaderAPIType) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetProgramSources(shaderAPIType);
}
