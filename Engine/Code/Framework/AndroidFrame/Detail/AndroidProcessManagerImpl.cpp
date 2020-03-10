// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.4 (2019/08/01 13:24)

#include "Framework/FrameworkExport.h"

#include "CoreTools/Helper/ExceptionMacro.h"
#include "AndroidProcessManagerImpl.h"
#include "Framework/AndroidFrame/AndroidCallBackInterface.h"
#include "System/Android/AndroidInputKeyEvent.h"
#include "System/Android/Flags/AndroidNativeAppGlueFlags.h"
#include "System/Android/AndroidInputMotionEvent.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "System/Helper/UnusedMacro.h"

#include <boost/assign/list_inserter.hpp>

Framework::AndroidProcessManagerImpl::AndroidCallBackInterfacePtr
	Framework::AndroidProcessManagerImpl
	::sm_AndroidCallBackPtr;

Framework::AndroidProcessManagerImpl::HandleCmdFunctionPointerMap
	Framework::AndroidProcessManagerImpl::sm_HandleCmdFunctionPointerMap;

Framework::AndroidProcessManagerImpl::KeyHandleInputFunctionPointerMap
	Framework::AndroidProcessManagerImpl::sm_HandleKeyInputFunctionPointerMap;

Framework::AndroidProcessManagerImpl::MotionHandleInputFunctionPointerMap
	Framework::AndroidProcessManagerImpl::sm_HandleMotionInputFunctionPointerMap;

Framework::AndroidProcessManagerImpl
	::AndroidProcessManagerImpl()
{
	GenerateHandleCmdMessage();
	GenerateHandleKeyInputMessage();
	GenerateHandleMotionInputMessage();

	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

// private
void Framework::AndroidProcessManagerImpl
	::GenerateHandleCmdMessage()
{
	sm_HandleCmdFunctionPointerMap.clear();

	boost::assign::insert(sm_HandleCmdFunctionPointerMap)
		(System::AppCmd::InputChanged,&AndroidCallBackInterface::NotDealCmdMessage)
		(System::AppCmd::InitWindow,&AndroidCallBackInterface::InitMessage)
		(System::AppCmd::TermWindow, &AndroidCallBackInterface::TermMessage)
		(System::AppCmd::WindowResized, &AndroidCallBackInterface::ResizedMessage)
		(System::AppCmd::WindowRedrawNeeded, &AndroidCallBackInterface::RedrawNeededMessage)
		(System::AppCmd::ContentRectChanged, &AndroidCallBackInterface::RectChanged)
		(System::AppCmd::GainedFocus, &AndroidCallBackInterface::NotDealCmdMessage)
		(System::AppCmd::LostFocus, &AndroidCallBackInterface::NotDealCmdMessage)
		(System::AppCmd::ConfigChanged, &AndroidCallBackInterface::NotDealCmdMessage)
		(System::AppCmd::LowMemory, &AndroidCallBackInterface::NotDealCmdMessage)
		(System::AppCmd::Start, &AndroidCallBackInterface::NotDealCmdMessage)
		(System::AppCmd::Resume, &AndroidCallBackInterface::NotDealCmdMessage)
		(System::AppCmd::SaveState, &AndroidCallBackInterface::NotDealCmdMessage)
		(System::AppCmd::Pause, &AndroidCallBackInterface::NotDealCmdMessage)
		(System::AppCmd::Stop, &AndroidCallBackInterface::NotDealCmdMessage)
		(System::AppCmd::Destory, &AndroidCallBackInterface::NotDealCmdMessage);
}

// private
void Framework::AndroidProcessManagerImpl
	::GenerateHandleKeyInputMessage()
{
	sm_HandleKeyInputFunctionPointerMap.clear();

	boost::assign::insert(sm_HandleKeyInputFunctionPointerMap)
		(System::AndroidKeyEventAction::Down,&AndroidCallBackInterface::KeyDownMessage)
		(System::AndroidKeyEventAction::Up,&AndroidCallBackInterface::KeyUpMessage)
		(System::AndroidKeyEventAction::Multiple,&AndroidCallBackInterface::NotDealInputMessage);
}

// private
void Framework::AndroidProcessManagerImpl
	::GenerateHandleMotionInputMessage()
{
	sm_HandleMotionInputFunctionPointerMap.clear();

	boost::assign::insert(sm_HandleMotionInputFunctionPointerMap)
		(System::AndroidMotionEventAction::Down,&AndroidCallBackInterface::ActionDownMessage)
		(System::AndroidMotionEventAction::Up, &AndroidCallBackInterface::ActionUpMessage)
		(System::AndroidMotionEventAction::Move, &AndroidCallBackInterface::ActionMoveMessage)
		(System::AndroidMotionEventAction::Cancel, &AndroidCallBackInterface::NotDealInputMessage)
		(System::AndroidMotionEventAction::Outside, &AndroidCallBackInterface::NotDealInputMessage)
		(System::AndroidMotionEventAction::PointerDown, &AndroidCallBackInterface::NotDealInputMessage)
		(System::AndroidMotionEventAction::PointerUp, &AndroidCallBackInterface::NotDealInputMessage)
		(System::AndroidMotionEventAction::HoverMove, &AndroidCallBackInterface::NotDealInputMessage)
		(System::AndroidMotionEventAction::Scroll, &AndroidCallBackInterface::NotDealInputMessage)
		(System::AndroidMotionEventAction::HoverEnter, &AndroidCallBackInterface::NotDealInputMessage)
		(System::AndroidMotionEventAction::HoverExit, &AndroidCallBackInterface::NotDealInputMessage);
}

CLASS_INVARIANT_STUB_DEFINE(Framework,AndroidProcessManagerImpl)

Framework::AndroidProcessManagerImpl::AndroidCallBackInterfacePtr
	Framework::AndroidProcessManagerImpl
	::GetAndroidCallBackInterfacePtr() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return sm_AndroidCallBackPtr;
}

