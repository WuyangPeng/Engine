///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 14:47)

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
        NODISCARD WindowsHWnd GetHWnd() const noexcept;
        NODISCARD WindowsHdc GetWindowsDc();
        void ReleaseWindowsDcTest(WindowsHdc windowsDc);
        NODISCARD OpenGLHglrc GetCreateWglContext(WindowsHdc windowsDc);
        void DeleteWglContextTest(OpenGLHglrc openGLHglrc);
        void SetWindowPixelFormatTest(WindowsHdc windowsDc);

    protected:
        static constexpr auto colorBits = 32;
        static constexpr auto depthBits = 24;
        static constexpr auto stencilBits = 8;

    private:
        WindowsHWnd hWnd;
    };
}

#endif  // SYSTEM_WINDOWS_TESTING_OPENGL_SUITE_OPENGL_WGL_PROTOTYPES_TESTING_BASE_H