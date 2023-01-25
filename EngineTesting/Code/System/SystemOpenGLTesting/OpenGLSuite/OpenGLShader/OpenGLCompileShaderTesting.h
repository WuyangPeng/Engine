///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.0 (2023/01/15 13:26)

#ifndef SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_COMPILE_SHADER_TESTING_H
#define SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_COMPILE_SHADER_TESTING_H

#include "OpenGLShaderTestingBase.h"

namespace System
{
    class OpenGLCompileShaderTesting final : public OpenGLShaderTestingBase
    {
    public:
        using ClassType = OpenGLCompileShaderTesting;
        using ParentType = OpenGLShaderTestingBase;

    public:
        explicit OpenGLCompileShaderTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void CompileShaderTest();

        void DoCompileShaderTest(OpenGLUInt shaderHandle);
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_COMPILE_SHADER_TESTING_H