///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/09/21 09:46)

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
