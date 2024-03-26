/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 16:39)

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
        void DoRunUnitTest() override;
        void MainTest();

        void CompileShaderTest();

        void DoCompileShaderTest(OpenGLUnsignedInt shaderHandle);
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_COMPILE_SHADER_TESTING_H