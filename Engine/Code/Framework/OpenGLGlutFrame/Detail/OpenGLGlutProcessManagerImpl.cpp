///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/07 14:42)

#include "Framework/FrameworkExport.h"

#include "OpenGLGlutProcessManagerImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Framework/MainFunctionHelper/MainFunctionHelperBase.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutCallBackInterface.h"

using namespace std::literals;

Framework::OpenGLGlutProcessManagerImpl::OpenGLGlutCallBackInterfaceSharedPtr Framework::OpenGLGlutProcessManagerImpl::openGLGlutCallBack{};

Framework::OpenGLGlutProcessManagerImpl::MainFunctionHelperBaseWeakPtr Framework::OpenGLGlutProcessManagerImpl::mainFunctionHelper{};

Framework::OpenGLGlutProcessManagerImpl::OpenGLGlutProcessManagerImpl() noexcept
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, OpenGLGlutProcessManagerImpl)

// static
Framework::OpenGLGlutProcessManagerImpl::OpenGLGlutCallBackInterfaceSharedPtr Framework::OpenGLGlutProcessManagerImpl::GetOpenGLGlutCallBack() noexcept
{
    return openGLGlutCallBack;
}

// static
void Framework::OpenGLGlutProcessManagerImpl::SetOpenGLGlutCallBack(const OpenGLGlutCallBackInterfaceSharedPtr& aOpenGLGlutCallBack) noexcept
{
    openGLGlutCallBack = aOpenGLGlutCallBack;
}

// static
void Framework::OpenGLGlutProcessManagerImpl::ClearOpenGLGlutCallBack() noexcept
{
    openGLGlutCallBack.reset();
}

// static
void Framework::OpenGLGlutProcessManagerImpl::SetWindowID(int window)
{
    if (openGLGlutCallBack != nullptr)
    {
        openGLGlutCallBack->SetWindowID(window);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack指针为空！"s));
    }
}

// static
int Framework::OpenGLGlutProcessManagerImpl::GetWindowID()
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    if (openGLGlutCallBack != nullptr)
    {
        return openGLGlutCallBack->GetWindowID();
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack指针为空！"s));
    }
}

// static
void Framework::OpenGLGlutProcessManagerImpl::SetMillisecond(int millisecond)
{
    if (openGLGlutCallBack != nullptr)
    {
        openGLGlutCallBack->SetMillisecond(millisecond);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack指针为空！"s));
    }
}

int Framework::OpenGLGlutProcessManagerImpl::GetMillisecond()
{
    if (openGLGlutCallBack != nullptr)
    {
        return openGLGlutCallBack->GetMillisecond();
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack指针为空！"s));
    }
}

// static
void Framework::OpenGLGlutProcessManagerImpl::SetMainFunctionHelper(const MainFunctionHelperBaseSharedPtr& mainFunctionHelperBase) noexcept
{
    mainFunctionHelper = mainFunctionHelperBase;
}

// static
void Framework::OpenGLGlutProcessManagerImpl::ClearMainFunctionHelper() noexcept
{
    mainFunctionHelper.reset();
}

Framework::OpenGLGlutProcessManagerImpl::MainFunctionHelperBaseSharedPtr Framework::OpenGLGlutProcessManagerImpl::GetMainFunctionHelper()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    auto helper = mainFunctionHelper.lock();
    if (helper != nullptr)
    {
        return helper;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("MainFunctionHelper指针为空！"s));
    }
}

// static
bool Framework::OpenGLGlutProcessManagerImpl::PreCreate()
{
    if (openGLGlutCallBack != nullptr)
    {
        return openGLGlutCallBack->PreCreate();
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack指针为空！"s));
    }
}

// static
bool Framework::OpenGLGlutProcessManagerImpl::Initialize()
{
    if (openGLGlutCallBack != nullptr)
    {
        return openGLGlutCallBack->Initialize();
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack指针为空！"s));
    }
}

// static
void Framework::OpenGLGlutProcessManagerImpl::PreIdle()
{
    if (openGLGlutCallBack != nullptr)
    {
        openGLGlutCallBack->PreIdle();
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack指针为空！"s));
    }
}

