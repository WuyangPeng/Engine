/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 17:13)

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
        explicit OpenGLWglPrototypesTestingBase(const OStreamShared& stream, WindowsHWnd hWnd);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        static constexpr auto colorBits = 32;
        static constexpr auto depthBits = 24;
        static constexpr auto stencilBits = 8;

    protected:
        NODISCARD WindowsHWnd GetHWnd() const noexcept;
        NODISCARD WindowsHdc GetWindowsDc();
        void ReleaseWindowsDcTest(WindowsHdc windowsDc);
        NODISCARD OpenGLRcHandle GetCreateWglContext(WindowsHdc windowsDc);
        void DeleteWglContextTest(OpenGLRcHandle openGLRcHandle);
        void SetWindowPixelFormatTest(WindowsHdc windowsDc);

    private:
        WindowsHWnd hWnd;
    };
}

#endif  // SYSTEM_WINDOWS_TESTING_OPENGL_SUITE_OPENGL_WGL_PROTOTYPES_TESTING_BASE_H