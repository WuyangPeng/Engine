/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 16:39)

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
        void DoRunUnitTest() override;
        void MainTest();

        void AttachShaderTest();

        void CreateShaderTest(OpenGLUnsignedInt programHandle);
        void DoAttachShaderTest(OpenGLUnsignedInt programHandle, OpenGLUnsignedInt shaderHandle);
        void GetAttachedGLShadersTest(OpenGLUnsignedInt programHandle, OpenGLUnsignedInt shaderHandle);
        void GetShaderInfoLogTest(OpenGLUnsignedInt shaderHandle);
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_ATTACH_SHADER_TESTING_H