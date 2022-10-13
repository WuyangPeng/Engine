///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.1 (2022/08/20 16:17)

#ifndef RENDERING_SHADERS_PROGRAM_FACTORY_H
#define RENDERING_SHADERS_PROGRAM_FACTORY_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "Rendering/Renderers/RenderersFwd.h"
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

    public:
        explicit ProgramFactory(RendererTypes rendererTypes);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ShaderAPIType GetAPI() const noexcept;

        NODISCARD VisualProgramSharedPtr CreateFromFiles(const std::string& vsFile, const std::string& psFile, const std::string& gsFile);
        NODISCARD VisualProgramSharedPtr CreateFromSources(const std::string& vsSource, const std::string& psSource, const std::string& gsSource);

        NODISCARD ComputeProgramSharedPtr CreateFromFile(const std::string& csFile);
        NODISCARD ComputeProgramSharedPtr CreateFromSource(const std::string& csSource);

        void PushDefines();
        void PopDefines();
        void PushFlags();
        void PopFlags() noexcept;

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_SHADERS_PROGRAM_FACTORY_H
