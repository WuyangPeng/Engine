/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/09 16:53)

#ifndef RENDERING_OPENGL_RENDERER_GLSL_PROGRAM_FACTORY_H
#define RENDERING_OPENGL_RENDERER_GLSL_PROGRAM_FACTORY_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"
#include "System/OpenGL/Using/OpenGLUsing.h"
#include "Rendering/Shaders/Detail/ProgramFactoryImpl.h"

namespace Rendering
{
    class GLSLProgramFactory : public ProgramFactoryImpl
    {
    public:
        using ClassType = GLSLProgramFactory;
        using ParentType = ProgramFactoryImpl;

        using OpenGLUInt = System::OpenGLUInt;
        using ShaderType = System::ShaderType;

    public:
        NODISCARD static ProgramFactorySharedPtr Create();
        explicit GLSLProgramFactory(CoreTools::DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD ShaderAPIType GetAPI() const noexcept override;

        NODISCARD VisualProgramSharedPtr CreateFromNamedSources(const std::string& vertexShaderName,
                                                                const std::string& vertexShaderSource,
                                                                const std::string& pixelShaderName,
                                                                const std::string& pixelShaderSource,
                                                                const std::string& geometryShaderName,
                                                                const std::string& geometryShaderSource) override;

        NODISCARD ComputeProgramSharedPtr CreateFromNamedSource(const std::string& computeShaderName, const std::string& computeShaderSource) override;

    private:
        NODISCARD OpenGLUInt Compile(ShaderType shaderType, const std::string& source);
        NODISCARD bool Link(OpenGLUInt programHandle);
    };
}

#endif  // RENDERING_OPENGL_RENDERER_GLSL_PROGRAM_FACTORY_H
