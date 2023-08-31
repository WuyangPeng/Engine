///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.1 (2023/07/05 11:15)

#ifndef RENDERING_SHADERS_NULL_PROGRAM_FACTORY_H
#define RENDERING_SHADERS_NULL_PROGRAM_FACTORY_H

#include "Rendering/RenderingDll.h"

#include "ProgramFactoryImpl.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE NullProgramFactory final : public ProgramFactoryImpl
    {
    public:
        using ClassType = NullProgramFactory;
        using ParentType = ProgramFactoryImpl;

    public:
        explicit NullProgramFactory(CoreTools::DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD ShaderAPIType GetAPI() const noexcept override;

    protected:
        NODISCARD VisualProgramSharedPtr CreateFromNamedSources(const std::string& vertexShaderName, const std::string& vertexShaderSource, const std::string& pixelShaderName, const std::string& pixelShaderSource, const std::string& geometryShaderName, const std::string& geometryShaderSource) override;
        NODISCARD ComputeProgramSharedPtr CreateFromNamedSource(const std::string& computeShaderName, const std::string& computeShaderSource) override;
    };
}

#endif  // RENDERING_SHADERS_NULL_PROGRAM_FACTORY_H