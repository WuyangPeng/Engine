///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 14:48)

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