//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.2 (2020/10/15 18:47)

#include "CoreTools/CoreToolsExport.h"

#include "Appender.h"
#include "AppenderManager.h"
#include "Logger.h"
#include "Detail/AppenderManagerImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;

CoreTools::AppenderManager::AppenderManager([[maybe_unused]] DisableNotThrow disableNotThrow)
    : m_Impl{ make_shared<AppenderManagerImpl>() }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, AppenderManager)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, AppenderManager, InsertLogger, Logger, bool)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, AppenderManager, InsertConsoleAppender, Appender, bool)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, AppenderManager, RemoveLogger, LogFilter, bool)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, AppenderManager, RemoveAppender, String, bool)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, AppenderManager, Write, LogMessage, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, AppenderManager, WriteToConsole, LogMessage, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, AppenderManager, Clear, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, AppenderManager, ReloadAppenderFile, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, AppenderManager, IsAppenderExist, String, bool)

bool CoreTools::AppenderManager::InsertAppender(const String& name, const Appender& appender)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->InsertAppender(name, appender);
}

void CoreTools::AppenderManager::Write(const String& name, const LogMessage& message)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->Write(name, message);
}

const System::String CoreTools::AppenderManager::GetConsoleAppenderName()
{
    return ImplType::GetConsoleAppenderName();
}

const System::String CoreTools::AppenderManager ::GetDefaultAppenderName()
{
    return ImplType::GetDefaultAppenderName();
}
