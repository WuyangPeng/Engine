/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 15:30)

#include "Framework/FrameworkExport.h"

#include "AndroidProcessManagerImpl.h"
#include "System/Android/AndroidInputEventFacade.h"
#include "System/Android/AndroidInputMotionEventFacade.h"
#include "System/Android/Flags/AndroidInputFlags.h"
#include "System/Android/Flags/AndroidNativeAppGlueFlags.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MainFunctionMacro.h"
#include "Framework/AndroidFrame/AndroidCallBackInterface.h"

Framework::AndroidProcessManagerImpl::AndroidCallBackInterfaceSharedPtr Framework::AndroidProcessManagerImpl::androidCallBack{};

CLASS_INVARIANT_STUB_DEFINE(Framework, AndroidProcessManagerImpl)

Framework::AndroidProcessManagerImpl::AndroidCallBackInterfaceSharedPtr Framework::AndroidProcessManagerImpl::GetAndroidCallBackInterface() noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return androidCallBack;
}

void Framework::AndroidProcessManagerImpl::SetAndroidCallBack(const AndroidCallBackInterfaceSharedPtr& aAndroidCallBack) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    androidCallBack = aAndroidCallBack;
}

void Framework::AndroidProcessManagerImpl::ClearAndroidCallBack() noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    androidCallBack.reset();
}

bool Framework::AndroidProcessManagerImpl::PreCreate()
{
    if (androidCallBack != nullptr)
    {
        return androidCallBack->PreCreate();
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("AndroidCallBack指针为空！"s))
    }
}

bool Framework::AndroidProcessManagerImpl::Initialize()
{
    if (androidCallBack != nullptr)
    {
        return androidCallBack->Initialize();
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("AndroidCallBack指针为空！"s))
    }
}

void Framework::AndroidProcessManagerImpl::PreIdle()
{
    if (androidCallBack != nullptr)
    {
        androidCallBack->PreIdle();
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("AndroidCallBack指针为空！"s))
    }
}

void Framework::AndroidProcessManagerImpl::Terminate()
{
    if (androidCallBack != nullptr)
    {
        androidCallBack->Terminate();
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("AndroidCallBack指针为空！"s))
    }
}

int Framework::AndroidProcessManagerImpl::HandleInput(AndroidApp* app, AndroidInputEvent* event)
{
    const System::AndroidInputEventFacade androidInputEvent{ event };

    switch (const auto eventType = androidInputEvent.GetType();
            eventType)
    {
        case System::AndroidInputEventType::Key:
            // 消息来自按键事件
            return HandleKeyInput(app, event);
        case System::AndroidInputEventType::Motion:
            // 消息来自移动事件
            return HandleMotionInput(app, event);
        default:
            return 0;
    }
}

void Framework::AndroidProcessManagerImpl::HandleCmd(AndroidApp* androidApp, int cmd)
{
    const auto handleCmdFunctionPointer = GetHandleCmdFunctionPointer();

    if (const auto iter = handleCmdFunctionPointer->find(System::UnderlyingCastEnum<AppCmd>(cmd));
        androidCallBack != nullptr && iter != handleCmdFunctionPointer->cend())
    {
        return ((*androidCallBack).*(iter->second))(androidApp);
    }
    else
    {
        return NotDealMessage(androidApp);
    }
}

void Framework::AndroidProcessManagerImpl::Display(AndroidApp* androidApp, int64_t timeDelta)
{
    if (androidCallBack != nullptr)
    {
        androidCallBack->Display(androidApp, timeDelta);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("AndroidCallBack指针为空！"s))
    }
}

int Framework::AndroidProcessManagerImpl::HandleKeyInput(AndroidApp* androidApp, AndroidInputEvent* event)
{
    const auto handleKeyInputFunctionPointer = GetKeyHandleInputFunctionPointer();
    const System::AndroidInputEventFacade androidKeyEvent{ event };
    const auto id = androidKeyEvent.GetAction();

    if (const auto iter = handleKeyInputFunctionPointer->find(id);
        androidCallBack != nullptr && iter != handleKeyInputFunctionPointer->cend())
    {
        return ((*androidCallBack).*(iter->second))(androidApp, event);
    }
    else
    {
        return NotDealMessage(androidApp, event);
    }
}

int Framework::AndroidProcessManagerImpl::HandleMotionInput(AndroidApp* androidApp, AndroidInputEvent* event)
{
    const auto handleMotionInputFunctionPointer = GetMotionHandleInputFunctionPointer();

    const System::AndroidInputMotionEventFacade androidKeyEvent{ event };
    const auto id = androidKeyEvent.GetAction();

    if (const auto iter = handleMotionInputFunctionPointer->find(id);
        androidCallBack != nullptr && iter != handleMotionInputFunctionPointer->cend())
    {
        return ((*androidCallBack).*(iter->second))(androidApp, event);
    }
    else
    {
        return NotDealMessage(androidApp, event);
    }
}

void Framework::AndroidProcessManagerImpl::NotDealMessage(const AndroidApp* androidApp) noexcept
{
    UnusedFunction(androidApp);
}

