///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/07 22:51)

#include "CoreTools/CoreToolsExport.h"

#include "LogAsynchronous.h"
#include "Detail/LogAsynchronousImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::make_unique;

SINGLETON_GET_PTR_DEFINE(CoreTools, LogAsynchronous);

CoreTools::LogAsynchronous::LogAsynchronousUniquePtr CoreTools::LogAsynchronous::logAsynchronous{};

void CoreTools::LogAsynchronous::Create()
{
    logAsynchronous = make_unique<CoreTools::LogAsynchronous>(LogAsynchronousCreate::Init);
}

void CoreTools::LogAsynchronous::Destroy() noexcept
{
    logAsynchronous.reset();
}

CoreTools::LogAsynchronous::LogAsynchronous(MAYBE_UNUSED LogAsynchronousCreate logAsynchronousCreate)
    : impl{ ImplCreateUseDefaultConstruction::Default }
{
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
