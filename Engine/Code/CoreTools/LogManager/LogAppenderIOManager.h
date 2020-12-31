//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/15 11:39)

// 日志输出位置IO管理器基类外部接口
#ifndef CORE_TOOLS_LOG_MANAGER_LOG_APPENDER_IO_MANAGER_H
#define CORE_TOOLS_LOG_MANAGER_LOG_APPENDER_IO_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "LogManagerFwd.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Exception/ExceptionFwd.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Threading/Mutex.h"

#include <boost/format/format_fwd.hpp>
#include <boost/noncopyable.hpp>
#include <string>

CORE_TOOLS_EXPORT_SHARED_PTR(LogAppenderIOManagerImpl);
EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE LogAppenderIOManager final : private boost::noncopyable
    {
    public:
        NON_COPY_CLASSES_TYPE_DECLARE(LogAppenderIOManager);
        using AppenderManagerPtr = std::shared_ptr<AppenderManager>;
        using Format = boost::basic_format<System::TChar>;

    public:
        LogAppenderIOManager(LogLevel logLevel, const AppenderManagerPtr& appenderManager);
        explicit LogAppenderIOManager(DisableNotThrow disableNotThrow);

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
        LogAppenderIOManager& operator<<(const std::wstring& message) noexcept;
        LogAppenderIOManager& operator<<(const FunctionDescribed& functionDescribed) noexcept;
        LogAppenderIOManager& operator<<(const Error& error) noexcept;
        LogAppenderIOManager& operator<<(const std::exception& error) noexcept;
        LogAppenderIOManager& operator<<(LogFilter filterType) noexcept;
        LogAppenderIOManager& operator<<(LogAppenderIOManageSign sign) noexcept;
        LogAppenderIOManager& operator<<(const LogFileName& logFileName) noexcept;

        void SetAppenderManager(const AppenderManagerPtr& appenderManager) noexcept;

    private:
        IMPL_TYPE_DECLARE(LogAppenderIOManager);
        Mutex m_LogAppenderIOManagerMutex;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_LOG_APPENDER_IO_MANAGER_H
