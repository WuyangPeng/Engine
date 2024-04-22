/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 14:05)

#include "CoreTools/CoreToolsExport.h"

#include "LogAppenderIOManager.h"
#include "Detail/LogAppenderIOManagerImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::LogAppenderIOManager::LogAppenderIOManagerSharedPtr CoreTools::LogAppenderIOManager::CreateSharedPtr(LogLevel logLevel, const AppenderManagerSharedPtr& appenderManager)
{
    return std::make_shared<LogAppenderIOManager>(logLevel, appenderManager);
}

CoreTools::LogAppenderIOManager CoreTools::LogAppenderIOManager::Create()
{
    return LogAppenderIOManager{ DisableNotThrow::Disable };
}

CoreTools::LogAppenderIOManager CoreTools::LogAppenderIOManager::Create(LogLevel logLevel, const AppenderManagerSharedPtr& appenderManager)
{
    return LogAppenderIOManager{ logLevel, appenderManager };
}

CoreTools::LogAppenderIOManager::LogAppenderIOManager(LogLevel logLevel, const AppenderManagerSharedPtr& appenderManager)
    : impl{ logLevel, appenderManager }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::LogAppenderIOManager::LogAppenderIOManager(DisableNotThrow disableNotThrow)
    : impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    System::UnusedFunction(disableNotThrow);

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, LogAppenderIOManager)

CoreTools::LogAppenderIOManager& CoreTools::LogAppenderIOManager::operator<<(const LogMessage& message)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    *impl << message;

    return *this;
}

void CoreTools::LogAppenderIOManager::SetAppenderManager(const AppenderManagerSharedPtr& appenderManager) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->SetAppenderManager(appenderManager);
}
