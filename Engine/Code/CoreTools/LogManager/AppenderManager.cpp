///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/21 09:58)

#include "CoreTools/CoreToolsExport.h"

#include "Appender.h"
#include "AppenderManager.h"
#include "Logger.h"
#include "Detail/AppenderManagerImpl.h"
#include "System/Helper/Tools.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::AppenderManager::AppenderManagerSharedPtr CoreTools::AppenderManager::Create()
{
    return std::make_shared<AppenderManager>(AppenderManagerCreate::Init);
}

CoreTools::AppenderManager::AppenderManager(AppenderManagerCreate appenderManagerCreate)
    : impl{ ImplCreateUseDefaultConstruction::Default }
{
    System::UnusedFunction(appenderManagerCreate);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, AppenderManager)

bool CoreTools::AppenderManager::IsAppenderExist(const String& name) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->IsAppenderExist(name);
}

bool CoreTools::AppenderManager::InsertLogger(const Logger& logger)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->InsertLogger(logger);
}

bool CoreTools::AppenderManager::RemoveLogger(LogFilter logFilter) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->RemoveLogger(logFilter);
}

bool CoreTools::AppenderManager::InsertConsoleAppender(const Appender& appender)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->InsertConsoleAppender(appender);
}

bool CoreTools::AppenderManager::RemoveAppender(const String& name) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->RemoveAppender(name);
}

void CoreTools::AppenderManager::Clear() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->Clear();
}

void CoreTools::AppenderManager::Write(const LogMessage& message) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->Write(message);
}

CoreTools::LogLevel CoreTools::AppenderManager::GetMinLogLevelType(LogFilter logFilter) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetMinLogLevelType(logFilter);
}

bool CoreTools::AppenderManager::InsertAppender(const String& name, const Appender& appender)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->InsertAppender(name, appender);
}

void CoreTools::AppenderManager::Write(const String& name, const LogMessage& message)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->Write(name, message);
}

System::String CoreTools::AppenderManager::GetConsoleAppenderName()
{
    return ImplType::GetConsoleAppenderName();
}

System::String CoreTools::AppenderManager::GetDefaultAppenderName()
{
    return ImplType::GetDefaultAppenderName();
}
