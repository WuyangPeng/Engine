/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 14:54)

#ifndef FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_PROCESS_DETAIL_H
#define FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_PROCESS_DETAIL_H

#include "OpenGLGlutProcess.h"
#include "OpenGLGlutProcessManager.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

template <typename OpenGLGlutCallBack>
Framework::OpenGLGlutProcess<OpenGLGlutCallBack>::OpenGLGlutProcess(int64_t delta)
{
    auto openGLGlutCallBack = std::make_shared<OpenGLGlutCallBack>(delta);

    OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.SetOpenGLGlutCallBack(openGLGlutCallBack);

    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename OpenGLGlutCallBack>
bool Framework::OpenGLGlutProcess<OpenGLGlutCallBack>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename OpenGLGlutCallBack>
int Framework::OpenGLGlutProcess<OpenGLGlutCallBack>::GetMillisecond() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.GetMillisecond();
}

template <typename OpenGLGlutCallBack>
void Framework::OpenGLGlutProcess<OpenGLGlutCallBack>::SetMillisecond(int millisecond)
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.SetMillisecond(millisecond);
}

template <typename OpenGLGlutCallBack>
typename Framework::OpenGLGlutProcess<OpenGLGlutCallBack>::RenderSceneCallback Framework::OpenGLGlutProcess<OpenGLGlutCallBack>::GetRenderSceneCallback() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return OpenGLGlutProcessManager::GetRenderSceneCallback();
}

template <typename OpenGLGlutCallBack>
typename Framework::OpenGLGlutProcess<OpenGLGlutCallBack>::ChangeSizeCallback Framework::OpenGLGlutProcess<OpenGLGlutCallBack>::GetChangeSizeCallback() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return OpenGLGlutProcessManager::GetChangeSizeCallback();
}

template <typename OpenGLGlutCallBack>
typename Framework::OpenGLGlutProcess<OpenGLGlutCallBack>::TimerFunctionCallback Framework::OpenGLGlutProcess<OpenGLGlutCallBack>::GetTimerFunctionCallback() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return OpenGLGlutProcessManager::GetTimerFunctionCallback();
}

template <typename OpenGLGlutCallBack>
typename Framework::OpenGLGlutProcess<OpenGLGlutCallBack>::SpecialKeysDownCallback Framework::OpenGLGlutProcess<OpenGLGlutCallBack>::GetSpecialKeysDownCallback() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return OpenGLGlutProcessManager::GetSpecialKeysDownCallback();
}

template <typename OpenGLGlutCallBack>
typename Framework::OpenGLGlutProcess<OpenGLGlutCallBack>::KeyboardDownCallback Framework::OpenGLGlutProcess<OpenGLGlutCallBack>::GetKeyboardDownCallback() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return OpenGLGlutProcessManager::GetKeyboardDownCallback();
}

template <typename OpenGLGlutCallBack>
typename Framework::OpenGLGlutProcess<OpenGLGlutCallBack>::SpecialKeysUpCallback Framework::OpenGLGlutProcess<OpenGLGlutCallBack>::GetSpecialKeysUpCallback() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return OpenGLGlutProcessManager::GetSpecialKeysUpCallback();
}

template <typename OpenGLGlutCallBack>
typename Framework::OpenGLGlutProcess<OpenGLGlutCallBack>::KeyboardUpCallback Framework::OpenGLGlutProcess<OpenGLGlutCallBack>::GetKeyboardUpCallback() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return OpenGLGlutProcessManager::GetKeyboardUpCallback();
}

template <typename OpenGLGlutCallBack>
typename Framework::OpenGLGlutProcess<OpenGLGlutCallBack>::MouseFunctionCallback Framework::OpenGLGlutProcess<OpenGLGlutCallBack>::GetMouseFunctionCallback() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return OpenGLGlutProcessManager::GetMouseFunctionCallback();
}

template <typename OpenGLGlutCallBack>
typename Framework::OpenGLGlutProcess<OpenGLGlutCallBack>::MotionFunctionCallback Framework::OpenGLGlutProcess<OpenGLGlutCallBack>::GetMotionFunctionCallback() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return OpenGLGlutProcessManager::GetMotionFunctionCallback();
}

template <typename OpenGLGlutCallBack>
typename Framework::OpenGLGlutProcess<OpenGLGlutCallBack>::PassiveMotionFunctionCallback Framework::OpenGLGlutProcess<OpenGLGlutCallBack>::GetPassiveMotionCallback() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return OpenGLGlutProcessManager::GetPassiveMotionCallback();
}

template <typename OpenGLGlutCallBack>
typename Framework::OpenGLGlutProcess<OpenGLGlutCallBack>::IdleFunctionCallback Framework::OpenGLGlutProcess<OpenGLGlutCallBack>::GetIdleFunctionCallback() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return OpenGLGlutProcessManager::GetIdleFunctionCallback();
}

template <typename OpenGLGlutCallBack>
typename Framework::OpenGLGlutProcess<OpenGLGlutCallBack>::ProcessMenuCallback Framework::OpenGLGlutProcess<OpenGLGlutCallBack>::GetProcessMenuCallback() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return OpenGLGlutProcessManager::GetProcessMenuCallback();
}

template <typename OpenGLGlutCallBack>
typename Framework::OpenGLGlutProcess<OpenGLGlutCallBack>::TerminateCallback Framework::OpenGLGlutProcess<OpenGLGlutCallBack>::GetTerminateCallback() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return OpenGLGlutProcessManager::GetTerminateCallback();
}

template <typename OpenGLGlutCallBack>
void Framework::OpenGLGlutProcess<OpenGLGlutCallBack>::SetWindowId(int window)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.SetWindowId(window);
}

template <typename OpenGLGlutCallBack>
int Framework::OpenGLGlutProcess<OpenGLGlutCallBack>::GetWindowId() const
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.GetWindowId();
}

template <typename OpenGLGlutCallBack>
bool Framework::OpenGLGlutProcess<OpenGLGlutCallBack>::PreCreate()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.PreCreate();
}

template <typename OpenGLGlutCallBack>
bool Framework::OpenGLGlutProcess<OpenGLGlutCallBack>::Initialize()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.Initialize();
}

template <typename OpenGLGlutCallBack>
void Framework::OpenGLGlutProcess<OpenGLGlutCallBack>::PreIdle()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.PreIdle();
}

template <typename OpenGLGlutCallBack>
void Framework::OpenGLGlutProcess<OpenGLGlutCallBack>::Terminate()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    OPENGL_GLUT_PROCESS_MANAGER_SINGLETON.Terminate();
}

#endif  // FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_PROCESS_DETAIL_H
