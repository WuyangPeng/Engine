///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/05 11:15)

#ifndef RENDERING_SHADERS_PROGRAM_FACTORY_IMPL_H
#define RENDERING_SHADERS_PROGRAM_FACTORY_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/RendererEngine/RendererEngineFwd.h"
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
        using ContainerConstIter = ProgramDefines::ContainerConstIter;

    public:
        ProgramFactoryImpl(std::string version,
                           std::string vertexShaderEntry,
                           std::string pixelShaderEntry,
                           std::string geometryShaderEntry,
                           std::string computeShaderEntry,
                           int flags);
        explicit ProgramFactoryImpl(CoreTools::DisableNotThrow disableNotThrow);
        virtual ~ProgramFactoryImpl() noexcept = default;
        ProgramFactoryImpl(const ProgramFactoryImpl& rhs) = delete;
        ProgramFactoryImpl& operator=(const ProgramFactoryImpl& rhs) = delete;
        ProgramFactoryImpl(ProgramFactoryImpl&& rhs) noexcept = delete;
        ProgramFactoryImpl& operator=(ProgramFactoryImpl&& rhs) noexcept = delete;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD virtual ShaderAPIType GetAPI() const noexcept = 0;

        NODISCARD VisualProgramSharedPtr CreateFromFiles(const std::string& vertexShaderFile, const std::string& pixelShaderFile, const std::string& geometryShaderFile);
        NODISCARD VisualProgramSharedPtr CreateFromSources(const std::string& vertexShaderSource, const std::string& pixelShaderSource, const std::string& geometryShaderSource);

        NODISCARD ComputeProgramSharedPtr CreateFromFile(const std::string& computeShaderFile);
        NODISCARD ComputeProgramSharedPtr CreateFromSource(const std::string& computeShaderSource);

        NODISCARD static std::string GetStringFromFile(const std::string& fileName);

        void PushDefines();
        void PopDefines();
        void PushFlags();
        void PopFlags() noexcept;

        NODISCARD static ProgramFactorySharedPtr Create(RendererTypes rendererTypes);

    protected:
        NODISCARD virtual VisualProgramSharedPtr CreateFromNamedSources(const std::string& vertexShaderName,
                                                                        const std::string& vertexShaderSource,
                                                                        const std::string& pixelShaderName,
                                                                        const std::string& pixelShaderSource,
                                                                        const std::string& geometryShaderName,
                                                                        const std::string& geometryShaderSource) = 0;

        NODISCARD virtual ComputeProgramSharedPtr CreateFromNamedSource(const std::string& computeShaderName, const std::string& computeShaderSource) = 0;

        NODISCARD std::string GetVersion() const;
        NODISCARD int GetDefinesSize() const;

        NODISCARD ContainerConstIter begin() const noexcept;
        NODISCARD ContainerConstIter end() const noexcept;

    private:
        using ProgramDefinesContainer = std::stack<ProgramDefines>;
        using FlagsType = std::stack<int>;

    private:
        std::string version;
        std::string vertexShaderEntry;
        std::string pixelShaderEntry;
        std::string geometryShaderEntry;
        std::string computeShaderEntry;
        ProgramDefines defines;
        int flags;

        ProgramDefinesContainer definesStack;
        FlagsType flagsStack;
    };
}

#endif  // RENDERING_SHADERS_PROGRAM_FACTORY_IMPL_H
