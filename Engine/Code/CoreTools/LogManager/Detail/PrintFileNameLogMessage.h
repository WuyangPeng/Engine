/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 00:37)

#ifndef CORE_TOOLS_LOG_MANAGER_PRINT_FILE_NAME_LOG_MESSAGE_IMPL_H
#define CORE_TOOLS_LOG_MANAGER_PRINT_FILE_NAME_LOG_MESSAGE_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "PrintLogMessage.h"
#include "CoreTools/LogManager/LogFileName.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE PrintFileNameLogMessage : public PrintLogMessage
    {
    public:
        using ClassType = PrintFileNameLogMessage;
        using ParentType = PrintLogMessage;

    public:
        PrintFileNameLogMessage(const LogFileName& fileName, LogLevel level, LogFilter filter, const FunctionDescribed& functionDescribed) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD LogMessageImplSharedPtr Clone() const override;

        NODISCARD String GetFileName() const override;

    private:
        LogFileName fileName;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_PRINT_FILE_NAME_LOG_MESSAGE_IMPL_H
