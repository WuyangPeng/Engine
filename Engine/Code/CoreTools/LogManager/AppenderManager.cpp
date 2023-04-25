///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/28 16:07)

#include "CoreTools/CoreToolsExport.h"

#include "Appender.h"
#include "AppenderManager.h"
#include "Logger.h"
#include "Detail/AppenderManagerImpl.h"
#include "System/Helper/Tools.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

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

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, AppenderManager, InsertLogger, Logger, bool)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, AppenderManager, InsertConsoleAppender, Appender, bool)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, AppenderManager, RemoveLogger, LogFilter, bool)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, AppenderManager, RemoveAppender, String, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, AppenderManager, Write, LogMessage, void) 
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, AppenderManager, Clear, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, AppenderManager, IsAppenderExist, String, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, AppenderManager, GetMinLogLevelType, LogFilter, CoreTools::LogLevel)

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
