///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/25 14:35)

#ifndef CORE_TOOLS_LOG_HELPER_LOG_H
#define CORE_TOOLS_LOG_HELPER_LOG_H

#include "CoreTools/CoreToolsDll.h"

#include "LogManagerFwd.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Exception/Error.h"

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE LogHelper final
    {
    public:
        using ClassType = LogHelper;
        using String = System::String;

    public:
        template <typename... Types>
        LogHelper(LogLevel logLevel, LogFilter logFilter, const FunctionDescribed& functionDescribed, Types&&... arguments) noexcept;

        template <typename... Types>
        LogHelper(const LogFileName& fileName, LogLevel logLevel, LogFilter logFilter, const FunctionDescribed& functionDescribed, Types&&... arguments) noexcept;

        LogHelper() noexcept = delete;
        ~LogHelper() noexcept = default;
        LogHelper(const LogHelper& rhs) noexcept = delete;
        LogHelper& operator=(const LogHelper& rhs) noexcept = delete;
        LogHelper(LogHelper&& rhs) noexcept = delete;
        LogHelper& operator=(LogHelper&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

    private:
        template <typename Type, typename... Types>
        void Process(LogMessage& logMessage, Type&& argument, Types&&... arguments);
        void Process(const LogMessage& logMessage);
    };
}

#endif  // CORE_TOOLS_LOG_HELPER_LOG_H
