///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/07 22:43)

#include "CoreTools/CoreToolsExport.h"

#include "Appender.h"
#include "AppenderManager.h"
#include "Logger.h"
#include "Detail/AppenderManagerImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

CoreTools::AppenderManager::AppenderManagerSharedPtr CoreTools::AppenderManager::Create()
{
    return std::make_shared<AppenderManager>(AppenderManagerCreate::Init);
}

CoreTools::AppenderManager::AppenderManager(MAYBE_UNUSED AppenderManagerCreate appenderManagerCreate)
    : impl{ ImplCreateUseDefaultConstruction::Default }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, AppenderManager)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, AppenderManager, InsertLogger, Logger, bool)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, AppenderManager, InsertConsoleAppender, Appender, bool)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, AppenderManager, RemoveLogger, LogFilter, bool)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, AppenderManager, RemoveAppender, String, bool)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, AppenderManager, Write, LogMessage, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, AppenderManager, WriteToConsole, LogMessage, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, AppenderManager, Clear, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, AppenderManager, ReloadAppenderFile, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, AppenderManager, IsAppenderExist, String, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, AppenderManager, GetMinLogLevelType, LogFilter, CoreTools::LogLevel)

bool CoreTools::AppenderManager::InsertAppender(const String& name, const Appender& appender)
{
    return impl->InsertAppender(name, appender);
}

void CoreTools::AppenderManager::Write(const String& name, const LogMessage& message)
{
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
