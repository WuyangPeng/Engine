/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 00:38)

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
        // ����AppenderConsole
        explicit Appender(AppenderPrint appenderFlags, LogLevel logLevel = LogLevel::Disabled);

        // ����AppenderFile
        Appender(const String& directory,
                 const String& fileName,
                 AppenderPrint appenderFlags,
                 LogLevel logLevel,
                 int maxFileSize,
                 bool backup,
                 const String& extensionName);

        // ����AppenderFileConfiguration
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
        void Write(const LogMessage& message) const;

        NODISCARD String GetDirectory() const;
        NODISCARD String GetExtensionName() const;
        NODISCARD int GetMaxFileSize() const noexcept;
        NODISCARD bool IsBackup() const noexcept;

        NODISCARD bool IsDefault() const noexcept;
        void SetIsDefault(bool isDefault);

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_APPENDER_H
