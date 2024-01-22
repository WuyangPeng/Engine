/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 00:35)

#ifndef CORE_TOOLS_LOG_MANAGER_APPENDER_FILE_CONFIGURATION_H
#define CORE_TOOLS_LOG_MANAGER_APPENDER_FILE_CONFIGURATION_H

#include "CoreTools/CoreToolsDll.h"

#include "AppenderImpl.h"
#include "System/Helper/UnicodeUsing.h"

#include <string>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE AppenderFileConfiguration final : public AppenderImpl
    {
    public:
        using ClassType = AppenderFileConfiguration;
        using ParentType = AppenderImpl;

    public:
        AppenderFileConfiguration(String directory,
                                  AppenderPrint appenderFlags,
                                  LogLevel logLevel,
                                  int maxFileSize,
                                  bool backup,
                                  String extensionName) noexcept;

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD AppenderType GetAppenderType() const noexcept override;

        NODISCARD const AppenderImplSharedPtr Clone() const override;

        NODISCARD String GetDirectory() const override;
        NODISCARD String GetExtensionName() const override;
        NODISCARD int GetMaxFileSize() const noexcept override;
        NODISCARD bool IsBackup() const noexcept override;

    private:
        void DoWrite(const LogMessage& message, const LogMessagePrefix& prefix, const LogMessagePostfix& postfix) const noexcept override;

    private:
        String directory;
        String extensionName;
        int maxFileSize;
        bool backup;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_APPENDER_FILE_CONFIGURATION_H
