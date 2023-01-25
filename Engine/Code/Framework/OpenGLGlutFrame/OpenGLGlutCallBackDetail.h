///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/07 13:59)

#ifndef FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_CALL_BACK_DETAIL_H
#define FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_CALL_BACK_DETAIL_H

#include "OpenGLGlutCallBack.h"
#include "System/OpenGL/OpenGLBase.h"
#include "System/OpenGL/OpenGLGlut.h"
#include "System/Windows/Flags/WindowsDisplayFlags.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/Application/Flags/ApplicationTrait.h"
#include "Framework/MiddleLayer/Flags/MiddleLayerPlatformFlags.h"
#include "Framework/WindowCreate/WindowPoint.h"
#include "Framework/WindowCreate/WindowSize.h"
#include "Framework/WindowProcess/Flags/MouseTypes.h"

template <typename MiddleLayer>
Framework::OpenGLGlutCallBack<MiddleLayer>::OpenGLGlutCallBack(int64_t delta, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ delta },
      middleLayer{ MiddleLayerType::CreateMiddleLayer(MiddleLayerPlatform::Windows, environmentDirectory) },
      lastTime{},
      glutModifiers{},
      button{ MouseButtonsTypes::NullButton },
      accumulative{ 0 }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename MiddleLayer>
bool Framework::OpenGLGlutCallBack<MiddleLayer>::IsValid() const noexcept
{
    if (ParentType::IsValid() && middleLayer != nullptr)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename MiddleLayer>
bool Framework::OpenGLGlutCallBack<MiddleLayer>::RenderScene()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    System::ClearAllGLBufferBit();

    if (!middleLayer->Paint())
    {
        DestroyWindow();

        return false;
    }

    System::GlutSwapBuffers();

    return true;
}

template <typename MiddleLayer>
bool Framework::OpenGLGlutCallBack<MiddleLayer>::ChangeSize(int width, int height)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (!(ParentType::ChangeSize(width, height) &&
          middleLayer->Resize(System::WindowsDisplay::GLUTUnDefinition, WindowSize(width, height)) &&
          middleLayer->Paint()))
    {
        DestroyWindow();

        return false;
    }

    return true;
}

template <typename MiddleLayer>
bool Framework::OpenGLGlutCallBack<MiddleLayer>::IdleFunction()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    const auto timeDelta = lastTime.GetThisElapsedTime();

    accumulative += timeDelta;

    if (GetDelta() <= accumulative)
    {
        if (!(ParentType::IdleFunction() && middleLayer->Idle(timeDelta)))
        {
            DestroyWindow();

            return false;
        }

        accumulative = 0;
    }

    return true;
}

template <typename MiddleLayer>
bool Framework::OpenGLGlutCallBack<MiddleLayer>::TimerFunction(TimerFunctionCallback callback)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (!(ParentType::TimerFunction(callback)))
    {
        DestroyWindow();

        return false;
    }

    return true;
}

template <typename MiddleLayer>
bool Framework::OpenGLGlutCallBack<MiddleLayer>::SpecialKeysDown(int key, int xCoordinate, int yCoordinate)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (!(ParentType::SpecialKeysDown(key, xCoordinate, yCoordinate) &&
          middleLayer->SpecialKeyDown(key, WindowPoint{ xCoordinate, yCoordinate })))
    {
        DestroyWindow();

        return false;
    }

    return true;
}

template <typename MiddleLayer>
bool Framework::OpenGLGlutCallBack<MiddleLayer>::KeyboardDown(int key, int xCoordinate, int yCoordinate)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (!(ParentType::KeyboardDown(key, xCoordinate, yCoordinate) &&
          key != GetTerminateKey() &&
          middleLayer->KeyDown(key, WindowPoint{ xCoordinate, yCoordinate })))
    {
        DestroyWindow();

        return false;
    }

    return true;
}

template <typename MiddleLayer>
bool Framework::OpenGLGlutCallBack<MiddleLayer>::SpecialKeysUp(int key, int xCoordinate, int yCoordinate)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (!(ParentType::SpecialKeysUp(key, xCoordinate, yCoordinate) &&
          middleLayer->SpecialKeyUp(key, WindowPoint{ xCoordinate, yCoordinate })))
    {
        DestroyWindow();

        return false;
    }

    return true;
}

template <typename MiddleLayer>
bool Framework::OpenGLGlutCallBack<MiddleLayer>::KeyboardUp(int key, int xCoordinate, int yCoordinate)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (!(ParentType::KeyboardUp(key, xCoordinate, yCoordinate) &&
          middleLayer->KeyUp(key, WindowPoint{ xCoordinate, yCoordinate })))
    {
        DestroyWindow();

        return false;
    }

    return true;
}

template <typename MiddleLayer>
bool Framework::OpenGLGlutCallBack<MiddleLayer>::MotionFunction(int xCoordinate, int yCoordinate)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (!(ParentType::MotionFunction(xCoordinate, yCoordinate) &&
          middleLayer->Motion(WindowPoint{ xCoordinate, yCoordinate }, glutModifiers)))
    {
        DestroyWindow();

        return false;
    }

    return true;
}

template <typename MiddleLayer>
bool Framework::OpenGLGlutCallBack<MiddleLayer>::PassiveMotion(int xCoordinate, int yCoordinate)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (!(ParentType::PassiveMotion(xCoordinate, yCoordinate) &&
          middleLayer->PassiveMotion(WindowPoint{ xCoordinate, yCoordinate })))
    {
        DestroyWindow();

        return false;
    }

    return true;
}

template <typename MiddleLayer>
bool Framework::OpenGLGlutCallBack<MiddleLayer>::MouseClick(int aButton, int state, int xCoordinate, int yCoordinate)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    SetGLUTModifiers(aButton, state);

    const auto buttonType = GetMouseButtonsTypes(aButton);
    const auto stateType = GetMouseStateTypes(state);

    if (!(ParentType::MouseClick(aButton, state, xCoordinate, yCoordinate) &&
          middleLayer->MouseClick(buttonType, stateType, WindowPoint{ xCoordinate, yCoordinate }, glutModifiers)))
    {
        DestroyWindow();

        return false;
    }

    return true;
}

// private
template <typename MiddleLayer>
void Framework::OpenGLGlutCallBack<MiddleLayer>::SetGLUTModifiers(int aButton, int state) noexcept
{
    const auto modifiers = System::GlutGetModifiers();
    glutModifiers.SetModifiers(modifiers);

    if (state == GlutApplicationTrait::MouseState::mouseDown)
        glutModifiers.SetMouseButtonsTypes(aButton);
    else
        glutModifiers.ClearMouseButtonsTypes();
}

template <typename MiddleLayer>
bool Framework::OpenGLGlutCallBack<MiddleLayer>::ProcessMenu(int menuValue)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (!(ParentType::ProcessMenu(menuValue)))
    {
        DestroyWindow();

        return false;
    }

    return true;
}

template <typename MiddleLayer>
void Framework::OpenGLGlutCallBack<MiddleLayer>::DestroyWindow()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    middleLayer->Destroy();

    ParentType::DestroyWindow();
}

#endif  // FRAMEWORK_OPENGL_GLUT_FRAME_OPENGL_GLUT_CALL_BACK_DETAIL_H
