///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/13 14:17)

#include "Framework/FrameworkExport.h"

#include "OpenGLGlutCallBackInterface.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/OpenGL/OpenGLBase.h"
#include "System/OpenGL/OpenGLGlut.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/Assertion/FrameworkCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/Application/Flags/ApplicationTrait.h"
#include "Framework/WindowProcess/Flags/MouseTypes.h"

Framework::OpenGLGlutCallBackInterface::OpenGLGlutCallBackInterface(int64_t delta) noexcept
    : windowID{ 0 }, millisecond{ 0 }, delta{ delta }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Framework::OpenGLGlutCallBackInterface::IsValid() const noexcept
{
    if (0 <= windowID)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

int Framework::OpenGLGlutCallBackInterface::GetWindowID() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return windowID;
}

void Framework::OpenGLGlutCallBackInterface::SetWindowID(int window)
{
    FRAMEWORK_CLASS_IS_VALID_1;
    FRAMEWORK_ASSERTION_0(window != 0, "设置的窗口ID为零！");
    FRAMEWORK_ASSERTION_2(windowID == 0 || windowID == window, "不允许重复设置窗口ID!");

    windowID = window;
}

void Framework::OpenGLGlutCallBackInterface::SetMillisecond(int aMillisecond) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_1;

    millisecond = aMillisecond;
}

int64_t Framework::OpenGLGlutCallBackInterface::GetDelta() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return delta;
}

bool Framework::OpenGLGlutCallBackInterface::PreCreate()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    CoreTools::DisableNoexcept();

    return true;
}

bool Framework::OpenGLGlutCallBackInterface::Initialize()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    CoreTools::DisableNoexcept();

    return true;
}

void Framework::OpenGLGlutCallBackInterface::PreIdle()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    CoreTools::DisableNoexcept();
}

void Framework::OpenGLGlutCallBackInterface::Terminate()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    CoreTools::DisableNoexcept();
}

bool Framework::OpenGLGlutCallBackInterface::RenderScene()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    System::ClearAllGLBufferBit();

    System::GlutSwapBuffers();

    CoreTools::DisableNoexcept();

    return true;
}

bool Framework::OpenGLGlutCallBackInterface::ChangeSize(int width, int height)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    System::GlutPostWindowRedisplay(windowID);
    System::SetGLViewport(0, 0, boost::numeric_cast<System::OpenGLSize>(width), boost::numeric_cast<System::OpenGLSize>(height));

    CoreTools::DisableNoexcept();

    return true;
}

bool Framework::OpenGLGlutCallBackInterface::SpecialKeysDown([[maybe_unused]] int key, [[maybe_unused]] int xCoordinate, [[maybe_unused]] int yCoordinate)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    System::GlutPostWindowRedisplay(windowID);

    CoreTools::DisableNoexcept();

    return true;
}

bool Framework::OpenGLGlutCallBackInterface::KeyboardDown([[maybe_unused]] int key, [[maybe_unused]] int xCoordinate, [[maybe_unused]] int yCoordinate)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    System::GlutPostWindowRedisplay(windowID);

    CoreTools::DisableNoexcept();

    return true;
}

bool Framework::OpenGLGlutCallBackInterface::SpecialKeysUp([[maybe_unused]] int key, [[maybe_unused]] int xCoordinate, [[maybe_unused]] int yCoordinate)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    System::GlutPostWindowRedisplay(windowID);

    CoreTools::DisableNoexcept();

    return true;
}

bool Framework::OpenGLGlutCallBackInterface::KeyboardUp([[maybe_unused]] int key, [[maybe_unused]] int xCoordinate, [[maybe_unused]] int yCoordinate)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    System::GlutPostWindowRedisplay(windowID);

    CoreTools::DisableNoexcept();

    return true;
}

bool Framework::OpenGLGlutCallBackInterface::PassiveMotion([[maybe_unused]] int xCoordinate, [[maybe_unused]] int yCoordinate)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    System::GlutPostWindowRedisplay(windowID);

    CoreTools::DisableNoexcept();

    return true;
}

bool Framework::OpenGLGlutCallBackInterface::MouseClick([[maybe_unused]] int button, [[maybe_unused]] int state, [[maybe_unused]] int xCoordinate, [[maybe_unused]] int yCoordinate)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    System::GlutPostWindowRedisplay(windowID);

    CoreTools::DisableNoexcept();

    return true;
}

bool Framework::OpenGLGlutCallBackInterface::MotionFunction([[maybe_unused]] int xCoordinate, [[maybe_unused]] int yCoordinate)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    System::GlutPostWindowRedisplay(windowID);

    CoreTools::DisableNoexcept();

    return true;
}

bool Framework::OpenGLGlutCallBackInterface::IdleFunction()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    System::GlutPostWindowRedisplay(windowID);

    CoreTools::DisableNoexcept();

    return true;
}

bool Framework::OpenGLGlutCallBackInterface::TimerFunction(TimerFunctionCallback callback)
{
    FRAMEWORK_CLASS_IS_VALID_1;
    FRAMEWORK_ASSERTION_1(callback != nullptr, "函数指针不能为空！");

    System::GlutPostWindowRedisplay(windowID);
    System::GlutTimerFunc(GetMillisecond(), callback, 1);

    CoreTools::DisableNoexcept();

    return true;
}

bool Framework::OpenGLGlutCallBackInterface::ProcessMenu([[maybe_unused]] int menuValue)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    CoreTools::DisableNoexcept();

    return true;
}

void Framework::OpenGLGlutCallBackInterface::DestroyWindow()
{
    FRAMEWORK_CLASS_IS_VALID_1;
    FRAMEWORK_ASSERTION_0(windowID != 0, "窗口ID为零！");

    const auto window = windowID;
    windowID = 0;

    System::GlutDestroyWindow(window);
}

int Framework::OpenGLGlutCallBackInterface::GetMillisecond() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return millisecond;
}

int Framework::OpenGLGlutCallBackInterface::GetTerminateKey() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return GlutApplicationTrait::KeyIdentifiers::keyTerminate;
}

// protected
Framework::MouseButtonsTypes Framework::OpenGLGlutCallBackInterface::GetMouseButtonsTypes(int button) noexcept
{
    switch (button)
    {
        case GlutApplicationTrait::MouseButtons::mouseLeftButton:
            return MouseButtonsTypes::LeftButton;
        case GlutApplicationTrait::MouseButtons::mouseMiddleButton:
            return MouseButtonsTypes::MiddleButton;
        case GlutApplicationTrait::MouseButtons::mouseRightButton:
            return MouseButtonsTypes::RightButton;
        default:
            return MouseButtonsTypes::NullButton;
    }
}

// protected
Framework::MouseStateTypes Framework::OpenGLGlutCallBackInterface::GetMouseStateTypes(int state) noexcept
{
    switch (state)
    {
        case GlutApplicationTrait::MouseState::mouseUp:
            return MouseStateTypes::MouseUp;
        case GlutApplicationTrait::MouseState::mouseDown:
            return MouseStateTypes::MouseDown;
        default:
            return MouseStateTypes::MouseNull;
    }
}