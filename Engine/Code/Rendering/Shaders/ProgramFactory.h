/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/26 15:03)

#ifndef RENDERING_SHADERS_PROGRAM_FACTORY_H
#define RENDERING_SHADERS_PROGRAM_FACTORY_H

#include "Rendering/RenderingDll.h"

#include "Flags/ShaderAPIType.h"
#include "System/Helper/EnumCast.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "Rendering/RendererEngine/RendererEngineFwd.h"
#include "Rendering/Shaders/ShadersFwd.h"

#include <string>

RENDERING_NON_COPY_EXPORT_IMPL(ProgramFactoryImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE ProgramFactory
    {
    public:
        NON_COPY_TYPE_DECLARE(ProgramFactory);

        using VisualProgramSharedPtr = std::shared_ptr<VisualProgram>;
        using ComputeProgramSharedPtr = std::shared_ptr<ComputeProgram>;
        using ProgramSources = std::array<std::string, System::EnumCastUnderlying(ShaderAPIType::NumAPI)>;

    public:
        explicit ProgramFactory(RendererTypes rendererTypes);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ShaderAPIType GetAPI() const noexcept;

        NODISCARD VisualProgramSharedPtr CreateFromFiles(const std::string& vertexShaderFile, const std::string& pixelShaderFile, const std::string& geometryShaderFile);
        NODISCARD VisualProgramSharedPtr CreateFromSources(const std::string& vertexShaderSource, const std::string& pixelShaderSource, const std::string& geometryShaderSource);

        NODISCARD ComputeProgramSharedPtr CreateFromFile(const std::string& computeShaderFile);
        NODISCARD ComputeProgramSharedPtr CreateFromSource(const std::string& computeShaderSource);

        void PushDefines();
        void PopDefines();
        void PushFlags();
        void PopFlags() noexcept;

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_SHADERS_PROGRAM_FACTORY_H
