// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.4 (2019/08/01 13:22)

#ifndef FRAMEWORK_ANDROID_FRAME_ANDROID_CALL_BACK_DETAIL_H
#define FRAMEWORK_ANDROID_FRAME_ANDROID_CALL_BACK_DETAIL_H

#include "AndroidCallBack.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/WindowProcess/VirtualKeysTypes.h"
#include "Framework/WindowCreate/WindowSize.h"
#include "Framework/WindowCreate/WindowPoint.h"
#include "System/Window/Flags/WindowDisplayFlags.h"
#include "System/Android/AndroidInputMotionEvent.h"
#include "System/Android/AndroidInputKeyEvent.h"
#include "System/Android/AndroidNativeWindow.h"
#include "System/Android/Flags/AndroidNativeAppGlueFlags.h"

template <typename ModelViewControllerMiddleLayerContainer>
Framework::AndroidCallBack<ModelViewControllerMiddleLayerContainer>
	::AndroidCallBack()
	:ParentType{},m_MiddleLayerPtr(new ModelViewControllerMiddleLayerContainer)
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

template <typename ModelViewControllerMiddleLayerContainer>
Framework::AndroidCallBack<ModelViewControllerMiddleLayerContainer>
	::~AndroidCallBack()
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename ModelViewControllerMiddleLayerContainer>
bool Framework::AndroidCallBack<ModelViewControllerMiddleLayerContainer>
	::IsValid() const noexcept
{
	if(ParentType::IsValid() &&
	   m_MiddleLayerPtr != nullptr)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename ModelViewControllerMiddleLayerContainer>
void Framework::AndroidCallBack<ModelViewControllerMiddleLayerContainer>
	::RedrawNeededMessage( struct AndroidApp* state )
{
	FRAMEWORK_CLASS_IS_VALID_1;

	ParentType::RedrawNeededMessage(state);

	if(!m_MiddleLayerPtr->Paint())
	{
		state->destroyRequested = 1;
	}
}

template <typename ModelViewControllerMiddleLayerContainer>
void Framework::AndroidCallBack<ModelViewControllerMiddleLayerContainer>
	::ResizedMessage( struct AndroidApp* state )
{
	FRAMEWORK_CLASS_IS_VALID_1;

	ParentType::ResizedMessage(state);

	System::AndroidNativeWindow* nativeWindow = state->window;

	if(nativeWindow != nullptr)
	{
		int width = System::AndroidNativeWindowGetWidth(nativeWindow);
		int height = System::AndroidNativeWindowGetHeight(nativeWindow);

		if(!m_MiddleLayerPtr->Resize(System::WindowDisplay::AndroidUnDefinition,
			                         WindowSize(width,height)))
		{
			state->destroyRequested = 1;
		}
	}
}

template <typename ModelViewControllerMiddleLayerContainer>
void Framework::AndroidCallBack<ModelViewControllerMiddleLayerContainer>
	::RectChanged( struct AndroidApp* state )
{
	FRAMEWORK_CLASS_IS_VALID_1;

	ParentType::RectChanged(state);

	System::AndroidRect contentRect = state->contentRect;
	int width = abs(contentRect.GetRight() - contentRect.GetLeft());
	int height = abs(contentRect.GetTop() - contentRect.GetBottom());

	if(!m_MiddleLayerPtr->Resize(System::WindowDisplay::AndroidUnDefinition,
			                     WindowSize(width,height)))
	{
		state->destroyRequested = 1;
	}
}

template <typename ModelViewControllerMiddleLayerContainer>
void Framework::AndroidCallBack<ModelViewControllerMiddleLayerContainer>
	::InitMessage( struct AndroidApp* state )
{
	FRAMEWORK_CLASS_IS_VALID_1;

	ParentType::InitMessage(state);

	if(!m_MiddleLayerPtr->Create())
	{
		state->destroyRequested = 1;
	}
}

template <typename ModelViewControllerMiddleLayerContainer>
void Framework::AndroidCallBack<ModelViewControllerMiddleLayerContainer>
	::TermMessage( struct AndroidApp* state )
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if(state != nullptr)
	{
		ParentType::TermMessage(state);
		
		m_MiddleLayerPtr->Destroy();		
		
		state->destroyRequested = 1;
	}
}

template <typename ModelViewControllerMiddleLayerContainer>
void Framework::AndroidCallBack<ModelViewControllerMiddleLayerContainer>
	::Display( struct AndroidApp* state ,int64_t timeDelta )
{
	FRAMEWORK_CLASS_IS_VALID_1;

	ParentType::Display(state,timeDelta);

	if(!m_MiddleLayerPtr->Idle(timeDelta))
	{
		state->destroyRequested = 1;
	}
}

