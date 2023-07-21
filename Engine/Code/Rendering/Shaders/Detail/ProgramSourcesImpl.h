///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/06 09:46)

#ifndef RENDERING_SHADERS_PROGRAM_SOURCES_IMPL_H
#define RENDERING_SHADERS_PROGRAM_SOURCES_IMPL_H

#include "Rendering/RenderingDll.h"

#include "System/Helper/EnumCast.h"
#include "Rendering/Shaders/Flags/ShaderAPIType.h"

#include <array>
#include <string>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE ProgramSourcesImpl
    {
    public:
        using ClassType = ProgramSourcesImpl;

    public:
        ProgramSourcesImpl(const std::string& glsl, const std::string& hlsl);

        CLASS_INVARIANT_DECLARE;

        NODISCARD std::string GetProgramSources(ShaderAPIType shaderAPIType) const;

    private:
        using Container = std::array<std::string, System::EnumCastUnderlying(ShaderAPIType::NumAPI)>;

    private:
        Container container;
    };
}

#endif  // RENDERING_SHADERS_PROGRAM_SOURCES_IMPL_H
