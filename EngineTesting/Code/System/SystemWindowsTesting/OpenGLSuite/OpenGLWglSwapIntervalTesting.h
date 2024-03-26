/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 17:13)

#ifndef SYSTEM_WINDOWS_TESTING_OPENGL_SUITE_OPENGL_WGL_SWAP_INTERVAL_TESTING_H
#define SYSTEM_WINDOWS_TESTING_OPENGL_SUITE_OPENGL_WGL_SWAP_INTERVAL_TESTING_H

#include "OpenGLWglPrototypesTestingBase.h"

namespace System
{
    class OpenGLWglSwapIntervalTesting final : public OpenGLWglPrototypesTestingBase
    {
    public:
        using ClassType = OpenGLWglSwapIntervalTesting;
        using ParentType = OpenGLWglPrototypesTestingBase;

    public:
        OpenGLWglSwapIntervalTesting(const OStreamShared& stream, WindowsHWnd hWnd);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void OpenGLWglSwapIntervalTest();

        void GetContextTest(WindowsHdc windowsDc);
        void DoOpenGLWglSwapIntervalTest();
    };
}

#endif  // SYSTEM_WINDOWS_TESTING_OPENGL_SUITE_OPENGL_WGL_SWAP_INTERVAL_TESTING_H