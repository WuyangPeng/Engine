//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.2 (2020/10/15 17:55)

#include "CoreTools/CoreToolsExport.h"

#include "AppenderConsole.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/LogManager/LogConsoleTextColorsManager.h"
#include "CoreTools/LogManager/LogMessage.h"
#include "CoreTools/LogManager/LogMessagePostfix.h"
#include "CoreTools/LogManager/LogMessagePrefix.h"

#include <iostream>

using std::locale;
using std::make_shared;

CoreTools::AppenderConsole::AppenderConsole(AppenderPrint appenderFlags, LogLevel logLevel)
    : ParentType{ appenderFlags, logLevel }
{
#ifndef TCRE_USE_GCC
    locale chs{ "chs" };
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

void CoreTools::AppenderConsole::DoWrite(const LogMessage& message, const LogMessagePrefix& prefix, const LogMessagePostfix& postfix)
{
    LogConsoleTextColorsManager manager{ message.GetLogLevel() };

    auto messageDescribe = message.GetMessageDescribe();

    // 错误消息打印到错误控制台
    if (message.GetLogLevel() == LogLevel::Error || message.GetLogLevel() == LogLevel::Fatal)
    {
        CERR << prefix.GetPrefix() << messageDescribe << postfix.GetPostfix();
    }
    else
    {
        COUT << prefix.GetPrefix() << messageDescribe << postfix.GetPostfix();
    }
}

const CoreTools::AppenderConsole::AppenderImplPtr CoreTools::AppenderConsole::Clone() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return make_shared<ClassType>(*this);
}
