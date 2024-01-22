/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 00:37)

#ifndef CORE_TOOLS_LOG_MANAGER_LOG_MESSAGE_FACTORY_H
#define CORE_TOOLS_LOG_MANAGER_LOG_MESSAGE_FACTORY_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/LogManager/LogManagerInternalFwd.h"

#include <memory>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE LogMessageFactory
    {
    public:
        using ClassType = LogMessageFactory;

        using LogMessageImplSharedPtr = std::shared_ptr<LogMessageImpl>;
        using String = System::String;

    public:
        NODISCARD static LogMessageImplSharedPtr Create(LogLevel level, LogFilter filter, const FunctionDescribed& functionDescribed);
        NODISCARD static LogMessageImplSharedPtr Create(const LogFileName& fileName, LogLevel level, LogFilter filter, const FunctionDescribed& functionDescribed);

        CLASS_INVARIANT_DECLARE;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_LOG_MESSAGE_FACTORY_H
