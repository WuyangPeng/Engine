///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:21)

#ifndef RENDERING_OPENGL_RENDERER_GLSL_PROGRAM_FACTORY_H
#define RENDERING_OPENGL_RENDERER_GLSL_PROGRAM_FACTORY_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"
#include "System/OpenGL/Using/OpenGLUsing.h"
#include "Rendering/RendererEngine/RendererEngineFwd.h"
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

        NODISCARD VisualProgramSharedPtr CreateFromNamedSources(const std::string& vsName,
                                                                const std::string& vsSource,
                                                                const std::string& psName,
                                                                const std::string& psSource,
                                                                const std::string& gsName,
                                                                const std::string& gsSource) override;

        NODISCARD ComputeProgramSharedPtr CreateFromNamedSource(const std::string& csName, const std::string& csSource) override;

    private:
        NODISCARD OpenGLUInt Compile(ShaderType shaderType, const std::string& source);
        NODISCARD bool Link(OpenGLUInt programHandle);
    };
}

#endif  // RENDERING_OPENGL_RENDERER_GLSL_PROGRAM_FACTORY_H
