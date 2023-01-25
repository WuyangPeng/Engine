///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/23 0:13)

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
        explicit OpenGLWglSwapIntervalTesting(const OStreamShared& stream, WindowsHWnd hwnd);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void OpenGLWglSwapIntervalTest();

        void GetContextTest(WindowsHDC windowsDC);
        void DoOpenGLWglSwapIntervalTest();
    };
}

#endif  // SYSTEM_WINDOWS_TESTING_OPENGL_SUITE_OPENGL_WGL_SWAP_INTERVAL_TESTING_H