template <typename ModelViewControllerMiddleLayerContainer>
int Framework::AndroidCallBack<ModelViewControllerMiddleLayerContainer>
	::KeyDownMessage( struct AndroidApp* state, AndroidInputEvent* event )
{
	FRAMEWORK_CLASS_IS_VALID_1;

	int flags = static_cast<int>( System::AndroidKeyEventGetFlags(event));
	int keyCode = static_cast<int>(System::AndroidKeyEventGetKeyCode(event));

	if ((flags & static_cast<int>( System::AndroidKeyEvent::SoftKeyboard)) != 0)
	{
		if(!m_MiddleLayerPtr->KeyDown(static_cast<unsigned char>(keyCode),
			                          WindowPoint()))
		{
			state->destroyRequested = 1;
		}
	}
	else
	{
		if(!m_MiddleLayerPtr->SpecialKeyDown(keyCode,WindowPoint()))
		{
			state->destroyRequested = 1;
		}
	}

	return ParentType::KeyDownMessage(state,event);
}

template <typename ModelViewControllerMiddleLayerContainer>
int Framework::AndroidCallBack<ModelViewControllerMiddleLayerContainer>
	::KeyUpMessage( struct AndroidApp* state, AndroidInputEvent* event )
{
	FRAMEWORK_CLASS_IS_VALID_1;

	int flags = static_cast<int>(System::AndroidKeyEventGetFlags(event));
	int keyCode = static_cast<int>(System::AndroidKeyEventGetKeyCode(event));

	if ((flags & static_cast<int>(System::AndroidKeyEvent::SoftKeyboard)) != 0)
	{
		if(!m_MiddleLayerPtr->KeyUp(static_cast<unsigned char>(keyCode),
			                        WindowPoint()))
		{
			state->destroyRequested = 1;
		}
	}
	else
	{
		if(!m_MiddleLayerPtr->SpecialKeyUp(keyCode,WindowPoint()))
		{
			state->destroyRequested = 1;
		}
	}

	return ParentType::KeyUpMessage(state,event);
}

template <typename ModelViewControllerMiddleLayerContainer>
int Framework::AndroidCallBack<ModelViewControllerMiddleLayerContainer>
	::ActionDownMessage( struct AndroidApp* state, AndroidInputEvent* event )
{
	FRAMEWORK_CLASS_IS_VALID_1;

	int xOffset = static_cast<int>(System::AndroidMotionEventGetXOffset(event));
	int yOffset = static_cast<int>(System::AndroidMotionEventGetYOffset(event));

	// 可以通过使用AndroidMotionEventGetMetaState和AndroidMotionEventGetButtonState
	// 获取VirtualKeysTypes的值，
	// 但对于Android而言，没有太多实际的意义。
	if(!m_MiddleLayerPtr->MouseClick(MouseButtonsTypesLeftButton,
		                             MouseStateTypesMouseDown,
									 WindowPoint(xOffset,yOffset),
									 VirtualKeysTypes()))
	{
		state->destroyRequested = 1;
	}

	return ParentType::ActionDownMessage(state,event);
}

template <typename ModelViewControllerMiddleLayerContainer>
int Framework::AndroidCallBack<ModelViewControllerMiddleLayerContainer>
	::ActionUpMessage( struct AndroidApp* state, AndroidInputEvent* event )
{
	FRAMEWORK_CLASS_IS_VALID_1;

	int xOffset = static_cast<int>(System::AndroidMotionEventGetXOffset(event));
	int yOffset = static_cast<int>(System::AndroidMotionEventGetYOffset(event));

	if(!m_MiddleLayerPtr->MouseClick(MouseButtonsTypesLeftButton,
		                             MouseStateTypesMouseUp,
									 WindowPoint(xOffset,yOffset),
									 VirtualKeysTypes()))
	{
		state->destroyRequested = 1;
	}

	return ParentType::ActionUpMessage(state,event);
}

template <typename ModelViewControllerMiddleLayerContainer>
int Framework::AndroidCallBack<ModelViewControllerMiddleLayerContainer>
	::ActionMoveMessage( struct AndroidApp* state, AndroidInputEvent* event )
{
	FRAMEWORK_CLASS_IS_VALID_1;

	int xOffset = static_cast<int>(System::AndroidMotionEventGetXOffset(event));
	int yOffset = static_cast<int>(System::AndroidMotionEventGetYOffset(event));

	if(!m_MiddleLayerPtr->Motion(WindowPoint(xOffset,yOffset),
								 VirtualKeysTypes()))
	{
		state->destroyRequested = 1;
	}

	return ParentType::ActionMoveMessage(state,event);
}

#endif // FRAMEWORK_ANDROID_FRAME_ANDROID_CALL_BACK_DETAIL_H
