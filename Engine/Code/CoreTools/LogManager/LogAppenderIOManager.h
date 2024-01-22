/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 00:38)

#ifndef CORE_TOOLS_LOG_MANAGER_LOG_APPENDER_IO_MANAGER_H
#define CORE_TOOLS_LOG_MANAGER_LOG_APPENDER_IO_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "LogManagerFwd.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <boost/format/format_fwd.hpp>

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

    private:
        explicit LogAppenderIOManager(DisableNotThrow disableNotThrow);

    public:
        CLASS_INVARIANT_DECLARE;

        LogAppenderIOManager& operator<<(const LogMessage& message);

        void SetAppenderManager(const AppenderManagerSharedPtr& appenderManager) noexcept;

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_LOG_APPENDER_IO_MANAGER_H
