// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.4 (2019/08/01 13:20)

#include "Framework/FrameworkExport.h"

#include "OpenGLGlutProcessManagerImpl.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutCallBackInterface.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/MainFunctionHelper/MainFunctionHelperBase.h"
#include "System/Helper/UnusedMacro.h"

Framework::OpenGLGlutProcessManagerImpl::OpenGLGlutCallBackInterfacePtr
	Framework::OpenGLGlutProcessManagerImpl
	::sm_OpenGLGlutCallBackPtr;

Framework::MainFunctionHelperBase* Framework::OpenGLGlutProcessManagerImpl
	::sm_MainFunctionHelperPtr;

Framework::OpenGLGlutProcessManagerImpl
	::OpenGLGlutProcessManagerImpl()
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework,OpenGLGlutProcessManagerImpl)

Framework::OpenGLGlutProcessManagerImpl::OpenGLGlutCallBackInterfacePtr
    Framework::OpenGLGlutProcessManagerImpl
	::GetOpenGLGlutCallBackInterfacePtr() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return sm_OpenGLGlutCallBackPtr;
}

void Framework::OpenGLGlutProcessManagerImpl
	::SetOpenGLGlutCallBack( OpenGLGlutCallBackInterfacePtr ptr )
{
	FRAMEWORK_CLASS_IS_VALID_9;

	sm_OpenGLGlutCallBackPtr = ptr;
}

void Framework::OpenGLGlutProcessManagerImpl
	::ClearOpenGLGlutCallBack()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	sm_OpenGLGlutCallBackPtr.reset();
}

void Framework::OpenGLGlutProcessManagerImpl
	::SetWindowID( int window )
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if(sm_OpenGLGlutCallBackPtr != nullptr)
    {
		sm_OpenGLGlutCallBackPtr->SetWindowID(window);
    }
	else
    {
		THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack指针为空！"));
    }
}

int Framework::OpenGLGlutProcessManagerImpl
	::GetWindowID() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	if(sm_OpenGLGlutCallBackPtr != nullptr)
    {
		return sm_OpenGLGlutCallBackPtr->GetWindowID();
    }
	else
    {
		THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack指针为空！"));
    }
}

void Framework::OpenGLGlutProcessManagerImpl
	::SetMillisecond(unsigned millisecond)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if(sm_OpenGLGlutCallBackPtr != nullptr)
    {
		sm_OpenGLGlutCallBackPtr->SetMillisecond(millisecond);
    }
	else
    {
		THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack指针为空！"));
    }
}

void Framework::OpenGLGlutProcessManagerImpl
	::SetMainFunctionHelperPtr( MainFunctionHelperBase* ptr )
{
	FRAMEWORK_CLASS_IS_VALID_9;

	sm_MainFunctionHelperPtr = ptr;
}

void Framework::OpenGLGlutProcessManagerImpl
	::ClearMainFunctionHelperPtr()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	sm_MainFunctionHelperPtr = nullptr;
}

// static
bool Framework::OpenGLGlutProcessManagerImpl
	::PreCreate()
{
	if(sm_OpenGLGlutCallBackPtr != nullptr)
    {
		return sm_OpenGLGlutCallBackPtr->PreCreate();
    }
	else
    {
		THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack指针为空！"));
    }
}

// static
bool Framework::OpenGLGlutProcessManagerImpl
	::Initialize()
{
	if(sm_OpenGLGlutCallBackPtr != nullptr)
    {
		return sm_OpenGLGlutCallBackPtr->Initialize();
    }
	else
    {
		THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack指针为空！"));
    }
}

// static
void Framework::OpenGLGlutProcessManagerImpl
	::PreIdle()
{
	if(sm_OpenGLGlutCallBackPtr != nullptr)
    {
		sm_OpenGLGlutCallBackPtr->PreIdle();
    }
	else
    {
		THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack指针为空！"));
    }
}

// static
void Framework::OpenGLGlutProcessManagerImpl
	::Terminate()
{
	if(sm_OpenGLGlutCallBackPtr != nullptr)
    {
		sm_OpenGLGlutCallBackPtr->Terminate();
    }
	else
    {
		THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack指针为空！"));
    }
}


// static
void Framework::OpenGLGlutProcessManagerImpl
	::RenderScene()
{
	if(sm_OpenGLGlutCallBackPtr != nullptr)
    {
		sm_OpenGLGlutCallBackPtr->RenderScene();
    }
	else
    {
		THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack指针为空！"));
    }
}

// static
void Framework::OpenGLGlutProcessManagerImpl
	::ChangeSize( int width, int height )
{
	if(sm_OpenGLGlutCallBackPtr != nullptr)
    {
		sm_OpenGLGlutCallBackPtr->ChangeSize(width,height);
    }
	else
    {
		THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack指针为空！"));
    }
}

