// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.3.0.1 (2020/05/21 15:59)

#include "Framework/FrameworkExport.h"

#include "OpenGLGlutProcessManagerImpl.h"
#include "System/Helper/UnusedMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/MainFunctionHelper/MainFunctionHelperBase.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutCallBackInterface.h"

using namespace std::literals;

Framework::OpenGLGlutProcessManagerImpl::OpenGLGlutCallBackInterfaceSharedPtr Framework::OpenGLGlutProcessManagerImpl
	::sm_OpenGLGlutCallBack{ };

Framework::OpenGLGlutProcessManagerImpl::MainFunctionHelperBaseWeakPtr Framework::OpenGLGlutProcessManagerImpl
	::sm_MainFunctionHelper{ };

Framework::OpenGLGlutProcessManagerImpl
	::OpenGLGlutProcessManagerImpl() noexcept
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, OpenGLGlutProcessManagerImpl)

// static
Framework::OpenGLGlutProcessManagerImpl::OpenGLGlutCallBackInterfaceSharedPtr Framework::OpenGLGlutProcessManagerImpl
	::GetOpenGLGlutCallBack() noexcept
{
	return sm_OpenGLGlutCallBack;
}

// static
void Framework::OpenGLGlutProcessManagerImpl
	::SetOpenGLGlutCallBack(const OpenGLGlutCallBackInterfaceSharedPtr& openGLGlutCallBack) noexcept
{
	sm_OpenGLGlutCallBack = openGLGlutCallBack;
}

// static
void Framework::OpenGLGlutProcessManagerImpl
	::ClearOpenGLGlutCallBack() noexcept
{
	sm_OpenGLGlutCallBack.reset();
}

// static
void Framework::OpenGLGlutProcessManagerImpl
	::SetWindowID(int window)
{
	if (sm_OpenGLGlutCallBack != nullptr)
	{
		sm_OpenGLGlutCallBack->SetWindowID(window);
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack指针为空！"s));
	}
}

// static
int Framework::OpenGLGlutProcessManagerImpl
	::GetWindowID()
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	if (sm_OpenGLGlutCallBack != nullptr)
	{
		return sm_OpenGLGlutCallBack->GetWindowID();
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack指针为空！"s));
	}
}

// static
void Framework::OpenGLGlutProcessManagerImpl
	::SetMillisecond(int millisecond)
{
	if (sm_OpenGLGlutCallBack != nullptr)
	{
		sm_OpenGLGlutCallBack->SetMillisecond(millisecond);
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack指针为空！"s));
	}
}

int Framework::OpenGLGlutProcessManagerImpl
	::GetMillisecond()
{
	if (sm_OpenGLGlutCallBack != nullptr)
	{
		return sm_OpenGLGlutCallBack->GetMillisecond();
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack指针为空！"s));
	}
}

// static
void Framework::OpenGLGlutProcessManagerImpl
	::SetMainFunctionHelper(const MainFunctionHelperBaseSharedPtr& mainFunctionHelperBase) noexcept
{
	sm_MainFunctionHelper = mainFunctionHelperBase;
}

// static
void Framework::OpenGLGlutProcessManagerImpl
	::ClearMainFunctionHelper() noexcept
{
	sm_MainFunctionHelper.reset();
}

Framework::OpenGLGlutProcessManagerImpl::MainFunctionHelperBaseSharedPtr Framework::OpenGLGlutProcessManagerImpl
	::GetMainFunctionHelper()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	auto mainFunctionHelper = sm_MainFunctionHelper.lock();
	if (mainFunctionHelper)
	{
		return mainFunctionHelper;
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("MainFunctionHelper指针为空！"s));
	}
}

// static
bool Framework::OpenGLGlutProcessManagerImpl
	::PreCreate()
{
	if (sm_OpenGLGlutCallBack != nullptr)
	{
		return sm_OpenGLGlutCallBack->PreCreate();
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack指针为空！"s));
	}
}

// static
bool Framework::OpenGLGlutProcessManagerImpl
	::Initialize()
{
	if (sm_OpenGLGlutCallBack != nullptr)
	{
		return sm_OpenGLGlutCallBack->Initialize();
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack指针为空！"s));
	}
}

// static
void Framework::OpenGLGlutProcessManagerImpl
	::PreIdle()
{
	if (sm_OpenGLGlutCallBack != nullptr)
	{
		sm_OpenGLGlutCallBack->PreIdle();
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack指针为空！"s));
	}
}

// static
void Framework::OpenGLGlutProcessManagerImpl
	::Terminate()
{
	if (sm_OpenGLGlutCallBack != nullptr)
	{
		sm_OpenGLGlutCallBack->Terminate();
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack指针为空！"s));
	}
}