void Framework::AndroidProcessManagerImpl
	::SetAndroidCallBack( AndroidCallBackInterfacePtr ptr )
{
	FRAMEWORK_CLASS_IS_VALID_9;

	sm_AndroidCallBackPtr = ptr;
}

void Framework::AndroidProcessManagerImpl
	::ClearAndroidCallBack()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	sm_AndroidCallBackPtr.reset();
}

bool Framework::AndroidProcessManagerImpl
	::PreCreate()
{
	if(sm_AndroidCallBackPtr != nullptr)
    {
		return sm_AndroidCallBackPtr->PreCreate();
    }
	else
    {
		THROW_EXCEPTION(SYSTEM_TEXT("AndroidCallBack指针为空！"));
    }
}

bool Framework::AndroidProcessManagerImpl
	::Initialize()
{
	if(sm_AndroidCallBackPtr != nullptr)
    {
		return sm_AndroidCallBackPtr->Initialize();
    }
	else
    {
		THROW_EXCEPTION(SYSTEM_TEXT("AndroidCallBack指针为空！"));
    }
}

void Framework::AndroidProcessManagerImpl
	::PreIdle()
{
	if(sm_AndroidCallBackPtr != nullptr)
    {
		sm_AndroidCallBackPtr->PreIdle();
    }
	else
    {
		THROW_EXCEPTION(SYSTEM_TEXT("AndroidCallBack指针为空！"));
    }
}

void Framework::AndroidProcessManagerImpl
	::Terminate()
{
	if(sm_AndroidCallBackPtr != nullptr)
    {
		sm_AndroidCallBackPtr->Terminate();
    }
	else
    {
		THROW_EXCEPTION(SYSTEM_TEXT("AndroidCallBack指针为空！"));
    }
}

int Framework::AndroidProcessManagerImpl
	::HandleInput(struct AndroidApp* app,
	              AndroidInputEvent* event)
{
	System::AndroidInputEventType eventType = AndroidInputEventGetType(event);

	switch(eventType)
	{
	case System::AndroidInputEventType::Key:
		// 消息来自按键事件
		return HandleKeyInput(app,event);
	case System::AndroidInputEventType::Motion:
		// 消息来自移动事件
		return HandleMotionInput(app,event);
	default:
		return 0;
	}
}

void Framework::AndroidProcessManagerImpl
	::HandleCmd( struct AndroidApp* app, int cmd )
{
	HandleCmdFunctionPointerMapConstIter iter =
		sm_HandleCmdFunctionPointerMap.find(AppCmd(cmd));

	if(sm_AndroidCallBackPtr != nullptr &&
	   iter != sm_HandleCmdFunctionPointerMap.end())
		return ((*sm_AndroidCallBackPtr).*(iter->second))(app);
	else
		return NotDealMessage(app);
}

void Framework::AndroidProcessManagerImpl
	::Display(struct AndroidApp* state , int64_t timeDelta )
{
	if(sm_AndroidCallBackPtr != nullptr)
    {
		sm_AndroidCallBackPtr->Display(state,timeDelta);
    }
	else
    {
		THROW_EXCEPTION(SYSTEM_TEXT("AndroidCallBack指针为空！"));
    }
}

int Framework::AndroidProcessManagerImpl
	::HandleKeyInput( struct AndroidApp* app, AndroidInputEvent* event )
{
	int id = static_cast<int>(AndroidKeyEventGetAction(event));

	KeyHandleInputFunctionPointerMapConstIter iter =
		sm_HandleKeyInputFunctionPointerMap.find(AndroidKeyEventAction(id));

	if(sm_AndroidCallBackPtr != nullptr &&
	   iter != sm_HandleKeyInputFunctionPointerMap.end())
		return ((*sm_AndroidCallBackPtr).*(iter->second))(app,event);
	else
		return NotDealMessage(app,event);
}

int Framework::AndroidProcessManagerImpl
	::HandleMotionInput( struct AndroidApp* app, AndroidInputEvent* event )
{
	System::AndroidMotionEventAction id = System::AndroidMotionEventGetAction(event);

	MotionHandleInputFunctionPointerMapConstIter iter =
		sm_HandleMotionInputFunctionPointerMap.find(id);

	if(sm_AndroidCallBackPtr != nullptr &&
		iter != sm_HandleMotionInputFunctionPointerMap.end())
		return ((*sm_AndroidCallBackPtr).*(iter->second))(app,event);
	else
		return NotDealMessage(app,event);
}

void Framework::AndroidProcessManagerImpl
	::NotDealMessage( struct AndroidApp* state )
{
	SYSTEM_UNUSED_ARG(state);
}

int Framework::AndroidProcessManagerImpl
	::NotDealMessage( struct AndroidApp* state, AndroidInputEvent* event )
{
	SYSTEM_UNUSED_ARG(state);
	SYSTEM_UNUSED_ARG(event);

	return 0;
}

