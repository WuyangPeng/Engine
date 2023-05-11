///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.0 (2023/01/15 0:47)

#ifndef SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_ATTACH_SHADER_TESTING_H
#define SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_ATTACH_SHADER_TESTING_H

#include "OpenGLShaderTestingBase.h"

namespace System
{
    class OpenGLAttachShaderTesting final : public OpenGLShaderTestingBase
    {
    public:
        using ClassType = OpenGLAttachShaderTesting;
        using ParentType = OpenGLShaderTestingBase;

    public:
        explicit OpenGLAttachShaderTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void AttachShaderTest();

        void CreateShaderTest(OpenGLUInt programHandle);
        void DoAttachShaderTest(OpenGLUInt programHandle, OpenGLUInt shaderHandle);
        void GetAttachedGLShadersTest(OpenGLUInt programHandle, OpenGLUInt shaderHandle);
        void GetGLShaderInfoLogTest(OpenGLUInt shaderHandle);
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_ATTACH_SHADER_TESTING_H