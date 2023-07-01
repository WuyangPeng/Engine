///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 10:43)

#ifndef RENDERING_SHADERS_PROGRAM_FACTORY_H
#define RENDERING_SHADERS_PROGRAM_FACTORY_H

#include "Rendering/RenderingDll.h"

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
