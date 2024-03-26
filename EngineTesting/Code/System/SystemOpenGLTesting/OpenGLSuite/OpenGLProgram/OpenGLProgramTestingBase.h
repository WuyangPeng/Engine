/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 16:38)

#ifndef SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_PROGRAM_TESTING_BASE_H
#define SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_PROGRAM_TESTING_BASE_H

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
        void DeleteGLProgramTest(OpenGLUnsignedInt programHandle) const noexcept;
        void DeleteGLShaderTest(OpenGLUnsignedInt shaderHandle) const noexcept;
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_PROGRAM_TESTING_BASE_H