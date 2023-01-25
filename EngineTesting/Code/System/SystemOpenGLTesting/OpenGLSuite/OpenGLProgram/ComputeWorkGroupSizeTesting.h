///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/13 13:06)

#ifndef SYSTEM_OPENGL_TESTING_OPENGL_SUITE_COMPUTE_WORK_GROUP_SIZE_TESTING_H
#define SYSTEM_OPENGL_TESTING_OPENGL_SUITE_COMPUTE_WORK_GROUP_SIZE_TESTING_H

#include "OpenGLProgramTestingBase.h"

namespace System
{
    class ComputeWorkGroupSizeTesting final : public OpenGLProgramTestingBase
    {
    public:
        using ClassType = ComputeWorkGroupSizeTesting;
        using ParentType = OpenGLProgramTestingBase;

    public:
        explicit ComputeWorkGroupSizeTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void ComputeWorkGroupSizeTest();
        void DoComputeWorkGroupSizeTest(OpenGLUInt programHandle);

        void DoCreateGLShaderTest(OpenGLUInt shaderHandle, OpenGLUInt programHandle);

    private:
        CodeType code;
    };
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_SUITE_COMPUTE_WORK_GROUP_SIZE_TESTING_H