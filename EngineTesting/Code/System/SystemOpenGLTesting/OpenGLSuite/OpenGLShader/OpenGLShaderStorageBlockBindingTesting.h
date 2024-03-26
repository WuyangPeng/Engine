/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/25 19:19)

#ifndef SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_SHADER_STORAGE_BLOCK_BINDING_TESTING_H
#define SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_SHADER_STORAGE_BLOCK_BINDING_TESTING_H

#include "OpenGLShaderTestingBase.h"

namespace System
{
    class OpenGLShaderStorageBlockBindingTesting final : public OpenGLShaderTestingBase
    {
    public:
        using ClassType = OpenGLShaderStorageBlockBindingTesting;
        using ParentType = OpenGLShaderTestingBase;

    public:
        explicit OpenGLShaderStorageBlockBindingTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void ShaderStorageBlockBindingTest();

        void DoShaderStorageBlockBindingTest(OpenGLUnsignedInt programHandle);
        void BlockBindingTest(OpenGLUnsignedInt programHandle);

    private:
        CodeType computeShader;
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_SHADER_STORAGE_BLOCK_BINDING_TESTING_H