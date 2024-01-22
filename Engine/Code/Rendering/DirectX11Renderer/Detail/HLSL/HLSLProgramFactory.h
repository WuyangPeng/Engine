/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/14 00:04)

#ifndef RENDERING_SHADERS_HLSL_PROGRAM_FACTORY_H
#define RENDERING_SHADERS_HLSL_PROGRAM_FACTORY_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Shaders/Detail/ProgramFactoryImpl.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE HLSLProgramFactory final : public ProgramFactoryImpl
    {
    public:
        using ClassType = HLSLProgramFactory;
        using ParentType = ProgramFactoryImpl;

    public:
        explicit HLSLProgramFactory(CoreTools::DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD ShaderAPIType GetAPI() const noexcept override;

    protected:
        NODISCARD VisualProgramSharedPtr CreateFromNamedSources(const std::string& vertexShaderName, const std::string& vertexShaderSource, const std::string& pixelShaderName, const std::string& pixelShaderSource, const std::string& geometryShaderName, const std::string& geometryShaderSource) override;
        NODISCARD ComputeProgramSharedPtr CreateFromNamedSource(const std::string& computeShaderName, const std::string& computeShaderSource) override;
    };
}

#endif  // RENDERING_SHADERS_HLSL_PROGRAM_FACTORY_H
