///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/31 14:46)

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
        void DoOpenGLGetCurrentWglContextTest(OpenGLHglrc openGLHglrc);
    };
}

#endif  // SYSTEM_WINDOWS_TESTING_OPENGL_SUITE_OPENGL_GET_CURRENT_WGL_CONTEXT_TESTING_H