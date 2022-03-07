///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/07 22:25)

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

    const locale chs{ "chs" };
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
    const LogConsoleTextColorsManager manager{ message.GetLogLevel() };

    const auto messageDescribe = message.GetMessageDescribe();

    // ������Ϣ��ӡ���������̨
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

    return make_shared<ClassType>(*this);
}
