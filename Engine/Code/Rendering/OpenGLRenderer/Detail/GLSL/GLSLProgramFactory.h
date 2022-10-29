///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.1 (2022/08/21 15:14)

#ifndef RENDERING_OPENGL_RENDERER_GLSL_PROGRAM_FACTORY_H
#define RENDERING_OPENGL_RENDERER_GLSL_PROGRAM_FACTORY_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Renderers/RenderersFwd.h"
#include "Rendering/Shaders/Detail/ProgramFactoryImpl.h"

namespace Rendering
{
    class GLSLProgramFactory : public ProgramFactoryImpl
    {
    public:
        using ClassType = GLSLProgramFactory;
        using ParentType = ProgramFactoryImpl;

    public:
        explicit GLSLProgramFactory(CoreTools::DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD ShaderAPIType GetAPI() const noexcept override;

        NODISCARD VisualProgramSharedPtr CreateFromNamedSources(const std::string& vsName, const std::string& vsSource,
                                                                const std::string& psName, const std::string& psSource,
                                                                const std::string& gsName, const std::string& gsSource) override;

        NODISCARD ComputeProgramSharedPtr CreateFromNamedSource(const std::string& csName, const std::string& csSource) override;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_GLSL_PROGRAM_FACTORY_H
