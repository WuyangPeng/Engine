///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/31 14:03)

#ifndef SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL__PROGRAM_TESTING_BASE_H
#define SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL__PROGRAM_TESTING_BASE_H

#include "System/OpenGL/Using/OpenGLUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class OpenGLProgramTestingBase : public CoreTools::UnitTest
    {
    public:
        using ClassType = OpenGLProgramTestingBase;
        using ParentType = UnitTest;

    public:
        explicit OpenGLProgramTestingBase(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        using CodeType = std::vector<const GLchar*>;

    protected:
        void DeleteGLProgramTest(OpenGLUInt programHandle) noexcept;
        void DeleteGLShaderTest(OpenGLUInt shaderHandle) noexcept;
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL__PROGRAM_TESTING_BASE_H