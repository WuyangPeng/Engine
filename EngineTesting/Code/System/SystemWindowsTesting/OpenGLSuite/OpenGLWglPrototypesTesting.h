///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.6 (2021/07/01 19:18)

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