/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 14:53)

#include "Framework/FrameworkExport.h"

#include "OpenGLGlutProcessManagerImpl.h"
#include "System/Helper/Tools.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "Framework/MainFunctionHelper/MainFunctionHelperBase.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutCallBackInterface.h"

Framework::OpenGLGlutProcessManagerImpl::OpenGLGlutCallBackInterfaceSharedPtr Framework::OpenGLGlutProcessManagerImpl::openGLGlutCallBack{};

Framework::OpenGLGlutProcessManagerImpl::MainFunctionHelperBaseWeakPtr Framework::OpenGLGlutProcessManagerImpl::mainFunctionHelper{};

Framework::OpenGLGlutProcessManagerImpl::OpenGLGlutProcessManagerImpl() noexcept
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, OpenGLGlutProcessManagerImpl)

Framework::OpenGLGlutProcessManagerImpl::OpenGLGlutCallBackInterfaceSharedPtr Framework::OpenGLGlutProcessManagerImpl::GetOpenGLGlutCallBack() noexcept
{
    return openGLGlutCallBack;
}

void Framework::OpenGLGlutProcessManagerImpl::SetOpenGLGlutCallBack(const OpenGLGlutCallBackInterfaceSharedPtr& aOpenGLGlutCallBack) noexcept
{
    openGLGlutCallBack = aOpenGLGlutCallBack;
}

void Framework::OpenGLGlutProcessManagerImpl::ClearOpenGLGlutCallBack() noexcept
{
    openGLGlutCallBack.reset();
}

void Framework::OpenGLGlutProcessManagerImpl::SetWindowId(int window)
{
    if (openGLGlutCallBack != nullptr)
    {
        openGLGlutCallBack->SetWindowId(window);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack已释放"s))
    }
}

int Framework::OpenGLGlutProcessManagerImpl::GetWindowId()
{
    if (openGLGlutCallBack != nullptr)
    {
        return openGLGlutCallBack->GetWindowId();
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack已释放"s))
    }
}

void Framework::OpenGLGlutProcessManagerImpl::SetMillisecond(int millisecond)
{
    if (openGLGlutCallBack != nullptr)
    {
        openGLGlutCallBack->SetMillisecond(millisecond);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack已释放"s))
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
        THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack已释放"s))
    }
}

void Framework::OpenGLGlutProcessManagerImpl::SetMainFunctionHelper(const MainFunctionHelperBaseSharedPtr& mainFunctionHelperBase) noexcept
{
    mainFunctionHelper = mainFunctionHelperBase;
}

void Framework::OpenGLGlutProcessManagerImpl::ClearMainFunctionHelper() noexcept
{
    mainFunctionHelper.reset();
}

Framework::OpenGLGlutProcessManagerImpl::MainFunctionHelperBaseSharedPtr Framework::OpenGLGlutProcessManagerImpl::GetMainFunctionHelper()
{
    if (auto helper = mainFunctionHelper.lock();
        helper != nullptr)
    {
        return helper;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("MainFunctionHelper已释放"s))
    }
}

bool Framework::OpenGLGlutProcessManagerImpl::PreCreate()
{
    if (openGLGlutCallBack != nullptr)
    {
        return openGLGlutCallBack->PreCreate();
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack已释放"s))
    }
}

bool Framework::OpenGLGlutProcessManagerImpl::Initialize()
{
    if (openGLGlutCallBack != nullptr)
    {
        return openGLGlutCallBack->Initialize();
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack已释放"s))
    }
}

void Framework::OpenGLGlutProcessManagerImpl::PreIdle()
{
    if (openGLGlutCallBack != nullptr)
    {
        openGLGlutCallBack->PreIdle();
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack已释放"s))
    }
}

void Framework::OpenGLGlutProcessManagerImpl::Terminate()
{
    if (openGLGlutCallBack != nullptr)
    {
        openGLGlutCallBack->Terminate();
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack已释放"s))
    }
}

void Framework::OpenGLGlutProcessManagerImpl::RenderScene()
{
    if (openGLGlutCallBack != nullptr)
    {
        if (!openGLGlutCallBack->RenderScene())
        {
            LOG_SINGLETON_ENGINE_APPENDER(Info, Framework, SYSTEM_TEXT("RenderScene出现错误。"));
        }
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack已释放"s))
    }
}

void Framework::OpenGLGlutProcessManagerImpl::ChangeSize(int width, int height)
{
    if (openGLGlutCallBack != nullptr)
    {
        if (!openGLGlutCallBack->ChangeSize(width, height))
        {
            LOG_SINGLETON_ENGINE_APPENDER(Info, Framework, SYSTEM_TEXT("ChangeSize出现错误。"));
        }
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack已释放"s))
    }
}

void Framework::OpenGLGlutProcessManagerImpl::TimerFunction(int timer)
{
    System::UnusedFunction(timer);

    if (openGLGlutCallBack != nullptr)
    {
        if (!openGLGlutCallBack->TimerFunction(TimerFunction))
        {
            LOG_SINGLETON_ENGINE_APPENDER(Info, Framework, SYSTEM_TEXT("TimerFunction出现错误。"));
        }
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack已释放"s))
    }
}

