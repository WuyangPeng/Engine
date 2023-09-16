///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/31 14:04)

#ifndef SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_SHADER_STATUS_TESTING_H
#define SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_SHADER_STATUS_TESTING_H

#include "OpenGLShaderTestingBase.h"

namespace System
{
    class OpenGLShaderStatusTesting final : public OpenGLShaderTestingBase
    {
    public:
        using ClassType = OpenGLShaderStatusTesting;
        using ParentType = OpenGLShaderTestingBase;

    public:
        explicit OpenGLShaderStatusTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void ShaderStatusTest();

        void DoShaderStatusTest(OpenGLUInt shaderHandle);
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_SHADER_STATUS_TESTING_H