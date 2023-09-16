///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 14:03)

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

        void CreateShaderTest(OpenGLUInt programHandle);
        void DoAttachShaderTest(OpenGLUInt programHandle, OpenGLUInt shaderHandle);
        void GetAttachedGLShadersTest(OpenGLUInt programHandle, OpenGLUInt shaderHandle);
        void GetGLShaderInfoLogTest(OpenGLUInt shaderHandle);
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_ATTACH_SHADER_TESTING_H