void Framework::OpenGLGlutProcessManagerImpl::SpecialKeysDown(int key, int xCoordinate, int yCoordinate)
{
    if (openGLGlutCallBack != nullptr)
    {
        if (!openGLGlutCallBack->SpecialKeysDown(key, xCoordinate, yCoordinate))
        {
            LOG_SINGLETON_ENGINE_APPENDER(Info, Framework, SYSTEM_TEXT("SpecialKeysDown出现错误。"));
        }
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack已释放"s))
    }
}

void Framework::OpenGLGlutProcessManagerImpl::KeyboardDown(unsigned char key, int xCoordinate, int yCoordinate)
{
    if (openGLGlutCallBack != nullptr)
    {
        if (!openGLGlutCallBack->KeyboardDown(key, xCoordinate, yCoordinate))
        {
            LOG_SINGLETON_ENGINE_APPENDER(Info, Framework, SYSTEM_TEXT("KeyboardDown出现错误。"));
        }
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack已释放"s))
    }
}

void Framework::OpenGLGlutProcessManagerImpl::MouseFunction(int button, int state, int xCoordinate, int yCoordinate)
{
    if (openGLGlutCallBack != nullptr)
    {
        if (!openGLGlutCallBack->MouseClick(button, state, xCoordinate, yCoordinate))
        {
            LOG_SINGLETON_ENGINE_APPENDER(Info, Framework, SYSTEM_TEXT("MouseClick出现错误。"));
        }
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack已释放"s))
    }
}

void Framework::OpenGLGlutProcessManagerImpl::MotionFunction(int xCoordinate, int yCoordinate)
{
    if (openGLGlutCallBack != nullptr)
    {
        if (!openGLGlutCallBack->MotionFunction(xCoordinate, yCoordinate))
        {
            LOG_SINGLETON_ENGINE_APPENDER(Info, Framework, SYSTEM_TEXT("MotionFunction出现错误。"));
        }
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack已释放"s))
    }
}

void Framework::OpenGLGlutProcessManagerImpl::PassiveMotion(int xCoordinate, int yCoordinate)
{
    if (openGLGlutCallBack != nullptr)
    {
        if (!openGLGlutCallBack->PassiveMotion(xCoordinate, yCoordinate))
        {
            LOG_SINGLETON_ENGINE_APPENDER(Info, Framework, SYSTEM_TEXT("PassiveMotion出现错误。"));
        }
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack已释放"s))
    }
}

void Framework::OpenGLGlutProcessManagerImpl::IdleFunction()
{
    if (openGLGlutCallBack != nullptr)
    {
        if (!openGLGlutCallBack->IdleFunction())
        {
            LOG_SINGLETON_ENGINE_APPENDER(Info, Framework, SYSTEM_TEXT("IdleFunction出现错误。"));
        }
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack已释放"s))
    }
}

void Framework::OpenGLGlutProcessManagerImpl::ProcessMenu(int menuValue)
{
    if (openGLGlutCallBack != nullptr)
    {
        if (!openGLGlutCallBack->ProcessMenu(menuValue))
        {
            LOG_SINGLETON_ENGINE_APPENDER(Info, Framework, SYSTEM_TEXT("ProcessMenu出现错误。"));
        }
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack已释放"s))
    }
}

void Framework::OpenGLGlutProcessManagerImpl::SpecialKeysUp(int key, int xCoordinate, int yCoordinate)
{
    if (openGLGlutCallBack != nullptr)
    {
        if (!openGLGlutCallBack->SpecialKeysUp(key, xCoordinate, yCoordinate))
        {
            LOG_SINGLETON_ENGINE_APPENDER(Info, Framework, SYSTEM_TEXT("SpecialKeysUp出现错误。"));
        }
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack已释放"s))
    }
}

void Framework::OpenGLGlutProcessManagerImpl::KeyboardUp(unsigned char key, int xCoordinate, int yCoordinate)
{
    if (openGLGlutCallBack != nullptr)
    {
        if (!openGLGlutCallBack->KeyboardUp(key, xCoordinate, yCoordinate))
        {
            LOG_SINGLETON_ENGINE_APPENDER(Info, Framework, SYSTEM_TEXT("KeyboardUp出现错误。"));
        }
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("OpenGLGlutCallBack已释放"s))
    }
}

void Framework::OpenGLGlutProcessManagerImpl::TerminateFunction()
{
    EXCEPTION_TRY
    {
        DoTerminateFunction();
    }
    EXCEPTION_ALL_CATCH(Framework)
}

void Framework::OpenGLGlutProcessManagerImpl::DoTerminateFunction()
{
    Terminate();

    openGLGlutCallBack.reset();

    if (auto helper = mainFunctionHelper.lock();
        helper != nullptr)
    {
        helper->Destroy();
        helper.reset();
    }
}
