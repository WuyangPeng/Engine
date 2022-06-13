///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/16 14:35)

#ifndef SYSTEM_WINDOWS_TESTING_OPENGL_SUITE_OPENGL_WGL_PROTOTYPES_TESTING_H
#define SYSTEM_WINDOWS_TESTING_OPENGL_SUITE_OPENGL_WGL_PROTOTYPES_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace System
{
    class OpenGLWglPrototypesTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = OpenGLWglPrototypesTesting;
        using ParentType = UnitTest;

    public:
        explicit OpenGLWglPrototypesTesting(const OStreamShared& stream, WindowsHWnd hwnd);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void CreateWglTest();
        void SwapTest();

        static constexpr auto colorBits = 32;
        static constexpr auto depthBits = 24;
        static constexpr auto stencilBits = 8;

    private:
        WindowsHWnd hwnd;
    };
}

#endif  // SYSTEM_WINDOWS_TESTING_OPENGL_SUITE_OPENGL_WGL_PROTOTYPES_TESTING_H