// static
void Framework::OpenGLGlutProcessManagerImpl::Terminate()
{
    if (openGLGlutCallBack != nullptr)
    {
        openGLGlutCallBack->Terminate();
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack指针为空！"s));
    }
}

// static
void Framework::OpenGLGlutProcessManagerImpl::RenderScene()
{
    if (openGLGlutCallBack != nullptr)
    {
        openGLGlutCallBack->RenderScene();
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack指针为空！"s));
    }
}

// static
void Framework::OpenGLGlutProcessManagerImpl::ChangeSize(int width, int height)
{
    if (openGLGlutCallBack != nullptr)
    {
        openGLGlutCallBack->ChangeSize(width, height);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack指针为空！"s));
    }
}

// static
void Framework::OpenGLGlutProcessManagerImpl::TimerFunction([[maybe_unused]] int timer)
{
    if (openGLGlutCallBack != nullptr)
    {
        openGLGlutCallBack->TimerFunction(TimerFunction);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack指针为空！"s));
    }
}

// static
void Framework::OpenGLGlutProcessManagerImpl::SpecialKeysDown(int key, int xCoordinate, int yCoordinate)
{
    if (openGLGlutCallBack != nullptr)
    {
        openGLGlutCallBack->SpecialKeysDown(key, xCoordinate, yCoordinate);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack指针为空！"s));
    }
}

// static
void Framework::OpenGLGlutProcessManagerImpl::KeyboardDown(unsigned char key, int xCoordinate, int yCoordinate)
{
    if (openGLGlutCallBack != nullptr)
    {
        openGLGlutCallBack->KeyboardDown(key, xCoordinate, yCoordinate);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack指针为空！"s));
    }
}

// static
void Framework::OpenGLGlutProcessManagerImpl::MouseFunction(int button, int state, int xCoordinate, int yCoordinate)
{
    if (openGLGlutCallBack != nullptr)
    {
        openGLGlutCallBack->MouseClick(button, state, xCoordinate, yCoordinate);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack指针为空！"s));
    }
}

// static
void Framework::OpenGLGlutProcessManagerImpl::MotionFunction(int xCoordinate, int yCoordinate)
{
    if (openGLGlutCallBack != nullptr)
    {
        openGLGlutCallBack->MotionFunction(xCoordinate, yCoordinate);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack指针为空！"s));
    }
}

// static
void Framework::OpenGLGlutProcessManagerImpl::PassiveMotion(int xCoordinate, int yCoordinate)
{
    if (openGLGlutCallBack != nullptr)
    {
        openGLGlutCallBack->PassiveMotion(xCoordinate, yCoordinate);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack指针为空！"s));
    }
}

// static
void Framework::OpenGLGlutProcessManagerImpl::IdleFunction()
{
    if (openGLGlutCallBack != nullptr)
    {
        openGLGlutCallBack->IdleFunction();
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack指针为空！"s));
    }
}

// static
void Framework::OpenGLGlutProcessManagerImpl::ProcessMenu(int menuValue)
{
    if (openGLGlutCallBack != nullptr)
    {
        openGLGlutCallBack->ProcessMenu(menuValue);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack指针为空！"s));
    }
}

// static
void Framework::OpenGLGlutProcessManagerImpl::SpecialKeysUp(int key, int xCoordinate, int yCoordinate)
{
    if (openGLGlutCallBack != nullptr)
    {
        openGLGlutCallBack->SpecialKeysUp(key, xCoordinate, yCoordinate);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack指针为空！"s));
    }
}

// static
void Framework::OpenGLGlutProcessManagerImpl::KeyboardUp(unsigned char key, int xCoordinate, int yCoordinate)
{
    if (openGLGlutCallBack != nullptr)
    {
        openGLGlutCallBack->KeyboardUp(key, xCoordinate, yCoordinate);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack指针为空！"s));
    }
}

// static
void Framework::OpenGLGlutProcessManagerImpl::TerminateFunction()
{
    EXCEPTION_TRY
    {
        Terminate();

        openGLGlutCallBack.reset();

        auto helper = mainFunctionHelper.lock();
        if (helper != nullptr)
        {
            helper->Destroy();
            helper.reset();
        }
    }
    EXCEPTION_ALL_CATCH(Framework)
}
