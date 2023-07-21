﻿///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/06 09:46)

#include "Rendering/RenderingExport.h"

#include "ProgramSourcesImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::ProgramSourcesImpl::ProgramSourcesImpl(const std::string& glsl, const std::string& hlsl)
    : container{ glsl, hlsl }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, ProgramSourcesImpl)

std::string Rendering::ProgramSourcesImpl::GetProgramSources(ShaderAPIType shaderAPIType) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return container.at(System::EnumCastUnderlying(shaderAPIType));
}