int Framework::AndroidProcessManagerImpl::NotDealMessage(const AndroidApp* androidApp, const AndroidInputEvent* event) noexcept
{
    UnusedFunction(androidApp, event);

    return 0;
}

Framework::AndroidProcessManagerImpl::HandleCmdFunctionPointerSharedPtr Framework::AndroidProcessManagerImpl::GetHandleCmdFunctionPointer()
{
    static const HandleCmdFunctionPointerContainer handleCmdFunctionPointerContainer{ { AppCmd::InputChanged, &AndroidCallBackInterface::NotDealCmdMessage },
                                                                                      { AppCmd::InitWindow, &AndroidCallBackInterface::InitMessage },
                                                                                      { AppCmd::TermWindow, &AndroidCallBackInterface::TermMessage },
                                                                                      { AppCmd::WindowResized, &AndroidCallBackInterface::ResizedMessage },
                                                                                      { AppCmd::WindowRedrawNeeded, &AndroidCallBackInterface::RedrawNeededMessage },
                                                                                      { AppCmd::ContentRectChanged, &AndroidCallBackInterface::RectChanged },
                                                                                      { AppCmd::GainedFocus, &AndroidCallBackInterface::NotDealCmdMessage },
                                                                                      { AppCmd::LostFocus, &AndroidCallBackInterface::NotDealCmdMessage },
                                                                                      { AppCmd::ConfigChanged, &AndroidCallBackInterface::NotDealCmdMessage },
                                                                                      { AppCmd::LowMemory, &AndroidCallBackInterface::NotDealCmdMessage },
                                                                                      { AppCmd::Start, &AndroidCallBackInterface::NotDealCmdMessage },
                                                                                      { AppCmd::Resume, &AndroidCallBackInterface::NotDealCmdMessage },
                                                                                      { AppCmd::SaveState, &AndroidCallBackInterface::NotDealCmdMessage },
                                                                                      { AppCmd::Pause, &AndroidCallBackInterface::NotDealCmdMessage },
                                                                                      { AppCmd::Stop, &AndroidCallBackInterface::NotDealCmdMessage },
                                                                                      { AppCmd::Destroy, &AndroidCallBackInterface::NotDealCmdMessage } };

    static HandleCmdFunctionPointerSharedPtr functionPointer = make_shared<HandleCmdFunctionPointerContainer>(handleCmdFunctionPointerContainer);

    return functionPointer;
}

Framework::AndroidProcessManagerImpl::KeyHandleInputFunctionPointerSharedPtr Framework::AndroidProcessManagerImpl::GetKeyHandleInputFunctionPointer()
{
    static const KeyHandleInputFunctionPointerContainer keyHandleInputFunctionPointerContainer{ { AndroidKeyEventAction::Down, &AndroidCallBackInterface::KeyDownMessage },
                                                                                                { AndroidKeyEventAction::Up, &AndroidCallBackInterface::KeyUpMessage },
                                                                                                { AndroidKeyEventAction::Multiple, &AndroidCallBackInterface::NotDealInputMessage } };

    static KeyHandleInputFunctionPointerSharedPtr functionPointer = make_shared<KeyHandleInputFunctionPointerContainer>(keyHandleInputFunctionPointerContainer);

    return functionPointer;
}

Framework::AndroidProcessManagerImpl::MotionHandleInputFunctionPointerSharedPtr Framework::AndroidProcessManagerImpl::GetMotionHandleInputFunctionPointer()
{
    static const MotionHandleInputFunctionPointerContainer motionHandleInputFunctionPointerContainer{ { AndroidMotionEventAction::Down, &AndroidCallBackInterface::ActionDownMessage },
                                                                                                      { AndroidMotionEventAction::Up, &AndroidCallBackInterface::ActionUpMessage },
                                                                                                      { AndroidMotionEventAction::Move, &AndroidCallBackInterface::ActionMoveMessage },
                                                                                                      { AndroidMotionEventAction::Cancel, &AndroidCallBackInterface::NotDealInputMessage },
                                                                                                      { AndroidMotionEventAction::Outside, &AndroidCallBackInterface::NotDealInputMessage },
                                                                                                      { AndroidMotionEventAction::PointerDown, &AndroidCallBackInterface::NotDealInputMessage },
                                                                                                      { AndroidMotionEventAction::PointerUp, &AndroidCallBackInterface::NotDealInputMessage },
                                                                                                      { AndroidMotionEventAction::HoverMove, &AndroidCallBackInterface::NotDealInputMessage },
                                                                                                      { AndroidMotionEventAction::Scroll, &AndroidCallBackInterface::NotDealInputMessage },
                                                                                                      { AndroidMotionEventAction::HoverEnter, &AndroidCallBackInterface::NotDealInputMessage },
                                                                                                      { AndroidMotionEventAction::HoverExit, &AndroidCallBackInterface::NotDealInputMessage } };

    static MotionHandleInputFunctionPointerSharedPtr functionPointer = make_shared<MotionHandleInputFunctionPointerContainer>(motionHandleInputFunctionPointerContainer);

    return functionPointer;
}
