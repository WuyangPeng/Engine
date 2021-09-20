//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/15 11:39)

// ��־���λ��IO�����������ⲿ�ӿ�
#ifndef CORE_TOOLS_LOG_MANAGER_LOG_APPENDER_IO_MANAGER_H
#define CORE_TOOLS_LOG_MANAGER_LOG_APPENDER_IO_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "LogManagerFwd.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Exception/ExceptionFwd.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Threading/Mutex.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include <boost/format/format_fwd.hpp>
 
#include <string>

CORE_TOOLS_NON_COPY_EXPORT_IMPL(LogAppenderIOManagerImpl);


namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE LogAppenderIOManager final 
    {
    public:
        NON_COPY_TYPE_DECLARE(LogAppenderIOManager);
        using AppenderManagerPtr = std::shared_ptr<AppenderManager>;
        using Format = boost::basic_format<System::TChar>;

    public:
        LogAppenderIOManager(LogLevel logLevel, const AppenderManagerPtr& appenderManager);
        explicit LogAppenderIOManager(DisableNotThrow disableNotThrow);
        ~LogAppenderIOManager() noexcept = default;
        LogAppenderIOManager(const LogAppenderIOManager& rhs) noexcept = delete;
        LogAppenderIOManager& operator=(const LogAppenderIOManager& rhs) noexcept = delete;
        LogAppenderIOManager(LogAppenderIOManager&& rhs) noexcept = delete;
        LogAppenderIOManager& operator=(LogAppenderIOManager&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        // ����������ͨ����ӡ��־����������º������׳��κ��쳣����Ҫ���������쳣��
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
        PackageType impl;
        Mutex m_LogAppenderIOManagerMutex;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_LOG_APPENDER_IO_MANAGER_H
