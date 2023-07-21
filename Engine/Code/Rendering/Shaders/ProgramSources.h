///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/06 09:52)

#ifndef RENDERING_SHADERS_PROGRAM_SOURCES_H
#define RENDERING_SHADERS_PROGRAM_SOURCES_H

#include "Rendering/RenderingDll.h"

#include "ShadersFwd.h"
#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"

#include <string>

RENDERING_COPY_UNSHARED_EXPORT_IMPL(ProgramSources, ProgramSourcesImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE ProgramSources
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(ProgramSources);

    public:
        ProgramSources(const std::string& glsl, const std::string& hlsl);

        CLASS_INVARIANT_DECLARE;

        NODISCARD std::string GetProgramSources(ShaderAPIType shaderAPIType) const;

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_SHADERS_PROGRAM_SOURCES_H
