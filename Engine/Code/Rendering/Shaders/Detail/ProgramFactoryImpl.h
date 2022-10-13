///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.1 (2022/08/21 15:14)

#ifndef RENDERING_SHADERS_PROGRAM_FACTORY_IMPL_H
#define RENDERING_SHADERS_PROGRAM_FACTORY_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Renderers/RenderersFwd.h"
#include "Rendering/Shaders/ProgramDefines.h"
#include "Rendering/Shaders/ShadersFwd.h"

#include <memory>
#include <stack>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE ProgramFactoryImpl
    {
    public:
        using ClassType = ProgramFactoryImpl;
        using FactoryType = ClassType;
        using ProgramFactorySharedPtr = std::shared_ptr<ProgramFactoryImpl>;
        using VisualProgramSharedPtr = std::shared_ptr<VisualProgram>;
        using ComputeProgramSharedPtr = std::shared_ptr<ComputeProgram>;

    public:
        explicit ProgramFactoryImpl(CoreTools::DisableNotThrow disableNotThrow);
        virtual ~ProgramFactoryImpl() noexcept = default;
        ProgramFactoryImpl(const ProgramFactoryImpl& rhs) = delete;
        ProgramFactoryImpl& operator=(const ProgramFactoryImpl& rhs) = delete;
        ProgramFactoryImpl(ProgramFactoryImpl&& rhs) noexcept = delete;
        ProgramFactoryImpl& operator=(ProgramFactoryImpl&& rhs) noexcept = delete;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD virtual ShaderAPIType GetAPI() const noexcept = 0;

        NODISCARD VisualProgramSharedPtr CreateFromFiles(const std::string& vsFile, const std::string& psFile, const std::string& gsFile);
        NODISCARD VisualProgramSharedPtr CreateFromSources(const std::string& vsSource, const std::string& psSource, const std::string& gsSource);

        NODISCARD ComputeProgramSharedPtr CreateFromFile(const std::string& csFile);
        NODISCARD ComputeProgramSharedPtr CreateFromSource(const std::string& csSource);

        NODISCARD static std::string GetStringFromFile(const std::string& filename);

        void PushDefines();
        void PopDefines();
        void PushFlags();
        void PopFlags() noexcept;

        NODISCARD static ProgramFactorySharedPtr Create(RendererTypes rendererTypes);

    protected:
        NODISCARD virtual VisualProgramSharedPtr CreateFromNamedSources(const std::string& vsName, const std::string& vsSource,
                                                                        const std::string& psName, const std::string& psSource,
                                                                        const std::string& gsName, const std::string& gsSource) = 0;

        NODISCARD virtual ComputeProgramSharedPtr CreateFromNamedSource(const std::string& csName, const std::string& csSource) = 0;

    private:
        using ProgramDefinesContainer = std::stack<ProgramDefines>;
        using FlagsType = std::stack<int>;

    private:
        std::string version;
        std::string vsEntry;
        std::string psEntry;
        std::string gsEntry;
        std::string csEntry;
        ProgramDefines defines;
        int flags;

        ProgramDefinesContainer definesStack;
        FlagsType flagsStack;
    };
}

#endif  // RENDERING_SHADERS_PROGRAM_FACTORY_IMPL_H
