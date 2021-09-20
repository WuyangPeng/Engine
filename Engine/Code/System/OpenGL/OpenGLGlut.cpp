///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.5 (2021/06/24 20:09)

#include "System/SystemExport.h"

#include "OpenGLGlut.h"
#include "Flags/GlutFlags.h"
#include "System/Helper/WindowsMacro.h"

using std::string;

void System::GlutInit(int* pargc, char** argv) noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)

    ::glutInit(pargc, argv);

#else  // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)

    NullFunction<int*, char**>(pargc, argv);

#endif  // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

int System::GlutCreateWindow(const string& title) noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)

    return ::glutCreateWindow(title.c_str());

#else  // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)

    NullFunction<string>(title);

    return 0;

#endif  // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

void System::GlutInitWindowSize(int width, int height) noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)

    ::glutInitWindowSize(width, height);

#else  // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)

    NullFunction<int, int>(width, height);

#endif  // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

void System::GlutInitContextVersion(int majorVersion, int minorVersion) noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)

    ::glutInitContextVersion(majorVersion, minorVersion);

#else  // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)

    NullFunction<int, int>(majorVersion, minorVersion);

#endif  // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

void System::GlutDestroyWindow(int window) noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)

    ::glutDestroyWindow(window);

#else  // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)

    NullFunction<int>(window);

#endif  // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

void System::GlutSwapBuffers() noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)

    ::glutSwapBuffers();

#else  // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)

#endif  // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

void System::GlutPostWindowRedisplay(int window) noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)

    ::glutPostWindowRedisplay(window);

#else  // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)

    NullFunction<int>(window);

#endif  // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

void System::GlutTimerFunc(unsigned millisecond, TimerFunctionCallback callback, int value) noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)

    ::glutTimerFunc(millisecond, callback, value);

#else  // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)

    NullFunction<unsigned, TimerFunctionCallback, int>(millisecond, callback, int value);

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

void System::GlutInitDisplayMode(bool multiSample) noexcept
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

    NullFunction<bool>(multiSample);

#endif  // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

void System::GlutInitWindowPosition(int x, int y) noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)

    ::glutInitWindowPosition(x, y);

#else  // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)

    NullFunction<int, int>(x, y);

#endif  // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

void System::GlutReshapeFunc(ChangeSizeCallback callback) noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)

    ::glutReshapeFunc(callback);

#else  // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)

    NullFunction<ChangeSizeCallback>(callback);

#endif  // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

void System::GlutDisplayFunc(RenderSceneCallback callback) noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)

    ::glutDisplayFunc(callback);

#else  // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)

    NullFunction<RenderSceneCallback>(callback);

#endif  // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

void System::GlutIdleFunc(IdleFunctionCallback callback) noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)

    ::glutIdleFunc(callback);

#else  // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)

    NullFunction<IdleFunctionCallback>(callback);

#endif  // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

void System::GlutKeyboardFunc(KeyboardDownCallback callback) noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)

    ::glutKeyboardFunc(callback);

#else  // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)

    NullFunction<KeyboardDownCallback>(callback);

#endif  // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

void System::GlutSpecialFunc(SpecialKeysDownCallback callback) noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)

    ::glutSpecialFunc(callback);

#else  // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)

    NullFunction<SpecialKeysDownCallback>(callback);

#endif  // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

void System::GlutKeyboardUpFunc(KeyboardUpCallback callback) noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)

    ::glutKeyboardUpFunc(callback);

#else  // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)

    NullFunction<KeyboardUpCallback>(callback);

#endif  // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

void System::GlutSpecialUpFunc(SpecialKeysUpCallback callback) noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)

    ::glutSpecialUpFunc(callback);

#else  // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)

    NullFunction<SpecialKeysUpCallback>(callback);

#endif  // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

void System::GlutMouseFunc(MouseFunctionCallback callback) noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)

    ::glutMouseFunc(callback);

#else  // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)

    NullFunction<MouseFunctionCallback>(callback);

#endif  // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

void System::GlutMotionFunc(MotionFunctionCallback callback) noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)

    ::glutMotionFunc(callback);

#else  // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)

    NullFunction<MotionFunctionCallback>(callback);

#endif  // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

void System::GlutPassiveMotionFunc(PassiveMotionFunctionCallback callback) noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)

    ::glutPassiveMotionFunc(callback);

#else  // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)

    NullFunction<PassiveMotionFunctionCallback>(callback);

#endif  // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

int System::GlutCreateMenu(ProcessMenuCallback callback) noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)

    return ::glutCreateMenu(callback);

#else  // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)

    NullFunction<ProcessMenuCallback>(callback);

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

void System::GlutSetWindow(int window) noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)

    return ::glutSetWindow(window);

#else  // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)

    NullFunction<int>(window);

#endif  // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

void System::GlutSetOption(GlutOption what, int value) noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)

    return ::glutSetOption(EnumCastUnderlying(what), value);

#else  // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)

    NullFunction<GLenum, int>(what, value);

#endif  // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}
