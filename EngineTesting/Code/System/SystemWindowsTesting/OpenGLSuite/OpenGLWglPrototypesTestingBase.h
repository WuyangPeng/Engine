///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.0 (2023/01/23 0:04)

#ifndef SYSTEM_WINDOWS_TESTING_OPENGL_SUITE_OPENGL_WGL_PROTOTYPES_TESTING_BASE_H
#define SYSTEM_WINDOWS_TESTING_OPENGL_SUITE_OPENGL_WGL_PROTOTYPES_TESTING_BASE_H

#include "System/OpenGL/Using/WglExtensionsUsing.h"
#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class OpenGLWglPrototypesTestingBase : public CoreTools::UnitTest
    {
    public:
        using ClassType = OpenGLWglPrototypesTestingBase;
        using ParentType = UnitTest;

    public:
        explicit OpenGLWglPrototypesTestingBase(const OStreamShared& stream, WindowsHWnd hwnd);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        NODISCARD WindowsHWnd GetHwnd() const noexcept;
        NODISCARD WindowsHDC GetWindowsDC();
        void ReleaseWindowsDCTest(WindowsHDC windowsDC);
        NODISCARD OpenGLHglrc GetCreateWglContext(WindowsHDC windowsDC);
        void DeleteWglContextTest(OpenGLHglrc openGLHglrc);
        void SetWindowPixelFormatTest(WindowsHDC windowsDC);

    protected:
        static constexpr auto colorBits = 32;
        static constexpr auto depthBits = 24;
        static constexpr auto stencilBits = 8;

    private:
        WindowsHWnd hwnd;
    };
}

#endif  // SYSTEM_WINDOWS_TESTING_OPENGL_SUITE_OPENGL_WGL_PROTOTYPES_TESTING_BASE_H