///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 14:03)

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

        void DoGetUniformLocationTest(OpenGLUInt programHandle);
        void UniformTest(OpenGLUInt shaderHandle, OpenGLUInt programHandle);

        NODISCARD std::string GetuUniformName(OpenGLUInt shaderHandle, OpenGLUInt programHandle);
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_OPENGL_GET_UNIFORM_LOCATION_TESTING_H