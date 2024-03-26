/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 17:12)

#ifndef SYSTEM_WINDOWS_TESTING_OPENGL_SUITE_OPENGL_GET_CURRENT_WGL_CONTEXT_TESTING_H
#define SYSTEM_WINDOWS_TESTING_OPENGL_SUITE_OPENGL_GET_CURRENT_WGL_CONTEXT_TESTING_H

#include "OpenGLWglPrototypesTestingBase.h"

namespace System
{
    class OpenGLGetCurrentWglContextTesting final : public OpenGLWglPrototypesTestingBase
    {
    public:
        using ClassType = OpenGLGetCurrentWglContextTesting;
        using ParentType = OpenGLWglPrototypesTestingBase;

    public:
        OpenGLGetCurrentWglContextTesting(const OStreamShared& stream, WindowsHWnd hWnd);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void OpenGLGetCurrentWglContextTest();

        void GetContextTest(WindowsHdc windowsDc);
        void DoOpenGLGetCurrentWglContextTest(OpenGLRcHandle openGLRcHandle);
    };
}

#endif  // SYSTEM_WINDOWS_TESTING_OPENGL_SUITE_OPENGL_GET_CURRENT_WGL_CONTEXT_TESTING_H