unsigned int Framework::OpenGLGlutProcessManagerImpl
	::GetMillisecond()
{
	if(sm_OpenGLGlutCallBackPtr != nullptr)
    {
		return sm_OpenGLGlutCallBackPtr->GetMillisecond();
    }
	else
    {
		THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack指针为空！"));
    }
}

// static
void Framework::OpenGLGlutProcessManagerImpl
	::TimerFunction(int timer)
{
	if(sm_OpenGLGlutCallBackPtr != nullptr)
    {
		sm_OpenGLGlutCallBackPtr->TimerFunction(TimerFunction);
    }
	else
    {
		THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack指针为空！"));
    }

    SYSTEM_UNUSED_ARG(timer);
}

// static
void Framework::OpenGLGlutProcessManagerImpl
	::SpecialKeysDown( int key,int xCoordinate,int yCoordinate )
{
	if(sm_OpenGLGlutCallBackPtr != nullptr)
    {
		sm_OpenGLGlutCallBackPtr->SpecialKeysDown(key,xCoordinate,yCoordinate);
    }
	else
    {
		THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack指针为空！"));
    }
}

// static
void Framework::OpenGLGlutProcessManagerImpl
	::KeyboardDown( unsigned char key,int xCoordinate,int yCoordinate )
{
	if(sm_OpenGLGlutCallBackPtr != nullptr)
    {
		sm_OpenGLGlutCallBackPtr->KeyboardDown(key,xCoordinate,yCoordinate);
    }
	else
    {
		THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack指针为空！"));
    }
}

// static
void Framework::OpenGLGlutProcessManagerImpl
	::MouseFunction( int button,int state,int xCoordinate,int yCoordinate )
{
	if(sm_OpenGLGlutCallBackPtr != nullptr)
    {
		sm_OpenGLGlutCallBackPtr->MouseClick(button,state,xCoordinate,yCoordinate);
    }
	else
    {
		THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack指针为空！"));
    }
}

// static
void Framework::OpenGLGlutProcessManagerImpl
	::MotionFunction( int xCoordinate,int yCoordinate )
{
	if(sm_OpenGLGlutCallBackPtr != nullptr)
    {
		sm_OpenGLGlutCallBackPtr->MotionFunction(xCoordinate,yCoordinate);
    }
	else
    {
		THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack指针为空！"));
    }
}

// static
void Framework::OpenGLGlutProcessManagerImpl
	::PassiveMotion( int xCoordinate,int yCoordinate )
{
	if(sm_OpenGLGlutCallBackPtr != nullptr)
    {
		sm_OpenGLGlutCallBackPtr->PassiveMotion(xCoordinate,yCoordinate);
    }
	else
    {
		THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack指针为空！"));
    }
}

// static
void Framework::OpenGLGlutProcessManagerImpl
	::IdleFunction()
{
	if(sm_OpenGLGlutCallBackPtr != nullptr)
    {
		sm_OpenGLGlutCallBackPtr->IdleFunction();
    }
	else
    {
		THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack指针为空！"));
    }
}

// static
void Framework::OpenGLGlutProcessManagerImpl
	::ProcessMenu( int menuValue )
{
	if(sm_OpenGLGlutCallBackPtr != nullptr)
    {
		sm_OpenGLGlutCallBackPtr->ProcessMenu(menuValue);
    }
	else
    {
		THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack指针为空！"));
    }
}

// static
void Framework::OpenGLGlutProcessManagerImpl
	::TerminateFunction()
{
	try
	{
		Terminate();

		sm_OpenGLGlutCallBackPtr.reset();

		if (sm_MainFunctionHelperPtr != nullptr)
		{
			sm_MainFunctionHelperPtr->Destroy();
			sm_MainFunctionHelperPtr = nullptr;
		}
	}
	catch (...)
	{
		
	}
}

// static
void Framework::OpenGLGlutProcessManagerImpl
	::SpecialKeysUp( int key,int xCoordinate,int yCoordinate )
{
	if(sm_OpenGLGlutCallBackPtr != nullptr)
    {
		sm_OpenGLGlutCallBackPtr->SpecialKeysUp(key,xCoordinate,yCoordinate);
    }
	else
    {
		THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack指针为空！"));
    }
}

// static
void Framework::OpenGLGlutProcessManagerImpl
	::KeyboardUp( unsigned char key,int xCoordinate,int yCoordinate )
{
	if(sm_OpenGLGlutCallBackPtr != nullptr)
    {
		sm_OpenGLGlutCallBackPtr->KeyboardUp(key,xCoordinate,yCoordinate);
    }
	else
    {
		THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack指针为空！"));
    }
}
 
Framework::MainFunctionHelperBase* Framework::OpenGLGlutProcessManagerImpl
	::GetMainFunctionHelperPtr() 
{
	FRAMEWORK_CLASS_IS_VALID_9;

	return sm_MainFunctionHelperPtr;
}



