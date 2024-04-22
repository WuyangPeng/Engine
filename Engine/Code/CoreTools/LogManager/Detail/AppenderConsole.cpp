/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 13:56)

#include "CoreTools/CoreToolsExport.h"

#include "AppenderConsole.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/LogManager/LogConsoleTextColorsManager.h"
#include "CoreTools/LogManager/LogMessage.h"
#include "CoreTools/LogManager/LogMessagePostfix.h"
#include "CoreTools/LogManager/LogMessagePrefix.h"

#include <iostream>

CoreTools::AppenderConsole::AppenderConsole(AppenderPrint appenderFlags, LogLevel logLevel)
    : ParentType{ appenderFlags, logLevel }
{
#ifndef TCRE_USE_GCC

    const std::locale chs{ "chs" };
    COUT.imbue(chs);

#endif  // TCRE_USE_GCC

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, AppenderConsole)

CoreTools::AppenderType CoreTools::AppenderConsole::GetAppenderType() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return AppenderType::Console;
}

void CoreTools::AppenderConsole::DoWrite(const LogMessage& message, const LogMessagePrefix& prefix, const LogMessagePostfix& postfix) const
{
    const LogConsoleTextColorsManager manager{ message.GetLogLevel() };

    const auto messageDescribe = message.GetMessageDescribe();

    /// 错误消息打印到错误控制台
    if (message.GetLogLevel() == LogLevel::Error || message.GetLogLevel() == LogLevel::Fatal)
    {
        CERR << prefix.GetPrefix() << messageDescribe << postfix.GetPostfix();
    }
    else
    {
        COUT << prefix.GetPrefix() << messageDescribe << postfix.GetPostfix();
    }
}

const CoreTools::AppenderConsole::AppenderImplSharedPtr CoreTools::AppenderConsole::Clone() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return std::make_shared<ClassType>(*this);
}
