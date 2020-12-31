//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/25 13:17)

#ifndef SYSTEM_OPENGL_OPENGL_GLUT_H
#define SYSTEM_OPENGL_OPENGL_GLUT_H

#include "System/SystemDll.h"

#include "Flags/GlutKeyCodesFlags.h"
#include "Using/GL11ExtensionsUsing.h"
#include "Using/GlutUsing.h"

#include <string>

namespace System
{
    void SYSTEM_DEFAULT_DECLARE GlutInit(int* pargc, char** argv) noexcept;
    [[nodiscard]] int SYSTEM_DEFAULT_DECLARE GlutCreateWindow(const std::string& title) noexcept;
    void SYSTEM_DEFAULT_DECLARE GlutInitWindowSize(int width, int height) noexcept;
    void SYSTEM_DEFAULT_DECLARE GlutInitContextVersion(int majorVersion, int minorVersion) noexcept;
    void SYSTEM_DEFAULT_DECLARE GlutDestroyWindow(int window) noexcept;
    void SYSTEM_DEFAULT_DECLARE GlutSwapBuffers() noexcept;
    void SYSTEM_DEFAULT_DECLARE GlutPostWindowRedisplay(int window) noexcept;
    void SYSTEM_DEFAULT_DECLARE GlutTimerFunc(unsigned millisecond, TimerFunctionCallback callback, int value) noexcept;

    [[nodiscard]] int SYSTEM_DEFAULT_DECLARE GlutGetModifiers() noexcept;
    void SYSTEM_DEFAULT_DECLARE GlutInitDisplayMode(bool multiSample) noexcept;
    void SYSTEM_DEFAULT_DECLARE GlutInitWindowPosition(int x, int y) noexcept;

    void SYSTEM_DEFAULT_DECLARE GlutReshapeFunc(ChangeSizeCallback callback) noexcept;
    void SYSTEM_DEFAULT_DECLARE GlutDisplayFunc(RenderSceneCallback callback) noexcept;
    void SYSTEM_DEFAULT_DECLARE GlutIdleFunc(IdleFunctionCallback callback) noexcept;
    void SYSTEM_DEFAULT_DECLARE GlutKeyboardFunc(KeyboardDownCallback callback) noexcept;
    void SYSTEM_DEFAULT_DECLARE GlutSpecialFunc(SpecialKeysDownCallback callback) noexcept;
    void SYSTEM_DEFAULT_DECLARE GlutKeyboardUpFunc(KeyboardUpCallback callback) noexcept;
    void SYSTEM_DEFAULT_DECLARE GlutSpecialUpFunc(SpecialKeysUpCallback callback) noexcept;
    void SYSTEM_DEFAULT_DECLARE GlutMouseFunc(MouseFunctionCallback callback) noexcept;
    void SYSTEM_DEFAULT_DECLARE GlutMotionFunc(MotionFunctionCallback callback) noexcept;
    void SYSTEM_DEFAULT_DECLARE GlutPassiveMotionFunc(PassiveMotionFunctionCallback callback) noexcept;
    void SYSTEM_DEFAULT_DECLARE GlutMainLoop() noexcept;
    void SYSTEM_DEFAULT_DECLARE GlutLeaveMainLoop() noexcept;
    [[nodiscard]] int SYSTEM_DEFAULT_DECLARE GlutCreateMenu(ProcessMenuCallback callback) noexcept;

    [[nodiscard]] int SYSTEM_DEFAULT_DECLARE GlutGetWindow() noexcept;
    void SYSTEM_DEFAULT_DECLARE GlutSetWindow(int window) noexcept;

    void SYSTEM_DEFAULT_DECLARE GlutSetOption(GLenum what, int value) noexcept;
}

#endif  // SYSTEM_OPENGL_OPENGL_GLUT_H