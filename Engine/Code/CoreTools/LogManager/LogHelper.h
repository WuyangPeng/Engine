/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 13:53)

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
        static void Process(const LogMessage& logMessage);
    };
}

#endif  // CORE_TOOLS_LOG_HELPER_LOG_H