// static
void Framework::OpenGLGlutProcessManagerImpl
	::RenderScene()
{
	if (sm_OpenGLGlutCallBack != nullptr)
	{
		sm_OpenGLGlutCallBack->RenderScene();
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack指针为空！"s));
	}
}

// static
void Framework::OpenGLGlutProcessManagerImpl
	::ChangeSize(int width, int height)
{
	if (sm_OpenGLGlutCallBack != nullptr)
	{
		sm_OpenGLGlutCallBack->ChangeSize(width, height);
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack指针为空！"s));
	}
}

// static
void Framework::OpenGLGlutProcessManagerImpl
	::TimerFunction(int timer)
{
	if (sm_OpenGLGlutCallBack != nullptr)
	{
		sm_OpenGLGlutCallBack->TimerFunction(TimerFunction);
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack指针为空！"s));
	}

	SYSTEM_UNUSED_ARG(timer);
}

// static
void Framework::OpenGLGlutProcessManagerImpl
	::SpecialKeysDown(int key, int xCoordinate, int yCoordinate)
{
	if (sm_OpenGLGlutCallBack != nullptr)
	{
		sm_OpenGLGlutCallBack->SpecialKeysDown(key, xCoordinate, yCoordinate);
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack指针为空！"s));
	}
}

// static
void Framework::OpenGLGlutProcessManagerImpl
	::KeyboardDown(unsigned char key, int xCoordinate, int yCoordinate)
{
	if (sm_OpenGLGlutCallBack != nullptr)
	{
		sm_OpenGLGlutCallBack->KeyboardDown(key, xCoordinate, yCoordinate);
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack指针为空！"s));
	}
}

// static
void Framework::OpenGLGlutProcessManagerImpl
	::MouseFunction(int button, int state, int xCoordinate, int yCoordinate)
{
	if (sm_OpenGLGlutCallBack != nullptr)
	{
		sm_OpenGLGlutCallBack->MouseClick(button, state, xCoordinate, yCoordinate);
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack指针为空！"s));
	}
}

// static
void Framework::OpenGLGlutProcessManagerImpl
	::MotionFunction(int xCoordinate, int yCoordinate)
{
	if (sm_OpenGLGlutCallBack != nullptr)
	{
		sm_OpenGLGlutCallBack->MotionFunction(xCoordinate, yCoordinate);
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack指针为空！"s));
	}
}

// static
void Framework::OpenGLGlutProcessManagerImpl
	::PassiveMotion(int xCoordinate, int yCoordinate)
{
	if (sm_OpenGLGlutCallBack != nullptr)
	{
		sm_OpenGLGlutCallBack->PassiveMotion(xCoordinate, yCoordinate);
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack指针为空！"s));
	}
}

// static
void Framework::OpenGLGlutProcessManagerImpl
	::IdleFunction()
{
	if (sm_OpenGLGlutCallBack != nullptr)
	{
		sm_OpenGLGlutCallBack->IdleFunction();
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack指针为空！"s));
	}
}

// static
void Framework::OpenGLGlutProcessManagerImpl
	::ProcessMenu(int menuValue)
{
	if (sm_OpenGLGlutCallBack != nullptr)
	{
		sm_OpenGLGlutCallBack->ProcessMenu(menuValue);
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack指针为空！"s));
	}
}

// static
void Framework::OpenGLGlutProcessManagerImpl
	::SpecialKeysUp(int key, int xCoordinate, int yCoordinate)
{
	if (sm_OpenGLGlutCallBack != nullptr)
	{
		sm_OpenGLGlutCallBack->SpecialKeysUp(key, xCoordinate, yCoordinate);
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack指针为空！"s));
	}
}

// static
void Framework::OpenGLGlutProcessManagerImpl
	::KeyboardUp(unsigned char key, int xCoordinate, int yCoordinate)
{
	if (sm_OpenGLGlutCallBack != nullptr)
	{
		sm_OpenGLGlutCallBack->KeyboardUp(key, xCoordinate, yCoordinate);
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack指针为空！"s));
	}
}

// static
void Framework::OpenGLGlutProcessManagerImpl
	::TerminateFunction()
{
	EXCEPTION_TRY
	{
		Terminate();

		sm_OpenGLGlutCallBack.reset();

		auto mainFunctionHelper = sm_MainFunctionHelper.lock();
		if (mainFunctionHelper != nullptr)
		{		
			mainFunctionHelper->Destroy();
			sm_MainFunctionHelper.reset();
		}
	}
	EXCEPTION_ALL_CATCH(Framework)
}





