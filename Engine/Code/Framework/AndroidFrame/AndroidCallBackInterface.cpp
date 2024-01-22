/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 15:30)

#include "Framework/FrameworkExport.h"

#include "AndroidCallBackInterface.h"

#include "System/Helper/Tools.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/Application/Flags/ApplicationTrait.h"

Framework::AndroidCallBackInterface::AndroidCallBackInterface(int64_t delta) noexcept
    : state{ nullptr }, delta{ delta }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, AndroidCallBackInterface)

bool Framework::AndroidCallBackInterface::PreCreate()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    CoreTools::DisableNoexcept();

    return true;
}

bool Framework::AndroidCallBackInterface::Initialize()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    CoreTools::DisableNoexcept();

    return true;
}

void Framework::AndroidCallBackInterface::PreIdle()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    CoreTools::DisableNoexcept();
}

void Framework::AndroidCallBackInterface::Terminate()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    CoreTools::DisableNoexcept();
}

int Framework::AndroidCallBackInterface::GetTerminateKey() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return AndroidApplicationTrait::KeyIdentifiers::keyTerminate;
}

void Framework::AndroidCallBackInterface::InitMessage(AndroidApp* androidApp)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    CoreTools::DisableNoexcept();

    state = androidApp;
}

void Framework::AndroidCallBackInterface::ResizedMessage(AndroidApp* androidApp)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(androidApp);

    CoreTools::DisableNoexcept();
}

void Framework::AndroidCallBackInterface::TermMessage(AndroidApp* androidApp)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(androidApp);

    CoreTools::DisableNoexcept();
}

void Framework::AndroidCallBackInterface::RedrawNeededMessage(AndroidApp* androidApp)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(androidApp);

    CoreTools::DisableNoexcept();
}

void Framework::AndroidCallBackInterface::Display(AndroidApp* androidApp, int64_t timeDelta)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(androidApp, timeDelta);

    CoreTools::DisableNoexcept();
}

void Framework::AndroidCallBackInterface::NotDealCmdMessage(AndroidApp* androidApp)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(androidApp);

    CoreTools::DisableNoexcept();
}

int Framework::AndroidCallBackInterface::NotDealInputMessage(AndroidApp* androidApp, AndroidInputEvent* androidInputEvent)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(androidApp, androidInputEvent);

    CoreTools::DisableNoexcept();

    return 0;
}

void Framework::AndroidCallBackInterface::RectChanged(AndroidApp* androidApp)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(androidApp);

    CoreTools::DisableNoexcept();
}

int Framework::AndroidCallBackInterface::KeyDownMessage(AndroidApp* androidApp, AndroidInputEvent* androidInputEvent)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(androidApp, androidInputEvent);

    CoreTools::DisableNoexcept();

    return 0;
}

int Framework::AndroidCallBackInterface::KeyUpMessage(AndroidApp* androidApp, AndroidInputEvent* androidInputEvent)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(androidApp, androidInputEvent);

    CoreTools::DisableNoexcept();

    return 0;
}

int Framework::AndroidCallBackInterface::ActionDownMessage(AndroidApp* androidApp, AndroidInputEvent* androidInputEvent)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(androidApp, androidInputEvent);

    CoreTools::DisableNoexcept();

    return 0;
}

int Framework::AndroidCallBackInterface::ActionUpMessage(AndroidApp* androidApp, AndroidInputEvent* androidInputEvent)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(androidApp, androidInputEvent);

    CoreTools::DisableNoexcept();

    return 0;
}

int Framework::AndroidCallBackInterface::ActionMoveMessage(AndroidApp* androidApp, AndroidInputEvent* androidInputEvent)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(androidApp, androidInputEvent);

    CoreTools::DisableNoexcept();

    return 0;
}

System::AndroidApp* Framework::AndroidCallBackInterface::GetAndroidApp() noexcept
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return state;
}

int64_t Framework::AndroidCallBackInterface::GetDelta() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return delta;
}
