//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/15 11:37)

// 输出位置外部接口
#ifndef CORE_TOOLS_LOG_MANAGER_APPENDER_H
#define CORE_TOOLS_LOG_MANAGER_APPENDER_H

#include "CoreTools/CoreToolsDll.h"

#include "LogManagerFwd.h"
#include "Flags/LogManagerFlags.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
CORE_TOOLS_DELAY_COPY_UNSHARED_EXPORT_IMPL(Appender,AppenderImpl);

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
        Appender(const String& directory, const String& fileName, AppenderPrint appenderFlags, LogLevel logLevel,
                 int maxFileSize, bool backup, const String& extensionName);

        // 创建AppenderFileConfiguration
        Appender(const String& directory, AppenderPrint appenderFlags, LogLevel logLevel,
                 int maxFileSize, bool backup, const String& extensionName);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] LogLevel GetLogLevel() const noexcept;
        [[nodiscard]] AppenderPrint GetFlags() const noexcept;
        [[nodiscard]] AppenderType GetAppenderType() const noexcept;

        void SetLogLevel(LogLevel level);
        void Write(const LogMessage& message);

        [[nodiscard]] String GetDirectory() const;
        [[nodiscard]] String GetExtensionName() const;
        [[nodiscard]] int GetMaxFileSize() const noexcept;
        [[nodiscard]] bool IsBackup() const noexcept;

        void Reload();

        [[nodiscard]] bool IsDefault() const noexcept;
        void SetIsDefault(bool isDefault);

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_APPENDER_H
