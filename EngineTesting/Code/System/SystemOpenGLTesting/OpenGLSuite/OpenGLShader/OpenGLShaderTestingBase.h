/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 16:39)

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
        void DeleteProgramTest(OpenGLUnsignedInt programHandle) const noexcept;
        void DeleteShaderTest(OpenGLUnsignedInt shaderHandle) const noexcept;
        void ShaderSourceTest(OpenGLUnsignedInt shaderHandle) const;

    private:
        CodeType code;
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_SHADER_TESTING_BASE_H