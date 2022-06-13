///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/12 14:53)

#ifndef SYSTEM_OPENGL_TESTING_OPENGL_GLUT_CALL_BACK_H
#define SYSTEM_OPENGL_TESTING_OPENGL_GLUT_CALL_BACK_H

#include "Framework/OpenGLGlutFrame/OpenGLGlutCallBackUnitTestSuite.h"

namespace System
{
    class OpenGLGlutCallBack final : public Framework::OpenGLGlutCallBackUnitTestSuite
    {
    public:
        using ClassType = OpenGLGlutCallBack;
        using ParentType = OpenGLGlutCallBackUnitTestSuite;
        using Suite = CoreTools::Suite;

    public:
        explicit OpenGLGlutCallBack(int64_t delta);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void AddSuite() final;

        void AddOpenGLSuite();
    };

    using OpenGLGlutProcessSystemOpenGLTesting = Framework::OpenGLGlutProcess<OpenGLGlutCallBack>;
}

#endif  // SYSTEM_OPENGL_TESTING_OPENGL_GLUT_CALL_BACK_H
