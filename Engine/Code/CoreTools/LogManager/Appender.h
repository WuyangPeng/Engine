//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/10/15 11:37)

// ���λ���ⲿ�ӿ�
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
        // ����AppenderConsole
        explicit Appender(AppenderPrint appenderFlags, LogLevel logLevel = LogLevel::Disabled);

        // ����AppenderFile
        Appender(const String& directory, const String& fileName, AppenderPrint appenderFlags, LogLevel logLevel,
                 int maxFileSize, bool backup, const String& extensionName);

        // ����AppenderFileConfiguration
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
