///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.0 (2023/01/23 0:13)

#ifndef SYSTEM_WINDOWS_TESTING_OPENGL_SUITE_OPENGL_SWAP_DEVICE_BUFFERS_TESTING_H
#define SYSTEM_WINDOWS_TESTING_OPENGL_SUITE_OPENGL_SWAP_DEVICE_BUFFERS_TESTING_H

#include "OpenGLWglPrototypesTestingBase.h"

namespace System
{
    class OpenGLSwapDeviceBuffersTesting final : public OpenGLWglPrototypesTestingBase
    {
    public:
        using ClassType = OpenGLSwapDeviceBuffersTesting;
        using ParentType = OpenGLWglPrototypesTestingBase;

    public:
        explicit OpenGLSwapDeviceBuffersTesting(const OStreamShared& stream, WindowsHWnd hwnd);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void OpenGLSwapDeviceBuffersTest();

        void GetContextTest(WindowsHDC windowsDC);
        void DoOpenGLSwapDeviceBuffersTest(WindowsHDC windowsDC);
    };
}

#endif  // SYSTEM_WINDOWS_TESTING_OPENGL_SUITE_OPENGL_SWAP_DEVICE_BUFFERS_TESTING_H