// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:49)

#include "System/SystemExport.h"

#include "OpenGLGlut.h"
#include "Flags/GlutFlags.h"
#include "System/Helper/UnusedMacro.h"

using std::string;

void System
	::GlutInit(int* pargc, char** argv) noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
	::glutInit(pargc, argv);
#else // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)
	SYSTEM_UNUSED_ARG(pargc);
	SYSTEM_UNUSED_ARG(argv);
#endif // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

int System
	::GlutCreateWindow(const string& title) noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
	return ::glutCreateWindow(title.c_str());
#else // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)
	SYSTEM_UNUSED_ARG(title);

	return 0;
#endif // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

void System
	::GlutInitWindowSize(int width, int height) noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
	::glutInitWindowSize(width, height);
#else // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)
	SYSTEM_UNUSED_ARG(width);
	SYSTEM_UNUSED_ARG(height);
#endif // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

void System
	::GlutInitContextVersion(int majorVersion, int minorVersion) noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
	::glutInitContextVersion(majorVersion, minorVersion);
#else // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)
	SYSTEM_UNUSED_ARG(majorVersion);
	SYSTEM_UNUSED_ARG(minorVersion);
#endif // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

void System
	::GlutDestroyWindow(int window) noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
	::glutDestroyWindow(window);
#else // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)
	SYSTEM_UNUSED_ARG(window);
#endif // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

void System
	::GlutSwapBuffers() noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
	::glutSwapBuffers();
#else // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)

#endif // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

void System
	::GlutPostWindowRedisplay(int window) noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
	::glutPostWindowRedisplay(window);
#else // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)
	SYSTEM_UNUSED_ARG(window);
#endif // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

void System
	::GlutTimerFunc(unsigned millisecond, TimerFunctionCallback callback, int value) noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
	::glutTimerFunc(millisecond, callback, value);
#else // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)
	SYSTEM_UNUSED_ARG(millisecond);
	SYSTEM_UNUSED_ARG(callback);
	SYSTEM_UNUSED_ARG(value);
#endif // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

int System
	::GlutGetModifiers() noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
	return ::glutGetModifiers();
#else // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)
	return 0;
#endif // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

void System
	::GlutInitDisplayMode(bool multiSample) noexcept
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
#else // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)
	SYSTEM_UNUSED_ARG(multiSample);
#endif // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

void System
	::GlutInitWindowPosition(int x, int y) noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
	::glutInitWindowPosition(x, y);
#else // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)
	SYSTEM_UNUSED_ARG(x);
	SYSTEM_UNUSED_ARG(y);
#endif // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

void System
	::GlutReshapeFunc(ChangeSizeCallback callback) noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
	::glutReshapeFunc(callback);
#else // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)
	SYSTEM_UNUSED_ARG(callback);
#endif // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

void System
	::GlutDisplayFunc(RenderSceneCallback callback) noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
	::glutDisplayFunc(callback);
#else // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)
	SYSTEM_UNUSED_ARG(callback);
#endif // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

void System
	::GlutIdleFunc(IdleFunctionCallback callback) noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
	::glutIdleFunc(callback);
#else // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)
	SYSTEM_UNUSED_ARG(callback);
#endif // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

void System
	::GlutKeyboardFunc(KeyboardDownCallback callback) noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
	::glutKeyboardFunc(callback);
#else // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)
	SYSTEM_UNUSED_ARG(callback);
#endif // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

void System
	::GlutSpecialFunc(SpecialKeysDownCallback callback) noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
	::glutSpecialFunc(callback);
#else // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)
	SYSTEM_UNUSED_ARG(callback);
#endif // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

void System
	::GlutKeyboardUpFunc(KeyboardUpCallback callback) noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
	::glutKeyboardUpFunc(callback);
#else // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)
	SYSTEM_UNUSED_ARG(callback);
#endif // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

void System
	::GlutSpecialUpFunc(SpecialKeysUpCallback callback) noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
	::glutSpecialUpFunc(callback);
#else // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)
	SYSTEM_UNUSED_ARG(callback);
#endif // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

void System
	::GlutMouseFunc(MouseFunctionCallback callback) noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
	::glutMouseFunc(callback);
#else // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)
	SYSTEM_UNUSED_ARG(callback);
#endif // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

void System
	::GlutMotionFunc(MotionFunctionCallback callback) noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
	::glutMotionFunc(callback);
#else // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)
	SYSTEM_UNUSED_ARG(callback);
#endif // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

void System
	::GlutPassiveMotionFunc(PassiveMotionFunctionCallback callback) noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
	::glutPassiveMotionFunc(callback);
#else // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)
	SYSTEM_UNUSED_ARG(callback);
#endif // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

int System
	::GlutCreateMenu(ProcessMenuCallback callback) noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
	return ::glutCreateMenu(callback);
#else // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)
	SYSTEM_UNUSED_ARG(callback);

	return 0;
#endif // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

void System
	::GlutMainLoop() noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32) 
	::glutMainLoop();
#else // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)

#endif // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

void System
	::GlutLeaveMainLoop() noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32) 
	::glutLeaveMainLoop();
#else // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)

#endif // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

int System
	::GlutGetWindow() noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32) 
	return ::glutGetWindow();
#else // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)
	return 0;
#endif // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

void System
	::GlutSetWindow(int window) noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32) 
	return ::glutSetWindow(window);
#else // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)
	SYSTEM_UNUSED_ARG(window);
#endif // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}

void System
	::GlutSetOption(GLenum what, int value) noexcept
{
#if defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32) 
	return ::glutSetOption(what, value);
#else // !defined(SYSTEM_USE_GLUT) || !defined(SYSTEM_PLATFORM_WIN32)
	SYSTEM_UNUSED_ARG(what);
	SYSTEM_UNUSED_ARG(value);
#endif // defined(SYSTEM_USE_GLUT) && defined(SYSTEM_PLATFORM_WIN32)
}
