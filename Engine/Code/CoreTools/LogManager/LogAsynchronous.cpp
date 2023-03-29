///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/28 16:08)

#include "CoreTools/CoreToolsExport.h"

#include "LogAsynchronous.h"
#include "Detail/LogAsynchronousImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

SINGLETON_GET_PTR_DEFINE(CoreTools, LogAsynchronous);

CoreTools::LogAsynchronous::LogAsynchronousUniquePtr CoreTools::LogAsynchronous::logAsynchronous{};

void CoreTools::LogAsynchronous::Create()
{
    logAsynchronous = std::make_unique<CoreTools::LogAsynchronous>(LogAsynchronousCreate::Init);
}

void CoreTools::LogAsynchronous::Destroy() noexcept
{
    logAsynchronous.reset();
}

CoreTools::LogAsynchronous::LogAsynchronous(LogAsynchronousCreate logAsynchronousCreate)
    : impl{ ImplCreateUseDefaultConstruction::Default }
{
    System::UnusedFunction(logAsynchronousCreate);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, LogAsynchronous)

void CoreTools::LogAsynchronous::Registered(const LogMessage& message, const AppenderManagerSharedPtr& appenderManager)
{
    SINGLETON_SCOPED_MUTEX_ENTER_MEMBER;

    CORE_TOOLS_CLASS_IS_VALID_9;

    impl->Registered(message, appenderManager);
}

void CoreTools::LogAsynchronous::Registered(const String& fileName, const LogMessage& message, const AppenderManagerSharedPtr& appenderManager)
{
    SINGLETON_SCOPED_MUTEX_ENTER_MEMBER;

    CORE_TOOLS_CLASS_IS_VALID_9;

    impl->Registered(fileName, message, appenderManager);
}

void CoreTools::LogAsynchronous::Registered(const OStreamShared& streamShared, const std::string& message, LogLevel logLevel)
{
    SINGLETON_SCOPED_MUTEX_ENTER_MEMBER;

    CORE_TOOLS_CLASS_IS_VALID_9;

    impl->Registered(streamShared, message, logLevel);
}

void CoreTools::LogAsynchronous::Run()
{
    SINGLETON_SCOPED_MUTEX_ENTER_MEMBER;

    CORE_TOOLS_CLASS_IS_VALID_9;

    impl->SetThread();
}

void CoreTools::LogAsynchronous::Stop()
{
    SINGLETON_SCOPED_MUTEX_ENTER_MEMBER;

    CORE_TOOLS_CLASS_IS_VALID_9;

    impl->Stop();
    impl->Join();
}
