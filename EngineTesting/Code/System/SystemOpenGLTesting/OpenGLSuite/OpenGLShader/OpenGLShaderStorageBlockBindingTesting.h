/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/25 19:19)

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