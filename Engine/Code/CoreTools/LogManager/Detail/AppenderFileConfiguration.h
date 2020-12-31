//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/15 9:56)

#ifndef CORE_TOOLS_LOG_MANAGER_APPENDER_FILE_CONFIGURATION_H
#define CORE_TOOLS_LOG_MANAGER_APPENDER_FILE_CONFIGURATION_H

#include "CoreTools/CoreToolsDll.h"

#include "AppenderImpl.h"
#include "System/Helper/UnicodeUsing.h"

#include <fstream>
#include <string>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE AppenderFileConfiguration final : public AppenderImpl
    {
    public:
        using ClassType = AppenderFileConfiguration;
        using ParentType = AppenderImpl;

    public:
        AppenderFileConfiguration(const String& directory, AppenderPrint appenderFlags, LogLevel logLevel,
                                  int maxFileSize, bool backup, const String& extensionName);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] AppenderType GetAppenderType() const noexcept final;

        [[nodiscard]] const AppenderImplPtr Clone() const final;

        [[nodiscard]] String GetDirectory() const final;
        [[nodiscard]] String GetExtensionName() const final;
        [[nodiscard]] int GetMaxFileSize() const noexcept final;
        [[nodiscard]] bool IsBackup() const noexcept final;

    private:
        void DoWrite(const LogMessage& message, const LogMessagePrefix& prefix, const LogMessagePostfix& postfix) noexcept final;

    private:
        String m_Directory;
        String m_ExtensionName;
        int m_MaxFileSize;
        bool m_Backup;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_APPENDER_FILE_CONFIGURATION_H
