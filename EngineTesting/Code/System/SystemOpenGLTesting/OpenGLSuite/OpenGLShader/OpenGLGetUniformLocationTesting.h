/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 16:39)

#ifndef SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_GET_UNIFORM_LOCATION_TESTING_H
#define SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_GET_UNIFORM_LOCATION_TESTING_H

#include "OpenGLShaderTestingBase.h"

namespace System
{
    class OpenGLGetUniformLocationTesting final : public OpenGLShaderTestingBase
    {
    public:
        using ClassType = OpenGLGetUniformLocationTesting;
        using ParentType = OpenGLShaderTestingBase;

    public:
        explicit OpenGLGetUniformLocationTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void GetUniformLocationTest();

        void DoGetUniformLocationTest(OpenGLUnsignedInt programHandle);
        void UniformTest(OpenGLUnsignedInt shaderHandle, OpenGLUnsignedInt programHandle);
        void BlockBindingTest(OpenGLUnsignedInt programHandle) const noexcept;

        NODISCARD std::string GetUniformName(OpenGLUnsignedInt shaderHandle, OpenGLUnsignedInt programHandle);
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_GET_UNIFORM_LOCATION_TESTING_H