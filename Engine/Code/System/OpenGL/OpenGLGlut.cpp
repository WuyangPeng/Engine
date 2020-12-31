//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/26 15:32)

#include "System/SystemExport.h"

#include "OpenGLGlut.h"
#include "Flags/GlutFlags.h"

using std::string;

void System::GlutInit([[maybe_unused]] int* pargc, [[maybe_unused]] char** argv) noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
    ::glutInit(pargc, argv);
#else  // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)

#endif  // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

int System::GlutCreateWindow([[maybe_unused]] const string& title) noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
    return ::glutCreateWindow(title.c_str());
#else  // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)

    return 0;
#endif  // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

void System::GlutInitWindowSize([[maybe_unused]] int width, [[maybe_unused]] int height) noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
    ::glutInitWindowSize(width, height);
#else  // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)

#endif  // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

void System::GlutInitContextVersion([[maybe_unused]] int majorVersion, [[maybe_unused]] int minorVersion) noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
    ::glutInitContextVersion(majorVersion, minorVersion);
#else  // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)

#endif  // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

void System::GlutDestroyWindow([[maybe_unused]] int window) noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
    ::glutDestroyWindow(window);
#else  // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)

#endif  // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

void System::GlutSwapBuffers() noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
    ::glutSwapBuffers();
#else  // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)

#endif  // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

void System::GlutPostWindowRedisplay([[maybe_unused]] int window) noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
    ::glutPostWindowRedisplay(window);
#else  // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)

#endif  // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

void System::GlutTimerFunc([[maybe_unused]] unsigned millisecond, [[maybe_unused]] TimerFunctionCallback callback, [[maybe_unused]] int value) noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
    ::glutTimerFunc(millisecond, callback, value);
#else  // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)

#endif  // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

int System::GlutGetModifiers() noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
    return ::glutGetModifiers();
#else  // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)
    return 0;
#endif  // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

void System::GlutInitDisplayMode([[maybe_unused]] bool multiSample) noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
    constexpr auto glutMacro = GlutMacro::Double | GlutMacro::Rgba | GlutMacro::Depth | GlutMacro::Stencil | GlutMacro::Accum;

    if (multiSample)
    {
        glutInitDisplayMode(EnumCastUnderlying(glutMacro | GlutMacro::Multisample));
    }
    else
    {
        glutInitDisplayMode(EnumCastUnderlying(glutMacro));
    }
#else  // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)

#endif  // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

void System::GlutInitWindowPosition([[maybe_unused]] int x, [[maybe_unused]] int y) noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
    ::glutInitWindowPosition(x, y);
#else  // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)

#endif  // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

void System::GlutReshapeFunc([[maybe_unused]] ChangeSizeCallback callback) noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
    ::glutReshapeFunc(callback);
#else  // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)

#endif  // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

void System::GlutDisplayFunc([[maybe_unused]] RenderSceneCallback callback) noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
    ::glutDisplayFunc(callback);
#else  // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)

#endif  // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

void System::GlutIdleFunc([[maybe_unused]] IdleFunctionCallback callback) noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
    ::glutIdleFunc(callback);
#else  // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)

#endif  // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

void System::GlutKeyboardFunc([[maybe_unused]] KeyboardDownCallback callback) noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
    ::glutKeyboardFunc(callback);
#else  // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)

#endif  // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

void System::GlutSpecialFunc([[maybe_unused]] SpecialKeysDownCallback callback) noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
    ::glutSpecialFunc(callback);
#else  // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)

#endif  // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

void System::GlutKeyboardUpFunc([[maybe_unused]] KeyboardUpCallback callback) noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
    ::glutKeyboardUpFunc(callback);
#else  // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)

#endif  // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

void System::GlutSpecialUpFunc([[maybe_unused]] SpecialKeysUpCallback callback) noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
    ::glutSpecialUpFunc(callback);
#else  // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)

#endif  // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

void System::GlutMouseFunc([[maybe_unused]] MouseFunctionCallback callback) noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
    ::glutMouseFunc(callback);
#else  // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)

#endif  // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

void System::GlutMotionFunc([[maybe_unused]] MotionFunctionCallback callback) noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
    ::glutMotionFunc(callback);
#else  // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)

#endif  // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

void System::GlutPassiveMotionFunc([[maybe_unused]] PassiveMotionFunctionCallback callback) noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
    ::glutPassiveMotionFunc(callback);
#else  // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)

#endif  // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

int System::GlutCreateMenu([[maybe_unused]] ProcessMenuCallback callback) noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
    return ::glutCreateMenu(callback);
#else  // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)

    return 0;
#endif  // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

void System::GlutMainLoop() noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
    ::glutMainLoop();
#else  // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)

#endif  // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

void System::GlutLeaveMainLoop() noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
    ::glutLeaveMainLoop();
#else  // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)

#endif  // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

int System::GlutGetWindow() noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
    return ::glutGetWindow();
#else  // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)
    return 0;
#endif  // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

void System::GlutSetWindow([[maybe_unused]] int window) noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
    return ::glutSetWindow(window);
#else  // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)

#endif  // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

void System::GlutSetOption([[maybe_unused]] GLenum what, [[maybe_unused]] int value) noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
    return ::glutSetOption(what, value);
#else  // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)

#endif  // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}
