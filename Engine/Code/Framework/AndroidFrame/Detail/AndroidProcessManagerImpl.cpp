// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.3.0.1 (2020/05/21 16:41)

#include "Framework/FrameworkExport.h"

#include "AndroidProcessManagerImpl.h"

#include "System/Android/AndroidInputKeyEvent.h"
#include "System/Android/AndroidInputMotionEvent.h"
#include "System/Android/Flags/AndroidNativeAppGlueFlags.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/AndroidFrame/AndroidCallBackInterface.h"

CORE_TOOLS_MUTEX_EXTERN(Framework);

using std::make_shared;
using namespace std::literals;

Framework::AndroidProcessManagerImpl::AndroidCallBackInterfaceSharedPtr	Framework::AndroidProcessManagerImpl
	::sm_AndroidCallBack{ };

CLASS_INVARIANT_STUB_DEFINE(Framework, AndroidProcessManagerImpl)

Framework::AndroidProcessManagerImpl::AndroidCallBackInterfaceSharedPtr Framework::AndroidProcessManagerImpl
	::GetAndroidCallBackInterface() noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return sm_AndroidCallBack;
}

void Framework::AndroidProcessManagerImpl
	::SetAndroidCallBack(const AndroidCallBackInterfaceSharedPtr& androidCallBack) noexcept
{
	FRAMEWORK_CLASS_IS_VALID_9;

	sm_AndroidCallBack = androidCallBack;
}

void Framework::AndroidProcessManagerImpl
	::ClearAndroidCallBack() noexcept
{
	FRAMEWORK_CLASS_IS_VALID_9;

	sm_AndroidCallBack.reset();
}

bool Framework::AndroidProcessManagerImpl
	::PreCreate()
{
	if (sm_AndroidCallBack != nullptr)
	{
		return sm_AndroidCallBack->PreCreate();
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("AndroidCallBack指针为空！"s));
	}
}

bool Framework::AndroidProcessManagerImpl
	::Initialize()
{
	if (sm_AndroidCallBack != nullptr)
	{
		return sm_AndroidCallBack->Initialize();
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("AndroidCallBack指针为空！"s));
	}
}

void Framework::AndroidProcessManagerImpl
	::PreIdle()
{
	if (sm_AndroidCallBack != nullptr)
	{
		sm_AndroidCallBack->PreIdle();
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("AndroidCallBack指针为空！"s));
	}
}

void Framework::AndroidProcessManagerImpl
	::Terminate()
{
	if (sm_AndroidCallBack != nullptr)
	{
		sm_AndroidCallBack->Terminate();
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("AndroidCallBack指针为空！"s));
	}
}

int Framework::AndroidProcessManagerImpl
	::HandleInput(AndroidApp* app, AndroidInputEvent* event)
{
	const auto eventType = AndroidInputEventGetType(event);

	switch (eventType)
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

void Framework::AndroidProcessManagerImpl
	::HandleCmd(AndroidApp* androidApp, int cmd)
{
	auto handleCmdFunctionPointer = GetHandleCmdFunctionPointer();
	const auto iter = handleCmdFunctionPointer->find(System::UnderlyingCastEnum<AppCmd>(cmd));

	if (sm_AndroidCallBack != nullptr && iter != handleCmdFunctionPointer->cend())
		return ((*sm_AndroidCallBack).*(iter->second))(androidApp);
	else
		return NotDealMessage(androidApp);
}

void Framework::AndroidProcessManagerImpl
	::Display(AndroidApp* androidApp, int64_t timeDelta)
{
	if (sm_AndroidCallBack != nullptr)
	{
		sm_AndroidCallBack->Display(androidApp, timeDelta);
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("AndroidCallBack指针为空！"s));
	}
}

int Framework::AndroidProcessManagerImpl
	::HandleKeyInput(AndroidApp* androidApp, AndroidInputEvent* event)
{
	auto handleKeyInputFunctionPointer = GetKeyHandleInputFunctionPointer();

	const auto id = AndroidKeyEventGetAction(event);	

	const auto iter = handleKeyInputFunctionPointer->find(id);

	if (sm_AndroidCallBack != nullptr && iter != handleKeyInputFunctionPointer->cend())
		return ((*sm_AndroidCallBack).*(iter->second))(androidApp, event);
	else
		return NotDealMessage(androidApp, event);
}

int Framework::AndroidProcessManagerImpl
	::HandleMotionInput(AndroidApp* androidApp, AndroidInputEvent* event)
{
	auto handleMotionInputFunctionPointer = GetMotionHandleInputFunctionPointer();

	const auto id = System::AndroidMotionEventGetAction(event);	

	const auto iter = handleMotionInputFunctionPointer->find(id);

	if (sm_AndroidCallBack != nullptr && iter != handleMotionInputFunctionPointer->cend())
		return ((*sm_AndroidCallBack).*(iter->second))(androidApp, event);
	else
		return NotDealMessage(androidApp, event);
}
 
void Framework::AndroidProcessManagerImpl ::NotDealMessage([[maybe_unused]] const AndroidApp* state) noexcept
{
	 
}

int Framework::AndroidProcessManagerImpl ::NotDealMessage([[maybe_unused]] const AndroidApp* state, [[maybe_unused]] const AndroidInputEvent* event) noexcept
{
	 

	return 0;
}

