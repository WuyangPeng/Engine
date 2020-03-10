// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:36)

#ifndef SYSTEM_OPENGL_OPENGL_GLUT_FWD_H
#define SYSTEM_OPENGL_OPENGL_GLUT_FWD_H  

#include "System/OpenGL/Using/GlutUsing.h"

namespace System
{
	void GlutInit(int* pargc, char** argv) noexcept;
	int GlutCreateWindow(const std::string& title) noexcept;
	void GlutInitWindowSize(int width, int height) noexcept;
	void GlutInitContextVersion(int majorVersion, int minorVersion) noexcept;
	void GlutDestroyWindow(int window) noexcept;
	void GlutSwapBuffers() noexcept;
	void GlutPostWindowRedisplay(int window) noexcept;
	void GlutTimerFunc(unsigned millisecond, TimerFunctionCallback callback, int value) noexcept;

	int GlutGetModifiers() noexcept;
	void GlutInitDisplayMode(bool multiSample) noexcept;
	void GlutInitWindowPosition(int x, int y) noexcept;

	void GlutReshapeFunc(ChangeSizeCallback callback) noexcept;
	void GlutDisplayFunc(RenderSceneCallback callback) noexcept;
	void GlutIdleFunc(IdleFunctionCallback callback) noexcept;
	void GlutKeyboardFunc(KeyboardDownCallback callback) noexcept;
	void GlutSpecialFunc(SpecialKeysDownCallback callback) noexcept;
	void GlutKeyboardUpFunc(KeyboardUpCallback callback) noexcept;
	void GlutSpecialUpFunc(SpecialKeysUpCallback callback) noexcept;
	void GlutMouseFunc(MouseFunctionCallback callback) noexcept;
	void GlutMotionFunc(MotionFunctionCallback callback) noexcept;
	void GlutPassiveMotionFunc(PassiveMotionFunctionCallback callback) noexcept;
	void GlutMainLoop() noexcept;
	void GlutLeaveMainLoop() noexcept;
	int GlutCreateMenu(ProcessMenuCallback callback) noexcept;

	int GlutGetWindow() noexcept;
	void GlutSetWindow(int window) noexcept;

	void GlutSetOption(GLenum what, int value) noexcept;
}

#endif // SYSTEM_OPENGL_OPENGL_GLUT_FWD_H