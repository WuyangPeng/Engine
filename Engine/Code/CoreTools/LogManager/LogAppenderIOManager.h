///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/07 21:37)

#ifndef CORE_TOOLS_LOG_MANAGER_LOG_APPENDER_IO_MANAGER_H
#define CORE_TOOLS_LOG_MANAGER_LOG_APPENDER_IO_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "LogManagerFwd.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Exception/ExceptionFwd.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Threading/Mutex.h"

#include <boost/format/format_fwd.hpp>
#include <string>

CORE_TOOLS_NON_COPY_EXPORT_IMPL(LogAppenderIOManagerImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE LogAppenderIOManager final
    {
    public:
        NON_COPY_TYPE_DECLARE(LogAppenderIOManager);
        using AppenderManagerSharedPtr = std::shared_ptr<AppenderManager>;
        using Format = boost::basic_format<System::TChar>;
        using LogAppenderIOManagerSharedPtr = std::shared_ptr<LogAppenderIOManager>;

    public:
        NODISCARD static LogAppenderIOManagerSharedPtr CreateSharedPtr(LogLevel logLevel, const AppenderManagerSharedPtr& appenderManager);
        NODISCARD static LogAppenderIOManager Create();
        NODISCARD static LogAppenderIOManager Create(LogLevel logLevel, const AppenderManagerSharedPtr& appenderManager);

        LogAppenderIOManager(LogLevel logLevel, const AppenderManagerSharedPtr& appenderManager);
        ~LogAppenderIOManager() noexcept = default;
        LogAppenderIOManager(const LogAppenderIOManager& rhs) = delete;
        LogAppenderIOManager& operator=(const LogAppenderIOManager& rhs) = delete;
        LogAppenderIOManager(LogAppenderIOManager&& rhs) noexcept;
        LogAppenderIOManager& operator=(LogAppenderIOManager&& rhs) noexcept;

    private:
        explicit LogAppenderIOManager(MAYBE_UNUSED DisableNotThrow disableNotThrow);

    public:
        CLASS_INVARIANT_DECLARE;

        // 析构函数会通过打印日志报告错误，以下函数不抛出任何异常，需要捕获所有异常。
        LogAppenderIOManager& operator<<(const char* message) noexcept;
        LogAppenderIOManager& operator<<(const wchar_t* message) noexcept;
        LogAppenderIOManager& operator<<(int32_t value) noexcept;
        LogAppenderIOManager& operator<<(uint32_t value) noexcept;
        LogAppenderIOManager& operator<<(int64_t value) noexcept;
        LogAppenderIOManager& operator<<(uint64_t value) noexcept;
        LogAppenderIOManager& operator<<(float value) noexcept;
        LogAppenderIOManager& operator<<(double value) noexcept;
        LogAppenderIOManager& operator<<(const std::string& message) noexcept;
        LogAppenderIOManager& operator<<(const std::string_view& message) noexcept;
        LogAppenderIOManager& operator<<(const std::wstring& message) noexcept;
        LogAppenderIOManager& operator<<(const FunctionDescribed& functionDescribed) noexcept;
        LogAppenderIOManager& operator<<(const Error& error) noexcept;
        LogAppenderIOManager& operator<<(const std::exception& error) noexcept;
        LogAppenderIOManager& operator<<(LogFilter filterType) noexcept;
        LogAppenderIOManager& operator<<(LogAppenderIOManageSign sign) noexcept;
        LogAppenderIOManager& operator<<(const LogFileName& logFileName) noexcept;

        void SetAppenderManager(const AppenderManagerSharedPtr& appenderManager) noexcept;

    private:
        PackageType impl;
        Mutex logAppenderIOManagerMutex;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_LOG_APPENDER_IO_MANAGER_H
