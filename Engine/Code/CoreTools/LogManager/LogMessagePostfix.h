//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/15 11:46)

// 日志消息后缀类外部接口
#ifndef CORE_TOOLS_LOG_MANAGER_LOG_MESSAGE_POSTFIX_H
#define CORE_TOOLS_LOG_MANAGER_LOG_MESSAGE_POSTFIX_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/LogManager/LogManagerFwd.h"

#include <string>

CORE_TOOLS_EXPORT_SHARED_PTR(LogMessagePostfixImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE LogMessagePostfix final
    {
    public:
        PERFORMANCE_UNSHARE_CLASSES_TYPE_DECLARE(LogMessagePostfix);
        using String = System::String;

    public:
        LogMessagePostfix(AppenderPrint appenderFlags, LogLevel level, const FunctionDescribed& functionDescribed);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] String GetPostfix() const;
        [[nodiscard]] int GetPostfixSize() const;

    private:
        IMPL_TYPE_DECLARE(LogMessagePrefix);
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_LOG_MESSAGE_POSTFIX_H
