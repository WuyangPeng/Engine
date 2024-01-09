/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/26 14:58)

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
        static constexpr auto numAPI = System::EnumCastUnderlying(ShaderAPIType::NumAPI);
        using Container = std::array<std::string, numAPI>;

    private:
        Container container;
    };
}

#endif  // RENDERING_SHADERS_PROGRAM_SOURCES_IMPL_H
