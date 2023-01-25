///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/23 0:13)

#ifndef SYSTEM_WINDOWS_TESTING_OPENGL_SUITE_OPENGL_GET_WGL_PROC_ADDRESS_TESTING_H
#define SYSTEM_WINDOWS_TESTING_OPENGL_SUITE_OPENGL_GET_WGL_PROC_ADDRESS_TESTING_H

#include "OpenGLWglPrototypesTestingBase.h"

namespace System
{
    class OpenGLGetWglProcAddressTesting final : public OpenGLWglPrototypesTestingBase
    {
    public:
        using ClassType = OpenGLGetWglProcAddressTesting;
        using ParentType = OpenGLWglPrototypesTestingBase;

    public:
        explicit OpenGLGetWglProcAddressTesting(const OStreamShared& stream, WindowsHWnd hwnd);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void OpenGLGetWglProcAddressTest();

        void GetContextTest(WindowsHDC windowsDC);
        void DoOpenGLGetWglProcAddressTest();
    };
}

#endif  // SYSTEM_WINDOWS_TESTING_OPENGL_SUITE_OPENGL_GET_WGL_PROC_ADDRESS_TESTING_H