Framework::AndroidProcessManagerImpl::HandleCmdFunctionPointerSharedPtr Framework::AndroidProcessManagerImpl
	::GetHandleCmdFunctionPointer()
{
	static HandleCmdFunctionPointerSharedPtr functionPointer;

	if (!functionPointer)
	{
		SINGLETON_MUTEX_ENTER_GLOBAL(Framework);

		if (!functionPointer)
		{
			HandleCmdFunctionPointerContainer handleCmdFunctionPointerContainer{ { AppCmd::InputChanged, &AndroidCallBackInterface::NotDealCmdMessage },
																				 { AppCmd::InitWindow, &AndroidCallBackInterface::InitMessage },
																				 { AppCmd::TermWindow, &AndroidCallBackInterface::TermMessage },
																				 { AppCmd::WindowResized, &AndroidCallBackInterface::ResizedMessage },
																				 { AppCmd::WindowRedrawNeeded, &AndroidCallBackInterface::RedrawNeededMessage },
																				 { AppCmd::ContentRectChanged, &AndroidCallBackInterface::RectChanged },
																				 { AppCmd::GainedFocus, &AndroidCallBackInterface::NotDealCmdMessage },
																				 { AppCmd::LostFocus, &AndroidCallBackInterface::NotDealCmdMessage },
																				 { AppCmd::ConfigChanged, &AndroidCallBackInterface::NotDealCmdMessage},
																				 { AppCmd::LowMemory, &AndroidCallBackInterface::NotDealCmdMessage },
																				 { AppCmd::Start, &AndroidCallBackInterface::NotDealCmdMessage },
																				 { AppCmd::Resume, &AndroidCallBackInterface::NotDealCmdMessage },
																				 { AppCmd::SaveState, &AndroidCallBackInterface::NotDealCmdMessage },
																				 { AppCmd::Pause, &AndroidCallBackInterface::NotDealCmdMessage },
																				 { AppCmd::Stop, &AndroidCallBackInterface::NotDealCmdMessage },
																				 { AppCmd::Destory, &AndroidCallBackInterface::NotDealCmdMessage } };

			functionPointer = make_shared<HandleCmdFunctionPointerContainer>(handleCmdFunctionPointerContainer);
		}
	}

	return functionPointer;
}

Framework::AndroidProcessManagerImpl::KeyHandleInputFunctionPointerSharedPtr Framework::AndroidProcessManagerImpl
	::GetKeyHandleInputFunctionPointer()
{
	static KeyHandleInputFunctionPointerSharedPtr functionPointer;

	if (!functionPointer)
	{
		SINGLETON_MUTEX_ENTER_GLOBAL(Framework);

		if (!functionPointer)
		{
			KeyHandleInputFunctionPointerContainer keyHandleInputFunctionPointerContainer{ { AndroidKeyEventAction::Down,&AndroidCallBackInterface::KeyDownMessage },
																						   { AndroidKeyEventAction::Up,&AndroidCallBackInterface::KeyUpMessage },
																						   { AndroidKeyEventAction::Multiple,&AndroidCallBackInterface::NotDealInputMessage } };

			functionPointer = make_shared<KeyHandleInputFunctionPointerContainer>(keyHandleInputFunctionPointerContainer);
		}
	}

	return functionPointer;
}

Framework::AndroidProcessManagerImpl::MotionHandleInputFunctionPointerSharedPtr Framework::AndroidProcessManagerImpl
	::GetMotionHandleInputFunctionPointer()
{
	static MotionHandleInputFunctionPointerSharedPtr functionPointer;

	if (!functionPointer)
	{
		SINGLETON_MUTEX_ENTER_GLOBAL(Framework);

		if (!functionPointer)
		{
			MotionHandleInputFunctionPointerContainer motionHandleInputFunctionPointerContainer{ { AndroidMotionEventAction::Down,&AndroidCallBackInterface::ActionDownMessage },
																								 { AndroidMotionEventAction::Up, &AndroidCallBackInterface::ActionUpMessage },
																								 { AndroidMotionEventAction::Move, &AndroidCallBackInterface::ActionMoveMessage },
																								 { AndroidMotionEventAction::Cancel, &AndroidCallBackInterface::NotDealInputMessage },
																								 { AndroidMotionEventAction::Outside, &AndroidCallBackInterface::NotDealInputMessage },
																								 { AndroidMotionEventAction::PointerDown, &AndroidCallBackInterface::NotDealInputMessage},
																								 { AndroidMotionEventAction::PointerUp, &AndroidCallBackInterface::NotDealInputMessage },
																								 { AndroidMotionEventAction::HoverMove, &AndroidCallBackInterface::NotDealInputMessage },
																								 { AndroidMotionEventAction::Scroll, &AndroidCallBackInterface::NotDealInputMessage },
																								 { AndroidMotionEventAction::HoverEnter, &AndroidCallBackInterface::NotDealInputMessage },
																								 { AndroidMotionEventAction::HoverExit, &AndroidCallBackInterface::NotDealInputMessage } };

			functionPointer = make_shared<MotionHandleInputFunctionPointerContainer>(motionHandleInputFunctionPointerContainer);
		}
	}

	return functionPointer;
}
 