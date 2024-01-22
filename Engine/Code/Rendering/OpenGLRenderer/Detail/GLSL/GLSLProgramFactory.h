/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/14 00:19)

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

        /// GLSLVisualProgram��GLSLComputeProgram������������ɫ���ͳ���
        /// ��������������װΪ����ָ�룬�������Զ�����

    protected:
        /// ����GPU��ʾ���򡣴˳����뼤�����������������
        /// ֻ�е�programHandleΪ��ʱ�����صĳ������Ч��
        NODISCARD VisualProgramSharedPtr CreateFromNamedSources(const std::string& vertexShaderName,
                                                                const std::string& vertexShaderSource,
                                                                const std::string& pixelShaderName,
                                                                const std::string& pixelShaderSource,
                                                                const std::string& geometryShaderName,
                                                                const std::string& geometryShaderSource) override;

        /// ����GPU������򡣴˳����뼤�����������������
        /// ֻ�е�programHandleΪ��ʱ�����صĳ������Ч��
        NODISCARD ComputeProgramSharedPtr CreateFromNamedSource(const std::string& computeShaderName,
                                                                const std::string& computeShaderSource) override;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_GLSL_PROGRAM_FACTORY_H
