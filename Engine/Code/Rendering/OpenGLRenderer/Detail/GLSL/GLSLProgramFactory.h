/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/14 00:19)

#ifndef RENDERING_OPENGL_RENDERER_GLSL_PROGRAM_FACTORY_H
#define RENDERING_OPENGL_RENDERER_GLSL_PROGRAM_FACTORY_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"
#include "System/OpenGL/Using/OpenGLUsing.h"
#include "Rendering/Shaders/Detail/ProgramFactoryImpl.h"
#include "System/Helper/UnicodeUsing.h"

namespace Rendering
{
    class GLSLProgramFactory final : public ProgramFactoryImpl
    {
    public:
        using ClassType = GLSLProgramFactory;
        using ParentType = ProgramFactoryImpl;

        using String = System::String;
        using OpenGLUInt = System::OpenGLUInt;
        using ShaderType = System::ShaderType;

    public:
        NODISCARD static ProgramFactorySharedPtr Create();
        explicit GLSLProgramFactory(CoreTools::DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD ShaderAPIType GetAPI() const noexcept override;

        /// GLSLVisualProgram和GLSLComputeProgram对象负责销毁着色器和程序。
        /// 工厂将程序对象包装为共享指针，以允许自动清理。

    protected:
        /// 创建GPU显示程序。此程序与激活的引擎对象相关联。
        /// 只有当programHandle为正时，返回的程序才有效。
        NODISCARD VisualProgramSharedPtr CreateFromNamedSources(const std::string& vertexShaderName,
                                                                const std::string& vertexShaderSource,
                                                                const std::string& pixelShaderName,
                                                                const std::string& pixelShaderSource,
                                                                const std::string& geometryShaderName,
                                                                const std::string& geometryShaderSource) override;

        /// 创建GPU计算程序。此程序与激活的引擎对象相关联。
        /// 只有当programHandle为正时，返回的程序才有效。
        NODISCARD ComputeProgramSharedPtr CreateFromNamedSource(const std::string& computeShaderName,
                                                                const std::string& computeShaderSource) override;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_GLSL_PROGRAM_FACTORY_H
