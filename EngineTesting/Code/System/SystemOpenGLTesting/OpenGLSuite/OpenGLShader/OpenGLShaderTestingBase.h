///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.0 (2023/01/15 0:36)

#ifndef SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_SHADER_TESTING_BASE_H
#define SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_SHADER_TESTING_BASE_H

#include "System/OpenGL/Using/OpenGLUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class OpenGLShaderTestingBase : public CoreTools::UnitTest
    {
    public:
        using ClassType = OpenGLShaderTestingBase;
        using ParentType = UnitTest;

    public:
        explicit OpenGLShaderTestingBase(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        using CodeType = std::vector<const GLchar*>;
        using ResultType = std::vector<OpenGLChar>;

    protected:
        void DeleteProgramTest(OpenGLUInt programHandle) noexcept;
        void DeleteShaderTest(OpenGLUInt shaderHandle) noexcept;
        void ShaderSourceTest(OpenGLUInt shaderHandle);

    private:
        CodeType code;
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_SHADER_TESTING_BASE_H