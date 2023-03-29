///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/24 16:00)

#include "CoreTools/CoreToolsExport.h"

#include "LogAppenderIOManager.h"
#include "Detail/LogAppenderIOManagerImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

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

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR_NOEXCEPT(CoreTools, LogAppenderIOManager, SetAppenderManager, AppenderManagerSharedPtr, void)

CoreTools::LogAppenderIOManager& CoreTools::LogAppenderIOManager::operator<<(const LogMessage& message)
{
    *impl << message;

    return *this;
}
