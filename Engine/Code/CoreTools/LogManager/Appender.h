///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/07 21:33)

#ifndef CORE_TOOLS_LOG_MANAGER_APPENDER_H
#define CORE_TOOLS_LOG_MANAGER_APPENDER_H

#include "CoreTools/CoreToolsDll.h"

#include "LogManagerFwd.h"
#include "Flags/LogManagerFlags.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"

CORE_TOOLS_DELAY_COPY_UNSHARED_EXPORT_IMPL(Appender, AppenderImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE Appender final
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(Appender);
        using String = System::String;

    public:
        // 创建AppenderConsole
        explicit Appender(AppenderPrint appenderFlags, LogLevel logLevel = LogLevel::Disabled);

        // 创建AppenderFile
        Appender(const String& directory,
                 const String& fileName,
                 AppenderPrint appenderFlags,
                 LogLevel logLevel,
                 int maxFileSize,
                 bool backup,
                 const String& extensionName);

        // 创建AppenderFileConfiguration
        Appender(const String& directory,
                 AppenderPrint appenderFlags,
                 LogLevel logLevel,
                 int maxFileSize,
                 bool backup,
                 const String& extensionName);

        CLASS_INVARIANT_DECLARE;

        NODISCARD LogLevel GetLogLevel() const noexcept;
        NODISCARD AppenderPrint GetFlags() const noexcept;
        NODISCARD AppenderType GetAppenderType() const noexcept;

        void SetLogLevel(LogLevel level);
        void Write(const LogMessage& message);

        NODISCARD String GetDirectory() const;
        NODISCARD String GetExtensionName() const;
        NODISCARD int GetMaxFileSize() const noexcept;
        NODISCARD bool IsBackup() const noexcept;

        void Reload();

        NODISCARD bool IsDefault() const noexcept;
        void SetIsDefault(bool isDefault);

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_APPENDER_H
