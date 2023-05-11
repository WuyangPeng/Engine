///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.0 (2023/01/15 18:21)

#ifndef SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_SHADER_ATTRIBUTES_TESTING_H
#define SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_SHADER_ATTRIBUTES_TESTING_H

#include "OpenGLShaderTestingBase.h"

namespace System
{
    class OpenGLShaderAttributesTesting final : public OpenGLShaderTestingBase
    {
    public:
        using ClassType = OpenGLShaderAttributesTesting;
        using ParentType = OpenGLShaderTestingBase;

    public:
        explicit OpenGLShaderAttributesTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void ShaderAttributesTest();

        void DoShaderAttributesTest(OpenGLUInt shaderHandle);
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_SHADER_ATTRIBUTES_TESTING_H