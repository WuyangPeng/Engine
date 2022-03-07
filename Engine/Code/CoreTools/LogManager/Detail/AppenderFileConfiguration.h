///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/06 0:15)

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
        AppenderFileConfiguration(const String& directory,
                                  AppenderPrint appenderFlags,
                                  LogLevel logLevel,
                                  int maxFileSize,
                                  bool backup,
                                  const String& extensionName);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD AppenderType GetAppenderType() const noexcept final;

        NODISCARD const AppenderImplSharedPtr Clone() const final;

        NODISCARD String GetDirectory() const final;
        NODISCARD String GetExtensionName() const final;
        NODISCARD int GetMaxFileSize() const noexcept final;
        NODISCARD bool IsBackup() const noexcept final;

    private:
        void DoWrite(const LogMessage& message, const LogMessagePrefix& prefix, const LogMessagePostfix& postfix) noexcept final;

    private:
        String directory;
        String extensionName;
        int maxFileSize;
        bool backup;
    };
}

#endif  // CORE_TOOLS_LOG_MANAGER_APPENDER_FILE_CONFIGURATION_H
